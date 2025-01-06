#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n){
    s21_size_t dest_length=0;
    s21_size_t index=0;

    dest_length=s21_strlen(dest);

    for(;index<n;dest[index]=src[index],index++);

    //по справочнику этого быть не должно,а оно есть
    // if(index<dest_length)
    //     for(;index<dest_length;dest[index]='\0',index++);

    return dest;
}