#include "../s21_string.h"

#include <stdio.h>

typedef enum type { text, integer, string } TokenType_t;

typedef struct token_indices_and_type {
  int token_begin_index;
  int token_end_index;
  TokenType_t token_type;
} TokenIndicesAndType_t;

// sprintf flags
typedef enum s21_sprintf_flag {
  minus,
  plus,
  space,
  sharp,
  zero
} S21SprintfFlag_t;

typedef struct digit_token_format {
  S21SprintfFlag_t token_flag;
  // token_width;
  // token_accuracy;
  // token_length;
} DigitTokenFormat_t;

typedef struct digit_token {
  char token_string[256];
  char token_value[256];
  DigitTokenFormat_t token_format;
  int token_size;
  int token_position;
} DigitToken_t;

typedef struct string_token {
  char token_string[256];
  // string format
  int token_size;
  int token_position;
} StringToken_t;

typedef struct text_token {
  char token_string[256];
  char token_value[256];
  int token_size;
  int token_position;
} TextToken_t;

typedef union generic_token {
  DigitToken_t digit_token;
  StringToken_t string_token;
  TextToken_t text_token;
} Generic_Token_t;

typedef struct token {
  Generic_Token_t generic_token;
  int token_type;
} Token_t;

// TODO
//дополнить разбор %%
//выделить в субпарсер для строк формата

//позже удалить, ибо эта функция для проверки токенов
void print_lexemmes_throught_format_string(
    TokenIndicesAndType_t *tokens_metrics, int tokens_count,
    const char *format_string);
void print_generated_tokens(Token_t *tokens, int tokens_count);

void preparse_string_to_lexemmes(TokenIndicesAndType_t *returned_tokens_metrics,
                                 int *returned_tokens_count,
                                 const char *format_sting);
void build_text_token(const char *format_string,
                      TokenIndicesAndType_t *token_metrics,
                      TextToken_t *text_token);
void build_digit_token(const char *format_string,
                       TokenIndicesAndType_t *token_metrics,
                       DigitToken_t *digit_token);
void build_string_token(const char *format_string,
                        TokenIndicesAndType_t *token_metrics,
                        StringToken_t *string_token);

int s21_sprintf(char *str, const char *format, ...) {
  TokenIndicesAndType_t tokens_metrics[64] = {0};

  int tokens_count = 0;

  printf("buffer is %p\n",str);

  preparse_string_to_lexemmes(tokens_metrics, &tokens_count, format);

  print_lexemmes_throught_format_string(tokens_metrics, tokens_count, format);

  Token_t tokens[64] = {0};
  // Token_t current_token;

  for (int i = 0; i < tokens_count; i++) {
    printf("%d) ", i + 1);
    // current_token = tokens[i];
    switch (tokens_metrics[i].token_type) {
    case text:
      tokens[i].token_type = text;
      tokens[i].generic_token.text_token.token_position = i + 1;
      build_text_token(format, &tokens_metrics[i],
                       &tokens[i].generic_token.text_token);

      printf("hello from text token\n");
      break;
    case integer:
      tokens[i].token_type = integer;
      tokens[i].generic_token.digit_token.token_position = i + 1;
      build_digit_token(format, &tokens_metrics[i],
                        &tokens[i].generic_token.digit_token);

      printf("hello from integer token\n");
      break;
    case string:
      tokens[i].token_type = string;
      tokens[i].generic_token.string_token.token_position = i + 1;
      build_string_token(format, &tokens_metrics[i],
                         &tokens[i].generic_token.string_token);

      printf("hello from string token\n");
      break;
    }
  }

  print_generated_tokens(tokens, tokens_count);

  return 0;
}

void preparse_string_to_lexemmes(TokenIndicesAndType_t *returned_tokens_metrics,
                                 int *returned_tokens_count,
                                 const char *format_sting) {

  TokenIndicesAndType_t *current_token_metrics = S21_NULL;
  int format_length = 0;
  int current_char = 0;
  int tokens_count = 0;
  int is_spec_format_substring = 0;

  format_length = (int)s21_strlen(format_sting);
  format_length++;

  // "hello     %d\n world%s from sprintf\n"

  printf("Source string is : \"%s\"\n\n", format_sting);

  for (int i = 0; i < format_length; i++) {
    current_char = format_sting[i];
    //дополнить разбор %%
    if ((current_char == '%' || i == format_length - 1) &&
        format_sting[i + 1] != '%') {
      current_token_metrics = &returned_tokens_metrics[tokens_count];
      current_token_metrics->token_end_index = i;
      current_token_metrics->token_type = text;
      tokens_count++;

      current_token_metrics = &returned_tokens_metrics[tokens_count];
      current_token_metrics->token_begin_index = i + 1;
      is_spec_format_substring = 1;
    }

    //выделить в субпарсер для строк формата
    if (is_spec_format_substring) {
      switch (current_char) {
      case 'd':
        current_token_metrics->token_type = integer;
        is_spec_format_substring = 0;
        current_token_metrics->token_end_index = i;
        tokens_count++;

        current_token_metrics = &returned_tokens_metrics[tokens_count];
        current_token_metrics->token_begin_index = i + 1;
        break;
      case 's':
        current_token_metrics->token_type = string;
        is_spec_format_substring = 0;
        current_token_metrics->token_end_index = i;
        tokens_count++;

        current_token_metrics = &returned_tokens_metrics[tokens_count];
        current_token_metrics->token_begin_index = i + 1;
        break;
      }
    }
  }

  *returned_tokens_count = tokens_count;
}

