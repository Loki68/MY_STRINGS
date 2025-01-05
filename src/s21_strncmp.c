#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int delta = 0;

  for (s21_size_t i = 0; i < n && *str1 == *str2 && *str1 && *str2;
       i++,str1++, str2++)
    ;
    
    delta = *str1 - *str2;

  return delta;
}