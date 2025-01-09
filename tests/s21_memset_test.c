#include "s21_check_string.h"

//  char str_s21[] = "Hello world!";
//  char str[] = "Hello world!";
//  int c = 'w';
//  size_t n = 10;
START_TEST(test_s21_memset_1) {
  char str_s21[] = "Hello world!";
  char str[] = "Hello world!";
  int c = 'w';
  size_t n = 10;
  char *s21_memset_result = NULL;
  char *memset_result = NULL;

  s21_memset_result = (char *)s21_memset(str_s21, c, n);
  memset_result = (char *)memset(str, c, n);

  ck_assert_str_eq(s21_memset_result, memset_result);
}
END_TEST

//  char str_s21[] = "there is no power as no knowledge";
//  char str[] = "there is no power as no knowledge";
//  int c = 'w';
//  size_t n = 10;
START_TEST(test_s21_memset_2) {
  char str_s21[] = "there is no power as no knowledge";
  char str[] = "there is no power as no knowledge";
  int c = 'w';
  size_t n = 10;
  char *s21_memset_result = NULL;
  char *memset_result = NULL;

  s21_memset_result = (char *)s21_memset(str_s21, c, n);
  memset_result = (char *)memset(str, c, n);

  ck_assert_str_eq(s21_memset_result, memset_result);
}
END_TEST

//  char str_s21[] = "Hello world!";
//  char str[] = "Hello world!";
//  int c = ']';
//  size_t n = 10;
START_TEST(test_s21_memset_3) {
  char str_s21[] = "Hello world!";
  char str[] = "Hello world!";
  int c = ']';
  size_t n = 10;
  char *s21_memset_result = NULL;
  char *memset_result = NULL;

  s21_memset_result = (char *)s21_memset(str_s21, c, n);
  memset_result = (char *)memset(str, c, n);

  ck_assert_str_eq(s21_memset_result, memset_result);
}
END_TEST

//  char str_s21[] = "there is no power as no knowledge";
//  char str[] = "there is no power as no knowledge";
//  int c = ']';
//  size_t n = 10;
START_TEST(test_s21_memset_4) {
  char str_s21[] = "there is no power as no knowledge";
  char str[] = "there is no power as no knowledge";
  int c = ']';
  size_t n = 10;
  char *s21_memset_result = NULL;
  char *memset_result = NULL;

  s21_memset_result = (char *)s21_memset(str_s21, c, n);
  memset_result = (char *)memset(str, c, n);

  ck_assert_str_eq(s21_memset_result, memset_result);
}
END_TEST

//  char str_s21[] = "Hello world!";
//  char str[] = "Hello world!";
//  int c = '\0';
//  size_t n = 10;
START_TEST(test_s21_memset_5) {
  char str_s21[] = "Hello world!";
  char str[] = "Hello world!";
  int c = '\0';
  size_t n = 10;
  char *s21_memset_result = NULL;
  char *memset_result = NULL;

  s21_memset_result = (char *)s21_memset(str_s21, c, n);
  memset_result = (char *)memset(str, c, n);

  ck_assert_str_eq(s21_memset_result, memset_result);
}
END_TEST

//  char str_s21[] = "there is no power as no knowledge";
//  char str[] = "there is no power as no knowledge";
//  int c = '\0';
//  size_t n = 10;
START_TEST(test_s21_memset_6) {
  char str_s21[] = "there is no power as no knowledge";
  char str[] = "there is no power as no knowledge";
  int c = '\0';
  size_t n = 10;
  char *s21_memset_result = NULL;
  char *memset_result = NULL;

  s21_memset_result = (char *)s21_memset(str_s21, c, n);
  memset_result = (char *)memset(str, c, n);

  ck_assert_str_eq(s21_memset_result, memset_result);
}
END_TEST

//  char str_s21[] = "Hello world!";
//  char str[] = "Hello world!";
//  int c = -7;
//  size_t n = 10;
START_TEST(test_s21_memset_7) {
  char str_s21[] = "Hello world!";
  char str[] = "Hello world!";
  int c = -7;
  size_t n = 10;
  char *s21_memset_result = NULL;
  char *memset_result = NULL;

  s21_memset_result = (char *)s21_memset(str_s21, c, n);
  memset_result = (char *)memset(str, c, n);

  ck_assert_str_eq(s21_memset_result, memset_result);
}
END_TEST

