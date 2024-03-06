#include "tests.h"

START_TEST(trim_1) {
  char src[] = "Hello World!";
  char trim[] = "#@$";
  char result[] = "Hello World!";

  char *s21 = s21_trim(src, trim);

  ck_assert_str_eq(s21, result);
  free(s21);
}
END_TEST

START_TEST(trim_2) {
  char src[] = "#$Hello World!@";
  char trim[] = "#@$";
  char result[] = "Hello World!";

  char *s21 = s21_trim(src, trim);

  ck_assert_str_eq(s21, result);
  free(s21);
}
END_TEST

START_TEST(trim_3) {
  char src[] = "#$Hello #@$ World!@";
  char trim[] = "#@$";
  char result[] = "Hello #@$ World!";

  char *s21 = s21_trim(src, trim);

  ck_assert_str_eq(s21, result);
  free(s21);
}
END_TEST

START_TEST(trim_4) {
  char src[] = "#$#@$@";
  char trim[] = "#@$";
  char result[] = "";

  char *s21 = s21_trim(src, trim);

  ck_assert_str_eq(s21, result);
  free(s21);
}
END_TEST

START_TEST(trim_5) {
  char src[] = "";
  char trim[] = "";
  char result[] = "";

  char *s21 = s21_trim(src, trim);

  ck_assert_str_eq(s21, result);
  free(s21);
}
END_TEST

START_TEST(trim_6) {
  char *src = NULL;
  char trim[] = "";

  char *s21 = s21_trim(src, trim);

  ck_assert_ptr_null(s21);
}

START_TEST(trim_7) {
  char *src = "";
  char *trim = NULL;

  char *s21 = s21_trim(src, trim);

  ck_assert_ptr_null(s21);
}
END_TEST

START_TEST(trim_8) {
  char src[] = "Hello World!";
  char trim[] = "";
  char result[] = "Hello World!";

  char *s21 = s21_trim(src, trim);

  ck_assert_str_eq(s21, result);
  free(s21);
}
END_TEST

Suite *test_trim(void) {
  Suite *s = suite_create("suite_trim");
  TCase *tc = tcase_create("tc_trim");

  tcase_add_test(tc, trim_1);
  tcase_add_test(tc, trim_2);
  tcase_add_test(tc, trim_3);
  tcase_add_test(tc, trim_4);
  tcase_add_test(tc, trim_5);
  tcase_add_test(tc, trim_6);
  tcase_add_test(tc, trim_7);
  tcase_add_test(tc, trim_8);

  suite_add_tcase(s, tc);
  return s;
}