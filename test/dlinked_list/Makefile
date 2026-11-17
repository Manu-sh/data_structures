ASAN_FLAGS=-fsanitize=address,undefined,null,alignment,leak,pointer-compare,pointer-subtract,unreachable

CFLAGS=-std=c89 -O0 -pipe -Wall -Wextra -Werror -D_REENTRANT -Wno-unused-function -pedantic -fstack-protector-all -fstack-protector-strong -fno-builtin-memcpy -g3 -fno-omit-frame-pointer -ftrapv #-fno-strict-aliasing
CFLAGS += -I ../../include/

VALGRIND= valgrind --undef-value-errors=no --tool=memcheck --leak-check=full --show-reachable=yes --num-callers=20 --track-fds=yes -s

.PHONY: all clean

all:
	$(CC) $(CFLAGS) -o test_c test.c
	$(CC) $(CFLAGS) $(ASAN_FLAGS) -o test_c_asan test.c

	./test_c_asan
	$(VALGRIND) ./test_c

clean:
	rm -rf test_c test_c_asan
