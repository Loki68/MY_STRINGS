#include "s21_string_helpers.h"

int get_percent_count(const char *format_string) {
  int result = 1;

  for (int index = 0; format_string[index]; index++)
    if (format_string[index] == '%') {
      if (format_string[index + 1] == '%')
        index++;
      result += 2;
    }

  return result;
}

void parse_string(const char *format_string, int tokens_length,
                  FormattedToken_t *tokens) {

  FormattedToken_t *array_of_tokens = NULL;
  array_of_tokens = tokens;
  int tokens_counter = 0;
  int current_index = 0;
  int continue_loop = 1;

  array_of_tokens = tokens;
  ParsingState_t state = parsing_text;

  while (continue_loop) {
    switch (state) {
    case parsing_text:
      initialize_token(&array_of_tokens[tokens_counter], format_string);

      state = parse_to_text(&array_of_tokens[tokens_counter], &current_index);

      if (tokens_counter < tokens_length)
        tokens_counter = update_tokens_count(&array_of_tokens[tokens_counter],
                                             tokens_counter);

      break;
    case parsing_specs_text:

      initialize_token(&array_of_tokens[tokens_counter], format_string);

      state =
          parse_specs_to_text(&array_of_tokens[tokens_counter], &current_index);

      if (tokens_counter < tokens_length)
        tokens_counter = update_tokens_count(&array_of_tokens[tokens_counter],
                                             tokens_counter);

      break;
    case parsing_end:
      continue_loop = 0;
      break;
    }
  }
}

void initialize_token(FormattedToken_t *new_token, const char *format) {

  initialize_string_data(&new_token->token_format_string_data);
  initialize_string_data(&new_token->token_value_string_data);

  initialize_flags(&new_token->token_flags);

  initialize_accuracy_or_width(&new_token->token_width);
  initialize_accuracy_or_width(&new_token->token_accuracy);

  initialize_length(&new_token->token_length);

  initialize_spec(&new_token->token_spec);

  new_token->format_string = (char *)format;
  new_token->token_type = no_type;
  new_token->is_initialized = 1;
}

void initialize_string_data(FormatStringData_t *string_data) {
  FormatStringData_t *current_string_data = NULL;

  current_string_data = string_data;

  current_string_data->data_start_index = -1;
  current_string_data->data_length = 0;
}

void initialize_flags(Flags_t *token_flags) {
  Flags_t *current_token_flags = NULL;

  current_token_flags = token_flags;

  current_token_flags->no_flags = 1;
  current_token_flags->minus = 0;
  current_token_flags->plus = 0;
  current_token_flags->space = 0;
  current_token_flags->sharp = 0;
  current_token_flags->zero = 0;
  current_token_flags->flags_length = 0;
}

void initialize_accuracy_or_width(
    TokenAccuracyOrWidth_t *token_accuracy_or_width) {
  TokenAccuracyOrWidth_t *current_accuracy_or_width = NULL;

  current_accuracy_or_width = token_accuracy_or_width;

  current_accuracy_or_width->value_type = no_width_or_accuracy;

  initialize_string_data(&current_accuracy_or_width->accuracy_or_width_data);
}

void initialize_length(LengthFormat_t *token_length) {
  LengthFormat_t *current_token_length = NULL;

  current_token_length = token_length;

  current_token_length->length_type = no_length;

  initialize_string_data(&current_token_length->length_data);
}

void initialize_spec(SpecFormat_t *token_spec) {
  SpecFormat_t *current_token_spec = NULL;

  current_token_spec = token_spec;

  current_token_spec->type = no_spec;

  initialize_string_data(&current_token_spec->spec_format_data);
}

int update_tokens_count(FormattedToken_t *last_token, int tokens_count) {
  FormattedToken_t *token = NULL;
  int result = 0;

  token = last_token;

  result = tokens_count;

  if (token->token_format_string_data.data_length)
    result++;

  return result;
}

