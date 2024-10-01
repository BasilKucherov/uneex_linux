GENERATES = prog prog-a prog-so README
TRASH = *.o *~ o.* *.so *.a *.tmp
CFLAGS = -fPIC


all:    README prog prog-a prog-so

prog:   const.o fun.o prog.o

prog-a: liboutput_static.a prog.o
		cc -L. prog.o -loutput_static -o $@

prog-so: liboutput.so prog.o
		cc -L. prog.o -loutput -o $@
README: prog
		./$< 2> $@

fun.o: outlib.h

liboutput_static.a: fun.o const.o
		ar -rcs $@ $^

liboutput.so: fun.o const.o
		cc -shared $^ -o $@


test: test-noparam test-oneparam test-threeparams

test-noparam:
	./prog > prog_$@.tmp 2>&1
	./prog-a > prog-a_$@.tmp 2>&1
	./prog-so > prog-so_$@.tmp 2>&1
	
	cmp prog_$@.tmp prog-a_$@.tmp
	cmp prog_$@.tmp prog-a_$@.tmp 

test-oneparam:
	./prog a > prog_$@.tmp 2>&1
	./prog-a a > prog-a_$@.tmp 2>&1
	./prog-so a > prog-so_$@.tmp 2>&1
	
	cmp prog_$@.tmp prog-a_$@.tmp
	cmp prog_$@.tmp prog-a_$@.tmp 

test-threeparams:
	./prog a b c > prog_$@.tmp 2>&1
	./prog-a a b c > prog-a_$@.tmp 2>&1
	./prog-so a b c  > prog-so_$@.tmp 2>&1
	
	cmp prog_$@.tmp prog-a_$@.tmp
	cmp prog_$@.tmp prog-a_$@.tmp 


clean:
		rm -f $(TRASH)

distclean:      clean
		rm -rf $(GENERATES)