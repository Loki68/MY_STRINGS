# Makefile  находится в папке src, пожтому все другие пути к файлам и папкам указаны
# относительно папки src.
# Ребят, это не догма,все пути можно менять. просто я у себя расположил так, а дальше менять было лень)

#Настройки сборки библиотеки
LIBRARY = s21_string.a
CC = gcc
# Следующие две строки можно заменить одной ARR_S = ar -rcs.
# Без флага s ar создает просто архив объектных файлов. 
# Этот флаг (s) или использование ranlib индексирует содержимое архива 
# и превращает его уже в библиотеку.
# Без индексации, архив объектных файлов будет тоже работать,
# но это будет заготовкой под библиотеку,а не библиотекой.
# Вот ссылка на туториал по либам в си:
# https://younglinux.info/c/library
ARR = ar
RL = ranlib
# Закомментирована строка с превращением предупреждений в ошибки.
# Раскомментируется ближе к sprintf потому что заготовка есть,но она еще пустая,
# и компилятор ругается на неиспользуемые параметры
#CFLAGS = -Wall -Wextra -Werror -std=c11
CFLAGS = -Wall -Wextra -std=c11
SOURCE = s21_strlen.c s21_memchr.c s21_memcmp.c s21_memcpy.c s21_memset.c s21_strncat.c s21_strchr.c s21_strncmp.c s21_strncpy.c s21_strrchr.c s21_strpbrk.c s21_strstr.c s21_strcspn.c sprintscan/s21_sprintf.c
OBJECTS = s21_strlen.o s21_memchr.o s21_memcmp.o s21_memcpy.o s21_memset.o s21_strncat.o s21_strchr.o s21_strncmp.o s21_strncpy.o s21_strrchr.o s21_strpbrk.o s21_strstr.o s21_strcspn.o s21_sprintf.o
# Это флаги для подключения уже собранной библиотеки к тестовому проекту
# Их можно было добавить в стандартную переменную LDFLAGS, но я подумал,что так нагляднее
# Потому что библиотек оч много подключать в этом задании 
LIB = -L. -l:s21_string.a
#конец настроек сборки библиотеки

#Настройки для тестирования с помощью библиотеки check
# Сама документация:
# https://libcheck.github.io/check/doc/check_html/check_toc.html#SEC_Contents
# Начинать ее читать стоит с 3 и 4 пунктов. Там именно что:
# написание простого теста
# и множественных тестов
# На моем компе папка tests находится на одном уровне с папкой src
# И все, что связано с самими тестами находится в папке tests
TESTS_DIR = ../tests
# Собственно конечный тестовый файл
TEST_PROGRAM = $(TESTS_DIR)/s21_check_string
# Переменная для файлов исходного кода тестов
TESTS = $(TESTS_DIR)/s21_check_string.c $(TESTS_DIR)/s21_memchr_test.c $(TESTS_DIR)/s21_memcmp_test.c $(TESTS_DIR)/s21_memcpy_test.c $(TESTS_DIR)/s21_memset_test.c $(TESTS_DIR)/s21_strchr_test.c $(TESTS_DIR)/s21_strlen_test.c $(TESTS_DIR)/s21_strncat_test.c $(TESTS_DIR)/s21_strncmp_test.c $(TESTS_DIR)/s21_strncpy_test.c $(TESTS_DIR)/s21_strpbrk_test.c $(TESTS_DIR)/s21_strrchr_test.c $(TESTS_DIR)/s21_strstr_test.c $(TESTS_DIR)/s21_strcspn_test.c $(TESTS_DIR)/s21_sprintf_test.c
# Переменная для объектных файлов
TESTS_OBJECTS = $(TESTS_DIR)/s21_check_string.o $(TESTS_DIR)/s21_memchr_test.o $(TESTS_DIR)/s21_memcmp_test.o $(TESTS_DIR)/s21_memcpy_test.o $(TESTS_DIR)/s21_memset_test.o $(TESTS_DIR)/s21_strchr_test.o $(TESTS_DIR)/s21_strlen_test.o $(TESTS_DIR)/s21_strncat_test.o $(TESTS_DIR)/s21_strncmp_test.o $(TESTS_DIR)/s21_strncpy_test.o $(TESTS_DIR)/s21_strpbrk_test.o $(TESTS_DIR)/s21_strrchr_test.o $(TESTS_DIR)/s21_strstr_test.o $(TESTS_DIR)/s21_strcspn_test.o $(TESTS_DIR)/s21_sprintf_test.o
# Самая интересная часть. здесь указаны флаги для сборки только на линуксе.
# С этим связан нюанс. на маке достаточно -lcheck, но наличие их всех не вызывает никаких проблем вовсе.
# По итогу, просто обернем это в if с выбором системы и все.
# -pthread тоже можно добавить 
TEST_FLAGS = -lcheck -lrt -lm -lsubunit 
#конец настроек тестов с помощью библиотеки check

