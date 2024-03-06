#include "tests.h"

START_TEST(err_0) {
  int err = 0;
  char *s21 = s21_strerror(err);
  char *gnu = strerror(err);
  ck_assert_str_eq(s21, gnu);
}
END_TEST

START_TEST(err_negative) {
  int err = -1;
  char *s21 = s21_strerror(err);
  char *gnu = strerror(err);
  ck_assert_str_eq(s21, gnu);
}
END_TEST

START_TEST(err_all) {
  char *s21;
  char *gnu;

  for (int err = -512; err < 150; err++) {
    s21 = s21_strerror(err);
    gnu = strerror(err);
    ck_assert_str_eq(s21, gnu);
  }
  free(gnu);
}
END_TEST

Suite *test_strerror(void) {
  Suite *s = suite_create("suite_strerror");
  TCase *tc = tcase_create("tc_strerror");

  tcase_add_test(tc, err_0);
  tcase_add_test(tc, err_negative);
  tcase_add_test(tc, err_all);

  suite_add_tcase(s, tc);
  return s;
}