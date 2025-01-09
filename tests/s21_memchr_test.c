#include "s21_check_string.h"

//  char* str = "Hello world!";
//  char c = 'w';
//  size_t n = 10;
START_TEST(test_s21_memchr_1) {
  char *str = "Hello world!";
  char c = 'w';
  size_t n = 10;
  char *str_ptr = NULL;
  char *s21_str_ptr = NULL;

  str_ptr = memchr(str, c, n);
  s21_str_ptr = s21_memchr(str, c, n);

  ck_assert_ptr_eq(str_ptr, s21_str_ptr);
}
END_TEST

//  char* str = "Hello world!";
//  char c = ']';
//  size_t n = 10;
START_TEST(test_s21_memchr_2) {
  char *str = "Hello world!";
  char c = ']';
  size_t n = 10;
  char *str_ptr = NULL;
  char *s21_str_ptr = NULL;

  str_ptr = memchr(str, c, n);
  s21_str_ptr = s21_memchr(str, c, n);

  ck_assert_ptr_eq(str_ptr, s21_str_ptr);
}
END_TEST

//  char* str = "Hello world!";
//  char c = '\0';
//  size_t n = 10;
START_TEST(test_s21_memchr_3) {
  char *str = "Hello world!";
  char c = '\0';
  size_t n = 10;
  char *str_ptr = NULL;
  char *s21_str_ptr = NULL;

  str_ptr = memchr(str, c, n);
  s21_str_ptr = s21_memchr(str, c, n);

  ck_assert_ptr_eq(str_ptr, s21_str_ptr);
}
END_TEST

//  char* str = "Hello world!";
//  char c = 'w';
//  size_t n = 50;
START_TEST(test_s21_memchr_4) {
  char *str = "Hello world!";
  char c = 'w';
  size_t n = 50;
  char *str_ptr = NULL;
  char *s21_str_ptr = NULL;

  str_ptr = memchr(str, c, n);
  s21_str_ptr = s21_memchr(str, c, n);

  ck_assert_ptr_eq(str_ptr, s21_str_ptr);
}
END_TEST

//  char* str = "Hello world!";
//  char c = ']';
//  size_t n = 50;
START_TEST(test_s21_memchr_5) {
  char *str = "Hello world!";
  char c = ']';
  size_t n = 50;
  char *str_ptr = NULL;
  char *s21_str_ptr = NULL;

  str_ptr = memchr(str, c, n);
  s21_str_ptr = s21_memchr(str, c, n);

  ck_assert_ptr_eq(str_ptr, s21_str_ptr);
}
END_TEST

//  char* str = "Hello world!";
//  char c = '\0';
//  size_t n = 50;
START_TEST(test_s21_memchr_6) {
  char *str = "Hello world!";
  char c = '\0';
  size_t n = 50;
  char *str_ptr = NULL;
  char *s21_str_ptr = NULL;

  str_ptr = memchr(str, c, n);
  s21_str_ptr = s21_memchr(str, c, n);

  ck_assert_ptr_eq(str_ptr, s21_str_ptr);
}
END_TEST

//  char* str = "Hello world!";
//  char c = 'w';
//  size_t n = -5;
START_TEST(test_s21_memchr_7) {
  char *str = "Hello world!";
  char c = 'w';
  size_t n = -5;
  char *str_ptr = NULL;
  char *s21_str_ptr = NULL;

  str_ptr = memchr(str, c, n);
  s21_str_ptr = s21_memchr(str, c, n);

  ck_assert_ptr_eq(str_ptr, s21_str_ptr);
}
END_TEST

//  char* str = "Hello world!";
//  char c = ']';
//  size_t n = -5;
START_TEST(test_s21_memchr_8) {
  char *str = "Hello world!";
  char c = ']';
  size_t n = -5;
  char *str_ptr = NULL;
  char *s21_str_ptr = NULL;

  str_ptr = memchr(str, c, n);
  s21_str_ptr = s21_memchr(str, c, n);

  ck_assert_ptr_eq(str_ptr, s21_str_ptr);
}
END_TEST

//  char* str = "Hello world!";
//  char c = '\0';
//  size_t n = -5;
START_TEST(test_s21_memchr_9) {
  char *str = "Hello world!";
  char c = '\0';
  size_t n = -5;
  char *str_ptr = NULL;
  char *s21_str_ptr = NULL;

  str_ptr = memchr(str, c, n);
  s21_str_ptr = s21_memchr(str, c, n);

  ck_assert_ptr_eq(str_ptr, s21_str_ptr);
}
END_TEST

