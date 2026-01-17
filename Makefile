CC = gcc
CFLAGS = -Wall -Wextra -std=c99

filescanner: main.o scanner.o
	$(CC) $(CFLAGS) -o filescanner main.o scanner.o

main.o: main.c scanner.h
	$(CC) $(CFLAGS) -c main.c

scanner.o: scanner.c scanner.h
	$(CC) $(CFLAGS) -c scanner.c

clean:
	rm -f *.o filescanner