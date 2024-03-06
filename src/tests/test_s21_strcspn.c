#include "tests.h"

START_TEST(empty_empty) {
  char str1[] = "";
  char str2[] = "";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(empty_str) {
  char str1[] = "";
  char str2[] = "La Roshel";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(str_empty) {
  char str1[] = "La Roshel";
  char str2[] = "";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(sTr_str) {
  char str1[] = "ABC";
  char str2[] = "lemonad and wine";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(high_str) {
  char str1[] = "\129";
  char str2[] = "lemonad and wine";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(high_high) {
  char str1[] = "\129";
  char str2[] = "lemonad\129  and wine";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

Suite *test_strcspn(void) {
  Suite *s = suite_create("suite_strcspn");
  TCase *tc = tcase_create("tc_strcspn");

  tcase_add_test(tc, empty_empty);
  tcase_add_test(tc, empty_str);
  tcase_add_test(tc, str_empty);
  tcase_add_test(tc, sTr_str);
  tcase_add_test(tc, high_str);
  tcase_add_test(tc, high_high);

  suite_add_tcase(s, tc);
  return s;
}