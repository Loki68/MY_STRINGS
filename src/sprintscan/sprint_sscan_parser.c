#include "sprint_sscan_parser.h"

void preparse_string_to_lexemmes(TokenIndicesAndType_t *returned_tokens_metrics,
                                 int *returned_tokens_count,
                                 const char *format_sting) {
  int format_length = 0;
  int current_char = 0;
  int tokens_count = 0;
  int is_spec_format_substring = 0;

  format_length = (int)s21_strlen(format_sting);
  format_length++;

  for (int i = 0; i < format_length; i++) {
    current_char = format_sting[i];
    //дополнить разбор %%
    if ((current_char == '%' || i == format_length - 1) &&
        format_sting[i + 1] != '%') {
      returned_tokens_metrics[tokens_count].token_end_index = i;
      returned_tokens_metrics[tokens_count].token_type = text;
      tokens_count++;

      returned_tokens_metrics[tokens_count].token_begin_index = i + 1;
      is_spec_format_substring = 1;
    }

    //выделить в субпарсер для строк формата
    if (is_spec_format_substring)
      switch (current_char) {
      case 'd':
        is_spec_format_substring = 0;
        returned_tokens_metrics[tokens_count].token_type = integer;
        returned_tokens_metrics[tokens_count].token_end_index = i;
        tokens_count++;

        returned_tokens_metrics[tokens_count].token_begin_index = i + 1;
        break;
      case 's':
        is_spec_format_substring = 0;
        returned_tokens_metrics[tokens_count].token_type = string;
        returned_tokens_metrics[tokens_count].token_end_index = i;
        tokens_count++;

        returned_tokens_metrics[tokens_count].token_begin_index = i + 1;
        break;

        // case '%':
        // smth about text token
        //  break;
      }
  }
  *returned_tokens_count = tokens_count;
}

// minus='-', plus='+', space=' ', sharp='#', zero='0'
//строим текстовый токен
void build_text_token(const char *format_string,
                      TokenIndicesAndType_t *token_metrics,
                      FormattedToken_t *text_token) {
  int token_length = 0;

  token_length =
      token_metrics->token_end_index - token_metrics->token_begin_index;

  for (int i = token_metrics->token_begin_index;
       i < token_metrics->token_end_index; i++) {
    text_token->token_string[i - token_metrics->token_begin_index] =
        format_string[i];
  }

  text_token->token_string[token_length] = '\0';
  // token_length++;//с учетом '\0'
  text_token->token_size = token_length;
}

void build_specified_token(const char *format_string,
                           TokenIndicesAndType_t *token_metrics,
                           FormattedToken_t *specified_token) {
  // // Flags_t *flags = S21_NULL;
  // TokenAccuracyOrWidth_t *width = S21_NULL;
  // TokenAccuracyOrWidth_t *accuracy = S21_NULL;
  int token_length = 0;
  int current_index = 0;

  token_length =
      token_metrics->token_end_index - token_metrics->token_begin_index;
  //где то тут должно быть разделение на формат.
  if (token_length)
    for (int i = token_metrics->token_begin_index;
         i < token_metrics->token_end_index; i++) {
      specified_token->token_string[i - token_metrics->token_begin_index] =
          format_string[i];
    }

  specified_token->token_string[token_length] = '\0';
  // token_length++;
  specified_token->token_size = token_length;

  //выделить отдельную функцию инициализации флагов, ширины и точности
  parse_token_character_to_flag(specified_token, &current_index);
  parse_token_character_to_accuracy_or_width(specified_token, &current_index,
                                             width_flag);

  if (specified_token->token_string[current_index] == '.'){
    current_index++;
    parse_token_character_to_accuracy_or_width(specified_token, &current_index,
                                               accuracy_flag);
  }

  // //мб добавить флаги типа формат установлен или нет
  // token->is_format_installed=1/0;
  // и обнуление формата
  //а дальше вот это:
  //в отдельную функцию
  //   if(flags->no_flags && token_length)
  //         s21_strncpy(digit_token->token_value,digit_token->token_string,token_length);
}

