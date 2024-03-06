#include "tests.h"

START_TEST(strchr_1) {
  char s[] = "Hello, world!";
  int c = 'o';
  ck_assert_ptr_eq(strchr(s, c), s21_strchr(s, c));
}
END_TEST

START_TEST(strchr_2) {
  char s[] = "Hello, world!";
  int c = 'A';
  ck_assert_ptr_eq(strchr(s, c), s21_strchr(s, c));
}
END_TEST

START_TEST(strchr_3) {
  char s[] = "Hello\192, world!";
  int c = 'A' + 127;
  ck_assert_ptr_eq(strchr(s, c), s21_strchr(s, c));
}
END_TEST

START_TEST(strchr_4) {
  char s[] = "Hello A, world!";
  int c = 'A' + 127;
  ck_assert_ptr_eq(strchr(s, c), s21_strchr(s, c));
}
END_TEST

START_TEST(strchr_5) {
  char s[] = "";
  int c = 0;
  ck_assert_ptr_eq(strchr(s, c), s21_strchr(s, c));
}
END_TEST

START_TEST(strchr_6) {
  char s[] = "qwertyuiopasdfghjkll";
  int c = 0;
  ck_assert_ptr_eq(strchr(s, c), s21_strchr(s, c));
}
END_TEST

Suite *test_strchr(void) {
  Suite *s = suite_create("suite_strchr");
  TCase *tc = tcase_create("tc_strchr");

  tcase_add_test(tc, strchr_1);
  tcase_add_test(tc, strchr_2);
  tcase_add_test(tc, strchr_3);
  tcase_add_test(tc, strchr_4);
  tcase_add_test(tc, strchr_5);
  tcase_add_test(tc, strchr_6);

  suite_add_tcase(s, tc);
  return s;
}