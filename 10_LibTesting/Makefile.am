SUBDIRS = src tests

demo:	all
	./src/growable-buf

checklog:	check
	cat tests/*.log

gcov:	check
	$(MAKE) $(MAKEFLAGS) -C src gcov
