#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n){
    
    for(s21_size_t i=0;i<n && *(dest+i);*(dest+i)=*(src+i),i++);
    return dest;
}