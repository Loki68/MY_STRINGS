#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *string = S21_NULL;

  const unsigned char character = (const unsigned char)c;
  string = (char *)str;

  for (; *string != character; string++)
    ;

  return string;
}