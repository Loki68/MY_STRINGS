#include "../src/s21_string.h"

#include <stdio.h>
//необходима тому же check.h, чтобы взять тот же пустой указатель NULL
#include <stdlib.h>
//собственно подключение библиотеки для тестирования
#include <check.h>
//ну  эталонная реализация, с которой сравнивать наши реализации функций
#include <string.h>

//чтобы добавить новый набор тестов, нужно просто добавить аналогичную строку
//ниже:
//  Suite *подходящее_название(void);
//а в файле название_тестируемой_функции.c добавить такую же шаблонную
//реализацию
Suite *s21_memchr_suite(void);
Suite *s21_memcmp_suite(void);
Suite *s21_memcpy_suite(void);
Suite *s21_memset_suite(void);
Suite *s21_strchr_suite(void);
Suite *s21_strlen_suite(void);
Suite *s21_strncat_suite(void);
Suite *s21_strncmp_suite(void);
Suite *s21_strncpy_suite(void);
Suite *s21_strpbrk_suite(void);
Suite *s21_strrchr_suite(void);
Suite *s21_strstr_suite(void);
Suite *s21_strcspn_suite(void);
Suite *s21_strtok_suite(void);
Suite *s21_strerror_suite(void);