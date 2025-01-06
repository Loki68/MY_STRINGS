#include "s21_check_string.h" 



void setup(void){
    char s21_str[]="Hello world!";
    

    char str[]="Hello world!";
    
}


//нуль копируемых символов
//правильный размер строк
//символ раз
START_TEST (test_s21_memset_1)
{
    char s21_str[]="Hello world!";
    char str[]="Hello world!";

  char* s21_memset_result=NULL;
  char* memset_result=NULL;

  s21_memset_result=(char*)s21_memset(s21_str,EXIST_CH,NUMBER);
  memset_result=(char*)memset(str,EXIST_CH,NUMBER);
  
  ck_assert_str_eq(s21_memset_result,memset_result);
}
END_TEST

//второй вариант строк
//символ раз 
START_TEST (test_s21_memset_2)
{
    char s21_str[]="there is no power as no knowledge";
    char str[]="there is no power as no knowledge";

  char* s21_memset_result=NULL;
  char* memset_result=NULL;

  s21_memset_result=(char*)s21_memset(s21_str,EXIST_CH,NUMBER);
  memset_result=(char*)memset(str,EXIST_CH,NUMBER);
  
  ck_assert_str_eq(s21_memset_result,memset_result);
}
END_TEST

//символ двас
START_TEST (test_s21_memset_3)
{
    char s21_str[]="Hello world!";
    char str[]="Hello world!";

  char* s21_memset_result=NULL;
  char* memset_result=NULL;

  s21_memset_result=(char*)s21_memset(s21_str,NOT_EXIST_CH,NUMBER);
  memset_result=(char*)memset(str,NOT_EXIST_CH,NUMBER);
  
  ck_assert_str_eq(s21_memset_result,memset_result);
}
END_TEST

//второй вариант строк
//символ двас
START_TEST (test_s21_memset_4)
{
    char s21_str[]="there is no power as no knowledge";
    char str[]="there is no power as no knowledge";

  char* s21_memset_result=NULL;
  char* memset_result=NULL;

  s21_memset_result=(char*)s21_memset(s21_str,NOT_EXIST_CH,NUMBER);
  memset_result=(char*)memset(str,NOT_EXIST_CH,NUMBER);
  
  ck_assert_str_eq(s21_memset_result,memset_result);
}
END_TEST

//символ нуль
START_TEST (test_s21_memset_5)
{
    char s21_str[]="Hello world!";
    char str[]="Hello world!";

  char* s21_memset_result=NULL;
  char* memset_result=NULL;

  s21_memset_result=(char*)s21_memset(s21_str,ZERO_CH,NUMBER);
  memset_result=(char*)memset(str,ZERO_CH,NUMBER);
  
  ck_assert_str_eq(s21_memset_result,memset_result);
}
END_TEST

//второй вариант строк
//символ нуль
START_TEST (test_s21_memset_6)
{
    char s21_str[]="there is no power as no knowledge";
    char str[]="there is no power as no knowledge";

  char* s21_memset_result=NULL;
  char* memset_result=NULL;

  s21_memset_result=(char*)s21_memset(s21_str,NOT_EXIST_CH,NUMBER);
  memset_result=(char*)memset(str,NOT_EXIST_CH,NUMBER);
  
  ck_assert_str_eq(s21_memset_result,memset_result);
}
END_TEST

//отрицательный код символа
START_TEST (test_s21_memset_7)
{
    char s21_str[]="Hello world!";
    char str[]="Hello world!";

  char* s21_memset_result=NULL;
  char* memset_result=NULL;

  s21_memset_result=(char*)s21_memset(s21_str,NEGATIVE_NUMBER,NUMBER);
  memset_result=(char*)memset(str,NEGATIVE_NUMBER,NUMBER);
  
  ck_assert_str_eq(s21_memset_result,memset_result);
}
END_TEST

//второй вариант строк
//отрицательный код символа
START_TEST (test_s21_memset_8)
{
    char s21_str[]="there is no power as no knowledge";
    char str[]="there is no power as no knowledge";

  char* s21_memset_result=NULL;
  char* memset_result=NULL;

  s21_memset_result=(char*)s21_memset(s21_str,NEGATIVE_NUMBER,NUMBER);
  memset_result=(char*)memset(str,NEGATIVE_NUMBER,NUMBER);
  
  ck_assert_str_eq(s21_memset_result,memset_result);
}
END_TEST

//нулевое количество символов
START_TEST (test_s21_memset_9)
{
    char s21_str[]="Hello world!";
    char str[]="Hello world!";

  char* s21_memset_result=NULL;
  char* memset_result=NULL;

  s21_memset_result=(char*)s21_memset(s21_str,NEGATIVE_NUMBER,ZERO_NUMBER);
  memset_result=(char*)memset(str,NEGATIVE_NUMBER,ZERO_NUMBER);
  
  ck_assert_str_eq(s21_memset_result,memset_result);
}
END_TEST

//второй вариант строк
//нулевое количество символов
START_TEST (test_s21_memset_10)
{
    char s21_str[]="there is no power as no knowledge";
    char str[]="there is no power as no knowledge";

  char* s21_memset_result=NULL;
  char* memset_result=NULL;

  s21_memset_result=(char*)s21_memset(s21_str,NEGATIVE_NUMBER,ZERO_NUMBER);
  memset_result=(char*)memset(str,NEGATIVE_NUMBER,ZERO_NUMBER);
  
  ck_assert_str_eq(s21_memset_result,memset_result);
}
END_TEST
//

//отрицательные количества дают сегу
//бОльшие числа, чем есть в строке дают IOT stack smashing
Suite *s21_memset_suite(void){
  Suite *suite;
  TCase *tc_s21_memset;

  suite=suite_create("s21_memset");

  tc_s21_memset=tcase_create("Memset");

//нуль копируемых символов
////правильный размер строк
////символ раз
  tcase_add_test(tc_s21_memset, test_s21_memset_1);
  suite_add_tcase(suite, tc_s21_memset);

////второй вариант строк
////символ раз
    tcase_add_test(tc_s21_memset, test_s21_memset_2);
    suite_add_tcase(suite, tc_s21_memset);

////символ двас
    tcase_add_test(tc_s21_memset, test_s21_memset_3);
    suite_add_tcase(suite, tc_s21_memset);

////второй вариант строк
////символ двас
    tcase_add_test(tc_s21_memset, test_s21_memset_4);
    suite_add_tcase(suite, tc_s21_memset);

////символ нуль
    tcase_add_test(tc_s21_memset, test_s21_memset_5);
    suite_add_tcase(suite, tc_s21_memset);

////второй вариант строк
////символ нуль
    tcase_add_test(tc_s21_memset, test_s21_memset_6);
    suite_add_tcase(suite, tc_s21_memset);

////отрицательный код символа
    tcase_add_test(tc_s21_memset, test_s21_memset_7);
    suite_add_tcase(suite, tc_s21_memset);

////второй вариант строк
////отрицательный код символа
    tcase_add_test(tc_s21_memset, test_s21_memset_8);
    suite_add_tcase(suite, tc_s21_memset);

////нулевое количество символов
    tcase_add_test(tc_s21_memset, test_s21_memset_9);
    suite_add_tcase(suite, tc_s21_memset);

////второй вариант строк
////нулевое количество символов
    tcase_add_test(tc_s21_memset, test_s21_memset_10);
    suite_add_tcase(suite, tc_s21_memset);

  return suite;
}