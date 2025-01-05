#include "s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  char *string = (char *)str;
  const unsigned char character = (const unsigned char)c;
  s21_size_t count = n;
  s21_size_t index = 0;

  for (; index < count; string[index] = character, index++)
    ;

  return string;
}