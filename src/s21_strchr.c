#include "s21_string.h"

// returns S21_NULL
char *s21_strchr(const char *str, int c) {
  char *string = S21_NULL;

  const unsigned char character = (const unsigned char)c;
  string = (char *)str;

  for (; *string != character && *string; string++)
    ;

  if (*string != character)
    string = S21_NULL;

  return string;
}