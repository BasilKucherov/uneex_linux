CC = gcc
CFLAGS = -Wall -Wextra -g
GENERATES = esub
TRASH = *.out

all: esub

esub: esub.c
	$(CC) $(CFLAGS) -o $@ $<

test: test-simple

test-simple: test_name = "test-simple"
test-simple: regexp = "some"
test-simple: substitution = "no"
test-simple: string = "something"
	./esub $(regexp) $(substitution) $(string) > $(test_name)_esub.out
	echo '$(string)' | sed -E 's/$(regexp)/$(substitution)/' > $(test_name)_sed.out
	cmp $(test_name)_esub.out $(test_name)_sed.out

clean:
	rm -f $(TRASH) $(GENERATES)
