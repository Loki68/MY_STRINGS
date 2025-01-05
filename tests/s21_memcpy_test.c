#include "s21_check_string.h" 

char s21_str[]="Hello world!";
char str[]="Hello world!";
//одинаковые строки
//правильный размер
START_TEST (test_s21_memcpy_1)
{
  char* s21_memcpy_result=NULL;
  char* memcpy_result=NULL;

  s21_memcpy_result=(char*)s21_memcpy(s21_str,T_STR_A_SHORT,NUMBER);
  memcpy_result=(char*)memcpy(str,T_STR_A_SHORT,NUMBER);
  
  ck_assert_str_eq(s21_memcpy_result,memcpy_result);
}
END_TEST

Suite *s21_memcpy_suite(void){
  Suite *suite;
  TCase *tc_s21_memcpy;
  TCase *tc_s21_memcpy_limits;

  suite=suite_create("s21_memcpy");

  tc_s21_memcpy=tcase_create("Core");

  tcase_add_test(tc_s21_memcpy, test_s21_memcpy_1);
  suite_add_tcase(suite, tc_s21_memcpy);

//   tc_s21_memcmp_limits=tcase_create("Limits");

//   tcase_add_test(tc_s21_memcmp_limits,test_s21_memcmp_2);
//   suite_add_tcase(suite, tc_s21_memcmp_limits);

//   tcase_add_test(tc_s21_memcmp_limits,test_s21_memcmp_4);
//   suite_add_tcase(suite, tc_s21_memcmp_limits);

//   tcase_add_test(tc_s21_memcmp_limits,test_s21_memcmp_5);
//   suite_add_tcase(suite, tc_s21_memcmp_limits);

//   tcase_add_test(tc_s21_memcmp_limits,test_s21_memcmp_6);
//   suite_add_tcase(suite, tc_s21_memcmp_limits);

  return suite;
}