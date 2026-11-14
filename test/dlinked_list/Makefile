# CC=clang
# CC=tcc
CFLAGS=-std=c89 -Ofast -pipe -ffast-math -Wall -Wextra -D_REENTRANT -Wno-unused-function -fstack-protector-all -fstack-protector-strong -funroll-loops -pedantic
CFLAGS += -I ../../include/

.PHONY: all clean test

test:
	$(CC) $(CFLAGS) -o test_c test.c
	./test_c

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o test_c
