CC = cc
CFLAGS = -Wall -Werror
GENERATES = move special_remove.so
TRASH = *.o *.tmp
TEST_IN = test_in.tmp
TEST_PROTECTED_IN = PROTECTED_test_in.tmp
TEST_OUT = test_out.tmp

RED=\033[0;31m
GREEN=\033[0;32m
NC=\033[0m


all: $(GENERATES)

special_remove.so: special_remove.c
	$(CC) $(CFLAGS) -fPIC -shared -o $@ $<

move: move.c
	$(CC) $(CFLAGS) -o $@ $<

test: test-simple test-wrong-argument test-simple-protected test-success-protected test-open-source-failed test-open-destination-failed test-read-failed test-write-failed


test-success-protected: move
	@echo "something" >> $(TEST_PROTECTED_IN)
	@LD_PRELOAD=./special_remove.so ./move $(TEST_PROTECTED_IN) $(TEST_OUT) > /dev/null 2>&1; \
	exit_code=$$?; \
	if   [ $$exit_code -ne 0 ] ; then \
		echo "$(RED)Test failed$(NC): $@ - Expected exit status 0 but got $$exit_code"; \
	elif [ ! -f $(TEST_PROTECTED_IN) ]; then \
		echo "$(RED)Test failed$(NC): $@ - Source file was deleted"; \
	elif [ ! -f $(TEST_OUT) ]; then \
		echo "$(RED)Test failed$(NC): $@ - Destination file was not created"; \
	else \
		echo "$(GREEN)Test passed$(NC): $@"; \
	fi
	@rm -f $(TEST_PROTECTED_IN) $(TEST_OUT)


test-read-failed: move
	@echo "something" >> $(TEST_IN)
	@strace -e fault=read:error=EINVAL:when=2 ./move $(TEST_IN) $(TEST_OUT) > /dev/null 2>&1; \
	exit_code=$$?; \
	if   [ $$exit_code -ne 5 ] ; then \
		echo "$(RED)Test failed$(NC): $@ - Expected exit status 5 but got $$exit_code"; \
	else \
		echo "$(GREEN)Test passed$(NC): $@"; \
	fi
	@rm -f $(TEST_IN) $(TEST_OUT)


test-write-failed: move
	@echo "something" >> $(TEST_IN)
	@strace -e fault=write:error=EINVAL:when=1 ./move $(TEST_IN) $(TEST_OUT) > /dev/null 2>&1; \
	exit_code=$$?; \
	if   [ $$exit_code -ne 4 ] ; then \
		echo "$(RED)Test failed$(NC): $@ - Expected exit status 4 but got $$exit_code"; \
	else \
		echo "$(GREEN)Test passed$(NC): $@"; \
	fi
	@rm -f $(TEST_IN) $(TEST_OUT)


test-open-source-failed: move
	@echo "something" >> $(TEST_IN)
	@strace -e fault=openat:error=EACCES:when=3 ./move $(TEST_IN) $(TEST_OUT) > /dev/null 2>&1; \
	exit_code=$$?; \
	if   [ $$exit_code -ne 2 ] ; then \
		echo "$(RED)Test failed$(NC): $@ - Expected exit status 2 but got $$exit_code"; \
	else \
		echo "$(GREEN)Test passed$(NC): $@"; \
	fi
	@rm -f $(TEST_IN) $(TEST_OUT)

test-open-destination-failed: move
	@echo "something" >> $(TEST_IN)
	@strace -e fault=openat:error=EACCES:when=4 ./move $(TEST_IN) $(TEST_OUT) > /dev/null 2>&1; \
	exit_code=$$?; \
	if   [ $$exit_code -ne 3 ] ; then \
		echo "$(RED)Test failed$(NC): $@ - Expected exit status 3 but got $$exit_code"; \
	else \
		echo "$(GREEN)Test passed$(NC): $@"; \
	fi
	@rm -f $(TEST_IN) $(TEST_OUT)



test-simple: move
	@echo "something" >> $(TEST_IN)
	@./move $(TEST_IN) $(TEST_OUT) > /dev/null 2>&1; \
	exit_code=$$?; \
	if   [ $$exit_code -ne 0 ] ; then \
		echo "$(RED)Test failed$(NC): $@ - Expected exit status 0 but got $$exit_code"; \
	elif [ -f $(TEST_IN) ]; then \
		echo "$(RED)Test failed$(NC): $@ - Source file was not deleted"; \
	elif [ ! -f $(TEST_OUT) ]; then \
		echo "$(RED)Test failed$(NC): $@ - Destination file was not created"; \
	else \
		echo "$(GREEN)Test passed$(NC): $@"; \
	fi
	@rm -f $(TEST_IN) $(TEST_OUT)


test-wrong-argument: move
	@./move > /dev/null 2>&1; \
	exit_code=$$?; \
	if   [ $$exit_code -ne 1 ] ; then \
		echo "$(RED)Test failed$(NC): $@ - Expected exit status 1 but got $$exit_code"; \
	else \
		echo "$(GREEN)Test passed$(NC): $@"; \
	fi


test-simple-protected: move
	@echo "something" >> $(TEST_PROTECTED_IN)
	@./move $(TEST_PROTECTED_IN) $(TEST_OUT) > /dev/null 2>&1; \
	exit_code=$$?; \
	if   [ $$exit_code -ne 0 ] ; then \
		echo "$(RED)Test failed$(NC): $@ - Expected exit status 0 but got $$exit_code"; \
	elif [ -f $(TEST_PROTECTED_IN) ]; then \
		echo "$(RED)Test failed$(NC): $@ - Source file was not deleted"; \
	elif [ ! -f $(TEST_OUT) ]; then \
		echo "$(RED)Test failed$(NC): $@ - Destination file was not created"; \
	else \
		echo "$(GREEN)Test passed$(NC): $@"; \
	fi

	@rm -f $(TEST_PROTECTED_IN) $(TEST_OUT)

clean:
	rm -f $(GENERATES) $(TRASH)
