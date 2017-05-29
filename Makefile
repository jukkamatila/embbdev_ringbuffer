# make  - to compile normal run
# make test - to compile for unit testing 

#use this if googletest locally installed
ifndef LOCAL
GTEST_DIR=~/googletest/googletest
GTEST_INCLUDE=-I $(GTEST_DIR)/include
GTEST_LIB=libgtest.a
else
GTEST_DIR=
GTEST_INCLUDE=
GTEST_LIB=-lgtest
endif


COPTS=-Wall -fprofile-arcs -ftest-coverage
LDFLAGS=-fprofile-arcs -ftest-coverage
COV_OUTPUT=./cov_output

PROJ=functions

######### Main targets ##########
main: main.o $(PROJ).o
	gcc main.o $(PROJ).o -o main $(LDFLAGS)

test: Gtest_main.o testcase.o $(PROJ)_test.o libgtest.a   ## REMARK: remove libgtest.a
	g++  $(LDFLAGS) -pthread $(PROJ)_test.o testcase.o Gtest_main.o $(GTEST_LIB) -o test

########## Normal ###########

$(PROJ).o: $(PROJ).c
	gcc  -c $(PROJ).c

main.o: main.c include.h
	gcc -c main.c

########## Unit test ########

Gtest_main.o: Gtest_main.c
	g++ -c Gtest_main.c $(GTEST_INCLUDE)

$(PROJ)_test.o: $(PROJ).c
	g++  -c $(PROJ).c -o $(PROJ)_test.o

testcase.o: testcase.c
	g++ -c $(COPTS) testcase.c

########## Google Test framework ############
libgtest.a:
	g++ -isystem $(GTEST_DIR)/include -I $(GTEST_DIR) -pthread -c $(GTEST_DIR)/src/gtest-all.cc
	ar -rv libgtest.a gtest-all.o

########### Coverage analysis ############

report:

	lcov -rc lcov_branch_coverage=1 -c -i -d . -o .coverage.base
	lcov -rc lcov_branch_coverage=1 -c -d . -o .coverage.run
	lcov -rc lcov_branch_coverage=1 -d . -a .coverage.base -a .coverage.run -o .coverage.total
	genhtml --branch-coverage -o $(COV_OUTPUT) .coverage.total
	rm -f .coverage.base .coverage.run .coverage.total

clean:
	rm -f *.o test $(GTEST_LIB)
