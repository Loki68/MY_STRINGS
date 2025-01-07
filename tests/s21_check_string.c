#include "s21_check_string.h"
// TODO
// check all before strchr because segfault it's because NULL
// memchr good
// memcmp good
// memcpy good
// memset check overflow count
// strchr good
// strlen good
// strncat good
// strncmp good
// strncpy good
// strpbrk good
int main(void) {
  int number_failed = 0;
  SRunner *srunner = NULL;

  srunner = srunner_create(s21_memchr_suite());
  srunner_add_suite(srunner, s21_memcmp_suite());
  srunner_add_suite(srunner, s21_memcpy_suite());
  srunner_add_suite(srunner, s21_memset_suite());
  srunner_add_suite(srunner, s21_strchr_suite());
  srunner_add_suite(srunner, s21_strncat_suite());
  srunner_add_suite(srunner, s21_strlen_suite());
  srunner_add_suite(srunner, s21_strncmp_suite());
  srunner_add_suite(srunner, s21_strncpy_suite());
  srunner_add_suite(srunner,
                    s21_strpbrk_suite()); //собирать с -Wdiscarded-qualifiers
                                          //или удалить пустые тесты

  srunner_run_all(srunner, CK_NORMAL);
  number_failed = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}