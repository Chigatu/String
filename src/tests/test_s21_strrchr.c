#include "tests.h"

START_TEST(strrchr_1) {
  char s[] = "Hello, world!";
  int c = 'l';
  ck_assert_ptr_eq(strrchr(s, c), s21_strrchr(s, c));
}
END_TEST

START_TEST(strrchr_2) {
  char s[] = "";
  int c = 0;
  ck_assert_ptr_eq(strrchr(s, c), s21_strrchr(s, c));
}
END_TEST

START_TEST(strrchr_3) {
  char s[] = "asdasdasd";
  int c = 0;
  ck_assert_ptr_eq(strrchr(s, c), s21_strrchr(s, c));
}
END_TEST

START_TEST(strrchr_4) {
  char s[] = "abcdefghijkl";
  int c = -35;
  ck_assert_ptr_eq(strrchr(s, c), s21_strrchr(s, c));
}
END_TEST

Suite *test_strrchr(void) {
  Suite *s = suite_create("suite_strrchr");
  TCase *tc = tcase_create("tc_strrchr");

  tcase_add_test(tc, strrchr_1);
  tcase_add_test(tc, strrchr_2);
  tcase_add_test(tc, strrchr_3);
  tcase_add_test(tc, strrchr_4);

  suite_add_tcase(s, tc);
  return s;
}