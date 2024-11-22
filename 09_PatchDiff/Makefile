CFLAGS = -Wall -Wextra -pedantic -std=c99
CC = cc
GENERATES = lab1 lab2 lab3 lab4
TRASH = lab2.c lab3.c lab4.c

all: $(GENERATES)

lab1: lab1.c
	$(CC) $(CFLAGS) -o $@ $<
	
lab2.c: lab1.c 0001-Define-W.patch
	patch $< 0001-Define-W.patch -o $@

lab2: lab2.c
	$(CC) $(CFLAGS) -o $@ $< -lm

lab3.c: lab2.c 0002-Define-cells.patch
	patch $< 0002-Define-cells.patch -o $@

lab3: lab3.c
	$(CC) $(CFLAGS) -o $@ $< -lm

lab4.c: lab3.c 0003-Define-seed.patch
	patch $< 0003-Define-seed.patch -o $@

lab4: lab4.c
	$(CC) $(CFLAGS) -o $@ $< -lm

run: $(GENERATES)
	./lab1
	./lab2 25
	./lab3 '#.' 16
	./lab4 42 '#.' 9

clean:
	rm -f $(GENERATES) $(TRASH)
