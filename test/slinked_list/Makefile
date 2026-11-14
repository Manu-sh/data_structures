# CC=tcc
#CFLAGS=-std=c89 -Ofast -pipe -ffast-math -Wall -Wextra -D_REENTRANT -Wno-unused-function -fstack-protector-all -fstack-protector-strong -funroll-loops -pedantic -Werror
#CFLAGS += -I ../../include/

CXXFLAGS=-std=c++11 -Ofast -pipe -ffast-math -Wall -Wextra -D_REENTRANT -Wno-unused-function -fstack-protector-all -fstack-protector-strong -funroll-loops -pedantic -Werror
CXXFLAGS += -I ../../include/

.PHONY: all clean test

test:
	# $(CC) $(CFLAGS) -o test_c test.c
	$(CXX) $(CXXFLAGS) -o test_cpp test.cpp
	./test_cpp

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o test_cpp test_c
