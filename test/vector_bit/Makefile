CXXFLAGS=-std=c++11 -O0 -pipe -Wall -Wextra -Werror -D_REENTRANT -Wno-unused-function -pedantic -fstack-protector-all -fstack-protector-strong -fno-builtin-memcpy -g3 -fno-omit-frame-pointer -ftrapv #-fno-strict-aliasing
CXXFLAGS += -I ../../include/

ASAN_FLAGS=-fsanitize=address,undefined,null,alignment,leak,pointer-compare,pointer-subtract,unreachable

CFLAGS=-std=c99 -O0 -pipe -Wall -Wextra -Werror -D_REENTRANT -Wno-unused-function -pedantic -fstack-protector-all -fstack-protector-strong -fno-builtin-memcpy -g3 -fno-omit-frame-pointer -ftrapv #-fno-strict-aliasing
CFLAGS += -I ../../include/

VALGRIND= valgrind --undef-value-errors=no --tool=memcheck --leak-check=full --show-reachable=yes --num-callers=20 --track-fds=yes -s

.PHONY: all clean

all:
	$(CC) $(CFLAGS) -o test_c test.c
	$(CC) $(CFLAGS) $(ASAN_FLAGS) -o test_c_asan test.c

	$(CXX) $(CXXFLAGS) -o test_cpp test.cpp
	$(CXX) $(CXXFLAGS) $(ASAN_FLAGS) -o test_cpp_asan test.cpp

	./test_cpp_asan
	./test_c_asan

	$(VALGRIND) ./test_cpp
	$(VALGRIND) ./test_c

build_benchmark:
	$(CC) -I ../../include/ -std=c99 -Ofast -ffast-math -funroll-loops -march=native -mtune=native -funswitch-loops -ftree-vectorize -fivopts -fmodulo-sched -flto -pipe -Wall -Wextra -Wno-unused-function -pedantic -fno-builtin-memcpy benchmark.c -o benchmark -g3 # -DDEBUG

benchmark: build_benchmark
	time ./benchmark

clean:
	rm -rf test_c test_c_asan test_cpp test_cpp_asan benchmark
