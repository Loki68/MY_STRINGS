#include "s21_check_string.h"

//  char* str = "Hello world!";
//  char c = '\0';
//  size_t n = 0;
START_TEST(test_sprint_sscan_parser_1) {
  //   char *str = "Hello world!";
  //   char c = '\0';
  //   size_t n = 0;
  //   char *str_ptr = NULL;
  //   char *s21_str_ptr = NULL;

  //   str_ptr = memchr(str, c, n);
  //   s21_str_ptr = s21_memchr(str, c, n);

  //   ck_assert_ptr_eq(str_ptr, s21_str_ptr);
}
END_TEST
//

// n < 0 || &&c<0 => sega
Suite *sprint_sscan_parser_suite(void) {
  Suite *suite = NULL;
  TCase *tc_sprint_sscan_parser = NULL;

  suite = suite_create("sprint_sscan_parser");

  tc_sprint_sscan_parser = tcase_create("Sprint_sscan_parser");

  //  char* str = "Hello world!";
  //  char c = 'w';
  //  size_t n = 10;
  tcase_add_test(tc_sprint_sscan_parser, test_sprint_sscan_parser_1);
  suite_add_tcase(suite, tc_sprint_sscan_parser);

  return suite;
}