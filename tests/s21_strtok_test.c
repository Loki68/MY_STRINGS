#include "s21_check_string.h"

//параметры
START_TEST(test_s21_strtok_1) {
  //подготовка
  char string_s21[] = "AAASEGSEGESEGESEGDDDDDSS";
  char string[] = "AAASEGSEGESEGESEGDDDDDSS";
  char *tok = S21_NULL;
  char *tok_s21 = S21_NULL;

  //действие или вызов функций
  tok_s21 = s21_strtok(string_s21, "S");
  tok = strtok(string, "S");

  //проверка утверждения ака сравнение с эталоном. Сегу не проверяй,но, если
  //разберешься как ее ловить чеком, можешь
  ck_assert_str_eq(tok_s21, tok);
  free(tok_s21);
}
END_TEST

START_TEST(test_s21_strtok_2) {
  //подготовка
  char string_s21[] = "AAASEGSEGESEGESEGDDDDDSS";
  char string[] = "AAASEGSEGESEGESEGDDDDDSS";
  char *tok = S21_NULL;
  char *tok_s21 = S21_NULL;

  tok_s21 = s21_strtok(string_s21, "S");
  tok = strtok(string, "S");

  //действие или вызов функций
  while (tok != S21_NULL && tok_s21 != S21_NULL) {
    if (tok_s21) {
      tok_s21 = s21_strtok(S21_NULL, "S");
    }
    if (tok) {
      tok = strtok(S21_NULL, "S");
    }
  }
  ck_assert((tok == S21_NULL) && (tok_s21 == S21_NULL));

  //проверка утверждения ака сравнение с эталоном. Сегу не проверяй,но, если
  //разберешься как ее ловить чеком, можешь
}
END_TEST

START_TEST(test_s21_strtok_3) {
  //подготовка
  char string_s21[] = "AAASEGSEGESEGESEGDDDDDSS";
  char string[] = "AAASEGSEGESEGESEGDDDDDSS";
  char *tok = S21_NULL;
  char *tok_s21 = S21_NULL;

  //действие или вызов функций
  tok_s21 = s21_strtok(string_s21, "\0");
  tok = strtok(string, "\0");

  //проверка утверждения ака сравнение с эталоном. Сегу не проверяй,но, если
  //разберешься как ее ловить чеком, можешь
  ck_assert_str_eq(tok_s21, tok);
}
END_TEST

START_TEST(test_s21_strtok_4) {
  //подготовка
  char string_s21[] = "AAASEGSEGESEGESEGDDDDDSS";
  char string[] = "AAASEGSEGESEGESEGDDDDDSS";
  char *tok = S21_NULL;
  char *tok_s21 = S21_NULL;
  int i = 0;

  tok_s21 = s21_strtok(string_s21, "\0");
  tok = strtok(string, "\0");

  //действие или вызов функций
  while (i != 2) {
    if (tok_s21) {
      tok_s21 = s21_strtok(S21_NULL, "\0");
    }
    if (tok) {
      tok = strtok(S21_NULL, "\0");
    }
    i++;
  }
  ck_assert((tok == S21_NULL) && (tok_s21 == S21_NULL));

  //проверка утверждения ака сравнение с эталоном. Сегу не проверяй,но, если
  //разберешься как ее ловить чеком, можешь
}
END_TEST

START_TEST(test_s21_strtok_5) {
  //подготовка
  char string_s21[] = "AAASEGSEGESEGESEGDDDDDSS";
  char string[] = "AAASEGSEGESEGESEGDDDDDSS";
  char *tok = S21_NULL;
  char *tok_s21 = S21_NULL;
  int i = 0;

  tok_s21 = s21_strtok(string_s21, "S");
  tok = strtok(string, "S");

  //действие или вызов функций
  while (i != 1) {
    tok_s21 = s21_strtok(S21_NULL, "SEG");
    tok = strtok(S21_NULL, "SEG");
    i++;
  }

  ck_assert_str_eq(tok_s21, tok);

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

  tcase_add_test(tc_s21_strtok, test_s21_strtok_2);
  suite_add_tcase(suite, tc_s21_strtok);

  tcase_add_test(tc_s21_strtok, test_s21_strtok_3);
  suite_add_tcase(suite, tc_s21_strtok);

  tcase_add_test(tc_s21_strtok, test_s21_strtok_4);
  suite_add_tcase(suite, tc_s21_strtok);

  tcase_add_test(tc_s21_strtok, test_s21_strtok_5);
  suite_add_tcase(suite, tc_s21_strtok);

  return suite;
}