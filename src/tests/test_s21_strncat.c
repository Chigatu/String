#include "tests.h"

START_TEST(strncat_1) {
  char s[1000] = "Hello, world!";
  char d[] = "I am here";
  ck_assert_str_eq(strncat(s, d, 5), s21_strncat(s, d, 5));
}
END_TEST

START_TEST(strncat_2) {
  char s[1000] = "Hello, world!";
  char d[] = "!!!!!!!!!!!!!!!!!!!!!";
  ck_assert_str_eq(strncat(s, d, 5), s21_strncat(s, d, 5));
}
END_TEST

START_TEST(strncat_3) {
  char s[1000] = "Hello, world!";
  char d[] = "q";
  ck_assert_str_eq(strncat(s, d, 5), s21_strncat(s, d, 5));
}
END_TEST

START_TEST(strncat_4) {
  char s[1000] = "Hello, world!";
  char d[] = "q w e r t y";
  ck_assert_str_eq(strncat(s, d, 12), s21_strncat(s, d, 12));
}
END_TEST

START_TEST(strncat_5) {
  char s[1000] = "Hello, world!";
  char d[] = "";
  ck_assert_str_eq(strncat(s, d, 2), s21_strncat(s, d, 2));
}
END_TEST

START_TEST(strncat_6) {
  char s[1000] = "Hello, world!";
  char d[] = "I am here";
  ck_assert_str_eq(strncat(s, d, 0), s21_strncat(s, d, 0));
}
END_TEST

Suite *test_strncat(void) {
  Suite *s = suite_create("suite_strncat");
  TCase *tc = tcase_create("tc_strncat");

  tcase_add_test(tc, strncat_1);
  tcase_add_test(tc, strncat_2);
  tcase_add_test(tc, strncat_3);
  tcase_add_test(tc, strncat_4);
  tcase_add_test(tc, strncat_5);
  tcase_add_test(tc, strncat_6);

  suite_add_tcase(s, tc);
  return s;
}