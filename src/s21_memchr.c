#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  char *string = S21_NULL;
  char *result = S21_NULL;
  s21_size_t count = 0;
  s21_size_t index = 0;

  unsigned char character = (unsigned char)(unsigned int)c;

  string = (char *)str;

  count = (s21_size_t)(unsigned int)n;

  for (; index < count && string[index] != character; index++)
    ;

  if (index < count)
    result = (string + index);

  return result;
}