#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {

  char *result = S21_NULL;
  s21_size_t length_needle = 0;

  length_needle = s21_strlen(needle);

  if (length_needle) {
    for (s21_size_t index = 0; haystack[index] && !result; index++)
      if (haystack[index] == needle[0])
        if (!s21_strncmp(&haystack[index], needle, length_needle))
          result = &haystack[index];
  } else
    result = haystack;

  return result;
}