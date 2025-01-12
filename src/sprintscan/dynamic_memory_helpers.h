#ifndef DYNAMIC_MEMORY_HELPERS_H_INCLUDED
#define DYNAMIC_MEMORY_HELPERS_H_INCLUDED

#include <stdlib.h>

typedef enum type { text, integer, string } TokenType_t;

typedef struct token_indices_and_type {
  int token_begin_index;
  int token_end_index;
  TokenType_t token_type;
} TokenIndicesAndType_t;

// sprintf flags
typedef enum flags_enumeration {
  minus = '-',
  plus = '+',
  space = ' ',
  sharp = '#',
  zero = '0'
} FlagsEnumeration_t;

typedef struct flags {
  int no_flags;
  int minus;
  int plus;
  int space;
  int sharp;
  int zero;
  int not_flags; //днем
} Flags_t;

typedef enum accuracy_or_width_type {
  no_width_or_accuracy,
  number,
  star = '*'
} AccuracyOrWidthType_t;

typedef struct accuracy_width {
  int no_width_or_accuracy;
  int number;
  int star;
  int not_width_or_accuracy; //днем
} AccuracyOrWidth_t;

typedef enum length {
  //мб и нинад
  no_length,
  short_int_or_unsigned_short = 'h',
  long_int = 'l',
  long_float = 'L'
} Length_t;

typedef struct length_format {
  int no_length;
  int short_int_or_unsigned_short;
  int long_int;
  int long_float;
  int not_length;
} LengthFormat_t;

typedef struct token_accuracy_or_width {
  AccuracyOrWidth_t accuracy_or_width_flags;
  char accuracy_or_width_value[64];
} TokenAccuracyOrWidth_t;

typedef struct format_for_token {
  Flags_t token_flags;
  TokenAccuracyOrWidth_t token_width;
  TokenAccuracyOrWidth_t token_accuracy;
  LengthFormat_t token_length;
  // int is_not_format; //чтобы считать, что у нас текст
} FormatForToken_t;

typedef struct formatted_token {
  char token_string[256]; //позже изменить эту дичь на маллок
  char token_value[256]; //позже изменить эту дичь на маллок
  FormatForToken_t token_format;
  TokenType_t token_type;
  int token_size;
  int token_position;
} FormattedToken_t;

TokenIndicesAndType_t *
TokenIndicesAndType_t_create_array(unsigned long elements_count);
void TokenIndicesAndType_t_delete_array(TokenIndicesAndType_t *tokens_metrics);

FormattedToken_t *FormattedToken_t_create_array(unsigned long elements_count);
void FormattedToken_t_delete_array(FormattedToken_t *formated_token);

#endif