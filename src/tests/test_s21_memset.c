#include "tests.h"

START_TEST(memset_1) {
  char dst[S21_BUF];
  char s21_dst[S21_BUF];
  int fill = 'E';
  size_t size = S21_BUF / 2;

  memset(dst, fill, size);
  s21_memset(s21_dst, fill, size);
  ck_assert_mem_eq(dst, s21_dst, size);
}
END_TEST

START_TEST(memset_2) {
  char dst[S21_BUF];
  char s21_dst[S21_BUF];
  int fill = 'E';
  size_t size = 0;

  memset(dst, fill, size);
  s21_memset(s21_dst, fill, size);
  ck_assert_mem_eq(dst, s21_dst, size);
}
END_TEST

START_TEST(memset_3) {
  char dst[S21_BUF];
  char s21_dst[S21_BUF];
  int fill = '\177';
  size_t size = S21_BUF / 2;

  memset(dst, fill, size);
  s21_memset(s21_dst, fill, size);
  ck_assert_mem_eq(dst, s21_dst, size);
}
END_TEST

Suite *test_memset(void) {
  Suite *s = suite_create("suite_memset");
  TCase *tc = tcase_create("tc_memset");

  tcase_add_test(tc, memset_1);
  tcase_add_test(tc, memset_2);
  tcase_add_test(tc, memset_3);

  suite_add_tcase(s, tc);
  return s;
}