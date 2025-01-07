#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = S21_NULL;
  char *string_1 = S21_NULL;
  char *string_2 = S21_NULL;
  int length_str2 = 0;

  string_1 = (char *)str1;
  string_2 = (char *)str2;

  length_str2 = (int)s21_strlen(string_2);

  for (int index = 0; index < length_str2 && !result; index++)
    result = s21_strchr(string_1, string_2[index]);

  return result;
}