#include "tests.h"

START_TEST(strpbrk_1) {
  char str[] = "";
  char pat[] = "";

  ck_assert_pstr_eq(strpbrk(str, pat), s21_strpbrk(str, pat));
}
END_TEST

START_TEST(strpbrk_2) {
  char str[] = "";
  char pat[] = "ras";

  ck_assert_pstr_eq(strpbrk(str, pat), s21_strpbrk(str, pat));
}
END_TEST

START_TEST(strpbrk_3) {
  char str[] = "qwertyuio";
  char pat[] = "";

  ck_assert_pstr_eq(strpbrk(str, pat), s21_strpbrk(str, pat));
}
END_TEST

START_TEST(strpbrk_4) {
  char str[] = "qwertyuio";
  char pat[] = "\0";

  ck_assert_pstr_eq(strpbrk(str, pat), s21_strpbrk(str, pat));
}
END_TEST

START_TEST(strpbrk_5) {
  char str[] = "qwertyuio";
  char pat[] = "asderty";

  ck_assert_pstr_eq(strpbrk(str, pat), s21_strpbrk(str, pat));
}
END_TEST

START_TEST(strpbrk_6) {
  char str[] = "qwertyuio";
  char pat[] = "asdrtye";

  ck_assert_pstr_eq(strpbrk(str, pat), s21_strpbrk(str, pat));
}
END_TEST

Suite *test_strpbrk(void) {
  Suite *s = suite_create("suite_strpbrk");
  TCase *tc = tcase_create("tc_strpbrk");

  tcase_add_test(tc, strpbrk_1);
  tcase_add_test(tc, strpbrk_2);
  tcase_add_test(tc, strpbrk_3);
  tcase_add_test(tc, strpbrk_4);
  tcase_add_test(tc, strpbrk_5);
  tcase_add_test(tc, strpbrk_6);

  suite_add_tcase(s, tc);
  return s;
}