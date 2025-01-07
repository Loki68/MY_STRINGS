#include "s21_check_string.h"

//строка с нулем
START_TEST(test_s21_strncpy_1) {
  char s21_str[] = "Hello world!";
  char str[] = "Hello world!";
  size_t size = 12;
  char *s21_strncpy_result = NULL;
  char *strncpy_result = NULL;

  s21_strncpy_result = s21_strncpy(s21_str, T_STR_A_SHORT, size);
  strncpy_result = strncpy(str, T_STR_A_SHORT, size);

  ck_assert_str_eq(s21_strncpy_result, strncpy_result);
}
END_TEST

//строка
START_TEST(test_s21_strncpy_2) {
  char s21_str[] = "there is no power as no knowledge";
  char str[] = "there is no power as no knowledge";
  char *s21_strncpy_result = NULL;
  char *strncpy_result = NULL;

  s21_strncpy_result = s21_strncpy(s21_str, T_STR_SHORT, NUMBER);
  strncpy_result = strncpy(str, T_STR_SHORT, NUMBER);

  ck_assert_str_eq(s21_strncpy_result, strncpy_result);
}
END_TEST

//закомментированное на линупсе собирается с флагами -Wstringop-truncation
// //строка и ноль нужно копировать
// START_TEST (test_s21_strncpy_3)
// {
//   char s21_str[]="there is no power as no knowledge";
//   char str[]="there is no power as no knowledge";
//   char* s21_strncpy_result=NULL;
//   char* strncpy_result=NULL;

//   s21_strncpy_result=s21_strncpy(s21_str,T_STR_SHORT,ZERO_NUMBER);
//   strncpy_result=strncpy(str,T_STR_SHORT,ZERO_NUMBER);

//   ck_assert_str_eq(s21_strncpy_result,strncpy_result);
// }
// END_TEST

// //пустая строка
// START_TEST (test_s21_strncpy_4)
// {
//   char s21_str[]="there is no power as no knowledge";
//   char str[]="there is no power as no knowledge";
//   char* s21_strncpy_result=NULL;
//   char* strncpy_result=NULL;

//   s21_strncpy_result=s21_strncpy(s21_str,T_EMPTY,NUMBER);
//   strncpy_result=strncpy(str,T_EMPTY,NUMBER);

//   ck_assert_str_eq(s21_strncpy_result,strncpy_result);
// }
// END_TEST

// const string or null ptr => sega
//выход за границы => sega
Suite *s21_strncpy_suite(void) {
  Suite *suite;
  TCase *tc_s21_strncpy;

  suite = suite_create("s21_strncpy");

  tc_s21_strncpy = tcase_create("S21_strncpy");

  //строка с нулем
  tcase_add_test(tc_s21_strncpy, test_s21_strncpy_1);
  suite_add_tcase(suite, tc_s21_strncpy);

  //строка
  tcase_add_test(tc_s21_strncpy, test_s21_strncpy_2);
  suite_add_tcase(suite, tc_s21_strncpy);

  // //строка и ноль нужно копировать
  //   tcase_add_test(tc_s21_strncpy, test_s21_strncpy_3);
  //   suite_add_tcase(suite, tc_s21_strncpy);

  // //пустая строка
  //   tcase_add_test(tc_s21_strncpy, test_s21_strncpy_4);
  //   suite_add_tcase(suite, tc_s21_strncpy);

  return suite;
}