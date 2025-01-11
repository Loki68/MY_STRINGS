#include "s21_string.h"
#include <stdlib.h>

char *s21_strtok(char *str, const char *delim) {
  static char *buffer = S21_NULL;
  if (str != S21_NULL) {
    buffer = str;
  }
  char *out = S21_NULL;
  int lenOfToken = 0;
  int letters = 0;
  int plusDelimer = 0;
  out = malloc(sizeof(*buffer));
  s21_memset(out, '\0', sizeof(*buffer));
  for (int i = 0; buffer[i] != '\0'; i++) {
    int counter = 0;
    for (int j = 0; delim[j] != '\0'; j++) {
      if (buffer[i] == '\0') {
        break;
      }
      if (delim[j] != buffer[i]) {
        counter += 1;
      }
    }
    if (counter == (int)s21_strlen(delim)) {
      lenOfToken += 1;
      letters += 1;
    } else {
      if (lenOfToken != 0) {
        break;
      }
      buffer[i] = '\0';
      plusDelimer += 1;
    }
  }
  buffer += plusDelimer;
  if (lenOfToken != 0) {
    for (int i = 0; i != lenOfToken; i++) {
      out[i] = buffer[i];
    }
    if (plusDelimer == 0) {
      buffer[letters] = '\0';
      buffer++;
    }
  } else if (lenOfToken <= 0 || buffer == S21_NULL) {
    out = S21_NULL;
  }
  buffer += letters;
  return out;
}