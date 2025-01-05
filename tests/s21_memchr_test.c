#include "s21_check_string.h"

//memchr test
START_TEST (test_s21_memchr_exist_ch_number)
{
  char *str_ptr=NULL;
  char *s21_str_ptr=S21_NULL;

  str_ptr=memchr(T21_STR_1,EXIST_CH,NUMBER);
  s21_str_ptr=s21_memchr(T21_STR_1,EXIST_CH,NUMBER);
  
  ck_assert_ptr_eq(str_ptr,s21_str_ptr);
}
END_TEST

//memchr test
START_TEST (test_s21_memchr_not_exist_ch_number)
{
  char *str_ptr=NULL;
  char *s21_str_ptr=S21_NULL;

  str_ptr=memchr(T21_STR_1,NOT_EXIST_CH,NUMBER);
  s21_str_ptr=s21_memchr(T21_STR_1,NOT_EXIST_CH,NUMBER);
  
  ck_assert_ptr_eq(str_ptr,s21_str_ptr);
}
END_TEST

Suite *s21_memchr_suite(void){
  Suite *suite;
  TCase *tc_s21_memchr;
  TCase *tc_s21_memchr_limits;


  suite=suite_create("s21_memchr");

  tc_s21_memchr=tcase_create("Core");

  tcase_add_test(tc_s21_memchr, test_s21_memchr_exist_ch_number);
  suite_add_tcase(suite, tc_s21_memchr);

  tc_s21_memchr_limits=tcase_create("Limits");

  tcase_add_test(tc_s21_memchr_limits,test_s21_memchr_not_exist_ch_number);
  suite_add_tcase(suite, tc_s21_memchr_limits);

  return suite;
}