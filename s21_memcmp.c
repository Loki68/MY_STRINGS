#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int result = 0;
  s21_size_t count = 0;
  s21_size_t index = 0;

  count = (s21_size_t)(unsigned long)n;
  const char *first_string = (const char *)str1;
  const char *second_string = (const char *)str2;

  for (; index < count && first_string[index] == second_string[index]; index++)
    ;

  if (count - index > 1)
    result = first_string[index] - second_string[index];

  return result;
}