INCLUDE_FLAGS = -Iinclude -Iinclude/utils 
DEBUG_FLAGS = -fsanitize=address -g

# Library

lib: lib-compile
	gcc -shared -o lib/libmathlib.so lib/mathlib.o 

lib-compile: dir-lib
	gcc -c -fPIC -o lib/mathlib.o $(INCLUDE_FLAGS) src/mathlib.c  

# Tests

test: test-c test-cpp

test-c: c-bin
	./debug/test_c

test-cpp: cpp-bin
	./debug/test_cpp

c-bin: dir-debug
	gcc -o debug/test_c $(INCLUDE_FLAGS) $(DEBUG_FLAGS) tests/test_c.c -lm

cpp-bin: dir-debug
	g++ -o debug/test_cpp $(INCLUDE_FLAGS) $(DEBUG_FLAGS) tests/test_cpp.cpp -lm

# Directories

dir-lib:
	mkdir -p lib

dir-debug:
	mkdir -p debug

# Cleanup

clean:
	rm -f debug/* && rm -f lib/* 