void parse_token_character_to_flag(FormattedToken_t *token,
                                   int *current_start_index) {
  Flags_t *token_flags = NULL;
  int continue_parsing = 1;
  int token_length = 0;
  // int current_character = 0;

  token_flags = &token->token_format.token_flags;
  token_flags->no_flags = 1;

  token_length = token->token_size;

  for (int index = *current_start_index;
       index < token_length && continue_parsing; index++)
    if (token_flags)
      switch (token->token_string[index]) {
      case minus:
        token_flags->minus = 1;
        token_flags->no_flags = 0;
        break;
      case plus:
        token_flags->plus = 1;
        token_flags->no_flags = 0;
        break;
      case space:
        token_flags->space = 1;
        token_flags->no_flags = 0;
        break;
      case sharp:
        token_flags->sharp = 1;
        token_flags->no_flags = 0;
        break;
      case zero:
        token_flags->zero = 1;
        token_flags->no_flags = 0;
        break;
      default:
        continue_parsing = 0;
        *current_start_index = index;
        break;
      }
}

void parse_token_character_to_accuracy_or_width(
    FormattedToken_t *token, int *current_start_index,
    AccuracyOrWidthFlag_t is_accuracy_or_width) {
  TokenAccuracyOrWidth_t *token_accuracy_or_width = NULL;
  int continue_parsing = 1;
  int token_length = 0;
  int current_character = 0;
  int index = 0;

  if (is_accuracy_or_width == accuracy_flag)
    token_accuracy_or_width = &token->token_format.token_accuracy;
  else
    token_accuracy_or_width = &token->token_format.token_width;

  token_accuracy_or_width->accuracy_or_width_flags.no_width_or_accuracy = 1;

  token_length = token->token_size;
  //звезда и число вместе дают не формат
  for (index = *current_start_index; index < token_length && continue_parsing;
       index++) {
    current_character = token->token_string[index];

    switch (current_character) {
    case star:
      token_accuracy_or_width->accuracy_or_width_flags.no_width_or_accuracy = 0;
      token_accuracy_or_width->accuracy_or_width_flags.star = 1;
      break;
    default:
      if (current_character < 48 || current_character > 57) {
        continue_parsing = 0;
      } else {
        token_accuracy_or_width->accuracy_or_width_flags.no_width_or_accuracy =
            0;
        token_accuracy_or_width->accuracy_or_width_flags.number = 1;
        token_accuracy_or_width
            ->accuracy_or_width_value[index - *current_start_index] =
            current_character;
      }
      break;
    }
  }

  token_accuracy_or_width
      ->accuracy_or_width_value[index - *current_start_index] = '\0';
  index--;

  // if (token->token_string[index] != '.' && is_accuracy_or_width ==
  // width_flag)
  if (token->token_string[index] != '\0' && token->token_string[index] != '.' &&
      is_accuracy_or_width == width_flag)
    init_accuracy_or_width(token_accuracy_or_width);

  if (token_accuracy_or_width->accuracy_or_width_flags.star &&
      token_accuracy_or_width->accuracy_or_width_flags.number)
    init_accuracy_or_width(token_accuracy_or_width);

  *current_start_index = index;
}

void init_accuracy_or_width(TokenAccuracyOrWidth_t *token_accuracy_or_width) {
  token_accuracy_or_width->accuracy_or_width_flags.star = 0;
  token_accuracy_or_width->accuracy_or_width_flags.number = 0;
  token_accuracy_or_width->accuracy_or_width_flags.no_width_or_accuracy = 1;

  //заменить
  token_accuracy_or_width->accuracy_or_width_value[0] = '\0';
}

int is_a_digit(int character) {
  int result = 0;
  return result;
}
int is_a_point(int character) {
  int result = 0;
  return result;
}

// void print_lexemmes_throught_format_string(
//     TokenIndicesAndType_t *tokens_metrics, int tokens_count,
//     const char *format_string) {

//   printf("Tokens count = %d items\n\n", tokens_count);

//   for (int j = 0; j < tokens_count; j++) {
//     printf("-------------------------------------------------------------------"
//            "\n");
//     switch (tokens_metrics[j].token_type) {
//     case text:
//       printf("\tToken type : text\n");
//       break;
//     case integer:
//       printf("\tToken type : integer\n");
//       break;
//     case string:
//       printf("\tToken type : string\n");
//       break;
//     }

//     printf("\tToken begin index = %d\n\tToken end index = %d\n",
//            tokens_metrics[j].token_begin_index,
//            tokens_metrics[j].token_end_index);

//     printf("\tToken string : \"");

//     for (int k = tokens_metrics[j].token_begin_index;
//          k <= tokens_metrics[j].token_end_index && format_string[k]; k++)
//       putchar(format_string[k]);

//     printf("\"\n---------------------------------------------------------------"
//            "---\n\n");
//   }
// }

