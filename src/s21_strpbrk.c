#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = S21_NULL;
  int length_str2 = 0;

  length_str2 = s21_strlen(str2);

  for (int i = 0; i < length_str2 && !result; i++)
    result = s21_strchr(str1, str2[i]);

  return result;
}