
CC = clang++
CFLAGS = -Wall -std=c++11 -g

.PHONY: all main test valgrind clean


main: main.cpp MyContainer.hpp
	$(CC) $(CFLAGS) main.cpp -o main

test: test.cpp MyContainer.hpp
	$(CC) $(CFLAGS) test.cpp -o test
	./test

valgrind: main test
	valgrind --leak-check=full ./main
	valgrind --leak-check=full ./test

clean: 
	rm -f main test *.o