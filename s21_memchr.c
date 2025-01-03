#include "s21_string.h"

//не совсем как memchr
//скорее всего потому что ты скопировал идею strchr, а это просто массивы байт,
//без нулей
void *s21_memchr(const void *str, int c, s21_size_t n) {
  char *string = S21_NULL;
  s21_size_t count = 0;
  s21_size_t index = 0;

  const unsigned char character = (const unsigned char)c;

  string = (char *)str;
  count = (s21_size_t)(unsigned int)n;

  for (; index < count && *string != character && *string;
       index++, string += index)
    ;

  return string;
}