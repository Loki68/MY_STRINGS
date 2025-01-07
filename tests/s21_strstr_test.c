#include "s21_check_string.h"
#include <stdio.h>

//правильная строка
//  T21_STR_1 "Hello world!"
//подстрока не содержащаяся в первой
//  T_NO_SYMB "GEn_5"
START_TEST(test_s21_strstr_1) {
  char *s21_strstr_result = NULL;
  char *strstr_result = NULL;

  s21_strstr_result = s21_strstr(T21_STR_1, T_NO_SYMB);
  strstr_result = strstr(T21_STR_1, T_NO_SYMB);

  ck_assert_ptr_eq(s21_strstr_result, strstr_result);
}
END_TEST

//правильная строка
//  T21_STR_1 "Hello world!"
//подстрока не содержащаяся в первой
//  T_NO_SYMB "GEn_5"
// возвращает NULL
START_TEST(test_s21_strstr_2) {
  char *s21_strstr_result = NULL;

  s21_strstr_result = s21_strstr(T21_STR_1, T_NO_SYMB);

  ck_assert_ptr_null(s21_strstr_result);
}
END_TEST

//правильная строка
//  T21_STR_1 "Hello world!"
//подстрока содержащаяся в первой
//  T_STR_END "world"
START_TEST(test_s21_strstr_3) {
  char *s21_strstr_result = NULL;
  char *strstr_result = NULL;

  s21_strstr_result = s21_strstr(T21_STR_1, T_STR_END);
  strstr_result = strstr(T21_STR_1, T_STR_END);
  printf("s21 : %p, : %p\n", s21_strstr_result, strstr_result);

  ck_assert_ptr_eq(s21_strstr_result, strstr_result);
}
END_TEST

//правильная строка
//  T21_STR_1 "Hello world!"
//подстрока содержащаяся в первой
//  T_STR_END "world"
//сравниваем значеминя строк
START_TEST(test_s21_strstr_4) {
  char *s21_strstr_result = NULL;
  char *strstr_result = NULL;

  s21_strstr_result = s21_strstr(T21_STR_1, T_STR_END);
  strstr_result = strstr(T21_STR_1, T_STR_END);

  ck_assert_str_eq(s21_strstr_result, strstr_result);
}
END_TEST

//правильная строка
//  T21_STR_1 "Hello world!"
//пустая строка
//  T_EMPTY ""
START_TEST(test_s21_strstr_5) {
  char *s21_strstr_result = NULL;
  char *strstr_result = NULL;

  s21_strstr_result = s21_strstr(T21_STR_1, T_EMPTY);
  strstr_result = strstr(T21_STR_1, T_EMPTY);

  ck_assert_ptr_eq(s21_strstr_result, strstr_result);
}
END_TEST

//правильная строка
//  T21_STR_1 "Hello world!"
//короткая строка не содержащаяся в T21_STR_1
//  char* short_s= "TG"
START_TEST(test_s21_strstr_6) {
  const char *short_s = "TG";
  char *s21_strstr_result = NULL;
  char *strstr_result = NULL;

  s21_strstr_result = s21_strstr(T21_STR_1, short_s);
  strstr_result = strstr(T21_STR_1, short_s);

  ck_assert_ptr_eq(s21_strstr_result, strstr_result);
}
END_TEST

//правильная строка
//  T21_STR_1 "Hello world!"
//короткая строка не содержащаяся в T21_STR_1, но похожая
//  const char* short_s= "llow"
START_TEST(test_s21_strstr_7) {
  const char *short_s = "llow";
  char *s21_strstr_result = NULL;
  char *strstr_result = NULL;

  s21_strstr_result = s21_strstr(T21_STR_1, short_s);
  strstr_result = strstr(T21_STR_1, short_s);

  ck_assert_ptr_eq(s21_strstr_result, strstr_result);
}
END_TEST

