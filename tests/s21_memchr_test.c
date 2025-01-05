#include "s21_check_string.h"

//верное количество символов
//существующий в строке символ
START_TEST (test_s21_memchr_1)
{
  char *str_ptr=NULL;
  char *s21_str_ptr=S21_NULL;

  str_ptr=memchr(T21_STR_1,EXIST_CH,NUMBER);
  s21_str_ptr=s21_memchr(T21_STR_1,EXIST_CH,NUMBER);
  
  ck_assert_ptr_eq(str_ptr,s21_str_ptr);
}
END_TEST

//не существующий в строке символ
START_TEST (test_s21_memchr_2)
{
  char *str_ptr=NULL;
  char *s21_str_ptr=S21_NULL;

  str_ptr=memchr(T21_STR_1,NOT_EXIST_CH,NUMBER);
  s21_str_ptr=s21_memchr(T21_STR_1,NOT_EXIST_CH,NUMBER);
  
  ck_assert_ptr_eq(str_ptr,s21_str_ptr);
}
END_TEST

//нулевой символ
START_TEST (test_s21_memchr_3)
{
  char *str_ptr=NULL;
  char *s21_str_ptr=S21_NULL;

  str_ptr=memchr(T21_STR_1,ZERO_CH,NUMBER);
  s21_str_ptr=s21_memchr(T21_STR_1,ZERO_CH,NUMBER);
  
  ck_assert_ptr_eq(str_ptr,s21_str_ptr);
}
END_TEST
//

//большее, чем символов в dest количество символов
//существующий в строке символ
START_TEST (test_s21_memchr_4)
{
  char *str_ptr=NULL;
  char *s21_str_ptr=S21_NULL;

  str_ptr=memchr(T21_STR_1,EXIST_CH,OVERFLOW_NUMBER);
  s21_str_ptr=s21_memchr(T21_STR_1,EXIST_CH,OVERFLOW_NUMBER);
  
  ck_assert_ptr_eq(str_ptr,s21_str_ptr);
}
END_TEST

//не существующий в строке символ
START_TEST (test_s21_memchr_5)
{
  char *str_ptr=NULL;
  char *s21_str_ptr=S21_NULL;

  str_ptr=memchr(T21_STR_1,NOT_EXIST_CH,OVERFLOW_NUMBER);
  s21_str_ptr=s21_memchr(T21_STR_1,NOT_EXIST_CH,OVERFLOW_NUMBER);
  
  ck_assert_ptr_eq(str_ptr,s21_str_ptr);
}
END_TEST

//нулевой символ
START_TEST (test_s21_memchr_6)
{
  char *str_ptr=NULL;
  char *s21_str_ptr=S21_NULL;

  str_ptr=memchr(T21_STR_1,ZERO_CH,OVERFLOW_NUMBER);
  s21_str_ptr=s21_memchr(T21_STR_1,ZERO_CH,OVERFLOW_NUMBER);
  
  ck_assert_ptr_eq(str_ptr,s21_str_ptr);
}
END_TEST
//

//отрицательное количество символов
//существующий в строке символ
START_TEST (test_s21_memchr_7)
{
  char *str_ptr=NULL;
  char *s21_str_ptr=S21_NULL;

  str_ptr=memchr(T21_STR_1,EXIST_CH,NEGATIVE_NUMBER);
  s21_str_ptr=s21_memchr(T21_STR_1,EXIST_CH,NEGATIVE_NUMBER);
  
  ck_assert_ptr_eq(str_ptr,s21_str_ptr);
}
END_TEST

//не существующий в строке символ
START_TEST (test_s21_memchr_8)
{
  char *str_ptr=NULL;
  char *s21_str_ptr=S21_NULL;

  str_ptr=memchr(T21_STR_1,NOT_EXIST_CH,NEGATIVE_NUMBER);
  s21_str_ptr=s21_memchr(T21_STR_1,NOT_EXIST_CH,NEGATIVE_NUMBER);
  
  ck_assert_ptr_eq(str_ptr,s21_str_ptr);
}
END_TEST

//нулевой символ
START_TEST (test_s21_memchr_9)
{
  char *str_ptr=NULL;
  char *s21_str_ptr=S21_NULL;

  str_ptr=memchr(T21_STR_1,ZERO_CH,NEGATIVE_NUMBER);
  s21_str_ptr=s21_memchr(T21_STR_1,ZERO_CH,NEGATIVE_NUMBER);
  
  ck_assert_ptr_eq(str_ptr,s21_str_ptr);
}
END_TEST
//

Suite *s21_memchr_suite(void){
  Suite *suite;
  TCase *tc_s21_memchr;
  TCase *tc_s21_memchr_limits;


  suite=suite_create("s21_memchr");

  tc_s21_memchr=tcase_create("Core");

  tcase_add_test(tc_s21_memchr, test_s21_memchr_1);
  suite_add_tcase(suite, tc_s21_memchr);

  tc_s21_memchr_limits=tcase_create("Limits");

  tcase_add_test(tc_s21_memchr_limits,test_s21_memchr_2);
  suite_add_tcase(suite, tc_s21_memchr_limits);

  tcase_add_test(tc_s21_memchr_limits,test_s21_memchr_3);
  suite_add_tcase(suite, tc_s21_memchr_limits);

//
  tcase_add_test(tc_s21_memchr_limits,test_s21_memchr_4);
  suite_add_tcase(suite, tc_s21_memchr_limits);

  tcase_add_test(tc_s21_memchr_limits,test_s21_memchr_5);
  suite_add_tcase(suite, tc_s21_memchr_limits);

  tcase_add_test(tc_s21_memchr_limits,test_s21_memchr_6);
  suite_add_tcase(suite, tc_s21_memchr_limits);

//
  tcase_add_test(tc_s21_memchr_limits,test_s21_memchr_7);
  suite_add_tcase(suite, tc_s21_memchr_limits);

  tcase_add_test(tc_s21_memchr_limits,test_s21_memchr_8);
  suite_add_tcase(suite, tc_s21_memchr_limits);

  tcase_add_test(tc_s21_memchr_limits,test_s21_memchr_9);
  suite_add_tcase(suite, tc_s21_memchr_limits);

  return suite;
}