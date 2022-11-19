WWW = -Wall -Wextra -Werror

all: clean test

re: clean all 

test: s21_string.a clean_obj
	gcc $(WWW) -l check unit_tests.c s21_string.a -o s21_test
	./s21_test

gcov_report: gcov_report_build
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info

gcov_report_build:
	gcc $(WWW) --coverage -l check unit_tests.c s21_string.c -o gcov_report
	./gcov_report
	lcov -t "./gcov_report" -o gcov_report.info -c -d .
	genhtml -o report gcov_report.info

s21_string.a: build_s21_string clean_obj

build_s21_string:
	gcc $(WWW) -c s21_string.c
	ar rc s21_string.a *.o

install_brew:
	cd ~
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
	brew install lcov

clean_obj:
	@(rm -rf *.o)

clean_lib:
	@(rm -rf *.a)

clean_test:
	@(rm -rf *.gcda)
	@(rm -rf *.gcno)
	@(rm -rf *.info)
	@(rm -rf gcov_report)
	@(rm -rf report)

clean: clean_lib clean_lib clean_test clean_obj
	@(rm -rf s21_test)
