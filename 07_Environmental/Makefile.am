bin_PROGRAMS=rhasher
rhasher_SOURCES=rhasher.c

rhasher_CFLAGS=-std=c99 -lc
rhasher_LDADD=-lrhash -lreadline

TESTS=test_sha1sum.sh test_md5sum.sh

test_sha1sum.sh:
	echo 'sha1sum rhasher.c | awk '\''{print $1}'\'' | xxd -r -p | base64 > correct_sha1sum_base64.txt' >> $@
	echo 'echo "sha1 rhasher.c" | ./rhasher | tail -n 1 | awk '\''{print $1}'\'' > my_sha1sum_base64.txt' >> $@
	echo 'cmp correct_sha1sum_base64.txt my_sha1sum_base64.txt' >> $@
	chmod +x $@

test_md5sum.sh:
	echo 'md5sum rhasher.c | awk '\''{print $1}'\'' | xxd -r -p | base64 > correct_md5sum_base64.txt' >> $@
	echo 'echo "md5 rhasher.c" | ./rhasher | tail -n 1 | awk '\''{print $1}'\'' > my_md5sum_base64.txt' >> $@
	echo 'cmp correct_md5sum_base64.txt my_md5sum_base64.txt' >> $@
	chmod +x $@

CLEANFILES = my_sha1sum_base64.txt my_md5sum_base64.txt
DISTCLEANFILES = correct_sha1sum_base64.txt correct_md5sum_base64.txt

gitclean:
	git clean -df