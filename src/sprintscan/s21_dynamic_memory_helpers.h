#ifndef S21_DYNAMIC_MEMORY_HELPERS_H_INCLUDED
#define S21_DYNAMIC_MEMORY_HELPERS_H_INCLUDED

#include <stdlib.h>

typedef enum type {
  no_type,
  text,
  integer,
  real,
  string,
  single_character
} TokenType_t;

typedef enum spec_type {
  no_spec,
  c = 'c',
  d = 'd',
  f = 'f',
  s = 's',
  u = 'u',
  g = 'g',
  G = 'G',
  e = 'e',
  E = 'E',
  x = 'x',
  X = 'X',
  o = 'o',
  p = 'p'
} SpecType_t;

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
  int flags_length; 
} Flags_t;

typedef enum accuracy_or_width_type {
  no_width_or_accuracy,
  number,
  star = '*'
} AccuracyOrWidthType_t;

typedef struct format_string_data {
  int data_start_index;
  int data_length;
} FormatStringData_t;

typedef enum length {
  no_length,
  short_or_unsigned_short_int_length = 'h',
  long_int_length = 'l',
  long_double_length = 'L'
} Length_t;

typedef struct length_format {
  FormatStringData_t length_data;
  Length_t length_type;
} LengthFormat_t;

typedef struct token_accuracy_or_width {
  AccuracyOrWidthType_t value_type;
  FormatStringData_t accuracy_or_width_data;
} TokenAccuracyOrWidth_t;

typedef struct spec_format {
  SpecType_t type;
  FormatStringData_t spec_format_data;
} SpecFormat_t;

typedef struct formatted_token {
  FormatStringData_t token_format_string_data;
  FormatStringData_t token_value_string_data;
  Flags_t token_flags;
  TokenAccuracyOrWidth_t token_width;
  TokenAccuracyOrWidth_t token_accuracy;
  LengthFormat_t token_length;
  SpecFormat_t token_spec;
  char *format_string;
  TokenType_t token_type;
  int is_initialized;
} FormattedToken_t;

FormattedToken_t *FormattedToken_t_create_array(unsigned long elements_count);
void FormattedToken_t_delete_array(FormattedToken_t *formated_token);
#endif