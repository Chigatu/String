
#include "tests.h"

START_TEST(memcmp_1) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello";
  ck_assert_int_eq(memcmp(s1, s2, 5), 0);
  ck_assert_int_eq(s21_memcmp(s1, s2, 5), 0);
}
END_TEST

START_TEST(memcmp_2) {
  char s1[] = "Hello, world!";
  char s2[] = "HellO";
  ck_assert_int_gt(memcmp(s1, s2, 5), 0);
  ck_assert_int_gt(s21_memcmp(s1, s2, 5), 0);
}
END_TEST

START_TEST(memcmp_3) {
  char s1[] = "HellO, world!";
  char s2[] = "Hello";
  ck_assert_int_lt(memcmp(s1, s2, 5), 0);
  ck_assert_int_lt(s21_memcmp(s1, s2, 5), 0);
}
END_TEST

START_TEST(memcmp_4) {
  char s1[] = "HellO, world!";
  char s2[] = "Hello";
  ck_assert_int_lt(memcmp(s1, s2, 5), 0);
  ck_assert_int_lt(s21_memcmp(s1, s2, 5), 0);
}
END_TEST

START_TEST(memcmp_5) {
  char s1[] = "He\0llo, world!";
  char s2[] = "He\0llo";
  ck_assert_int_eq(memcmp(s1, s2, 5), 0);
  ck_assert_int_eq(s21_memcmp(s1, s2, 5), 0);
}
END_TEST

START_TEST(memcmp_6) {
  char s1[] = "He\0llo, world!";
  char s2[] = "He\0Alo";
  ck_assert_int_gt(memcmp(s1, s2, 5), 0);
  ck_assert_int_gt(s21_memcmp(s1, s2, 5), 0);
}
END_TEST

Suite *test_memcmp(void) {
  Suite *s = suite_create("suite_memcmp");
  TCase *tc = tcase_create("tc_memcmp");

  tcase_add_test(tc, memcmp_1);
  tcase_add_test(tc, memcmp_2);
  tcase_add_test(tc, memcmp_3);
  tcase_add_test(tc, memcmp_4);
  tcase_add_test(tc, memcmp_5);
  tcase_add_test(tc, memcmp_6);

  suite_add_tcase(s, tc);
  return s;
}