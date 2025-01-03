LIBRARY = s21_string.a
CC = gcc
ARR = ar
RL = ranlib
#CFLAGS = -Wall -Wextra -Werror -std=c11
CFLAGS = -Wall -Wextra -std=c11
#site: https://cplusplus.com/reference/cstring/memcpy/
SOURCE = s21_strlen.c s21_memchr.c s21_memcmp.c s21_memcpy.c s21_memset.c s21_strncat.c s21_strchr.c s21_strncmp.c s21_strncpy.c sprintscan/s21_sprintf.c
OBJECTS = s21_strlen.o s21_memchr.o s21_memcmp.o s21_memcpy.o s21_memset.o s21_strncat.o s21_strchr.o s21_strncmp.o s21_strncpy.o s21_sprintf.o

all : clean s21_string.a

s21_string.a  : build_archieve
	$(RL) $(LIBRARY)

build_archieve: s21_strlen s21_memchr s21_memcmp s21_memcpy s21_memset s21_strncat s21_strchr s21_strncmp s21_strncpy s21_sprintf
	$(ARR) r $(LIBRARY) $(OBJECTS)

s21_memchr :
	$(CC) $(CFLAGS) -c s21_memchr.c -o s21_memchr.o

s21_memcmp :
	$(CC) $(CFLAGS) -c s21_memcmp.c -o s21_memcmp.o

s21_memcpy :
	$(CC) $(CFLAGS) -c s21_memcpy.c -o s21_memcpy.o

s21_memset :
	$(CC) $(CFLAGS) -c s21_memset.c -o s21_memset.o

s21_strncat :
	$(CC) $(CFLAGS) -c s21_strncat.c -o s21_strncat.o

s21_strlen :
	$(CC) $(CFLAGS) -c s21_strlen.c -o s21_strlen.o

s21_strchr : #doesn't work as should
	$(CC) $(CFLAGS) -c s21_strchr.c -o s21_strchr.o

s21_strncmp :
	$(CC) $(CFLAGS) -c s21_strncmp.c -o s21_strncmp.o

s21_strncpy :
	$(CC) $(CFLAGS) -c s21_strncpy.c -o s21_strncpy.o

s21_sprintf :
	$(CC) $(CFLAGS) -c sprintscan/s21_sprintf.c -o s21_sprintf.o

clean : 
	rm -rf $(OBJECTS) $(LIBRARY)