#include "s21_check_string.h"

//  char* str1 = "Hello world!";
//подстрока
//  char* str2 = "Hello";
START_TEST(test_s21_strpbrk_1) {
  char *str1 = "Hello world!";
  char *str2 = "Hello";
  char *s21_strpbrk_result = NULL;
  char *strpbrk_result = NULL;

  s21_strpbrk_result = s21_strpbrk(str1, str2);
  strpbrk_result = strpbrk(str1, str2);

  ck_assert_ptr_eq(s21_strpbrk_result, strpbrk_result);
}
END_TEST

//  char* str1 = "Hello world!";
//пустая подстрока
//  char* str2= "";
START_TEST(test_s21_strpbrk_2) {
  char *str1 = "Hello world!";
  char *str2 = "";
  char *s21_strpbrk_result = NULL;
  char *strpbrk_result = NULL;

  s21_strpbrk_result = s21_strpbrk(str1, str2);
  strpbrk_result = strpbrk(str1, str2);

  ck_assert_ptr_eq(s21_strpbrk_result, strpbrk_result);
}
END_TEST

//  char* str_1 = "there is no power as no knowledge";
//подстрока не содержащая совпадений
//  char* str2 = "GEn_5";
START_TEST(test_s21_strpbrk_3) {
  char *str1 = "there is no power as no knowledge";
  char *str2 = "GEn_5";
  char *s21_strpbrk_result = NULL;
  const char *strpbrk_result = NULL;

  s21_strpbrk_result = s21_strpbrk(str1, str2);
  strpbrk_result = strpbrk(str1, str2);

  ck_assert_ptr_eq(s21_strpbrk_result, strpbrk_result);
}
END_TEST

//  char* str1 = "Hello";
//подстрока
//  char* str2 = "Hello world!";
START_TEST(test_s21_strpbrk_4) {
  char *str1 = "Hello";
  char *str2 = "Hello world!";
  char *s21_strpbrk_result = NULL;
  char *strpbrk_result = NULL;

  s21_strpbrk_result = s21_strpbrk(str1, str2);
  strpbrk_result = strpbrk(str1, str2);

  ck_assert_ptr_eq(s21_strpbrk_result, strpbrk_result);
}
END_TEST

//  char* str1 = "";
//подстрока не содержащая совпадений
//  char* str2 = "Hello world!";
START_TEST(test_s21_strpbrk_5) {
  char *str1 = "";
  char *str2 = "Hello world!";
  char *s21_strpbrk_result = NULL;
  char *strpbrk_result = NULL;

  s21_strpbrk_result = s21_strpbrk(str1, str2);
  strpbrk_result = strpbrk(str1, str2);

  ck_assert_ptr_eq(s21_strpbrk_result, strpbrk_result);
}
END_TEST

//  char* str1 = "bytecode\0why";
//подстрока не содержащая совпадений
//  char* str2 = "KHA..An!!11";
START_TEST(test_s21_strpbrk_6) {
  char *str1 = "bytecode\0why";
  char *str2 = "KHA..An!!11";
  char *s21_strpbrk_result = NULL;
  char *strpbrk_result = NULL;

  s21_strpbrk_result = s21_strpbrk(str1, str2);
  strpbrk_result = strpbrk(str1, str2);

  ck_assert_ptr_eq(s21_strpbrk_result, strpbrk_result);
}
END_TEST

//  char* str1 = "Hello world!";
//подстрока не содержащая совпадений
//  char* str2 = "GEn_5";
START_TEST(test_s21_strpbrk_7) {
  char *str1 = "Hello world!";
  char *str2 = "GEn_5";
  char *s21_strpbrk_result = NULL;
  char *strpbrk_result = NULL;

  s21_strpbrk_result = s21_strpbrk(str1, str2);
  strpbrk_result = strpbrk(str1, str2);

  ck_assert_ptr_eq(s21_strpbrk_result, strpbrk_result);
}
END_TEST

// const string or null ptr => sega
//выход за границы => sega
Suite *s21_strpbrk_suite(void) {
  Suite *suite;
  TCase *tc_s21_strpbrk;

  suite = suite_create("s21_strpbrk");

  tc_s21_strpbrk = tcase_create("S21_strpbrk");

  //  char* str1 = "Hello world!";
  //подстрока
  //  char* str2 = "Hello";
  tcase_add_test(tc_s21_strpbrk, test_s21_strpbrk_1);
  suite_add_tcase(suite, tc_s21_strpbrk);

  //  char* str1 = "Hello world!";
  //пустая подстрока
  //  char* str2= "";
  tcase_add_test(tc_s21_strpbrk, test_s21_strpbrk_2);
  suite_add_tcase(suite, tc_s21_strpbrk);

  //  char* str_1 = "there is no power as no knowledge";
  //подстрока не содержащая совпадений
  //  char* str2 = "GEn_5";
  tcase_add_test(tc_s21_strpbrk, test_s21_strpbrk_3);
  suite_add_tcase(suite, tc_s21_strpbrk);

  //  char* str1 = "Hello";
  //подстрока
  //  char* str2 = "Hello world!";
  tcase_add_test(tc_s21_strpbrk, test_s21_strpbrk_4);
  suite_add_tcase(suite, tc_s21_strpbrk);

  //  char* str1 = "";
  //подстрока не содержащая совпадений
  //  char* str2 = "Hello world!";
  tcase_add_test(tc_s21_strpbrk, test_s21_strpbrk_5);
  suite_add_tcase(suite, tc_s21_strpbrk);

  //  char* str1 = "bytecode\0why";
  //подстрока не содержащая совпадений
  //  char* str2 = "KHA..An!!11";
  tcase_add_test(tc_s21_strpbrk, test_s21_strpbrk_6);
  suite_add_tcase(suite, tc_s21_strpbrk);

  //  char* str1 = "Hello world!";
  //подстрока не содержащая совпадений
  //  char* str2 = "GEn_5";
  tcase_add_test(tc_s21_strpbrk, test_s21_strpbrk_7);
  suite_add_tcase(suite, tc_s21_strpbrk);

  return suite;
}