#include "s21_check_string.h"

//  char dest_s21[] = "Hello world!";
//  char dest[] = "Hello world!";
//  char* src = "KHA..An!!11";
//  size_t n = 12;
START_TEST(test_s21_strncpy_1) {
  char dest_s21[] = "Hello world!";
  char dest[] = "Hello world!";
  char *src = "KHA..An!!11";
  size_t n = 12;
  char *s21_strncpy_result = NULL;
  char *strncpy_result = NULL;

  s21_strncpy_result = s21_strncpy(dest_s21, src, n);
  strncpy_result = strncpy(dest, src, n);

  ck_assert_str_eq(s21_strncpy_result, strncpy_result);
}
END_TEST

//  char dest_s21[] = "there is no power as no knowledge";
//  char dest[] = "there is no power as no knowledge";
//  char* src = "Hello";
//  size_t n = 10;
START_TEST(test_s21_strncpy_2) {
  char dest_s21[] = "there is no power as no knowledge";
  char dest[] = "there is no power as no knowledge";
  char *src = "Hello";
  size_t n = 10;
  char *s21_strncpy_result = NULL;
  char *strncpy_result = NULL;

  s21_strncpy_result = s21_strncpy(dest_s21, src, n);
  strncpy_result = strncpy(dest, src, n);

  ck_assert_str_eq(s21_strncpy_result, strncpy_result);
}
END_TEST

//  char dest_s21[] = "there is no power as no knowledge";
//  char dest[] = "there is no power as no knowledge";
//  char* src = "Hello";
//  size_t n = 0;
START_TEST(test_s21_strncpy_3) {
  char dest_s21[] = "there is no power as no knowledge";
  char dest[] = "there is no power as no knowledge";
  char *src = "Hello";
  size_t n = 0;

  char *s21_strncpy_result = NULL;
  char *strncpy_result = NULL;

  s21_strncpy_result = s21_strncpy(dest_s21, src, n);
  strncpy_result = strncpy(dest, src, n);

  ck_assert_str_eq(s21_strncpy_result, strncpy_result);
}
END_TEST

//  char dest_s21[] = "there is no power as no knowledge";
//  char dest[] = "there is no power as no knowledge";
//  char* src = "";
//  size_t n = 10;
START_TEST(test_s21_strncpy_4) {
  char dest_s21[] = "there is no power as no knowledge";
  char dest[] = "there is no power as no knowledge";
  char *src = "";
  size_t n = 10;

  char *s21_strncpy_result = NULL;
  char *strncpy_result = NULL;

  s21_strncpy_result = s21_strncpy(dest_s21, src, n);
  strncpy_result = strncpy(dest, src, n);

  ck_assert_str_eq(s21_strncpy_result, strncpy_result);
}
END_TEST

// const string or null ptr => sega
//выход за границы => sega
Suite *s21_strncpy_suite(void) {
  Suite *suite;
  TCase *tc_s21_strncpy;

  suite = suite_create("s21_strncpy");

  tc_s21_strncpy = tcase_create("S21_strncpy");

  //  char dest_s21[] = "Hello world!";
  //  char dest[] = "Hello world!";
  //  char* src = "KHA..An!!11";
  //  size_t n = 12;
  tcase_add_test(tc_s21_strncpy, test_s21_strncpy_1);
  suite_add_tcase(suite, tc_s21_strncpy);

  //  char dest_s21[] = "there is no power as no knowledge";
  //  char dest[] = "there is no power as no knowledge";
  //  char* src = "Hello";
  //  size_t n = 10;
  tcase_add_test(tc_s21_strncpy, test_s21_strncpy_2);
  suite_add_tcase(suite, tc_s21_strncpy);

  //  char dest_s21[] = "there is no power as no knowledge";
  //  char dest[] = "there is no power as no knowledge";
  //  char* src = "Hello";
  //  size_t n = 0;
  tcase_add_test(tc_s21_strncpy, test_s21_strncpy_3);
  suite_add_tcase(suite, tc_s21_strncpy);

  //  char dest_s21[] = "there is no power as no knowledge";
  //  char dest[] = "there is no power as no knowledge";
  //  char* src = "";
  //  size_t n = 10;
  tcase_add_test(tc_s21_strncpy, test_s21_strncpy_4);
  suite_add_tcase(suite, tc_s21_strncpy);

  return suite;
}