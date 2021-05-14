CC=g++

CFLAGS=-c -Wall -pthread

all: math_operations

math_operations: main.o tokens.o calculable.o
	$(CC) -pthread main.o tokens.o calculable.o -o math_operations

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

tokens.o: tokens.cpp
	$(CC) $(CFLAGS) tokens.cpp

calculable.o: calculable.cpp
	$(CC) $(CFLAGS) calculable.cpp

clean:
	rm -rf *.o math_operations

