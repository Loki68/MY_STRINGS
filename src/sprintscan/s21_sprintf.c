#include "../s21_string.h"

#include "sprint_sscan_parser.h"

// TODO
//дополнить разбор %%
//обработать конец строки
//выделить в субпарсер для строк формата
// В этом файле и построение токена и его удаление ибо сложная процедура
// build_specified_token
//выделить отдельную функцию инициализации флагов, ширины и точности

//позже удалить, ибо эта функция для проверки токенов

int s21_sprintf(char *str, const char *format, ...) {

  TokenIndicesAndType_t *tokens_metrics = NULL;
  FormattedToken_t *generated_tokens = NULL;

  s21_size_t tokens_metrics_size = 0;
  //считаем точное число токенов, стобы выделить память под массив токенов
  int tokens_count = 0;

  tokens_metrics_size = s21_strlen(format);
  //в отдельную функцию
  tokens_metrics = TokenIndicesAndType_t_create_array(tokens_metrics_size);

  if (!tokens_metrics)
    exit(1);
  // end в отдельную функцию

  preparse_string_to_lexemmes(tokens_metrics, &tokens_count, format);
  // print_lexemmes_throught_format_string(tokens_metrics, tokens_count,
  // format);

  generated_tokens = FormattedToken_t_create_array(tokens_count);

  if (!generated_tokens)
    exit(1);

  for (int i = 0; i < tokens_count; i++) {
    switch (tokens_metrics[i].token_type) {
    case text:
      generated_tokens[i].token_type = text;
      generated_tokens[i].token_position = i + 1;
      build_text_token(format, &tokens_metrics[i], &generated_tokens[i]);
      break;
    case integer:
      generated_tokens[i].token_type = integer;
      generated_tokens[i].token_position = i + 1;
      build_specified_token(format, &tokens_metrics[i], &generated_tokens[i]);
      break;
    case string:
      generated_tokens[i].token_type = string;
      generated_tokens[i].token_position = i + 1;
      build_specified_token(format, &tokens_metrics[i], &generated_tokens[i]);
      break;
    }
  }

  //print_generated_tokens(generated_tokens, tokens_count);

  TokenIndicesAndType_t_delete_array(tokens_metrics);
  tokens_metrics=NULL;
  FormattedToken_t_delete_array(generated_tokens);
  generated_tokens=NULL;

  return 0;
}