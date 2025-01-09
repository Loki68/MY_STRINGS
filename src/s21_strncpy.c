#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  int dest_length = 0;
  int src_length = 0;
  int count = 0;
  int index = 0;

  count = n;

  dest_length = (int)s21_strlen(dest);
  src_length = (int)s21_strlen(src);

  for (; index < count; dest[index] = src[index], index++)
    ;

  if (count >= src_length)
    for (; index < dest_length; dest[index] = '\0', index++)
      ;

  return dest;
}