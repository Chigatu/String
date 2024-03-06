#include "tests.h"

START_TEST(strncmp_1) {
  char str1[] = "";
  char str2[] = "";
  size_t len = 1;

  ck_assert_int_eq(strncmp(str1, str2, len), 0);
  ck_assert_int_eq(s21_strncmp(str1, str2, len), 0);
}
END_TEST

START_TEST(strncmp_2) {
  char str1[] = "lalalal bubububu";
  char str2[] = "lalalal bubububu";
  size_t len = strlen(str1);

  ck_assert_int_eq(strncmp(str1, str2, len), 0);
  ck_assert_int_eq(s21_strncmp(str1, str2, len), 0);
}
END_TEST

START_TEST(strncmp_3) {
  char str1[] = "lalalal bubububu";
  char str2[] = "lalalal ";
  size_t len = strlen(str1);

  ck_assert_int_gt(strncmp(str1, str2, len), 0);
  ck_assert_int_gt(s21_strncmp(str1, str2, len), 0);
}
END_TEST

START_TEST(strncmp_4) {
  char str2[] = "lalalal bubububu";
  char str1[] = "lalalal ";
  size_t len = strlen(str2);

  ck_assert_int_lt(strncmp(str1, str2, len), 0);
  ck_assert_int_lt(s21_strncmp(str1, str2, len), 0);
}
END_TEST

START_TEST(strncmp_5) {
  char str2[] = "hight char A";
  char str1[] = "hight char \192";
  size_t len = strlen(str2);

  ck_assert_int_lt(strncmp(str1, str2, len), 0);
  ck_assert_int_lt(s21_strncmp(str1, str2, len), 0);
}
END_TEST

START_TEST(strncmp_6) {
  char str2[] = "hight char A";
  char str1[] = "hight char \192";
  size_t len = 0;

  ck_assert_int_eq(strncmp(str1, str2, len), 0);
  ck_assert_int_eq(s21_strncmp(str1, str2, len), 0);
}
END_TEST

Suite *test_strncmp(void) {
  Suite *s = suite_create("suite_strncmp");
  TCase *tc = tcase_create("tc_strncmp");

  tcase_add_test(tc, strncmp_1);
  tcase_add_test(tc, strncmp_2);
  tcase_add_test(tc, strncmp_3);
  tcase_add_test(tc, strncmp_4);
  tcase_add_test(tc, strncmp_5);
  tcase_add_test(tc, strncmp_6);

  suite_add_tcase(s, tc);
  return s;
}