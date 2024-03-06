#include "tests.h"

START_TEST(empty) {
  char src[] = "";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(long_line) {
  char src[] = "1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

Suite *test_strlen(void) {
  Suite *s = suite_create("suite_strlen");
  TCase *tc = tcase_create("tc_strlen");

  tcase_add_test(tc, empty);
  tcase_add_test(tc, long_line);

  suite_add_tcase(s, tc);
  return s;
}