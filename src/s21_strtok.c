#include "s21_string.h"
#include <stdlib.h>
#include <stdio.h>

char *s21_strtok(char* str,const char* delim){
    static char* out = S21_NULL;
    if(str != S21_NULL){
        out = str;
    }
    char* buffer =  S21_NULL;
       int letters = 0;
        buffer = malloc(s21_strlen(out));
        int plusDelimer = 0;
        s21_memset(buffer,'\0',sizeof(*out));
        int lenOfToken = 0;
        for(int i = 0; out[i]!='\0';i++){
            int counter = 0;
            for(int j = 0; delim[j]!='\0';j++){
                if(out[i] == '\0'){
                    break;
                }
                if (delim[j] != out[i]){
                    counter+=1;
                }
            }
            if(counter == (int)s21_strlen(delim)){
                lenOfToken+=1;
                letters += 1;
            }
            else{
                if(lenOfToken != 0){
                    break;
                }
                out[i] = '\0';
                plusDelimer += 1;
            }
        }
        out += plusDelimer;
        if(lenOfToken != 0){
        for(int i = 0;i != lenOfToken;i++){
            buffer[i] = out[i];
        }
        }
        else{
            buffer = S21_NULL;
        }
        out += letters;
    return buffer;
}