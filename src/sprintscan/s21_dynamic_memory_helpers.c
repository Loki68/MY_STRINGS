#include "s21_dynamic_memory_helpers.h"

FormattedToken_t *FormattedToken_t_create_array(unsigned long elements_count) {
  FormattedToken_t *formated_token = NULL;

  if (elements_count)
    formated_token =
        (FormattedToken_t *)calloc(elements_count, sizeof(FormattedToken_t));

  return formated_token;
}

void FormattedToken_t_delete_array(FormattedToken_t *formated_token) {
  free(formated_token);
}