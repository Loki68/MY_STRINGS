#include "s21_check_string.h"
// TODO
// check all before strchr because segfault it's because NULL

// 1 memchr finished
// 2 memcmp finished
// 3 memcpy finished
// 4 memset finished
// 5 strchr finished
// 6 strlen finished
// 7 strncat finished
// 8 strncmp finished
// 9 strncpy finished
// 10 strpbrk finished
// 11 strrchr finished
// 12 strstr finished
// 13 strcspn finished

// 14 strtok in_progress
// 15 strerror in_progress

// 16 sprintf in_implementation

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
  srunner_add_suite(srunner, s21_strpbrk_suite());
  srunner_add_suite(srunner, s21_strrchr_suite());
  srunner_add_suite(srunner, s21_strstr_suite());
  srunner_add_suite(srunner, s21_strcspn_suite());
  srunner_add_suite(srunner, s21_strtok_suite());
  srunner_add_suite(srunner, s21_strerror_suite());

  srunner_add_suite(srunner, dynamic_memory_helpers_suite());
  srunner_add_suite(srunner, sprint_sscan_parser_suite());
  srunner_add_suite(srunner, s21_sprintf_suite());

  srunner_run_all(srunner, CK_NORMAL);
  number_failed = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}