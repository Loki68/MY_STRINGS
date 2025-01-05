#include "s21_check_string.h" 

int main(void){
    int number_failed=0;
    //Suite *suite=NULL;
    SRunner *srunner=NULL;

    //suite = s21_strlen_suite();
    //srunner = srunner_create(suite);
    srunner = srunner_create(s21_memchr_suite());
    srunner_add_suite (srunner, s21_memcmp_suite());

    srunner_add_suite (srunner, s21_strlen_suite());

    srunner_run_all(srunner, CK_NORMAL);
    number_failed = srunner_ntests_failed(srunner);
    srunner_free(srunner);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}