//  char str_s21[] = "there is no power as no knowledge";
//  char str[] = "there is no power as no knowledge";
//  int c = -7;
//  size_t n = 10;
START_TEST(test_s21_memset_8) {
  char str_s21[] = "there is no power as no knowledge";
  char str[] = "there is no power as no knowledge";
  int c = -7;
  size_t n = 10;
  char *s21_memset_result = NULL;
  char *memset_result = NULL;

  s21_memset_result = (char *)s21_memset(str_s21, c, n);
  memset_result = (char *)memset(str, c, n);

  ck_assert_str_eq(s21_memset_result, memset_result);
}
END_TEST

// //нулевое количество символов выдает ошибку:
// // error: ‘memset’ used with constant zero length parameter; this could be
// due
// // to transposed parameters [-Werror=memset-transposed-args]
// //  char str_s21[] = "Hello world!";
// //  char str[] = "Hello world!";
// //  int c = -7;
// //  size_t n = 0;
// START_TEST(test_s21_memset_9) {
//   char str_s21[] = "Hello world!";
//   char str[] = "Hello world!";
//   int c = -7;
//   size_t n = 0;
//   char *s21_memset_result = NULL;
//   char *memset_result = NULL;

//   s21_memset_result = (char *)s21_memset(str_s21, c, n);
//   memset_result = (char *)memset(str, c, n);

//   ck_assert_str_eq(s21_memset_result, memset_result);
// }
// END_TEST

//отрицательные количества дают сегу
//бОльшие числа, чем есть в строке дают IOT stack smashing
Suite *s21_memset_suite(void) {
  Suite *suite;
  TCase *tc_s21_memset;

  suite = suite_create("s21_memset");

  tc_s21_memset = tcase_create("Memset");

  //  char str_s21[] = "Hello world!";
  //  char str[] = "Hello world!";
  //  int c = 'w';
  //  size_t n = 10;
  tcase_add_test(tc_s21_memset, test_s21_memset_1);
  suite_add_tcase(suite, tc_s21_memset);

  //  char str_s21[] = "there is no power as no knowledge";
  //  char str[] = "there is no power as no knowledge";
  //  int c = 'w';
  //  size_t n = 10;
  tcase_add_test(tc_s21_memset, test_s21_memset_2);
  suite_add_tcase(suite, tc_s21_memset);

  //  char str_s21[] = "Hello world!";
  //  char str[] = "Hello world!";
  //  int c = ']';
  //  size_t n = 10;
  tcase_add_test(tc_s21_memset, test_s21_memset_3);
  suite_add_tcase(suite, tc_s21_memset);

  //  char str_s21[] = "there is no power as no knowledge";
  //  char str[] = "there is no power as no knowledge";
  //  int c = ']';
  //  size_t n = 10;
  tcase_add_test(tc_s21_memset, test_s21_memset_4);
  suite_add_tcase(suite, tc_s21_memset);

  //  char str_s21[] = "Hello world!";
  //  char str[] = "Hello world!";
  //  int c = '\0';
  //  size_t n = 10;
  tcase_add_test(tc_s21_memset, test_s21_memset_5);
  suite_add_tcase(suite, tc_s21_memset);

  //  char str_s21[] = "there is no power as no knowledge";
  //  char str[] = "there is no power as no knowledge";
  //  int c = '\0';
  //  size_t n = 10;
  tcase_add_test(tc_s21_memset, test_s21_memset_6);
  suite_add_tcase(suite, tc_s21_memset);

  //  char str_s21[] = "Hello world!";
  //  char str[] = "Hello world!";
  //  int c = -7;
  //  size_t n = 10;
  tcase_add_test(tc_s21_memset, test_s21_memset_7);
  suite_add_tcase(suite, tc_s21_memset);

  //  char str_s21[] = "there is no power as no knowledge";
  //  char str[] = "there is no power as no knowledge";
  //  int c = -7;
  //  size_t n = 10;
  tcase_add_test(tc_s21_memset, test_s21_memset_8);
  suite_add_tcase(suite, tc_s21_memset);

  // //нулевое количество символов выдает ошибку:
  // //error: ‘memset’ used with constant zero length parameter; this could be
  // due to transposed parameters [-Werror=memset-transposed-args]
  // //  char str_s21[] = "Hello world!";
  // //  char str[] = "Hello world!";
  // //  int c = -7;
  // //  size_t n = 0;
  //   tcase_add_test(tc_s21_memset, test_s21_memset_9);
  //   suite_add_tcase(suite, tc_s21_memset);

  return suite;
}