// void print_generated_tokens(FormattedToken_t *tokens, int tokens_count) {
//   printf("\nGenerated tokens:\n");
//   for (int i = 0; i < tokens_count; i++) {
//     printf("-------------------------------------------------------------------"
//            "\n");
//     switch (tokens[i].token_type) {
//     case text:
//       printf("\tToken type : text\n\tToken size = %d\n\tToken position = "
//              "%d\n\tToken string is : \"%s\"\n\n",
//              tokens[i].token_size, tokens[i].token_position,
//              tokens[i].token_string);
//       break;
//     case integer:
//       printf("\tToken type : integer\n\tToken size = %d\n\tToken position = "
//              "%d\n\tToken string is : \"%s\"\n",
//              tokens[i].token_size, tokens[i].token_position,
//              tokens[i].token_string);

//       printf("\tToken flags:\n\t\tis no_flags = %d\n\t\tis minus = %d\n\t\tis "
//              "plus = %d\n\t\tis space = %d\n\t\tis sharp = %d\n\t\tis zero = "
//              "%d\n",
//              tokens[i].token_format.token_flags.no_flags,
//              tokens[i].token_format.token_flags.minus,
//              tokens[i].token_format.token_flags.plus,
//              tokens[i].token_format.token_flags.space,
//              tokens[i].token_format.token_flags.sharp,
//              tokens[i].token_format.token_flags.zero);
//       printf("\tToken width:\n");

//       printf("\t\tNo width = %d\n\t\tNumber = %d\n\t\tStar = %d\n",
//              tokens[i]
//                  .token_format.token_width.accuracy_or_width_flags
//                  .no_width_or_accuracy,
//              tokens[i].token_format.token_width.accuracy_or_width_flags.number,
//              tokens[i].token_format.token_width.accuracy_or_width_flags.star);

//       printf("\t\tValue is %s\n",
//              tokens[i].token_format.token_width.accuracy_or_width_value);

//       printf("\tToken accuracy:\n");

//       printf(
//           "\t\tNo accuracy = %d\n\t\tNumber = %d\n\t\tStar = %d\n",
//           tokens[i]
//               .token_format.token_accuracy.accuracy_or_width_flags
//               .no_width_or_accuracy,
//           tokens[i].token_format.token_accuracy.accuracy_or_width_flags.number,
//           tokens[i].token_format.token_accuracy.accuracy_or_width_flags.star);

//       printf("\t\tValue is %s",
//              tokens[i].token_format.token_accuracy.accuracy_or_width_value);

//       printf("\n\n");
//       break;
//     case string:
//       printf("\tToken type : string\n\tToken size = %d\n\tToken position = "
//              "%d\n\tToken string is : \"%s\"\n",
//              tokens[i].token_size, tokens[i].token_position,
//              tokens[i].token_string);

//       printf("\tToken flags:\n\t\tis no_flags = %d\n\t\tis minus = %d\n\t\tis "
//              "plus = %d\n\t\tis space = %d\n\t\tis sharp = %d\n\t\tis zero = "
//              "%d\n",
//              tokens[i].token_format.token_flags.no_flags,
//              tokens[i].token_format.token_flags.minus,
//              tokens[i].token_format.token_flags.plus,
//              tokens[i].token_format.token_flags.space,
//              tokens[i].token_format.token_flags.sharp,
//              tokens[i].token_format.token_flags.zero);
//       printf("\tToken width:\n");

//       printf("\t\tNo width = %d\n\t\tNumber = %d\n\t\tStar = %d\n",
//              tokens[i]
//                  .token_format.token_width.accuracy_or_width_flags
//                  .no_width_or_accuracy,
//              tokens[i].token_format.token_width.accuracy_or_width_flags.number,
//              tokens[i].token_format.token_width.accuracy_or_width_flags.star);

//       printf("\t\tValue is %s\n",
//              tokens[i].token_format.token_width.accuracy_or_width_value);

//       printf("\tToken accuracy:\n");

//       printf(
//           "\t\tNo accuracy = %d\n\t\tNumber = %d\n\t\tStar = %d\n",
//           tokens[i]
//               .token_format.token_accuracy.accuracy_or_width_flags
//               .no_width_or_accuracy,
//           tokens[i].token_format.token_accuracy.accuracy_or_width_flags.number,
//           tokens[i].token_format.token_accuracy.accuracy_or_width_flags.star);

//       printf("\t\tValue is %s",
//              tokens[i].token_format.token_accuracy.accuracy_or_width_value);

//       printf("\n\n");

//       break;
//     }
//     printf("\n---------------------------------------------------------------"
//            "---\n\n");
//   }
//   printf("\n\n");
// }