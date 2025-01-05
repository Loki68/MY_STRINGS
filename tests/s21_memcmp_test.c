#include "s21_check_string.h" 

//одинаковые строки
//правильный размер
START_TEST (test_s21_memcmp_1)
{
  int s21_memcmp_result=0;
  int memcmp_result=0;

  s21_memcmp_result=s21_memcmp(T21_STR_1,T21_STR_1,NUMBER);
  memcmp_result=memcmp(T21_STR_1,T21_STR_1,NUMBER);
  
  ck_assert_msg(s21_memcmp_result==memcmp_result,"Значения : %d и %d не совпадают", s21_memcmp_result,memcmp_result);
}
END_TEST

//размер > 0 за границами str1
START_TEST (test_s21_memcmp_2)
{
  int s21_memcmp_result=0;
  int memcmp_result=0;

  s21_memcmp_result=s21_memcmp(T21_STR_1,T21_STR_1,OVERFLOW_NUMBER);
  memcmp_result=memcmp(T21_STR_1,T21_STR_1,OVERFLOW_NUMBER);
  
  ck_assert_msg(s21_memcmp_result==memcmp_result,"Значения : %d и %d не совпадают", s21_memcmp_result,memcmp_result);
}
END_TEST

// //размер < 0 за границами str1
// START_TEST (test_s21_memcmp_3)
// {
//   int s21_memcmp_result=0;
//   int memcmp_result=0;

//   s21_memcmp_result=s21_memcmp(T21_STR_1,T21_STR_1,NEGATIVE_NUMBER);
//   memcmp_result=memcmp(T21_STR_1,T21_STR_1,NEGATIVE_NUMBER);
  
//   ck_assert_msg(s21_memcmp_result==memcmp_result,"Значения : %d и %d не совпадают", s21_memcmp_result,memcmp_result);
// }
// END_TEST
//

//разные строки
//правильный размер
START_TEST (test_s21_memcmp_4)
{
  int s21_memcmp_result=0;
  int memcmp_result=0;

  s21_memcmp_result=s21_memcmp(T21_STR_1,T_STR_SHORT,NUMBER);
  memcmp_result=memcmp(T21_STR_1,T_STR_SHORT,NUMBER);
  
  ck_assert_msg(s21_memcmp_result==memcmp_result,"Значения : %d и %d не совпадают", s21_memcmp_result,memcmp_result);
}
END_TEST
//

//1 suite нужно названия подобрать
Suite *s21_memcmp_suite(void){
  Suite *suite;
  TCase *tc_s21_memcmp;
  TCase *tc_s21_memcmp_limits;

  suite=suite_create("s21_memcmp");

  tc_s21_memcmp=tcase_create("Core");

  tcase_add_test(tc_s21_memcmp, test_s21_memcmp_1);
  suite_add_tcase(suite, tc_s21_memcmp);

  tc_s21_memcmp_limits=tcase_create("Limits");

  tcase_add_test(tc_s21_memcmp_limits,test_s21_memcmp_2);
  suite_add_tcase(suite, tc_s21_memcmp_limits);

// //сега нужно допилить либо реализацию и тестить ее, либо выпилить
//   tcase_add_test(tc_s21_memcmp_limits,test_s21_memcmp_3);
//   suite_add_tcase(suite, tc_s21_memcmp_limits);

  tcase_add_test(tc_s21_memcmp_limits,test_s21_memcmp_4);
  suite_add_tcase(suite, tc_s21_memcmp_limits);

  return suite;
}