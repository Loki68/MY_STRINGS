#include "s21_check_string.h"

//   char* str1 = "Hello world!";
//   char* str2 = "Hello world!";
//   size_t n = 10;
START_TEST(test_s21_memcmp_1) {
  char *str1 = "Hello world!";
  char *str2 = "Hello world!";
  size_t n = 10;
  int s21_memcmp_result = 0;
  int memcmp_result = 0;

  s21_memcmp_result = s21_memcmp(str1, str2, n);
  memcmp_result = memcmp(str1, str2, n);

  ck_assert_msg(s21_memcmp_result == memcmp_result,
                "Значения : %d и %d не совпадают", s21_memcmp_result,
                memcmp_result);
}
END_TEST

//   char* str1 = "Hello world!";
//   char* str2 = "Hello world!";
//   size_t n = 50;
START_TEST(test_s21_memcmp_2) {
  char *str1 = "Hello world!";
  char *str2 = "Hello world!";
  size_t n = 50;
  int s21_memcmp_result = 0;
  int memcmp_result = 0;

  s21_memcmp_result = s21_memcmp(str1, str2, n);
  memcmp_result = memcmp(str1, str2, n);

  ck_assert_msg(s21_memcmp_result == memcmp_result,
                "Значения : %d и %d не совпадают", s21_memcmp_result,
                memcmp_result);
}
END_TEST

//   char* str1 = "Hello world!";
//   char* str2 = "Hello world!";
//   size_t n = 0;
START_TEST(test_s21_memcmp_3) {
  char *str1 = "Hello world!";
  char *str2 = "Hello world!";
  size_t n = 0;
  int s21_memcmp_result = 0;
  int memcmp_result = 0;

  s21_memcmp_result = s21_memcmp(str1, str2, n);
  memcmp_result = memcmp(str1, str2, n);

  ck_assert_msg(s21_memcmp_result == memcmp_result,
                "Значения : %d и %d не совпадают", s21_memcmp_result,
                memcmp_result);
}
END_TEST

//   char* str1 = "Hello world!";
//   char* str2 = "Hello";
//   size_t n = 10;
START_TEST(test_s21_memcmp_4) {
  char *str1 = "Hello world!";
  char *str2 = "Hello";
  size_t n = 10;
  int s21_memcmp_result = 0;
  int memcmp_result = 0;

  s21_memcmp_result = s21_memcmp(str1, str2, n);
  memcmp_result = memcmp(str1, str2, n);

  ck_assert_msg(s21_memcmp_result == memcmp_result,
                "Значения : %d и %d не совпадают", s21_memcmp_result,
                memcmp_result);
}
END_TEST

//   char* str1 = "Hello world!";
//   char* str2 = "Hello";
//   size_t n = 50;
START_TEST(test_s21_memcmp_5) {
  char *str1 = "Hello world!";
  char *str2 = "Hello";
  size_t n = 50;
  int s21_memcmp_result = 0;
  int memcmp_result = 0;

  s21_memcmp_result = s21_memcmp(str1, str2, n);
  memcmp_result = memcmp(str1, str2, n);

  ck_assert_msg(s21_memcmp_result == memcmp_result,
                "Значения : %d и %d не совпадают", s21_memcmp_result,
                memcmp_result);
}
END_TEST

//   char* str1 = "Hello world!";
//   char* str2 = "Hello";
//   size_t n = strlen(T21_STR_1);
START_TEST(test_s21_memcmp_6) {
  char *str1 = "Hello world!";
  char *str2 = "Hello";
  size_t n = strlen(T21_STR_1);
  int s21_memcmp_result = 0;
  int memcmp_result = 0;

  s21_memcmp_result = s21_memcmp(str1, str2, n);
  memcmp_result = memcmp(str1, str2, n);

  ck_assert_msg(s21_memcmp_result == memcmp_result,
                "Значения : %d и %d не совпадают", s21_memcmp_result,
                memcmp_result);
}
END_TEST

