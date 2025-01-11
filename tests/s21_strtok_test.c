#include "s21_check_string.h"

//параметры
START_TEST(test_s21_strtok_1) {
  //подготовка

  //действие или вызов функций

  //проверка утверждения ака сравнение с эталоном. Сегу не проверяй,но, если
  //разберешься как ее ловить чеком, можешь
}
END_TEST

// const string or null ptr => sega
//выход за границы => sega
Suite *s21_strtok_suite(void) {
  Suite *suite;
  TCase *tc_s21_strtok;

  suite = suite_create("s21_strtok");

  tc_s21_strtok = tcase_create("S21_strtok");

  //по шаблону для каждого теста копипасти и меняй ток номер теста типа
  // test_s21_strtok_2бtest_s21_strtok_3 и т.д.
  tcase_add_test(tc_s21_strtok, test_s21_strtok_1);
  suite_add_tcase(suite, tc_s21_strtok);

  return suite;
}