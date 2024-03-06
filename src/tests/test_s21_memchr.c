#include "tests.h"

START_TEST(memchr_1) {
  char s[] = "Hello, world!";
  int ch = 'l';
  ck_assert_str_eq(memchr(s, ch, 5), s21_memchr(s, ch, 5));
}
END_TEST

START_TEST(memchr_2) {
  char s[] = "Hello, world!";
  int ch = 'e';
  ck_assert_str_eq(memchr(s, ch, 5), s21_memchr(s, ch, 5));
}
END_TEST

START_TEST(memchr_3) {
  char s[] = " cooool";
  int ch = 'l';
  ck_assert_str_eq(memchr(s, ch, 8), s21_memchr(s, ch, 8));
}
END_TEST

START_TEST(memchr_4) {
  char s[] = "Hello, wor%%%ld!";
  int ch = '%';
  ck_assert_ptr_null(s21_memchr(s, ch, 10));
}
END_TEST

START_TEST(memchr_5) {
  char s[] = "HelLo, world!";
  int ch = 'L';
  ck_assert_str_eq(memchr(s, ch, 5), s21_memchr(s, ch, 5));
}
END_TEST

START_TEST(memchr_6) {
  char s[] = "HeLLo, world!";
  int ch = 'l';
  ck_assert_str_eq(memchr(s, ch, 11), s21_memchr(s, ch, 11));
}
END_TEST

START_TEST(memchr_7) {
  char s[] = "HeLLo\0, world!";
  int ch = 0;
  ck_assert_str_eq(memchr(s, ch, 11), s21_memchr(s, ch, 11));
}
END_TEST

START_TEST(memchr_8) {
  char s[] = "HeLLo\0, world!";
  int ch = 'w';
  ck_assert_str_eq(memchr(s, ch, 11), s21_memchr(s, ch, 11));
}
END_TEST

Suite *test_memchr(void) {
  Suite *s = suite_create("suite_memchr");
  TCase *tc = tcase_create("tc_memchr");

  tcase_add_test(tc, memchr_1);
  tcase_add_test(tc, memchr_2);
  tcase_add_test(tc, memchr_3);
  tcase_add_test(tc, memchr_4);
  tcase_add_test(tc, memchr_5);
  tcase_add_test(tc, memchr_6);
  tcase_add_test(tc, memchr_7);
  tcase_add_test(tc, memchr_8);

  suite_add_tcase(s, tc);
  return s;
}