//   char* str1 = "Hello world!";
//   char* str2 = "Hello world!";
//   size_t n = -5;
START_TEST(test_s21_memcmp_7) {
  char *str1 = "Hello world!";
  char *str2 = "Hello world!";
  size_t n = -5;
  int s21_memcmp_result = 0;
  int memcmp_result = 0;

  s21_memcmp_result = s21_memcmp(str1, str2, n);
  memcmp_result = memcmp(str1, str2, n);

  ck_assert_msg(s21_memcmp_result == memcmp_result,
                "Значения : %d и %d не совпадают", s21_memcmp_result,
                memcmp_result);
}
END_TEST

//   char* str1 = "Hello world!";
//   char* str2 = "Hello_world!";
//   size_t n = -5;
START_TEST(test_s21_memcmp_8) {
  char *str1 = "Hello world!";
  char *str2 = "Hello_world!";
  size_t n = -5;
  int s21_memcmp_result = 0;
  int memcmp_result = 0;

  s21_memcmp_result = s21_memcmp(str1, str2, n);
  memcmp_result = memcmp(str1, str2, n);

  ck_assert_msg(s21_memcmp_result == memcmp_result,
                "Значения : %d и %d не совпадают", s21_memcmp_result,
                memcmp_result);
}
END_TEST

//   char* str1 = "Hello";
//   char* str2 = "Hello world!";
//   size_t n = 10;
START_TEST(test_s21_memcmp_9) {
  char *str1 = "Hello";
  char *str2 = "Hello world!";
  size_t n = 10;
  int s21_memcmp_result = 0;
  int memcmp_result = 0;

  s21_memcmp_result = s21_memcmp(str1, str2, n);
  memcmp_result = memcmp(str1, str2, n);

  ck_assert_msg(s21_memcmp_result == memcmp_result,
                "Значения : %d и %d не совпадают", s21_memcmp_result,
                memcmp_result);
}
END_TEST
//

Suite *s21_memcmp_suite(void) {
  Suite *suite;
  TCase *tc_s21_memcmp;

  suite = suite_create("s21_memcmp");

  tc_s21_memcmp = tcase_create("S21_memcmp");

  //   char* str1 = "Hello world!";
  //   char* str2 = "Hello world!";
  //   size_t n = 10;
  tcase_add_test(tc_s21_memcmp, test_s21_memcmp_1);
  suite_add_tcase(suite, tc_s21_memcmp);

  //   char* str1 = "Hello world!";
  //   char* str2 = "Hello world!";
  //   size_t n = 50;
  tcase_add_test(tc_s21_memcmp, test_s21_memcmp_2);
  suite_add_tcase(suite, tc_s21_memcmp);

  //   char* str1 = "Hello world!";
  //   char* str2 = "Hello world!";
  //   size_t n = 0;
  tcase_add_test(tc_s21_memcmp, test_s21_memcmp_3);
  suite_add_tcase(suite, tc_s21_memcmp);

  //   char* str1 = "Hello world!";
  //   char* str2 = "Hello";
  //   size_t n = 10;
  tcase_add_test(tc_s21_memcmp, test_s21_memcmp_4);
  suite_add_tcase(suite, tc_s21_memcmp);

  //   char* str1 = "Hello world!";
  //   char* str2 = "Hello";
  //   size_t n = 50;
  tcase_add_test(tc_s21_memcmp, test_s21_memcmp_5);
  suite_add_tcase(suite, tc_s21_memcmp);

  //   char* str1 = "Hello world!";
  //   char* str2 = "Hello";
  //   size_t n = strlen(T21_STR_1);
  tcase_add_test(tc_s21_memcmp, test_s21_memcmp_6);
  suite_add_tcase(suite, tc_s21_memcmp);

  //   char* str1 = "Hello world!";
  //   char* str2 = "Hello world!";
  //   size_t n = -5;
  tcase_add_test(tc_s21_memcmp, test_s21_memcmp_7);
  suite_add_tcase(suite, tc_s21_memcmp);

  //   char* str1 = "Hello world!";
  //   char* str2 = "Hello_world!";
  //   size_t n = -5;
  tcase_add_test(tc_s21_memcmp, test_s21_memcmp_8);
  suite_add_tcase(suite, tc_s21_memcmp);

  //   char* str1 = "Hello";
  //   char* str2 = "Hello world!";
  //   size_t n = 10;
  tcase_add_test(tc_s21_memcmp, test_s21_memcmp_9);
  suite_add_tcase(suite, tc_s21_memcmp);

  return suite;
}