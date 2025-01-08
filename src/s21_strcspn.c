#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t result = 0;
  s21_size_t temp_result = 0;
  char *current_character_ptr = S21_NULL;

  result = s21_strlen(str1);

  for (int index = 0; str2[index]; index++) {
    current_character_ptr = s21_strchr(str1, str2[index]);

    if (current_character_ptr) {
      temp_result = current_character_ptr - str1;

      if (result > temp_result)
        result = temp_result;
    }
  }

  return result;
}