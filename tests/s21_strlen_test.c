#include "s21_check_string.h"

//1 test
START_TEST (test_s21_strlen_1)
{
  char *str=T21_STR_1;
  s21_size_t s21_str_size=0;
  size_t str_size=0;

  s21_str_size=s21_strlen(str);
  str_size=strlen(str);
  //ck_assert(s21_str_size==str_size);
  //or

  ck_assert_msg(s21_str_size==str_size,"Значения размеров строки: %s\nсовпадают", str);
}
END_TEST

//2 test
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



//1 suite нужно названия подобрать
Suite *s21_strlen_suite(void){
  Suite *suite;
  TCase *tc_s21_strlen;
  TCase *tc_s21_strlen_limits;

  suite=suite_create("s21_strlen");

  tc_s21_strlen=tcase_create("Core");

  tcase_add_test(tc_s21_strlen, test_s21_strlen_1);
  suite_add_tcase(suite, tc_s21_strlen);

  tc_s21_strlen_limits=tcase_create("Limits");

  tcase_add_test(tc_s21_strlen_limits,test_s21_strlen_2);
  suite_add_tcase(suite, tc_s21_strlen_limits);

  return suite;
}