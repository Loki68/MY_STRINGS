#include "../s21_string.h"

#include <stdio.h>

typedef enum type{
    text,
    integer,
    string
}s21_token_type_t;

typedef struct token{
    s21_token_type_t type;
    //s21_size_t token_length;
    char buffer[256];
}s21_token_t;

void s21_sprintf_handle_text(const char *string,s21_size_t start_index, s21_size_t text_length,s21_token_t *text_token);
//bug with specificator% when %% shold handle this kind of works
s21_size_t s21_sprintf_handle_specifier(const char *format,s21_size_t fmt_index,s21_token_t *spec_token);
//start/end handler

void show_string_info(s21_token_t *tokens,int tokens_count,int parameters_count,const char* format);

//нужно обмазаться проверками на %, иначе начинается дичь
int s21_sprintf(char *str, const char *format, ...){
    s21_token_t tokens[1024]={};
    s21_token_t* current_token=S21_NULL;
    int tokens_count=0;
    int parameters_count=0;

    s21_size_t fmt_size=0;
    s21_size_t index=0;
    s21_size_t text_start_index=0;
    s21_size_t text_length=0;

    fmt_size=s21_strlen(format);

    for(;index<fmt_size;index++){
        if(!current_token)
            current_token=&tokens[tokens_count];

        if(format[index]=='%'){
            if(index || (format[index+1]=='%')){
                text_length=index-text_start_index;
                s21_sprintf_handle_text(format,text_start_index,text_length,current_token);
                tokens_count++;
                current_token=&tokens[tokens_count];
            }

            text_start_index=0;
        }

        if(!text_start_index)
            text_start_index=index;
        // if(format[index]=='%'){
        //     if(index && index>(text_start_index+1)){
        //         s21_sprintf_handle_text(format,text_start_index,index,current_token);
        //         tokens_count++;
        //         current_token=&tokens[tokens_count];
        //     }
            
        //     if(format[index+1]!='%'){
        //     index=s21_sprintf_handle_specifier(format,index,current_token);
        //     tokens_count++;
        //     parameters_count++;
        //     text_start_index=index;

        //     current_token=S21_NULL;}
        // }
    }

    // if(current_token){
    //     text_length=index-text_start_index;
    //     s21_sprintf_handle_text(format,text_start_index,text_length,current_token);
    //     tokens_count++;

    //     index=0;
    //     text_length=0;
    //     current_token=S21_NULL;
    // }

    show_string_info(tokens,tokens_count,parameters_count,format);

    return parameters_count;
}

void s21_sprintf_handle_text(const char *string,s21_size_t start_index, s21_size_t text_length,s21_token_t *text_token){
    s21_size_t index=0;

    index=start_index;
    text_token->type=text;
    for(;index<text_length;index++)
        text_token->buffer[index-start_index]=string[index];

    text_token->buffer[text_length]='\0';
}

s21_size_t s21_sprintf_handle_specifier(const char *format,s21_size_t fmt_index,s21_token_t *spec_token){
    int break_flag=0;
    s21_size_t start_index=0;
    int delta=0;

    start_index=++fmt_index;

    while(!break_flag && format[fmt_index]){
        
        switch(format[fmt_index]){
        case 's':
        spec_token->type=string;

        break_flag=1;
        break;
        case 'd':
        spec_token->type=integer;
        break_flag=1;
        break;
        }
        
        fmt_index++;    
    }

    delta=fmt_index-start_index;
    s21_strncat(spec_token->buffer,format+start_index,delta);

    return fmt_index;
}

void show_string_info(s21_token_t *tokens,int tokens_count,int parameters_count,const char* format){
    printf("Source string : %s\n",format);

    printf("String is : ");

    for(int i=0;i<tokens_count;i++)
                printf("$%s",tokens[i].buffer);
        
    putchar('\n');


    for(int i=0;i<tokens_count;i++){
        printf("\nToken type: ");
        switch(tokens[i].type){
            case text:
                printf("text\n");
            break;
            case integer:
                printf("integer\n");
            break;
            case string:
                printf("string\n");
            break;
        }
        
        for(s21_size_t index=0;tokens[i].buffer[index];index++)//возможно вылетит в сегфолт
            putchar(tokens[i].buffer[index]);
        
        putchar('\n');
    }

    printf("\nHandled parameters : %d\n",parameters_count);
}