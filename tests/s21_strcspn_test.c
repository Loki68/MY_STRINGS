#include "s21_check_string.h"

//исходная строка
// char *str = "there is no power as no knowledge";
//строка для поиска символов которых нет в строке
// char *tk = ",.!?";
START_TEST(test_s21_strcspn_1) {
  char *str = "there is no power as no knowledge";
  char *tk = ",.!?";
  size_t s21_strcspn_result = 0;
  size_t strcspn_result = 0;

  s21_strcspn_result = s21_strcspn(str, tk);
  strcspn_result = strcspn(str, tk);

  ck_assert(s21_strcspn_result == strcspn_result);
}
END_TEST

//исходная строка
// char *str = "there is no power as no knowledge";
//строка для поиска символов с символом с которого начинается строка
// char *tk = "t,.!?";
START_TEST(test_s21_strcspn_2) {
  char *str = "there is no power as no knowledge";
  char *tk = "t,.!?";
  size_t s21_strcspn_result = 0;
  size_t strcspn_result = 0;

  s21_strcspn_result = s21_strcspn(str, tk);
  strcspn_result = strcspn(str, tk);

  ck_assert(s21_strcspn_result == strcspn_result);
}
END_TEST

//исходная строка
// char *str = "there is no power as no knowledge";
//строка для поиска символов с существующим символом внутри строки
// char *tk = ",.o!?";
START_TEST(test_s21_strcspn_3) {
  char *str = "there is no power as no knowledge";
  char *tk = ",.o!?";
  size_t s21_strcspn_result = 0;
  size_t strcspn_result = 0;

  s21_strcspn_result = s21_strcspn(str, tk);
  strcspn_result = strcspn(str, tk);

  ck_assert(s21_strcspn_result == strcspn_result);
}
END_TEST

//исходная строка
// char *str = "there is no power as no knowledge";
//строка для поиска символов с существующим символом внутри строки
// char *tk = ",.t!?o"
START_TEST(test_s21_strcspn_4) {
  char *str = "there is no power as no knowledge";
  char *tk = ",.t!?o";
  size_t s21_strcspn_result = 0;
  size_t strcspn_result = 0;

  s21_strcspn_result = s21_strcspn(str, tk);
  strcspn_result = strcspn(str, tk);

  ck_assert(s21_strcspn_result == strcspn_result);
}
END_TEST

//исходная строка
// char *str = "there is no power as no knowledge";
//пустая строка символов
// char *tk = ""
START_TEST(test_s21_strcspn_5) {
  char *str = "there is no power as no knowledge";
  char *tk = "";
  size_t s21_strcspn_result = 0;
  size_t strcspn_result = 0;

  s21_strcspn_result = s21_strcspn(str, tk);
  strcspn_result = strcspn(str, tk);

  ck_assert(s21_strcspn_result == strcspn_result);
}
END_TEST

//пустая исходная строка
// char *str = "";
//строка для поиска символов с существующим символом внутри строки
// char *tk = ",.t!?o"
START_TEST(test_s21_strcspn_6) {
  char *str = "";
  char *tk = ",.t!?o";
  size_t s21_strcspn_result = 0;
  size_t strcspn_result = 0;

  s21_strcspn_result = s21_strcspn(str, tk);
  strcspn_result = strcspn(str, tk);

  ck_assert(s21_strcspn_result == strcspn_result);
}
END_TEST

//пустая исходная строка
// char *str = "";
//пустая строка символов
// char *tk = ""
START_TEST(test_s21_strcspn_7) {
  char *str = "";
  char *tk = "";
  size_t s21_strcspn_result = 0;
  size_t strcspn_result = 0;

  s21_strcspn_result = s21_strcspn(str, tk);
  strcspn_result = strcspn(str, tk);

  ck_assert(s21_strcspn_result == strcspn_result);
}
END_TEST

// const string or null ptr => sega
Suite *s21_strcspn_suite(void) {
  Suite *suite;
  TCase *tc_s21_strcspn;

  suite = suite_create("s21_strcspn");

  tc_s21_strcspn = tcase_create("S21_strcspn");

  //исходная строка
  // char *str = "there is no power as no knowledge";
  //строка для поиска символов которых нет в строке
  // char *tk = ",.!?";
  tcase_add_test(tc_s21_strcspn, test_s21_strcspn_1);
  suite_add_tcase(suite, tc_s21_strcspn);

  //исходная строка
  // char *str = "there is no power as no knowledge";
  //строка для поиска символов с символом с которого начинается строка
  // char *tk = "t,.!?";
  tcase_add_test(tc_s21_strcspn, test_s21_strcspn_2);
  suite_add_tcase(suite, tc_s21_strcspn);

  //исходная строка
  // char *str = "there is no power as no knowledge";
  //строка для поиска символов с существующим символом внутри строки
  // char *tk = ",.o!?";
  tcase_add_test(tc_s21_strcspn, test_s21_strcspn_3);
  suite_add_tcase(suite, tc_s21_strcspn);

  //исходная строка
  // char *str = "there is no power as no knowledge";
  //строка для поиска символов с существующим символом внутри строки
  // char *tk = ",.t!?o"
  tcase_add_test(tc_s21_strcspn, test_s21_strcspn_4);
  suite_add_tcase(suite, tc_s21_strcspn);

  //исходная строка
  // char *str = "there is no power as no knowledge";
  //пустая строка символов
  // char *tk = ""
  tcase_add_test(tc_s21_strcspn, test_s21_strcspn_5);
  suite_add_tcase(suite, tc_s21_strcspn);

  //пустая исходная строка
  // char *str = "";
  //строка для поиска символов с существующим символом внутри строки
  // char *tk = ",.t!?o"
  tcase_add_test(tc_s21_strcspn, test_s21_strcspn_6);
  suite_add_tcase(suite, tc_s21_strcspn);

  //пустая исходная строка
  // char *str = "";
  //пустая строка символов
  // char *tk = ""
  tcase_add_test(tc_s21_strcspn, test_s21_strcspn_7);
  suite_add_tcase(suite, tc_s21_strcspn);

  return suite;
}