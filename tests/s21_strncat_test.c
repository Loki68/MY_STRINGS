#include "s21_check_string.h" 

//correct number
START_TEST (test_s21_strncat_1)
{
  char s21_str_1[OVERFLOW_NUMBER]="there is no power as no knowledge";
  char str_1[OVERFLOW_NUMBER]="there is no power as no knowledge";
  char* s21_strncat_result=NULL;
  char* strncat_result=NULL;

  s21_strncat_result=(char*)s21_strncat(s21_str_1,T_STR_A_SHORT,NUMBER);
  strncat_result=(char*)strncat(str_1,T_STR_A_SHORT,NUMBER);
  
  ck_assert_str_eq(s21_strncat_result,strncat_result);
}
END_TEST

//нулевое количество символов
START_TEST (test_s21_strncat_2)
{
  char s21_str_1[OVERFLOW_NUMBER]="there is no power as no knowledge";
  char str_1[OVERFLOW_NUMBER]="there is no power as no knowledge";
  char* s21_strncat_result=NULL;
  char* strncat_result=NULL;

  s21_strncat_result=(char*)s21_strncat(s21_str_1,T_STR_SHORT,ZERO_NUMBER);
  strncat_result=(char*)strncat(str_1,T_STR_SHORT,ZERO_NUMBER);
  
  ck_assert_str_eq(s21_strncat_result,strncat_result);
}
END_TEST

//другая дополнительная строка
START_TEST (test_s21_strncat_3)
{
  char s21_str_1[OVERFLOW_NUMBER]="there is no power as no knowledge";
  char str_1[OVERFLOW_NUMBER]="there is no power as no knowledge";
  char* s21_strncat_result=NULL;
  char* strncat_result=NULL;

  s21_strncat_result=(char*)s21_strncat(s21_str_1,T_STR_A_SHORT,NUMBER);
  strncat_result=(char*)strncat(str_1,T_STR_A_SHORT,NUMBER);
  
  ck_assert_str_eq(s21_strncat_result,strncat_result);
}
END_TEST

//другая строка
START_TEST (test_s21_strncat_4)
{
  char s21_str_1[OVERFLOW_NUMBER/2]="Hello world!";
  char str_1[OVERFLOW_NUMBER/2]="Hello world!";
  char* s21_strncat_result=NULL;
  char* strncat_result=NULL;

  s21_strncat_result=(char*)s21_strncat(s21_str_1,T_STR_SHORT,NUMBER);
  strncat_result=(char*)strncat(str_1,T_STR_SHORT,NUMBER);
  
  ck_assert_str_eq(s21_strncat_result,strncat_result);
}
END_TEST

//const string or null ptr => sega
Suite *s21_strncat_suite(void){
  Suite *suite;
  TCase *tc_s21_strncat;

  suite=suite_create("s21_strncat");

  tc_s21_strncat=tcase_create("S21_strncat");

////правильный размер. остальное - неопределенное поведение
  tcase_add_test(tc_s21_strncat, test_s21_strncat_1);
  suite_add_tcase(suite, tc_s21_strncat);

////правильный размер.
  tcase_add_test(tc_s21_strncat, test_s21_strncat_2);
  suite_add_tcase(suite, tc_s21_strncat);

//другая дополнительная строка
  tcase_add_test(tc_s21_strncat, test_s21_strncat_3);
  suite_add_tcase(suite, tc_s21_strncat);

//другая строка
  tcase_add_test(tc_s21_strncat, test_s21_strncat_4);
  suite_add_tcase(suite, tc_s21_strncat);

  return suite;
}