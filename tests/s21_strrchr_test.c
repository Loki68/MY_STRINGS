#include "s21_check_string.h"

//  char *str = "Hello world!";
//символ, содержащийся в строке
//  char c = 'w';
START_TEST(test_s21_strrchr_1) {
  char *str = "Hello world!";
  char c = 'w';
  char *s21_strrchr_result = NULL;
  char *strrchr_result = NULL;

  s21_strrchr_result = s21_strrchr(str, c);
  strrchr_result = strrchr(str, c);

  ck_assert_ptr_eq(s21_strrchr_result, strrchr_result);
}
END_TEST

//  char *str = "Hello world!";
//символ, не содержащийся в строке
//  char c = ']';
START_TEST(test_s21_strrchr_2) {
  char *str = "Hello world!";
  char c = ']';
  char *s21_strrchr_result = NULL;
  char *strrchr_result = NULL;

  s21_strrchr_result = s21_strrchr(str, c);
  strrchr_result = strrchr(str, c);

  ck_assert_ptr_eq(s21_strrchr_result, strrchr_result);
}
END_TEST

//  char *str = "Hello world!";
//нулевой символ
//  char c = '\0';
START_TEST(test_s21_strrchr_3) {
  char *str = "Hello world!";
  char c = '\0';
  char *s21_strrchr_result = NULL;
  char *strrchr_result = NULL;

  s21_strrchr_result = s21_strrchr(str, c);
  strrchr_result = strrchr(str, c);

  ck_assert_ptr_eq(s21_strrchr_result, strrchr_result);
}
END_TEST

//  char *str = "bytecode\0why";
//нулевой символ
//  char c = '\0';
START_TEST(test_s21_strrchr_4) {
  char *str = "bytecode\0why";
  char c = '\0';
  char *s21_strrchr_result = NULL;
  char *strrchr_result = NULL;

  s21_strrchr_result = s21_strrchr(str, c);
  strrchr_result = strrchr(str, c);

  ck_assert_ptr_eq(s21_strrchr_result, strrchr_result);
}
END_TEST

// const string or null ptr => sega
//выход за границы => sega
Suite *s21_strrchr_suite(void) {
  Suite *suite;
  TCase *tc_s21_strrchr;

  suite = suite_create("s21_strrchr");

  tc_s21_strrchr = tcase_create("S21_strrchr");

  //  char *str = "Hello world!";
  //символ, содержащийся в строке
  //  char c = 'w';
  tcase_add_test(tc_s21_strrchr, test_s21_strrchr_1);
  suite_add_tcase(suite, tc_s21_strrchr);

  //  char *str = "Hello world!";
  //символ, не содержащийся в строке
  //  char c = ']';
  tcase_add_test(tc_s21_strrchr, test_s21_strrchr_2);
  suite_add_tcase(suite, tc_s21_strrchr);

  //  char *str = "Hello world!";
  //нулевой символ
  //  char c = '\0';
  tcase_add_test(tc_s21_strrchr, test_s21_strrchr_3);
  suite_add_tcase(suite, tc_s21_strrchr);

  //  char *str = "bytecode\0why";
  //нулевой символ
  //  char c = '\0';
  tcase_add_test(tc_s21_strrchr, test_s21_strrchr_4);
  suite_add_tcase(suite, tc_s21_strrchr);

  return suite;
}