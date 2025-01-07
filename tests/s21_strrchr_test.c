#include "s21_check_string.h"

//правильная строка
//  T21_STR_1 "Hello world!"
// существующий символ
//  EXIST_CH 'w'
START_TEST(test_s21_strrchr_1) {
  char *s21_strrchr_result = NULL;
  char *strrchr_result = NULL;

  s21_strrchr_result = s21_strrchr(T21_STR_1, EXIST_CH);
  strrchr_result = strrchr(T21_STR_1, EXIST_CH);

  ck_assert_ptr_eq(s21_strrchr_result, strrchr_result);
}
END_TEST

//правильная строка
//  T21_STR_1 "Hello world!"
// не существующий символ
//  NOT_EXIST_CH ']'
START_TEST(test_s21_strrchr_2) {
  char *s21_strrchr_result = NULL;
  char *strrchr_result = NULL;

  s21_strrchr_result = s21_strrchr(T21_STR_1, NOT_EXIST_CH);
  strrchr_result = strrchr(T21_STR_1, NOT_EXIST_CH);

  ck_assert_ptr_eq(s21_strrchr_result, strrchr_result);
}
END_TEST

//правильная строка
//  T21_STR_1 "Hello world!"
// нулевой символ
//  ZERO_CH '\0'
START_TEST(test_s21_strrchr_3) {
  char *s21_strrchr_result = NULL;
  char *strrchr_result = NULL;

  s21_strrchr_result = s21_strrchr(T21_STR_1, ZERO_CH);
  strrchr_result = strrchr(T21_STR_1, ZERO_CH);

  ck_assert_ptr_eq(s21_strrchr_result, strrchr_result);
}
END_TEST

//правильная строка
//  T_S_W_ZERO "bytecode\0why"
// нулевой символ
//  ZERO_CH '\0'
START_TEST(test_s21_strrchr_4) {
  char *s21_strrchr_result = NULL;
  char *strrchr_result = NULL;

  s21_strrchr_result = s21_strrchr(T_S_W_ZERO, ZERO_CH);
  strrchr_result = strrchr(T_S_W_ZERO, ZERO_CH);

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

  //правильная строка
  //  T21_STR_1 "Hello world!"
  // существующий символ
  //  EXIST_CH 'w'
  tcase_add_test(tc_s21_strrchr, test_s21_strrchr_1);
  suite_add_tcase(suite, tc_s21_strrchr);

  //правильная строка
  //  T21_STR_1 "Hello world!"
  // не существующий символ
  //  NOT_EXIST_CH ']'
  tcase_add_test(tc_s21_strrchr, test_s21_strrchr_2);
  suite_add_tcase(suite, tc_s21_strrchr);

  //правильная строка
  //  T21_STR_1 "Hello world!"
  // нулевой символ
  //  ZERO_CH '\0'
  tcase_add_test(tc_s21_strrchr, test_s21_strrchr_3);
  suite_add_tcase(suite, tc_s21_strrchr);

  //правильная строка
  //  T_S_W_ZERO "bytecode\0why"
  // нулевой символ
  //  ZERO_CH '\0'
  tcase_add_test(tc_s21_strrchr, test_s21_strrchr_4);
  suite_add_tcase(suite, tc_s21_strrchr);

  return suite;
}