#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t dest_length = 0;
  s21_size_t src_length = 0;
  s21_size_t count = 0;
  s21_size_t index = 0;

  count = n;

  dest_length = s21_strlen(dest);
  src_length = s21_strlen(src);

  for (; index < count; dest[index] = src[index], index++)
    ;

  if (count >= src_length)
    for (; index < dest_length; dest[index] = '\0', index++)
      ;

  return dest;
}