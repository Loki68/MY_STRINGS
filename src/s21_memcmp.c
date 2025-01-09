#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int result = 0;
  s21_size_t count = 0;
  s21_size_t index = 0;
  char *first_string = S21_NULL;
  char *second_string = S21_NULL;

  count = (s21_size_t)(unsigned int)n;

  first_string = (char *)str1;

  second_string = (char *)str2;

  for (; index < count && first_string[index] == second_string[index] &&
         first_string[index];
       index++)
    ;

  if (count - index)
    result = first_string[index] - second_string[index];

  return result;
}