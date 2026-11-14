#CC=gcc
#CC=tcc
CFLAGS=-std=c89 -Ofast -pipe -ffast-math -Wall -Wextra -D_REENTRANT -Wno-unused-function -fstack-protector-all -fstack-protector-strong -funroll-loops -pedantic -Werror
CFLAGS += -I ../../include/

#CXXFLAGS=-Ofast -pipe -ffast-math -Wall -Wextra -D_REENTRANT -Wno-unused-function -fstack-protector-all -fstack-protector-strong -funroll-loops -pedantic -Werror -march=native -mtune=native -funswitch-loops -ftree-vectorize -fivopts -fmodulo-sched -flto

# since std::vector function are templates and im compiling .o object the inline of cpp is unfair my function cant be inlined if i link as .o
CXXFLAGS=-std=c++14 -fno-inline -Ofast -pipe -ffast-math -Wall -Wextra -D_REENTRANT -Wno-unused-function -fstack-protector-all -fstack-protector-strong -funroll-loops -pedantic -Werror -march=native -mtune=native -funswitch-loops -ftree-vectorize -fivopts -fmodulo-sched
CXXFLAGS += -I ../../include/

#CXXFLAGS=-O0 -g -fno-inline
.PHONY: all clean test

all:
	$(CC) $(CFLAGS) -o test_c test.c
	$(CXX) $(CXXFLAGS) -o test_cpp test.cpp
	./test_c
	./test_cpp

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

test: all
	./test_c
	./test_cpp
	./single_blob

clean:
	rm -f *.o test single_blob test_c test_cpp
