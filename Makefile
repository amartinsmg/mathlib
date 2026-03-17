# Makefile for building the "test" target and creating the "debug" directory.

#Targets
# `test`: runs the test.
# `test-bin`: compiles the main.c file in the tests directory.
# `dir`: creates the "debug" directory if it doesn't already exist.

test: test-bin
	./debug/test

test-bin: dir
	gcc -o debug/test -Iinclude -fsanitize=address -g tests/main.c -lm

dir:
	mkdir -p debug

clean:
	rm -f debug/*
