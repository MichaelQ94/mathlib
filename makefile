CC=g++
CFLAGS=-Wall -std=c++11

test: mathlib.o rational.o prime.o
	$(CC) $(CFLAGS) test.cpp algorithm.h mathlib.o rational.o prime.o -o test

mathlib.o:
	$(CC) $(CFLAGS) -c mathlib.cpp

rational.o:
	$(CC) $(CFLAGS) -c rational.cpp

prime.o:
	$(CC) $(CFLAGS) -c prime.cpp

clean:
	rm -f *.o test
