#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {

  int length_haystack = s21_strlen(haystack);
  int length_needle = s21_strlen(needle);
  if (length_needle == 0) {
    return (char *)haystack;
  }
  for (int i = 0; i < length_haystack; i++) {
    if (haystack[i] == needle[0]) {
      int j = 1;
      int flag = 0;
      while (j < length_needle && flag == 0) {
        if (haystack[i + j] == needle[j]) {
          j++;
        } else {
          flag = 1;
        }
      }
      if (j == length_needle) {
        return (char *)(haystack + i);
      }
    }
  }
  return S21_NULL;
}