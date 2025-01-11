#include "s21_check_string.h"

//параметры
START_TEST(test_s21_strerror_1) {
  //подготовка

  //действие или вызов функций

  //проверка утверждения ака сравнение с эталоном. Сегу не проверяй,но, если
  //разберешься как ее ловить чеком, можешь
}
END_TEST

// const string or null ptr => sega
//выход за границы => sega
Suite *s21_strerror_suite(void) {
  Suite *suite;
  TCase *tc_s21_strerror;

  suite = suite_create("s21_strerror");

  tc_s21_strerror = tcase_create("S21_strerror");

  //по шаблону для каждого теста копипасти и меняй ток номер теста типа
  // test_s21_strerror_2,test_s21_strerror_3 и т.д.
  tcase_add_test(tc_s21_strerror, test_s21_strerror_1);
  suite_add_tcase(suite, tc_s21_strerror);

  return suite;
}