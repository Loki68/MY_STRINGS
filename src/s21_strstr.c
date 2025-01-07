#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {

  char *result = S21_NULL;
  char *dest = S21_NULL;
  char *src = S21_NULL;
  s21_size_t length_needle = 0;

  dest = (char *)haystack;
  src = (char *)needle;
  length_needle = s21_strlen(src);

  if (length_needle) {
    for (long index = 0; dest[index] && !result; index++)
      if (dest[index] == src[0])
        if (!s21_strncmp(&dest[index], src, length_needle))
          result = &dest[index];
  } else
    result = dest;

  return result;
}