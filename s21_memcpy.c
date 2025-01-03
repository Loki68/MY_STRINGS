#include "s21_string.h"

// works fine with const char ptr-segfalt as should be
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  // here n can be below zero
  s21_size_t count = (s21_size_t)n;
  char *destination = (char *)dest;
  const char *source = (const char *)src;
  s21_size_t index = 0;

  for (; index < count; destination[index] = source[index], index++)
    ;

  return destination;
}