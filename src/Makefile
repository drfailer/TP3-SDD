CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS = 

prog: main.c abr.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf *.o
	rm -rf prog
