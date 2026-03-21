test: test-c test-cpp

test-c: c-bin
	./debug/test_c

test-cpp: cpp-bin
	./debug/test_cpp

c-bin: dir
	gcc -o debug/test_c -Iinclude -Iinclude/utils -fsanitize=address -g tests/test_c.c -lm

cpp-bin: dir
	g++ -o debug/test_cpp -Iinclude -Iinclude/utils -fsanitize=address -g tests/test_cpp.cpp -lm

dir:
	mkdir -p debug

clean:
	rm -f debug/*
