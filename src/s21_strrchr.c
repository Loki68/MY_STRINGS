#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  int length_str = s21_strlen(str);
  char* result;
  for (int i = 0; i < length_str; i++) {
    if (str[i] == c) {
      result = (char*)(str+i);
    }
  }
  if (result) {
    return result;
  } else {
    return S21_NULL;
  }
}
