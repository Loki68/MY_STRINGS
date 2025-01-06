#include "s21_check_string.h" 

//первая строка длиннее второй
START_TEST (test_s21_strncmp_1)
{
  int s21_strncmp_result=0;
  int strncmp_result=0;

  s21_strncmp_result=s21_strncmp(T21_STR_1,T_STR_SHORT,NUMBER);
  strncmp_result=strncmp(T21_STR_1,T_STR_SHORT,NUMBER);
  
  ck_assert_int_eq(s21_strncmp_result,strncmp_result);
}
END_TEST

//первая строка короче второй
START_TEST (test_s21_strncmp_2)
{
  int s21_strncmp_result=0;
  int strncmp_result=0;

  s21_strncmp_result=s21_strncmp(T_STR_SHORT,T21_STR_1,NUMBER);
  strncmp_result=strncmp(T_STR_SHORT,T21_STR_1,NUMBER);
  
  ck_assert_int_eq(s21_strncmp_result,strncmp_result);
}
END_TEST

//равные строки
START_TEST (test_s21_strncmp_3)
{
  int s21_strncmp_result=0;
  int strncmp_result=0;

  s21_strncmp_result=s21_strncmp(T21_STR_1,T21_STR_1,NUMBER);
  strncmp_result=strncmp(T21_STR_1,T21_STR_1,NUMBER);
  
  ck_assert_int_eq(s21_strncmp_result,strncmp_result);
}
END_TEST

//разые строки
START_TEST (test_s21_strncmp_4)
{
  int s21_strncmp_result=0;
  int strncmp_result=0;

  s21_strncmp_result=s21_strncmp(T21_STR_1,T_STR_A_SHORT,NUMBER);
  strncmp_result=strncmp(T21_STR_1,T_STR_A_SHORT,NUMBER);
  
  ck_assert_int_eq(s21_strncmp_result,strncmp_result);
}
END_TEST

//равные строки больший размер
START_TEST (test_s21_strncmp_5)
{
  int s21_strncmp_result=0;
  int strncmp_result=0;

  s21_strncmp_result=s21_strncmp(T21_STR_1,T21_STR_1,OVERFLOW_NUMBER);
  strncmp_result=strncmp(T21_STR_1,T21_STR_1,OVERFLOW_NUMBER);
  
  ck_assert_int_eq(s21_strncmp_result,strncmp_result);
}
END_TEST

//нулевой размер
START_TEST (test_s21_strncmp_6)
{
  int s21_strncmp_result=0;
  int strncmp_result=0;

  s21_strncmp_result=s21_strncmp(T21_STR_1,T21_STR_1,ZERO_NUMBER);
  strncmp_result=strncmp(T21_STR_1,T21_STR_1,ZERO_NUMBER);
  
  ck_assert_int_eq(s21_strncmp_result,strncmp_result);
}
END_TEST

//разные строки больший размер
START_TEST (test_s21_strncmp_7)
{
  int s21_strncmp_result=0;
  int strncmp_result=0;

  s21_strncmp_result=s21_strncmp(T21_STR_1,T_STR_A_SHORT,OVERFLOW_NUMBER);
  strncmp_result=strncmp(T21_STR_1,T_STR_A_SHORT,OVERFLOW_NUMBER);
  
  ck_assert_int_eq(s21_strncmp_result,strncmp_result);
}
END_TEST

//const string or null ptr => sega
Suite *s21_strncmp_suite(void){
  Suite *suite;
  TCase *tc_s21_strncmp;

  suite=suite_create("s21_strncmp");

  tc_s21_strncmp=tcase_create("S21_strncmp");

////первая строка длиннее второй
  tcase_add_test(tc_s21_strncmp, test_s21_strncmp_1);
  suite_add_tcase(suite, tc_s21_strncmp);

////первая строка короче второй
  tcase_add_test(tc_s21_strncmp, test_s21_strncmp_2);
  suite_add_tcase(suite, tc_s21_strncmp);

//равные строки
  tcase_add_test(tc_s21_strncmp, test_s21_strncmp_3);
  suite_add_tcase(suite, tc_s21_strncmp);

//разые строки
  tcase_add_test(tc_s21_strncmp, test_s21_strncmp_4);
  suite_add_tcase(suite, tc_s21_strncmp);

//равные строки больший размер
  tcase_add_test(tc_s21_strncmp, test_s21_strncmp_5);
  suite_add_tcase(suite, tc_s21_strncmp);

//нулевой размер
  tcase_add_test(tc_s21_strncmp, test_s21_strncmp_6);
  suite_add_tcase(suite, tc_s21_strncmp);

//разные строки больший размер
  tcase_add_test(tc_s21_strncmp, test_s21_strncmp_7);
  suite_add_tcase(suite, tc_s21_strncmp);

  return suite;
}