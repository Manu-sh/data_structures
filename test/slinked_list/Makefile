ASAN_FLAGS=-fsanitize=address,undefined,null,alignment,leak,pointer-compare,pointer-subtract,unreachable

CXXFLAGS=-std=c++14 -O0 -pipe -Wall -Wextra -Werror -D_REENTRANT -Wno-unused-function -pedantic -fstack-protector-all -fstack-protector-strong -fno-builtin-memcpy -g3 -fno-omit-frame-pointer -ftrapv #-fno-strict-aliasing
CXXFLAGS += -I ../../include/

VALGRIND= valgrind --undef-value-errors=no --tool=memcheck --leak-check=full --show-reachable=yes --num-callers=20 --track-fds=yes -s

.PHONY: all clean

all:
	$(CXX) $(CXXFLAGS) -o test_cpp test.cpp
	$(CXX) $(CXXFLAGS) $(ASAN_FLAGS) -o test_cpp_asan test.cpp

	./test_cpp_asan
	$(VALGRIND) ./test_cpp

clean:
	rm -f test_cpp test_cpp_asan
