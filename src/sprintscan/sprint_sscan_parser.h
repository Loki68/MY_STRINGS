#ifndef SPRINT_SSCAN_PARSER_H_INCLUDED
#define SPRINT_SSCAN_PARSER_H_INCLUDED

#include "dynamic_memory_helpers.h"

typedef enum accuracy_or_with_flag {
  accuracy_flag,
  width_flag
} AccuracyOrWidthFlag_t;

// //позже удалить
// void print_lexemmes_throught_format_string(
//     TokenIndicesAndType_t *tokens_metrics, int tokens_count,
//     const char *format_string);
// //позже удалить
// void print_generated_tokens(FormattedToken_t *tokens, int tokens_count);

void preparse_string_to_lexemmes(TokenIndicesAndType_t *returned_tokens_metrics,
                                 int *returned_tokens_count,
                                 const char *format_sting);

void build_text_token(const char *format_string,
                      TokenIndicesAndType_t *token_metrics,
                      FormattedToken_t *text_token);
void build_specified_token(const char *format_string,
                           TokenIndicesAndType_t *token_metrics,
                           FormattedToken_t *specified_token);
void parse_token_character_to_flag(FormattedToken_t *token,
                                   int *current_start_index);
void parse_token_character_to_accuracy_or_width(
    FormattedToken_t *token, int *current_start_index,
    AccuracyOrWidthFlag_t is_accuracy_or_width);

void init_accuracy_or_width(TokenAccuracyOrWidth_t *token_accuracy_or_width);

int is_a_digit(int character);
int is_a_point(int character);

#endif