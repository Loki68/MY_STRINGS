#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *destination = S21_NULL;
  char *source = S21_NULL;
  s21_size_t count = 0;
  s21_size_t index = 0;

  count = n;

  destination = (char *)dest;

  source = (char *)src;

  for (; index < count; destination[index] = source[index], index++)
    ;

  return destination;
}