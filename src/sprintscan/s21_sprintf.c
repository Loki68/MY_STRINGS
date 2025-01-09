#include "../s21_string.h"

#include <stdio.h>

typedef enum type { text, integer, string } TokenType_t;

typedef struct token {
  char token_string[512];
  s21_size_t token_size;
  TokenType_t token_type;
} Token_t;

int s21_sprintf(char *str, const char *format, ...) {
  Token_t tokens[64] = {0};
  Token_t *current_token = S21_NULL;
  int token_begin_index = 0;
  int tokens_count = 0;
  int parameters_count = 0;
  int format_length = 0;
  int current_char = 0;

  format_length = (int)s21_strlen(format);

  //"hello   %d world%s from sprintf\n"

  for (int i = 0; i <= format_length; i++) {
    current_char = format[i];

    if (current_char == '%' || i == format_length) {
      current_token = &tokens[tokens_count];
      parse_text_from_format(format, token_begin_index, i, current_token);
      tokens_count++;
      token_begin_index = i;
    }
  }

  printf("Tokens count = %d items\n\n", tokens_count);

  for (int j = 0; j < tokens_count; j++) {
    switch (tokens[j].token_type) {
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

    printf("\tToken string : ");
    for (int k = 0; tokens[j].token_string[k]; k++)
      putchar(tokens[j].token_string[k]);

    printf("\n");
    printf("\tToken size : %ld items\n\n", tokens[j].token_size - 1);
  }

  return 0;
}

void parse_text_from_format(const char *format_string, int begin_index,
                            int end_index, Token_t *token) {
  int token_length = 0;
  token->token_type = text;

  token_length = end_index - begin_index;

  for (int i = begin_index; i < end_index; i++) {
    // if()
    token->token_string[i - begin_index] = format_string[i];
  }

  token->token_string[token_length++] = '\0';
  token->token_size = (s21_size_t)token_length;
}