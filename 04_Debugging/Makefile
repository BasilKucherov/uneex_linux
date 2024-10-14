GENERATES = range
TRASH = *.o *.tmp

all: range

range: range.c
	cc -O0 -g -o $@ $^

test: test_1 test_2

test_1: range
	gdb --batch --quiet -x gdb_range_1.gdb ./$<| grep "@@@" > test_1_output.tmp
	cmp test_1_output.tmp gdb_range_1_expected.txt

test_2: range
	gdb --batch --quiet -x gdb_range_2.gdb ./$< | grep "@@@" > test_2_output.tmp
	cmp test_2_output.tmp gdb_range_2_expected.txt

clean:
	rm -f $(GENERATES) $(TRASH)
