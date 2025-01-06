#include "s21_check_string.h" 

//строка 1
//существующий в строке символ
START_TEST (test_s21_strchr_1)
{
    char* s21_str=T21_STR_1;
    char* str=T21_STR_1;
  char* s21_strchr_result=NULL;
  char* strchr_result=NULL;

  s21_strchr_result=s21_strchr(s21_str,EXIST_CH);
  strchr_result=strchr(str,EXIST_CH);
  
  ck_assert_ptr_eq(s21_strchr_result,strchr_result);
}
END_TEST

//существующий в строке символ '\0'
START_TEST (test_s21_strchr_2)
{
    char* s21_str=T21_STR_1;
    char* str=T21_STR_1;
  char* s21_strchr_result=NULL;
  char* strchr_result=NULL;

  s21_strchr_result=s21_strchr(s21_str,ZERO_CH);
  strchr_result=strchr(str,ZERO_CH);
  
  ck_assert_ptr_eq(s21_strchr_result,strchr_result);
}
END_TEST

//не существующий в строке символ 
START_TEST (test_s21_strchr_3)
{
    char* s21_str=T21_STR_1;
    char* str=T21_STR_1;
  char* s21_strchr_result=NULL;
  char* strchr_result=NULL;

  s21_strchr_result=s21_strchr(s21_str,NOT_EXIST_CH);
  strchr_result=strchr(str,NOT_EXIST_CH);
  
  ck_assert_ptr_eq(s21_strchr_result,strchr_result);
}
END_TEST

//строка 2
//существующий в строке символ '\0'
START_TEST (test_s21_strchr_4)
{
    char* s21_str=T_S_W_ZERO;
    char* str=T_S_W_ZERO;
  char* s21_strchr_result=NULL;
  char* strchr_result=NULL;

  s21_strchr_result=s21_strchr(s21_str,ZERO_CH);
  strchr_result=strchr(str,ZERO_CH);
  
  ck_assert_ptr_eq(s21_strchr_result,strchr_result);
}
END_TEST

//не существующий в строке символ 
START_TEST (test_s21_strchr_5)
{
    char* s21_str=T21_STR_1;
    char* str=T21_STR_1;
  char* s21_strchr_result=NULL;
  char* strchr_result=NULL;

  s21_strchr_result=s21_strchr(s21_str,NOT_EXIST_CH);
  strchr_result=strchr(str,NOT_EXIST_CH);
  
  ck_assert_ptr_eq(s21_strchr_result,strchr_result);
}
END_TEST
//

//коды вне символов строки дают сегу
Suite *s21_strchr_suite(void){
  Suite *suite;
  TCase *tc_s21_strchr;

  suite=suite_create("s21_strchr");

  tc_s21_strchr=tcase_create("Strchr");

//строка 1
////существующий в строке символ
  tcase_add_test(tc_s21_strchr, test_s21_strchr_1);
  suite_add_tcase(suite, tc_s21_strchr);

////существующий в строке символ '\0'
  tcase_add_test(tc_s21_strchr, test_s21_strchr_2);
  suite_add_tcase(suite, tc_s21_strchr);

////не существующий в строке символ 
  tcase_add_test(tc_s21_strchr, test_s21_strchr_3);
  suite_add_tcase(suite, tc_s21_strchr);

//строка 2
////существующий в строке символ '\0'
  tcase_add_test(tc_s21_strchr, test_s21_strchr_4);
  suite_add_tcase(suite, tc_s21_strchr);

////не существующий в строке символ 
  tcase_add_test(tc_s21_strchr, test_s21_strchr_5);
  suite_add_tcase(suite, tc_s21_strchr);

  return suite;
}