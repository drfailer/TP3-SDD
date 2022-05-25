CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS = 

prog: main.c abr.c ./piles_files/pile.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf *.o
	rm -rf prog