//правильная строка
//  const char* str ="thereis no power as no knowledge"
//короткая строка не содержащаяся в T21_STR_1, но похожая
//  const char* short_s= "owed"
START_TEST(test_s21_strstr_8) {
  const char *str = "thereis no power as no knowledge";
  const char *short_s = "owed";
  char *s21_strstr_result = NULL;
  char *strstr_result = NULL;

  s21_strstr_result = s21_strstr(str, short_s);
  strstr_result = strstr(str, short_s);

  ck_assert_ptr_eq(s21_strstr_result, strstr_result);
}
END_TEST

//правильная строка
//  const char* str = "owed"
//короткая строка не содержащаяся в T21_STR_1, но похожая
//  const char* short_s= "thereis no power as no knowledge"
START_TEST(test_s21_strstr_9) {
  const char *str = "owed";
  const char *short_s = "thereis no power as no knowledge";
  char *s21_strstr_result = NULL;
  char *strstr_result = NULL;

  s21_strstr_result = s21_strstr(str, short_s);
  strstr_result = strstr(str, short_s);

  ck_assert_ptr_eq(s21_strstr_result, strstr_result);
}
END_TEST

// const string or null ptr => sega
//выход за границы => sega
Suite *s21_strstr_suite(void) {
  Suite *suite;
  TCase *tc_s21_strstr;

  suite = suite_create("s21_strstr");

  tc_s21_strstr = tcase_create("S21_strstr");

  //правильная строка
  //  T21_STR_1 "Hello world!"
  //подстрока не содержащаяся в первой
  //  T_NO_SYMB "GEn_5"
  tcase_add_test(tc_s21_strstr, test_s21_strstr_1);
  suite_add_tcase(suite, tc_s21_strstr);

  //правильная строка
  //  T21_STR_1 "Hello world!"
  //подстрока не содержащаяся в первой
  //  T_NO_SYMB "GEn_5"
  // возвращает NULL
  tcase_add_test(tc_s21_strstr, test_s21_strstr_2);
  suite_add_tcase(suite, tc_s21_strstr);

  //правильная строка
  //  T21_STR_1 "Hello world!"
  //подстрока содержащаяся в первой
  //  T_STR_END "world"
  tcase_add_test(tc_s21_strstr, test_s21_strstr_3);
  suite_add_tcase(suite, tc_s21_strstr);

  //правильная строка
  //  T21_STR_1 "Hello world!"
  //подстрока содержащаяся в первой
  //  T_STR_END "world"
  //сравниваем значеминя строк
  tcase_add_test(tc_s21_strstr, test_s21_strstr_4);
  suite_add_tcase(suite, tc_s21_strstr);

  //правильная строка
  //  T21_STR_1 "Hello world!"
  //пустая строка
  //  T_EMPTY ""
  tcase_add_test(tc_s21_strstr, test_s21_strstr_5);
  suite_add_tcase(suite, tc_s21_strstr);

  //правильная строка
  //  T21_STR_1 "Hello world!"
  //короткая строка не содержащаяся в T21_STR_1
  //  char* short_s= "TG"
  tcase_add_test(tc_s21_strstr, test_s21_strstr_6);
  suite_add_tcase(suite, tc_s21_strstr);

  //правильная строка
  //  T21_STR_1 "Hello world!"
  //короткая строка не содержащаяся в T21_STR_1, но похожая
  //  const char* short_s= "llow"
  tcase_add_test(tc_s21_strstr, test_s21_strstr_7);
  suite_add_tcase(suite, tc_s21_strstr);

  //правильная строка
  //  const char* str "thereis no power as no knowledge"
  //короткая строка не содержащаяся в T21_STR_1, но похожая
  //  const char* short_s= "owed"
  tcase_add_test(tc_s21_strstr, test_s21_strstr_8);
  suite_add_tcase(suite, tc_s21_strstr);

  //правильная строка
  //  const char* str = "owed"
  //короткая строка не содержащаяся в T21_STR_1, но похожая
  //  const char* short_s= "thereis no power as no knowledge"
  tcase_add_test(tc_s21_strstr, test_s21_strstr_9);
  suite_add_tcase(suite, tc_s21_strstr);

  return suite;
}