#include "s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  char *string = S21_NULL;
  unsigned char character = 0;
  s21_size_t count = 0;
  s21_size_t index = 0;

  string = (char *)str;

  character = (unsigned char)(unsigned int)c;

  count = (s21_size_t)(unsigned int)n;

  for (; index < count; string[index] = character, index++)
    ;

  return string;
}