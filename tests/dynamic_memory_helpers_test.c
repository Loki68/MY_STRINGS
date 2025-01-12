#include "s21_check_string.h"

//  s21_size_t elements_count = 0;
START_TEST(test_TokenIndicesAndType_t_create_array_1) {
  s21_size_t elements_count = 0;
  TokenIndicesAndType_t *array = NULL;

  array = TokenIndicesAndType_t_create_array(elements_count);

  ck_assert_ptr_null(array);
}
END_TEST

//  s21_size_t elements_count != 0;
START_TEST(test_TokenIndicesAndType_t_create_array_2) {
  s21_size_t elements_count = 10;
  TokenIndicesAndType_t *array = NULL;

  array = TokenIndicesAndType_t_create_array(elements_count);

  ck_assert_ptr_nonnull(array);
  free(array);
}
END_TEST
//

//  TokenIndicesAndType_t *array = NULL;
START_TEST(test_TokenIndicesAndType_t_delete_array_1) {
  TokenIndicesAndType_t *array = NULL;

  TokenIndicesAndType_t_delete_array(array);

  ck_assert_ptr_null(array);
}
END_TEST

//  TokenIndicesAndType_t *array != NULL;
//  s21_size_t elements_count != 0;
START_TEST(test_TokenIndicesAndType_t_delete_array_2) {
  s21_size_t elements_count = 10;
  TokenIndicesAndType_t *array = NULL;
  array = TokenIndicesAndType_t_create_array(elements_count);

  TokenIndicesAndType_t_delete_array(array);

  // ck_abort();
  //  ck_assert_ptr_null(array);
}
END_TEST
//

//  s21_size_t elements_count = 0;
START_TEST(test_FormattedToken_t_create_array_1) {
  s21_size_t elements_count = 0;
  FormattedToken_t *array = NULL;

  array = FormattedToken_t_create_array(elements_count);

  ck_assert_ptr_null(array);
}
END_TEST

//  s21_size_t elements_count != 0;
START_TEST(test_FormattedToken_t_create_array_2) {
  s21_size_t elements_count = 10;
  FormattedToken_t *array = NULL;

  array = FormattedToken_t_create_array(elements_count);

  ck_assert_ptr_nonnull(array);
  free(array);
}
END_TEST

//  FormattedToken_t *array = NULL;
START_TEST(test_FormattedToken_t_delete_array_1) {
  FormattedToken_t *array = NULL;

  FormattedToken_t_delete_array(array);

  ck_assert_ptr_null(array);
}
END_TEST

//  FormattedToken_t *array != NULL;
//  s21_size_t elements_count != 0;
START_TEST(test_FormattedToken_t_delete_array_2) {
  s21_size_t elements_count = 10;
  FormattedToken_t *array = NULL;
  array = FormattedToken_t_create_array(elements_count);

  FormattedToken_t_delete_array(array);

  // ck_abort();
  //  ck_assert_ptr_null(array);
}
END_TEST

Suite *dynamic_memory_helpers_suite(void) {
  Suite *suite = NULL;
  TCase *tc_TokenIndicesAndType_t_create_array = NULL;
  TCase *tc_TokenIndicesAndType_t_delete_array = NULL;
  TCase *tc_FormattedToken_t_create_array = NULL;
  TCase *tc_FormattedToken_t_delete_array = NULL;

  suite = suite_create("dynamic_memory_helpers");

  tc_TokenIndicesAndType_t_create_array = tcase_create("TokenIndicesAndType_t");

  //  s21_size_t elements_count = 0;
  tcase_add_test(tc_TokenIndicesAndType_t_create_array,
                 test_TokenIndicesAndType_t_create_array_1);
  suite_add_tcase(suite, tc_TokenIndicesAndType_t_create_array);

  //  s21_size_t elements_count != 0;
  tcase_add_test(tc_TokenIndicesAndType_t_create_array,
                 test_TokenIndicesAndType_t_create_array_2);
  suite_add_tcase(suite, tc_TokenIndicesAndType_t_create_array);

  tc_TokenIndicesAndType_t_delete_array =
      tcase_create("TokenIndicesAndType_t_delete_array");

  //  TokenIndicesAndType_t *array = NULL;
  tcase_add_test(tc_TokenIndicesAndType_t_delete_array,
                 test_TokenIndicesAndType_t_delete_array_1);
  suite_add_tcase(suite, tc_TokenIndicesAndType_t_delete_array);

  //  TokenIndicesAndType_t *array != NULL;
  tcase_add_test(tc_TokenIndicesAndType_t_delete_array,
                 test_TokenIndicesAndType_t_delete_array_2);
  suite_add_tcase(suite, tc_TokenIndicesAndType_t_delete_array);

  tc_FormattedToken_t_create_array =
      tcase_create("FormattedToken_t_create_array");

  //  s21_size_t elements_count = 0;
  tcase_add_test(tc_FormattedToken_t_create_array,
                 test_FormattedToken_t_create_array_1);
  suite_add_tcase(suite, tc_FormattedToken_t_create_array);

  //  s21_size_t elements_count != 0;
  tcase_add_test(tc_FormattedToken_t_create_array,
                 test_FormattedToken_t_create_array_2);
  suite_add_tcase(suite, tc_FormattedToken_t_create_array);

  tc_FormattedToken_t_delete_array =
      tcase_create("FormattedToken_t_delete_array");

  //  s21_size_t elements_count = 0;
  tcase_add_test(tc_FormattedToken_t_delete_array,
                 test_FormattedToken_t_delete_array_1);
  suite_add_tcase(suite, tc_FormattedToken_t_delete_array);

  //  s21_size_t elements_count != 0;
  tcase_add_test(tc_FormattedToken_t_delete_array,
                 test_FormattedToken_t_delete_array_2);
  suite_add_tcase(suite, tc_FormattedToken_t_delete_array);
  return suite;
}