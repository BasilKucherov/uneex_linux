#include <check.h>
#include "buf.h"

float* buf = NULL;

#suite Initialization

void buf_teardown() {
	buf_free(buf);
}
#tcase CapacityInit

void buf_setup_1() {
	buf = NULL;
}

#test capacity_init
	ck_assert_int_eq(buf_capacity(buf), 0);
	ck_assert_int_eq(buf_size(buf), 0);

#tcase Capacity1
void buf_setup_2() {
	buf = NULL;
	buf_push(buf, 1.3f);
}

#test size_capacity_1
	ck_assert_int_eq(buf_size(buf), 1);
	ck_assert_float_eq(buf[0], 1.3f);

#tcase CapacityClearNotFree
void buf_setup_3() {
	buf = NULL;
	buf_push(buf, 1.3f);
	buf_clear(buf);
}

#test size_capacity_clear_not_free
	ck_assert_int_eq(buf_size(buf), 0);
	ck_assert_ptr_ne(buf, NULL);

#tcase CapacityClearFree

void buf_setup_4() {
	buf = NULL;
	buf_push(buf, 1.3f);
	buf_clear(buf);
	buf_free(buf);
}

#test size_capacity_clear_free
	ck_assert_int_eq(buf_size(buf), 0);
	ck_assert_ptr_eq(buf, NULL);

#tcase CapacityClearNull
void buf_setup_5() {
	buf = NULL;
}
#test size_capacity_clear_null
	ck_assert_int_eq(buf_size(buf), 0);
	ck_assert_ptr_eq(buf, NULL);


#suite PushPop
#tcase PushPop
void buf_setup_push_pop() {
	buf = NULL;
}

#test size_capacity_push_4
	buf_push(buf, 1.1);
	buf_push(buf, 1.2);
	buf_push(buf, 1.3);
	buf_push(buf, 1.4);
	ck_assert_int_eq(buf_size(buf), 4);
	ck_assert_float_eq(buf_pop(buf), 1.4f);
	buf_trunc(buf, 3);
	ck_assert_int_eq(buf_size(buf), 3);
	ck_assert_float_eq(buf_pop(buf), 1.3f);
	ck_assert_float_eq(buf_pop(buf), 1.2f);
	ck_assert_float_eq(buf_pop(buf), 1.1f);
	ck_assert_int_eq(buf_size(buf), 0);


#main-pre
	tcase_add_checked_fixture(tc1_1, buf_setup_1, buf_teardown);
	tcase_add_checked_fixture(tc1_2, buf_setup_2, buf_teardown);
	tcase_add_checked_fixture(tc1_3, buf_setup_3, buf_teardown);
	tcase_add_checked_fixture(tc1_4, buf_setup_4, buf_teardown);
	tcase_add_checked_fixture(tc1_5, buf_setup_5, buf_teardown);

	tcase_add_checked_fixture(tc2_1, buf_setup_push_pop, buf_teardown);