//строим текстовый токен
void build_text_token(const char *format_string,
                      TokenIndicesAndType_t *token_metrics,
                      TextToken_t *text_token) {
  int token_length = 0;

  token_length =
      token_metrics->token_end_index - token_metrics->token_begin_index;

  for (int i = token_metrics->token_begin_index;
       i < token_metrics->token_end_index; i++)
    text_token->token_string[i - token_metrics->token_begin_index] =
        format_string[i];

  text_token->token_string[token_length] = '\0';
  text_token->token_size = (s21_size_t)token_length;
}

void build_digit_token(const char *format_string,
                       TokenIndicesAndType_t *token_metrics,
                       DigitToken_t *digit_token) {
  int token_length = 0;

  token_length =
      token_metrics->token_end_index - token_metrics->token_begin_index;

  for (int i = token_metrics->token_begin_index;
       i < token_metrics->token_end_index; i++)
    digit_token->token_string[i - token_metrics->token_begin_index] =
        format_string[i];

  digit_token->token_string[token_length] = '\0';
  digit_token->token_size = (s21_size_t)token_length;
}

void build_string_token(const char *format_string,
                        TokenIndicesAndType_t *token_metrics,
                        StringToken_t *string_token) {
  int token_length = 0;

  token_length =
      token_metrics->token_end_index - token_metrics->token_begin_index;

  for (int i = token_metrics->token_begin_index;
       i < token_metrics->token_end_index; i++)
    string_token->token_string[i - token_metrics->token_begin_index] =
        format_string[i];

  string_token->token_string[token_length] = '\0';
  string_token->token_size = (s21_size_t)token_length;
}

void print_lexemmes_throught_format_string(
    TokenIndicesAndType_t *tokens_metrics, int tokens_count,
    const char *format_string) {

  printf("Tokens count = %d items\n\n", tokens_count);

  for (int j = 0; j < tokens_count; j++) {
    switch (tokens_metrics[j].token_type) {
    case text:
      printf("\tToken type : text\n");
      break;
    case integer:
      printf("\tToken type : integer\n");
      break;
    case string:
      printf("\tToken type : string\n");
      break;
    }

    printf("\tToken begin index = %d\n\tToken end index = %d\n",
           tokens_metrics[j].token_begin_index,
           tokens_metrics[j].token_end_index);

    printf("\tToken string : \"");

    for (int k = tokens_metrics[j].token_begin_index;
         k <= tokens_metrics[j].token_end_index && format_string[k]; k++)
      putchar(format_string[k]);

    printf("\"\n\n");
  }
}

void print_generated_tokens(Token_t *tokens, int tokens_count) {
  printf("\nGenerated tokens:\n");
  for (int i = 0; i < tokens_count; i++) {
    switch (tokens[i].token_type) {
    case text:
      printf("\tToken type : text\n\tToken size = %d\n\tToken position = "
             "%d\n\tToken string is : \"%s\"\n\n",
             tokens[i].generic_token.text_token.token_size,
             tokens[i].generic_token.text_token.token_position,
             tokens[i].generic_token.text_token.token_string);
      break;
    case integer:
      printf("\tToken type : integer\n\tToken size = %d\n\tToken position = "
             "%d\n\tToken string is : \"%s\"\n\n",
             tokens[i].generic_token.digit_token.token_size,
             tokens[i].generic_token.digit_token.token_position,
             tokens[i].generic_token.digit_token.token_string);
      break;
    case string:
      printf("\tToken type : string\n\tToken size = %d\n\tToken position = "
             "%d\n\tToken string is : \"%s\"\n\n",
             tokens[i].generic_token.string_token.token_size,
             tokens[i].generic_token.string_token.token_position,
             tokens[i].generic_token.string_token.token_string);
      break;
    }
  }
  printf("\n\n");
}