ParsingState_t parse_to_text(FormattedToken_t *token, int *returned_index) {
  FormattedToken_t *current_token = NULL;
  FormatStringData_t *token_format_data = NULL;
  char *format_string = NULL;
  ParsingState_t returning_state = parsing_text;
  int index = 0;
  int size = 0;

  current_token = token;
  token_format_data = &token->token_format_string_data;
  format_string = token->format_string;
  index = *returned_index;

  token_format_data->data_start_index = *returned_index;

  for (; format_string[index] && format_string[index] != '%'; index++)
    size++;

  if (size > 0) {
    current_token->token_type = text;
    token_format_data->data_length = size;

    *returned_index = index;
  }

  switch (format_string[index]) {
  case '\0':
    returning_state = parsing_end;
    break;
  case '%':
    returning_state = parsing_specs_text;
    break;
  }

  return returning_state;
}

ParsingState_t parse_specs_to_text(FormattedToken_t *token,
                                   int *returned_index) {
  FormattedToken_t *current_token = NULL;
  FormatStringData_t *token_format_data = NULL;
  SpecFormat_t *current_token_spec = NULL;
  char *format_string = NULL;
  ParsingState_t returning_state = parsing_text;
  int index = 0;
  int size = 1;
  int continue_loop = 1;
  index = *returned_index;

  current_token = token;
  token_format_data = &token->token_format_string_data;
  current_token_spec = &token->token_spec;
  format_string = token->format_string;
  token_format_data->data_start_index = *returned_index;
  index++;

  if (format_string[index] != '%') {
    for (; format_string[index] && continue_loop; index++)
      if (parse_to_spec(current_token_spec, &current_token->token_type,
                        format_string[index], index))
        continue_loop = 0;
      else
        size++;

    index--;
  }

  size++;

  returning_state = parsing_text;

  index++;

  if (size > 0) {
    token_format_data->data_length = size;

    *returned_index = index;
  }

  if (format_string[index] == '\0')
    returning_state = parsing_end;

  return returning_state;
}

void parse_format_of_tokens(FormattedToken_t *tokens, int tokens_count) {
  for (int i = 0; i < tokens_count; i++) {
    if (tokens[i].token_type != text)
      parse_single_format_of_token(&tokens[i]);

    if (tokens[i].token_type == text &&
        !tokens[i].token_value_string_data.data_length)
      fill_text_token_value(&tokens[i]);
  }
}

void parse_single_format_of_token(FormattedToken_t *token) {
  FormattedToken_t *current_token = NULL;
  char *string_pointer = NULL;
  int current_index = 0;
  current_token = token;

  if (current_token->token_format_string_data.data_length == 2)
    try_parse_percents_to_text(current_token);

  if (current_token->token_type != text &&
      current_token->token_format_string_data.data_length) {
    string_pointer = current_token->format_string;

    current_index = parse_to_flags(&current_token->token_flags,
                                   &current_token->token_format_string_data,
                                   string_pointer);

    current_index = parse_to_width(
        &current_token->token_width, string_pointer, current_index,
        current_token->token_format_string_data.data_length);

    current_index = parse_to_accuracy(
        &current_token->token_accuracy, string_pointer, current_index,
        current_token->token_format_string_data.data_length);

    parse_to_length(&current_token->token_length, string_pointer, current_index,
                    current_token->token_format_string_data.data_length);

    check_token_type(current_token);
  }
}

void try_parse_percents_to_text(FormattedToken_t *token) {
  FormattedToken_t *current_token = NULL;
  FormatStringData_t *format_data = NULL;
  FormatStringData_t *value_data = NULL;
  char *format_string = NULL;
  int begin_index = 0;
  int end_index = 0;

  current_token = token;
  format_string = token->format_string;
  format_data = &token->token_format_string_data;
  value_data = &token->token_value_string_data;

  begin_index = format_data->data_start_index;
  end_index = begin_index + format_data->data_length - 1;

  if (format_string[begin_index] == '%' && format_string[end_index] == '%') {
    current_token->token_type = text;
    value_data->data_start_index = begin_index;
    value_data->data_length = 1;
  }
}

void fill_text_token_value(FormattedToken_t *token) {
  FormattedToken_t *current_token = NULL;
  FormatStringData_t *format_data = NULL;
  FormatStringData_t *value_data = NULL;
  char *format_string = NULL;
  int begin_index = 0;
  int current_size = 0;

  current_token = token;
  format_string = token->format_string;
  format_data = &token->token_format_string_data;
  begin_index = format_data->data_start_index;
  current_size = format_data->data_length;

  if (current_size > 0) {
    value_data = &token->token_value_string_data;

    value_data->data_start_index = begin_index;
    value_data->data_length = current_size;
  }
}

