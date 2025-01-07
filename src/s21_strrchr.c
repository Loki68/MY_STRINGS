#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *result = S21_NULL;
  char *string = S21_NULL; //помогает избежать варнинга что конст снимается
  unsigned char character = (unsigned char)(unsigned int)c;
  long int index = 0;

  string = (char *)str;
  index = (long int)s21_strlen(string);

  for (; index >= 0 && !result; index--)
    if (string[index] == character)
      result = &string[index];

  return result;
}