//  char* str = "Hello world!";
//  char c = 'w';
//  size_t n = 0;
START_TEST(test_s21_memchr_10) {
  char *str = "Hello world!";
  char c = 'w';
  size_t n = 0;
  char *str_ptr = NULL;
  char *s21_str_ptr = NULL;

  str_ptr = memchr(str, c, n);
  s21_str_ptr = s21_memchr(str, c, n);

  ck_assert_ptr_eq(str_ptr, s21_str_ptr);
}
END_TEST

//  char* str = "Hello world!";
//  char c = ']';
//  size_t n = 0;
START_TEST(test_s21_memchr_11) {
  char *str = "Hello world!";
  char c = ']';
  size_t n = 0;
  char *str_ptr = NULL;
  char *s21_str_ptr = NULL;

  str_ptr = memchr(str, c, n);
  s21_str_ptr = s21_memchr(str, c, n);

  ck_assert_ptr_eq(str_ptr, s21_str_ptr);
}
END_TEST

//  char* str = "Hello world!";
//  char c = '\0';
//  size_t n = 0;
START_TEST(test_s21_memchr_12) {
  char *str = "Hello world!";
  char c = '\0';
  size_t n = 0;
  char *str_ptr = NULL;
  char *s21_str_ptr = NULL;

  str_ptr = memchr(str, c, n);
  s21_str_ptr = s21_memchr(str, c, n);

  ck_assert_ptr_eq(str_ptr, s21_str_ptr);
}
END_TEST
//

// n < 0 || &&c<0 => sega
Suite *s21_memchr_suite(void) {
  Suite *suite;
  TCase *tc_s21_memchr;

  suite = suite_create("s21_memchr");

  tc_s21_memchr = tcase_create("S21_memchr");

  //  char* str = "Hello world!";
  //  char c = 'w';
  //  size_t n = 10;
  tcase_add_test(tc_s21_memchr, test_s21_memchr_1);
  suite_add_tcase(suite, tc_s21_memchr);

  //  char* str = "Hello world!";
  //  char c = ']';
  //  size_t n = 10;
  tcase_add_test(tc_s21_memchr, test_s21_memchr_2);
  suite_add_tcase(suite, tc_s21_memchr);

  //  char* str = "Hello world!";
  //  char c = '\0';
  //  size_t n = 10;
  tcase_add_test(tc_s21_memchr, test_s21_memchr_3);
  suite_add_tcase(suite, tc_s21_memchr);

  //  char* str = "Hello world!";
  //  char c = 'w';
  //  size_t n = 50;
  tcase_add_test(tc_s21_memchr, test_s21_memchr_4);
  suite_add_tcase(suite, tc_s21_memchr);

  //  char* str = "Hello world!";
  //  char c = ']';
  //  size_t n = 50;
  tcase_add_test(tc_s21_memchr, test_s21_memchr_5);
  suite_add_tcase(suite, tc_s21_memchr);

  //  char* str = "Hello world!";
  //  char c = '\0';
  //  size_t n = 50;
  tcase_add_test(tc_s21_memchr, test_s21_memchr_6);
  suite_add_tcase(suite, tc_s21_memchr);

  //  char* str = "Hello world!";
  //  char c = 'w';
  //  size_t n = -5;
  tcase_add_test(tc_s21_memchr, test_s21_memchr_7);
  suite_add_tcase(suite, tc_s21_memchr);

  //  char* str = "Hello world!";
  //  char c = ']';
  //  size_t n = -5;
  tcase_add_test(tc_s21_memchr, test_s21_memchr_8);
  suite_add_tcase(suite, tc_s21_memchr);

  //  char* str = "Hello world!";
  //  char c = '\0';
  //  size_t n = -5;
  tcase_add_test(tc_s21_memchr, test_s21_memchr_9);
  suite_add_tcase(suite, tc_s21_memchr);

  //  char* str = "Hello world!";
  //  char c = 'w';
  //  size_t n = 0;
  tcase_add_test(tc_s21_memchr, test_s21_memchr_10);
  suite_add_tcase(suite, tc_s21_memchr);

  //  char* str = "Hello world!";
  //  char c = ']';
  //  size_t n = 0;
  tcase_add_test(tc_s21_memchr, test_s21_memchr_11);
  suite_add_tcase(suite, tc_s21_memchr);

  //  char* str = "Hello world!";
  //  char c = '\0';
  //  size_t n = 0;
  tcase_add_test(tc_s21_memchr, test_s21_memchr_12);
  suite_add_tcase(suite, tc_s21_memchr);

  return suite;
}