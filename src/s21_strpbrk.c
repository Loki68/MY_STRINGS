#include "s21_string.h"
char *s21_strpbrk(const char *str1, const char *str2) {
    int length_str2 = s21_strlen(str2);
    char* result = 0;
    for (int i = 0; i < length_str2; i++) {
        char* tmp = s21_strchr(str1, str2[i]);
        if (tmp != S21_NULL && (result == S21_NULL || tmp < result)) {
            result = tmp;
        }
    }
    if (result) {
        return result;
    } else {
        return S21_NULL;
    }    
}