#Настройки для сборки отчета gcov_report
# Флаги для сбора инфы о покрытии тестами
# На деле, эти оба двое можно заменить одним:
# GCOV_FLAGS = --coverage
# И он один будет работать ровно так же.
# Хорошая и доступная статья по теме:
# "для чего вообще нужны вместе gcov, lcov/geninfo, genhtml, и какие флаги сегодня в меню"
# https://ps-group.github.io/cxx/coverage_gcc
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
#
GCOV_RESULT = s21_check_string.c.gcov $(TESTS_DIR)/*.gcno $(TESTS_DIR)/*.gcda
GCOV_REPORT_DIR = ../gcov_report
#конец настроек для сборки отчета gcov_report

#Настройки для lcov
# как раз флаги для учета покрытия ветвлений тестами
# чтобы в отчете было и покрытие ветвлений, нужно запускать и lcov и genhtml с этими флагами
BRANCHES = --rc lcov_branch_coverage=1
#конец настроек для lcov

all : format_project s21_string.a test gcov_report

#Стадия сборки библиотеки - s21_string.a
# Индексируем архив с помощью ranlib
s21_string.a  : build_archieve
	$(RL) $(LIBRARY)

# Собираем архив из объектных файлов с помощью ar
build_archieve: s21_strlen s21_memchr s21_memcmp s21_memcpy s21_memset s21_strncat s21_strchr s21_strncmp s21_strncpy s21_strrchr s21_strpbrk s21_strstr s21_strpbrk s21_strcspn s21_sprintf
	$(ARR) r $(LIBRARY) $(OBJECTS)
# Пробегаемся по всем нужным функциям
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

s21_strpbrk :
	$(CC) $(CFLAGS) -c s21_strpbrk.c -o s21_strpbrk.o

s21_strrchr :
	$(CC) $(CFLAGS) -c s21_strrchr.c -o s21_strrchr.o

s21_strstr :
	$(CC) $(CFLAGS) -c s21_strstr.c -o s21_strstr.o

s21_strcspn :
	$(CC) $(CFLAGS) -c s21_strcspn.c -o s21_strcspn.o



s21_sprintf :
	$(CC) $(CFLAGS) -c sprintscan/s21_sprintf.c -o s21_sprintf.o

#конец стадии s21_string.a

#Стадии для сборки самих тестов
# такая же скучнота, как и для самой библиотеки, 
# разница только в том, что мы собираем вместе с библиотекой check 
test : build_tests test_program 
	$(TEST_PROGRAM)
	
test_program : s21_string.a build_tests s21_memchr_tests s21_memcmp_tests s21_memcpy_tests s21_memset_tests s21_strchr_tests s21_strlen_tests s21_strncat_tests s21_strncmp_tests s21_strncpy_tests s21_strpbrk_tests s21_strrchr_tests s21_strstr_tests s21_strcspn_tests s21_sprintf_tests
	$(CC) $(TESTS_OBJECTS) -o $(TEST_PROGRAM) $(LIB) $(TEST_FLAGS) 

build_tests :
	$(CC) $(CFLAGS) -c $(TESTS_DIR)/s21_check_string.c -o $(TESTS_DIR)/s21_check_string.o

s21_memchr_tests :
	$(CC) $(CFLAGS) -c $(TESTS_DIR)/s21_memchr_test.c -o $(TESTS_DIR)/s21_memchr_test.o

s21_memcmp_tests :
	$(CC) $(CFLAGS) -c $(TESTS_DIR)/s21_memcmp_test.c -o $(TESTS_DIR)/s21_memcmp_test.o

s21_memcpy_tests :
	$(CC) $(CFLAGS) -c $(TESTS_DIR)/s21_memcpy_test.c -o $(TESTS_DIR)/s21_memcpy_test.o

s21_memset_tests :
	$(CC) $(CFLAGS) -c $(TESTS_DIR)/s21_memset_test.c -o $(TESTS_DIR)/s21_memset_test.o

s21_strchr_tests :
	$(CC) $(CFLAGS) -c  $(TESTS_DIR)/s21_strchr_test.c -o $(TESTS_DIR)/s21_strchr_test.o

s21_strlen_tests :
	$(CC) $(CFLAGS) -c $(TESTS_DIR)/s21_strlen_test.c -o $(TESTS_DIR)/s21_strlen_test.o

s21_strncat_tests :
	$(CC) $(CFLAGS) -c $(TESTS_DIR)/s21_strncat_test.c -o $(TESTS_DIR)/s21_strncat_test.o 

s21_strncmp_tests :
	$(CC) $(CFLAGS) -c $(TESTS_DIR)/s21_strncmp_test.c -o $(TESTS_DIR)/s21_strncmp_test.o

s21_strncpy_tests :
	$(CC) $(CFLAGS) -c $(TESTS_DIR)/s21_strncpy_test.c -o $(TESTS_DIR)/s21_strncpy_test.o

s21_strpbrk_tests :
	$(CC) $(CFLAGS) -c $(TESTS_DIR)/s21_strpbrk_test.c -o $(TESTS_DIR)/s21_strpbrk_test.o

s21_strstr_tests :
	$(CC) $(CFLAGS) -c $(TESTS_DIR)/s21_strstr_test.c -o $(TESTS_DIR)/s21_strstr_test.o

s21_strrchr_tests :
	$(CC) $(CFLAGS) -c $(TESTS_DIR)/s21_strrchr_test.c -o $(TESTS_DIR)/s21_strrchr_test.o

s21_strcspn_tests :
	$(CC) $(CFLAGS) -c $(TESTS_DIR)/s21_strcspn_test.c -o $(TESTS_DIR)/s21_strcspn_test.o





s21_sprintf_tests :
	$(CC) $(CFLAGS) -c $(TESTS_DIR)/s21_sprintf_test.c -o $(TESTS_DIR)/s21_sprintf_test.o
#end of Test stages

#Стадия построения отчета о покрытии кода тестами - gcov_report
# Напоминаю, что подробности по ссылке:
# https://ps-group.github.io/cxx/coverage_gcc
gcov_report :
# В соответствии с требованием создания отчета, собираем:
# из файлов исходного кода функций нашей библиотеки $(SOURCE)
# из файлов исходного кода тестов $(TESTS)
# используя общие флаги $(CFLAGS)
# используя тестовые флаги для сборки с библиотекой check $(TEST_FLAGS)
# используя флаги для подсчета покрытия через gcov $(GCOV_FLAGS)
# исполняемый файл для составления отчета gcov $(TEST_PROGRAM)
# исполняемый файл тот же,что и просто в тестах. Просто собран иначе.
	$(CC) $(CFLAGS) $(TESTS) $(SOURCE) -o $(TEST_PROGRAM) $(TEST_FLAGS) $(GCOV_FLAGS)
# Требование gcov - запустить получившегося франкенштейна
	$(TEST_PROGRAM)
# Создаем папку для хранения отчета
	mkdir -p $(GCOV_REPORT_DIR)
# Собственно получаем файл с отчетом с учетом ветвлений - флаги $(BRANCHES)
	lcov -t "Report" -c -d $(TESTS_DIR) -o $(GCOV_REPORT_DIR)/coverage.info $(BRANCHES)
# и генерируем на основе файла с отчетом html разметку
	genhtml -o $(GCOV_REPORT_DIR)/html $(GCOV_REPORT_DIR)/coverage.info $(BRANCHES)
#конец стадии gcov_report

#Стадия очистки от объектных,исполняемых файлов, а так же промежуточных файлов gcov - clean 
clean : 
# Чистим объектные файлы функций и файл библиотеки
	rm -rf $(OBJECTS) $(LIBRARY) 
# Чистим объектные файлы тестов и исполняемый файл
	rm -rf $(TESTS_OBJECTS) $(TEST_PROGRAM)
# Чистим файлы, сгенерированные gcov/lcov/genhtml и удаляем папку с вебмордой ака html
	rm -rf $(GCOV_RESULT) $(GCOV_REPORT_DIR)
#конец стадии clean

scan_project_on_format:
	clang-format -n *.c *.h $(TESTS_DIR)/*.c $(TESTS_DIR)/*.h

format_project:
	clang-format -i *.c *.h $(TESTS_DIR)/*.c $(TESTS_DIR)/*.h

#Стадия пересборки
# создана чисто для удобства
rebuild : clean all
#конец стадии пересборки