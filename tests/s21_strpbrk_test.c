#include "s21_check_string.h"

//правильная строка
//  T21_STR_1 "Hello world!"
//подстрока
//  T_STR_SHORT "Hello"
START_TEST(test_s21_strpbrk_1) {
  char *s21_strpbrk_result = NULL;
  char *strpbrk_result = NULL;

  s21_strpbrk_result = s21_strpbrk(T21_STR_1, T_STR_SHORT);
  strpbrk_result = strpbrk(T21_STR_1, T_STR_SHORT);

  ck_assert_ptr_eq(s21_strpbrk_result, strpbrk_result);
}
END_TEST

//компилировать с флагом -Wdiscarded-qualifiers
//правильная строка
//  T21_STR_1 "Hello world!"
//подстрока не содержащая совпадений
//  T_EMPTY ""
START_TEST(test_s21_strpbrk_2) {
  char *s21_strpbrk_result = NULL;
  char *strpbrk_result = NULL;

  s21_strpbrk_result = s21_strpbrk(T21_STR_1, T_EMPTY);
  strpbrk_result = (char *)strpbrk(T21_STR_1, T_EMPTY);

  ck_assert_ptr_eq(s21_strpbrk_result, strpbrk_result);
}
END_TEST

//правильная строка
//  char s21_str_1[] = "there is no power as no knowledge";
//подстрока не содержащая совпадений
//  T_NO_SYMB "GEn_5"
START_TEST(test_s21_strpbrk_3) {
  char s21_str_1[] = "there is no power as no knowledge";
  char *s21_strpbrk_result = NULL;
  char *strpbrk_result = NULL;

  s21_strpbrk_result = s21_strpbrk(s21_str_1, T_NO_SYMB);
  strpbrk_result = strpbrk(s21_str_1, T_NO_SYMB);

  ck_assert_ptr_eq(s21_strpbrk_result, strpbrk_result);
}
END_TEST

//правильная строка
//  T_STR_SHORT "Hello"
//подстрока
//  T21_STR_1 "Hello world!"
START_TEST(test_s21_strpbrk_4) {
  char *s21_strpbrk_result = NULL;
  char *strpbrk_result = NULL;

  s21_strpbrk_result = s21_strpbrk(T_STR_SHORT, T21_STR_1);
  strpbrk_result = strpbrk(T_STR_SHORT, T21_STR_1);

  ck_assert_ptr_eq(s21_strpbrk_result, strpbrk_result);
}
END_TEST

//пустая строка
//  T_EMPTY ""
//подстрока не содержащая совпадений
//  T21_STR_1 "Hello world!"
START_TEST(test_s21_strpbrk_5) {
  char *s21_strpbrk_result = NULL;
  char *strpbrk_result = NULL;

  s21_strpbrk_result = s21_strpbrk(T_EMPTY, T21_STR_1);
  strpbrk_result = strpbrk(T_EMPTY, T21_STR_1);

  ck_assert_ptr_eq(s21_strpbrk_result, strpbrk_result);
}
END_TEST

//правильная строка обратный порядок
//  T_S_W_ZERO "bytecode\0why"
//подстрока не содержащая совпадений
//  T_STR_A_SHORT "KHA..An!!11"
START_TEST(test_s21_strpbrk_6) {
  char *s21_strpbrk_result = NULL;
  char *strpbrk_result = NULL;

  s21_strpbrk_result = s21_strpbrk(T_S_W_ZERO, T_STR_A_SHORT);
  strpbrk_result = strpbrk(T_S_W_ZERO, T_STR_A_SHORT);

  ck_assert_ptr_eq(s21_strpbrk_result, strpbrk_result);
}
END_TEST

//правильная строка
//  T21_STR_1 "Hello world!"
//подстрока не содержащая совпадений
//  T_NO_SYMB "GEn_5"
START_TEST(test_s21_strpbrk_7) {
  char *s21_strpbrk_result = NULL;
  char *strpbrk_result = NULL;

  s21_strpbrk_result = s21_strpbrk(T21_STR_1, T_NO_SYMB);
  strpbrk_result = strpbrk(T21_STR_1, T_NO_SYMB);

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

  //правильная строка
  //  T21_STR_1 "Hello world!"
  //подстрока
  //  T_STR_SHORT "Hello"
  tcase_add_test(tc_s21_strpbrk, test_s21_strpbrk_1);
  suite_add_tcase(suite, tc_s21_strpbrk);

  //правильная строка
  //  T21_STR_1 "Hello world!"
  //подстрока не содержащая совпадений
  //  T_EMPTY ""
  tcase_add_test(tc_s21_strpbrk, test_s21_strpbrk_2);
  suite_add_tcase(suite, tc_s21_strpbrk);

  //правильная строка
  //  char s21_str_1[] = "there is no power as no knowledge";
  //подстрока не содержащая совпадений
  //  T_NO_SYMB "GEn_5"
  tcase_add_test(tc_s21_strpbrk, test_s21_strpbrk_3);
  suite_add_tcase(suite, tc_s21_strpbrk);

  //правильная строка
  //  T_STR_SHORT "Hello"
  //подстрока
  //  T21_STR_1 "Hello world!"
  tcase_add_test(tc_s21_strpbrk, test_s21_strpbrk_4);
  suite_add_tcase(suite, tc_s21_strpbrk);

  //пустая строка
  //  T_EMPTY ""
  //подстрока не содержащая совпадений
  //  T21_STR_1 "Hello world!"
  tcase_add_test(tc_s21_strpbrk, test_s21_strpbrk_5);
  suite_add_tcase(suite, tc_s21_strpbrk);

  //правильная строка обратный порядок
  //  T_S_W_ZERO "bytecode\0why"
  //подстрока не содержащая совпадений
  //  T_STR_A_SHORT "KHA..An!!11"
  tcase_add_test(tc_s21_strpbrk, test_s21_strpbrk_6);
  suite_add_tcase(suite, tc_s21_strpbrk);

  //правильная строка
  //  T21_STR_1 "Hello world!"
  //подстрока не содержащая совпадений
  //  T_NO_SYMB "GEn_5"
  tcase_add_test(tc_s21_strpbrk, test_s21_strpbrk_7);
  suite_add_tcase(suite, tc_s21_strpbrk);

  return suite;
}