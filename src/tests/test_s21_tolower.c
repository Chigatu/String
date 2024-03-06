#include "tests.h"

START_TEST(to_lower_1) {
  char *s21 = s21_to_lower("Hello, WORLD!");
  ck_assert_str_eq("hello, world!", s21);
  free(s21);
}
END_TEST

START_TEST(to_lower_2) {
  char *s21 = s21_to_lower("");
  ck_assert_str_eq("", s21);
  free(s21);
}
END_TEST

START_TEST(to_lower_3) {
  char *s21 = s21_to_lower("1234567890-=");
  ck_assert_str_eq("1234567890-=", s21);
  free(s21);
}
END_TEST

Suite *test_to_lower(void) {
  Suite *s = suite_create("suite_to_lower");
  TCase *tc = tcase_create("tc_to_lower");

  tcase_add_test(tc, to_lower_1);
  tcase_add_test(tc, to_lower_2);
  tcase_add_test(tc, to_lower_3);

  suite_add_tcase(s, tc);
  return s;
}