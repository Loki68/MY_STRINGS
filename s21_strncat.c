#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t count = 0;
  s21_size_t index = 0;
  s21_size_t cat_index = 0;
  unsigned char character = 0;

  for (; dest[index]; index++)
    ;

  count = (s21_size_t)(unsigned int)n; // because original ubuntu strncat

  for (; cat_index < count && src[cat_index]; cat_index++) {
    character = (unsigned char)src[cat_index];
    dest[index + cat_index] = character;
  }

  dest[index + cat_index] = '\0';

  return dest;
}