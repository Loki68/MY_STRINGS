#include "s21_check_string.h" 

//одинаковые строки на вход
//правильный размер. 
START_TEST (test_s21_memcpy_1)
{
  char s21_str[]="Hello world!";
  char str[]="Hello world!";
  char* s21_memcpy_result=NULL;
  char* memcpy_result=NULL;

  s21_memcpy_result=(char*)s21_memcpy(s21_str,T_STR_A_SHORT,NUMBER);
  memcpy_result=(char*)memcpy(str,T_STR_A_SHORT,NUMBER);
  
  ck_assert_str_eq(s21_memcpy_result,memcpy_result);
}
END_TEST

// //больший размер
// //didn't works in test
// START_TEST (test_s21_memcpy_5)
// {
//   char s21_str[]="Hello world!";
//   char str[]="Hello world!";
//   char* s21_memcpy_result=NULL;
//   char* memcpy_result=NULL;

//   s21_memcpy_result=(char*)s21_memcpy(s21_str,T_STR_A_SHORT,OVERFLOW_NUMBER);
//   memcpy_result=(char*)memcpy(str,T_STR_A_SHORT,OVERFLOW_NUMBER);
  
//   ck_assert_str_eq(s21_memcpy_result,memcpy_result);
// }
// END_TEST

//второй вариант строк
START_TEST (test_s21_memcpy_2)
{
  char s21_str_1[]="there is no power as no knowledge";
  char str_1[]="there is no power as no knowledge";
  char* s21_memcpy_result=NULL;
  char* memcpy_result=NULL;

  s21_memcpy_result=(char*)s21_memcpy(s21_str_1,T_STR_1,NUMBER);
  memcpy_result=(char*)memcpy(str_1,T_STR_1,NUMBER);
  
  ck_assert_str_eq(s21_memcpy_result,memcpy_result);
}
END_TEST

//с нулем в строке
START_TEST (test_s21_memcpy_3)
{
  char s21_str_1[]="there is no power as no knowledge";
  char str_1[]="there is no power as no knowledge";
  char* s21_memcpy_result=NULL;
  char* memcpy_result=NULL;

  s21_memcpy_result=(char*)s21_memcpy(s21_str_1,T_S_W_ZERO,NUMBER);
  memcpy_result=(char*)memcpy(str_1,T_S_W_ZERO,NUMBER);
  
  ck_assert_str_eq(s21_memcpy_result,memcpy_result);
}
END_TEST

//нуль копируемых символов
START_TEST (test_s21_memcpy_4)
{
  char s21_str_1[]="there is no power as no knowledge";
  char str_1[]="there is no power as no knowledge";
  char* s21_memcpy_result=NULL;
  char* memcpy_result=NULL;

  s21_memcpy_result=(char*)s21_memcpy(s21_str_1,T_STR_A_SHORT,ZERO_NUMBER);
  memcpy_result=(char*)memcpy(str_1,T_STR_A_SHORT,ZERO_NUMBER);
  
  ck_assert_str_eq(s21_memcpy_result,memcpy_result);
}
END_TEST
//

//отрицательное - неопределенное поведение
Suite *s21_memcpy_suite(void){
  Suite *suite;
  TCase *tc_s21_memcpy;

  suite=suite_create("s21_memcpy");

  tc_s21_memcpy=tcase_create("Core");

//одинаковые строки на вход
////правильный размер. остальное - неопределенное поведение
  tcase_add_test(tc_s21_memcpy, test_s21_memcpy_1);
  suite_add_tcase(suite, tc_s21_memcpy);

// ////больший размер  
//   tcase_add_test(tc_s21_memcpy, test_s21_memcpy_5);
//   suite_add_tcase(suite, tc_s21_memcpy);

////второй вариант строк
  tcase_add_test(tc_s21_memcpy, test_s21_memcpy_2);
  suite_add_tcase(suite, tc_s21_memcpy);

////с нулем в строке
  tcase_add_test(tc_s21_memcpy, test_s21_memcpy_3);
  suite_add_tcase(suite, tc_s21_memcpy);

////нуль копируемых символов
  tcase_add_test(tc_s21_memcpy, test_s21_memcpy_4);
  suite_add_tcase(suite, tc_s21_memcpy);

  return suite;
}