int parse_to_flags(Flags_t *token_flags, FormatStringData_t *format_data,
                   char *format_string) {
  Flags_t *current_flags = NULL;
  char *format = NULL;

  int continue_parsing = 1;
  int index = 0;
  int format_length = 0;
  int flags_length = 0;

  current_flags = token_flags;
  format = format_string;

  index = format_data->data_start_index + 1;
  format_length = index + format_data->data_length;

  for (; index < format_length && continue_parsing; index++)
    switch (format[index]) {
    case minus:
      current_flags->minus = 1;
      current_flags->no_flags = 0;
      flags_length++;
      break;
    case plus:
      current_flags->plus = 1;
      current_flags->no_flags = 0;
      flags_length++;
      break;
    case space:
      current_flags->space = 1;
      current_flags->no_flags = 0;
      flags_length++;
      break;
    case sharp:
      current_flags->sharp = 1;
      current_flags->no_flags = 0;
      flags_length++;
      break;
    case zero:
      current_flags->zero = 1;
      current_flags->no_flags = 0;
      flags_length++;
      break;
    default:
      continue_parsing = 0;
      break;
    }

  current_flags->flags_length = flags_length;

  if (flags_length >= 0)
    index--;

  return index;
}

int parse_to_width(TokenAccuracyOrWidth_t *token_width, char *format_string,
                   int current_start_index, int current_length) {

  TokenAccuracyOrWidth_t *width_format = NULL;
  char *format = NULL;
  int continue_parsing = 1;
  int index = 0;
  int format_length = 0;

  int is_star = 0;
  int is_digit = 0;

  width_format = token_width;
  format = format_string;
  index = current_start_index;
  format_length = index + current_length;

  for (; index < format_length && continue_parsing; index++) {
    switch (format[index]) {
    case '*':
      is_star = 1;
      break;
    default:
      if (format[index] > 47 && format[index] < 58)
        is_digit = 1;
      else
        continue_parsing = 0;
      break;
    }
  }

  if (is_star && is_digit)
    width_format->value_type = no_width_or_accuracy;
  else if (is_star || is_digit) {

    if (is_star)
      width_format->value_type = star;
    else
      width_format->value_type = number;

    width_format->accuracy_or_width_data.data_start_index = current_start_index;
    width_format->accuracy_or_width_data.data_length =
        index - current_start_index - 1;
  }

  if (width_format->accuracy_or_width_data.data_length > 0)
    index--;

  return index;
}

int parse_to_accuracy(TokenAccuracyOrWidth_t *token_accuracy,
                      char *format_string, int current_start_index,
                      int current_length) {
  int index = 0;

  index = current_start_index;

  if (format_string[index] == '.') {
    index++;
    index =
        parse_to_width(token_accuracy, format_string, index, current_length);
  }

  return index;
}

void parse_to_length(LengthFormat_t *token_length, char *format_string,
                     int current_start_index, int current_length) {
  LengthFormat_t *length_format = NULL;
  char *format = NULL;
  int continue_parsing = 1;
  int format_length = 0;
  int index = 0;
  int h_count = 0;
  int l_count = 0;
  int L_count = 0;
  int length_length = 0;

  length_format = token_length;
  format = format_string;
  index = current_start_index;
  format_length = index + current_length;

  for (; index < format_length && continue_parsing; index++)
    switch (format[index]) {
    case 'h':
      h_count++;
      break;
    case 'l':
      l_count++;
      break;
    case 'L':
      L_count++;
      break;
    default:
      continue_parsing = 0;
      break;
    }

  length_length = h_count + l_count + L_count;

  if (length_length && length_length <= 2 && L_count < 2) {
    if (length_length == h_count)
      length_format->length_type = short_or_unsigned_short_int_length;

    if (length_length == l_count)
      length_format->length_type = long_int_length;

    if (length_length == L_count)
      length_format->length_type = long_double_length;
  }

  if (length_format->length_type != no_length && length_length) {
    length_format->length_data.data_start_index = current_start_index;
    length_format->length_data.data_length = length_length;
  }
}

