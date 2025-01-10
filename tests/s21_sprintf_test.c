#include "s21_check_string.h"

//  char *str = "there is no power as no knowledge";
//  int c = '[';
START_TEST(test_s21_sprintf_1) {
  char *str = "there is no power as no knowledge";
  int c = '[';
  char *s21_strchr_result = NULL;
  char *strchr_result = NULL;

  s21_strchr_result = s21_strchr(str, c);
  strchr_result = strchr(str, c);

  ck_assert_ptr_eq(s21_strchr_result, strchr_result);
}
END_TEST
//

//коды вне символов строки дают сегу
Suite *s21_sprintf_suite(void) {
  Suite *suite;
  TCase *tc_s21_sprintf;

  suite = suite_create("s21_sprintf");

  tc_s21_sprintf = tcase_create("S21_sprintf");

  //  char *str = "Hello world";
  //  int c = 'w';
  tcase_add_test(tc_s21_sprintf, test_s21_sprintf_1);
  suite_add_tcase(suite, tc_s21_sprintf);

  return suite;
}