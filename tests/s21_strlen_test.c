#include "s21_check_string.h"

//same string
START_TEST (test_s21_strlen_1)
{
  char *str=T21_STR_1;
  s21_size_t s21_str_size=0;
  size_t str_size=0;

  s21_str_size=s21_strlen(str);
  str_size=strlen(str);
  
  ck_assert(s21_str_size==str_size);
  //or

  //ck_assert_msg(s21_str_size==str_size,"Значения размеров строки: %s\nсовпадают", str);
}
END_TEST

//разные строки
START_TEST (test_s21_strlen_2)
{
  char *str=T21_STR_1;
  s21_size_t s21_str_size=0;
  size_t str_size=0;

  s21_str_size=s21_strlen(T_STR_SHORT);
  str_size=strlen(str);
  //ck_assert(s21_str_size==str_size);
  //or
  
  ck_assert_msg(s21_str_size<str_size,"Значения размеров строки: %s\nсовпадают", str);
}
END_TEST

//пустая строка
START_TEST (test_s21_strlen_3)
{
  s21_size_t s21_str_size=0;
  size_t str_size=0;

  s21_str_size=s21_strlen(T_EMPTY);
  str_size=strlen(T_EMPTY);
  
  ck_assert_msg(s21_str_size==str_size,"Значения размеров строки: %ld и %ld не совпадают", str_size,s21_str_size);
}
END_TEST

//нулевые строки дают сегу
Suite *s21_strlen_suite(void){
  Suite *suite;
  TCase *tc_s21_strlen;

  suite=suite_create("s21_strlen");

  tc_s21_strlen=tcase_create("S21_strlen");

  tcase_add_test(tc_s21_strlen, test_s21_strlen_1);
  suite_add_tcase(suite, tc_s21_strlen);

  tcase_add_test(tc_s21_strlen,test_s21_strlen_2);
  suite_add_tcase(suite, tc_s21_strlen);

  tcase_add_test(tc_s21_strlen,test_s21_strlen_3);
  suite_add_tcase(suite, tc_s21_strlen);

  return suite;
}