int parse_to_spec(SpecFormat_t *token_spec, TokenType_t *token_type,
                  char format_character, int current_start_index) {

  SpecFormat_t *current_spec = NULL;
  int spec = 0;
  int continue_parsing = 1;
  int result = 0;
  int format_length = 0;

  current_spec = token_spec;
  spec = format_character;
  // no_type, text, integer, real, string, single_character
  switch (spec) {
  case 'c':
    result = 1;
    current_spec->type = c;
    current_spec->spec_format_data.data_start_index = current_start_index;
    current_spec->spec_format_data.data_length = 1;
    *token_type = single_character;
    break;
  case 'd':
    result = 1;
    current_spec->type = d;
    current_spec->spec_format_data.data_start_index = current_start_index;
    current_spec->spec_format_data.data_length = 1;
    *token_type = integer;
    break;
  case 'f':
    result = 1;
    current_spec->type = f;
    current_spec->spec_format_data.data_start_index = current_start_index;
    current_spec->spec_format_data.data_length = 1;
    *token_type = real;
    break;
  case 's':
    result = 1;
    current_spec->type = s;
    current_spec->spec_format_data.data_start_index = current_start_index;
    current_spec->spec_format_data.data_length = 1;
    *token_type = real;
    break;
  case 'u':
    result = 1;
    current_spec->type = u;
    current_spec->spec_format_data.data_start_index = current_start_index;
    current_spec->spec_format_data.data_length = 1;
    *token_type = integer;
    break;
  case 'g':
    result = 1;
    current_spec->type = g;
    current_spec->spec_format_data.data_start_index = current_start_index;
    current_spec->spec_format_data.data_length = 1;
    *token_type = real;
    break;
  case 'G':
    result = 1;
    current_spec->type = G;
    current_spec->spec_format_data.data_start_index = current_start_index;
    current_spec->spec_format_data.data_length = 1;
    *token_type = real;
    break;
  case 'e':
    result = 1;
    current_spec->type = e;
    current_spec->spec_format_data.data_start_index = current_start_index;
    current_spec->spec_format_data.data_length = 1;
    *token_type = real;
    break;
  case 'E':
    result = 1;
    current_spec->type = E;
    current_spec->spec_format_data.data_start_index = current_start_index;
    current_spec->spec_format_data.data_length = 1;
    *token_type = real;
    break;
  case 'x':
    result = 1;
    current_spec->type = x;
    current_spec->spec_format_data.data_start_index = current_start_index;
    current_spec->spec_format_data.data_length = 1;
    *token_type = integer;
    break;
  case 'X':
    result = 1;
    current_spec->type = X;
    current_spec->spec_format_data.data_start_index = current_start_index;
    current_spec->spec_format_data.data_length = 1;
    *token_type = integer;
    break;
  case 'o':
    result = 1;
    current_spec->type = o;
    current_spec->spec_format_data.data_start_index = current_start_index;
    current_spec->spec_format_data.data_length = 1;
    *token_type = integer; //??
    break;
  case 'p':
    result = 1;
    current_spec->type = p;
    current_spec->spec_format_data.data_start_index = current_start_index;
    current_spec->spec_format_data.data_length = 1;
    *token_type = integer;
    break;
  }

  return result;
}

void check_token_type(FormattedToken_t *token) {
  FormattedToken_t *current_token = NULL;
  //потому что процент не учитываются
  int result_length = 1;
  int control_length = 0;

  current_token = token;
  control_length = token->token_format_string_data.data_length;

  if (current_token->token_accuracy.value_type != no_width_or_accuracy)
    result_length++;

  result_length += current_token->token_spec.spec_format_data.data_length;
  result_length += current_token->token_length.length_data.data_length;
  result_length +=
      current_token->token_accuracy.accuracy_or_width_data.data_length;
  result_length +=
      current_token->token_width.accuracy_or_width_data.data_length;
  result_length += current_token->token_flags.flags_length;

  if (result_length != control_length)
    current_token->token_type = text;

}