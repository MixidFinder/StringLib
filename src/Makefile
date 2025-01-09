GCC=gcc -Wall -Wextra -std=c11 -Werror
CF=clang-format -i
CPP=cppcheck --enable=all --suppress=missingIncludeSystem
T1=s21_string
Docker=../materials/build/run.sh
MAKEFLAGS += -ik

all: $(T1).a

$(T1).a: clangF
	$(GCC) -c $(T1).c -o $(T1).o
	$(GCC) -c s21_sscanf.c -o s21_sscanf.o
	$(GCC) -c s21_sprintf.c -o s21_sprintf.o
	$(GCC) -c s21_strerror.c -o s21_strerror.o
	ar rcs $(T1).a $(T1).o s21_sprintf.o s21_sscanf.o s21_strerror.o

test: clean $(T1).a
	$(GCC) -fprofile-arcs -ftest-coverage -o tests/$(T1)_tests tests/$(T1)_tests.c $(T1).c s21_sprintf.c -lcheck -lm -lsubunit
	./tests/$(T1)_tests || true
	$(GCC) -fprofile-arcs -ftest-coverage -o tests/s21_sscanf_tests tests/s21_sscanf_tests.c s21_sscanf.c s21_sprintf.c $(T1).c -lcheck -lm -lsubunit
	./tests/s21_sscanf_tests || true
	$(GCC) -fprofile-arcs -ftest-coverage -o tests/s21_sprintf_tests tests/s21_sprintf_tests.c s21_sprintf.c $(T1).c -lcheck -lm -lsubunit
	./tests/s21_sprintf_tests || true

gcov_report: test
	gcov -b tests/$(T1)_tests-$(T1).c
	gcov -b tests/s21_sscanf_tests-s21_sscanf.c
	gcov -b tests/s21_sprintf_tests-s21_sprintf.c
	lcov -c -d . -o coverage.info
	genhtml coverage.info -o coverage_report

v1: clean $(T1).a
	$(GCC) -fprofile-arcs -ftest-coverage -o tests/$(T1)_tests tests/$(T1)_tests.c $(T1).c s21_sprintf.c -lcheck -lm -lsubunit
	valgrind -q --tool=memcheck --leak-check=full ./tests/$(T1)_tests
	$(GCC) -fprofile-arcs -ftest-coverage -o tests/s21_sscanf_tests tests/s21_sscanf_tests.c s21_sscanf.c s21_sprintf.c $(T1).c -lcheck -lm -lsubunit
	valgrind -q --tool=memcheck --leak-check=full ./tests/s21_sscanf_tests
	$(GCC) -fprofile-arcs -ftest-coverage -o tests/s21_sprintf_tests tests/s21_sprintf_tests.c s21_sprintf.c $(T1).c -lcheck -lm -lsubunit
	valgrind -q --tool=memcheck --leak-check=full ./tests/s21_sprintf_tests

DOCKER:
	chmod 777 $(Docker)
	./$(Docker)

CPP:
	$(CPP) *.c
	$(CPP) *.h

clangF:
	$(CF) *.c
	$(CF) *.h
	$(CF) tests/*.c

push:
	git checkout develop
	git add *.c
	git add *.h
	git add *.sh
	git add Makefile
	git commit -m 'Quests'
	git push origin develop

clean:
	rm -f $(T1)
	rm -f $(T1)_tests
	rm -rf *.o
	rm -rf *.a
	rm -rf *.out
	rm -f tests/$(T1)_tests
	rm -f tests/s21_sprintf_tests
	rm -f tests/s21_sscanf_tests
	rm -rf tests/*.gcda
	rm -rf tests/*.gcno
	rm -rf *.info
	rm -rf *.gcov
	rm -rf *.gcda
	rm -rf coverage_report
#  rm -rf ../build/*_*

rebuild: clean all
