#include "tests.h"

START_TEST(to_upper_1) {
  char *s21 = s21_to_upper("Hello, world!");
  ck_assert_str_eq("HELLO, WORLD!", s21);
  free(s21);
}
END_TEST

START_TEST(to_upper_2) {
  char *s21 = s21_to_upper("");
  ck_assert_str_eq("", s21);
  free(s21);
}
END_TEST

START_TEST(to_upper_3) {
  char *s21 = s21_to_upper("1234567890-=");
  ck_assert_str_eq("1234567890-=", s21);
  free(s21);
}
END_TEST

Suite *test_to_upper(void) {
  Suite *s = suite_create("suite_to_upper");
  TCase *tc = tcase_create("tc_to_upper");

  tcase_add_test(tc, to_upper_1);
  tcase_add_test(tc, to_upper_2);
  tcase_add_test(tc, to_upper_3);

  suite_add_tcase(s, tc);
  return s;
}