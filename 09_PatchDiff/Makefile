CFLAGS = -Wall -Wextra -pedantic -std=c99
CC = cc
GENERATES = lab1

all: $(GENERATES)

lab1: lab1.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(GENERATES)
