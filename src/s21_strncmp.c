#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int delta = 0;
  s21_size_t index = 0;
  s21_size_t count = 0;

  count = n;

  for (; index < count && str1[index] == str2[index] && str1[index]; index++)
    ;
  if (index == count)
    index--;

  delta = str1[index] - str2[index];

  return delta;
}