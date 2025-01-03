#ifndef S21_STRING_H_INCLUDED
#define S21_STRING_H_INCLUDED
#define S21_NULL 0 //Оч спорно

typedef unsigned long int s21_size_t;
// TODO

void *s21_memchr(const void *str, int c, s21_size_t n); // done but not equal
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n); // works better then
                                                  // s21_memchr
char *s21_strncat(char *dest, const char *src, s21_size_t n);

char *s21_strchr(const char *str, int c);

int s21_strncmp(const char *str1, const char *str2, s21_size_t n);

char *s21_strncpy(char *dest, const char *src, s21_size_t n);

s21_size_t strcspn(const char *str1, const char *str2);
s21_size_t s21_strlen(const char *str);
char *strpbrk(const char *str1, const char *str2);
char *strrchr(const char *str, int c);
char *strstr(const char *haystack, const char *needle);
char *strtok(char *str, const char *delim);

char *strerror(int errnum);

int s21_sprintf(char *str, const char *format, ...);
#endif