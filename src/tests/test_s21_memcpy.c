#include "tests.h"

START_TEST(memcpy_1) {
  char dst[S21_BUF];
  char s21_dst[S21_BUF];
  char src[] = "Hello";
  size_t size = 6;

  memcpy(dst, src, size);
  s21_memcpy(s21_dst, src, size);
  ck_assert_mem_eq(dst, s21_dst, size);
}
END_TEST

START_TEST(memcpy_2) {
  char dst[S21_BUF];
  char s21_dst[S21_BUF];
  char src[] = "Hel\0lo";
  size_t size = 7;

  memcpy(dst, src, size);
  s21_memcpy(s21_dst, src, size);
  ck_assert_mem_eq(dst, s21_dst, size);
}
END_TEST

START_TEST(memcpy_3) {
  char dst[S21_BUF];
  char s21_dst[S21_BUF];
  char src[] = "";
  size_t size = 1;

  memcpy(dst, src, size);
  s21_memcpy(s21_dst, src, size);
  ck_assert_mem_eq(dst, s21_dst, size);
}
END_TEST

START_TEST(memcpy_4) {
  char dst[S21_BUF];
  char s21_dst[S21_BUF];
  char src[] = "la-la-la";
  size_t size = 0;

  memcpy(dst, src, size);
  s21_memcpy(s21_dst, src, size);
  ck_assert_mem_eq(dst, s21_dst, size);
}
END_TEST

START_TEST(memcpy_5) {
  char dst[S21_BUF];
  char s21_dst[S21_BUF];
  char src[] = "la-\200\250-la";
  size_t size = 9;

  memcpy(dst, src, size);
  s21_memcpy(s21_dst, src, size);
  ck_assert_mem_eq(dst, s21_dst, size);
}
END_TEST

Suite *test_memcpy(void) {
  Suite *s = suite_create("suite_memcpy");
  TCase *tc = tcase_create("tc_memcpy");

  tcase_add_test(tc, memcpy_1);
  tcase_add_test(tc, memcpy_2);
  tcase_add_test(tc, memcpy_3);
  tcase_add_test(tc, memcpy_4);
  tcase_add_test(tc, memcpy_5);

  suite_add_tcase(s, tc);
  return s;
}