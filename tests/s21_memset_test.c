#include "s21_check_string.h" 



void setup(void){
    char s21_str[]="Hello world!";
    char s21_str_1[]="there is no power as no knowledge";

    char str[]="Hello world!";
    char str_1[]="there is no power as no knowledge";
}

void teardown(void){

}

//нуль копируемых символов
START_TEST (test_s21_memset_1)
{
    char s21_str[]="Hello world!";
    char str[]="Hello world!";

  char* s21_memset_result=NULL;
  char* memset_result=NULL;

  s21_memset_result=(char*)s21_memset(s21_str,EXIST_CH,ZERO_NUMBER);
  memset_result=(char*)memset(str,EXIST_CH,NUMBER);
  
  ck_assert_str_eq(s21_memset_result,memset_result);
}
END_TEST
//

Suite *s21_memset_suite(void){
  Suite *suite;
  TCase *tc_s21_memset;

  suite=suite_create("s21_memset");

  tc_s21_memset=tcase_create("Memset");

//одинаковые строки на вход
////правильный размер. остальное - неопределенное поведение
  tcase_add_test(tc_s21_memset, test_s21_memset_1);
  suite_add_tcase(suite, tc_s21_memset);

// ////второй вариант строк
//   tcase_add_test(tc_s21_memcpy, test_s21_memcpy_2);
//   suite_add_tcase(suite, tc_s21_memcpy);

// ////с нулем в строке
//   tcase_add_test(tc_s21_memcpy, test_s21_memcpy_3);
//   suite_add_tcase(suite, tc_s21_memcpy);

// ////нуль копируемых символов
//   tcase_add_test(tc_s21_memcpy, test_s21_memcpy_4);
//   suite_add_tcase(suite, tc_s21_memcpy);

  return suite;
}