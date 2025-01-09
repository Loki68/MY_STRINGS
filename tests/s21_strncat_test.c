#include "s21_check_string.h"

void initialize_string(char *dest, const char *dest_filler, int filler_size) {
  strncpy(dest, dest_filler, filler_size);
}

//  char* dest_filler = "there is no power as no knowledge";
//  int dest_size = 50;
//  char dest_s21[dest_size];
//  char dest[dest_size];
//  char* src = "KHA..An!!11";
//  size_t n = 10;
START_TEST(test_s21_strncat_1) {
  char *dest_filler = "there is no power as no knowledge";
  int dest_size = 50;
  char dest_s21[dest_size];
  char dest[dest_size];
  char *src = "KHA..An!!11";
  size_t n = 10;
  char *s21_strncat_result = NULL;
  char *strncat_result = NULL;
  initialize_string(dest_s21, dest_filler, dest_size);
  initialize_string(dest, dest_filler, dest_size);

  s21_strncat_result = s21_strncat(dest_s21, src, n);
  strncat_result = strncat(dest, src, n);

  ck_assert_str_eq(s21_strncat_result, strncat_result);
}
END_TEST

//  char* dest_filler = "there is no power as no knowledge";
//  int dest_size = 50;
//  char dest_s21[dest_size];
//  char dest[dest_size];
//  char* src = "Hello";
//  size_t n = 0;
START_TEST(test_s21_strncat_2) {
  char *dest_filler = "there is no power as no knowledge";
  int dest_size = 50;
  char dest_s21[dest_size];
  char dest[dest_size];
  char *src = "Hello";
  size_t n = 0;
  char *s21_strncat_result = NULL;
  char *strncat_result = NULL;
  initialize_string(dest_s21, dest_filler, dest_size);
  initialize_string(dest, dest_filler, dest_size);

  s21_strncat_result = s21_strncat(dest_s21, src, n);
  strncat_result = strncat(dest, src, n);

  ck_assert_str_eq(s21_strncat_result, strncat_result);
}
END_TEST

//  char* dest_filler = "there is no power as no knowledge";
//  int dest_size = 50;
//  char dest_s21[dest_size];
//  char dest[dest_size];
//  char* src = "Hello";
//  size_t n = 10;
START_TEST(test_s21_strncat_3) {
  char *dest_filler = "there is no power as no knowledge";
  int dest_size = 50;
  char dest_s21[dest_size];
  char dest[dest_size];
  char *src = "Hello";
  size_t n = 10;
  char *s21_strncat_result = NULL;
  char *strncat_result = NULL;
  initialize_string(dest_s21, dest_filler, dest_size);
  initialize_string(dest, dest_filler, dest_size);

  s21_strncat_result = s21_strncat(dest_s21, src, n);
  strncat_result = strncat(dest, src, n);

  ck_assert_str_eq(s21_strncat_result, strncat_result);
}
END_TEST

//  char* dest_filler = "Hello world!";;
//  int dest_size = 50;
//  char dest_s21[dest_size];
//  char dest[dest_size];
//  char* src = "KHA..An!!11";
//  size_t n = 20;
START_TEST(test_s21_strncat_4) {
  char *dest_filler = "Hello world!";
  ;
  int dest_size = 50;
  char dest_s21[dest_size];
  char dest[dest_size];
  char *src = "KHA..An!!11";
  size_t n = 20;
  char *s21_strncat_result = NULL;
  char *strncat_result = NULL;
  initialize_string(dest_s21, dest_filler, dest_size);
  initialize_string(dest, dest_filler, dest_size);

  s21_strncat_result = s21_strncat(dest_s21, src, n);
  strncat_result = strncat(dest, src, n);

  ck_assert_str_eq(s21_strncat_result, strncat_result);
}
END_TEST

// const string or null ptr => sega
Suite *s21_strncat_suite(void) {
  Suite *suite;
  TCase *tc_s21_strncat;

  suite = suite_create("s21_strncat");

  tc_s21_strncat = tcase_create("S21_strncat");

  //  char* dest_filler = "there is no power as no knowledge";
  //  int dest_size = 50;
  //  char dest_s21[dest_size];
  //  char dest[dest_size];
  //  char* src = "KHA..An!!11";
  //  size_t n = 10;
  tcase_add_test(tc_s21_strncat, test_s21_strncat_1);
  suite_add_tcase(suite, tc_s21_strncat);

  //  char* dest_filler = "there is no power as no knowledge";
  //  int dest_size = 50;
  //  char dest_s21[dest_size];
  //  char dest[dest_size];
  //  char* src = "Hello";
  //  size_t n = 0;
  tcase_add_test(tc_s21_strncat, test_s21_strncat_2);
  suite_add_tcase(suite, tc_s21_strncat);

  //  char* dest_filler = "there is no power as no knowledge";
  //  int dest_size = 50;
  //  char dest_s21[dest_size];
  //  char dest[dest_size];
  //  char* src = "Hello";
  //  size_t n = 10;
  tcase_add_test(tc_s21_strncat, test_s21_strncat_3);
  suite_add_tcase(suite, tc_s21_strncat);

  //  char* dest_filler = "Hello world!";;
  //  int dest_size = 50;
  //  char dest_s21[dest_size];
  //  char dest[dest_size];
  //  char* src = "KHA..An!!11";
  //  size_t n = 20;
  tcase_add_test(tc_s21_strncat, test_s21_strncat_4);
  suite_add_tcase(suite, tc_s21_strncat);

  return suite;
}