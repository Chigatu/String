#include "tests.h"

START_TEST(strncpy_1) {
  char dst[S21_BUF] = "bu";
  char s21_dst[S21_BUF] = "gu";
  char src[] = "la-la-la-la";
  size_t len = strlen(src);

  strncpy(dst, src, len);
  s21_strncpy(s21_dst, src, len);
  ck_assert_str_eq(dst, s21_dst);
}
END_TEST

START_TEST(strncpy_2) {
  char dst[S21_BUF] = "bu-bu-bu";
  char s21_dst[S21_BUF] = "bu-bu-bu";
  char src[] = "la-la-la-la";
  size_t len = 3;

  strncpy(dst, src, len);
  s21_strncpy(s21_dst, src, len);
  ck_assert_str_eq(dst, s21_dst);
}
END_TEST

START_TEST(strncpy_3) {
  char dst[S21_BUF] = "bu";
  char s21_dst[S21_BUF] = "gu";
  char src[] = "";
  size_t len = strlen(src);

  strncpy(dst, src, len);
  s21_strncpy(s21_dst, src, len);
  ck_assert_str_eq(dst, dst);
  ck_assert_str_eq(s21_dst, s21_dst);
}
END_TEST

Suite *test_strncpy(void) {
  Suite *s = suite_create("suite_strncpy");
  TCase *tc = tcase_create("tc_strncpy");

  tcase_add_test(tc, strncpy_1);
  tcase_add_test(tc, strncpy_2);
  tcase_add_test(tc, strncpy_3);

  suite_add_tcase(s, tc);
  return s;
}