#include "s21_check_string.h"

//  char *str = "there is no power as no knowledge";
//  int c = '[';
START_TEST(test_s21_sprintf_1) {}
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