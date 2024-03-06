#include "tests.h"

START_TEST(strstr_1) {
  char h[] = "";
  char n[] = "";

  ck_assert_pstr_eq(strstr(h, n), s21_strstr(h, n));
}
END_TEST

START_TEST(strstr_2) {
  char h[] = "qwerty";
  char n[] = "";

  ck_assert_pstr_eq(strstr(h, n), s21_strstr(h, n));
}
END_TEST

START_TEST(strstr_3) {
  char h[] = "";
  char n[] = "qwerty";

  ck_assert_pstr_eq(strstr(h, n), s21_strstr(h, n));
}
END_TEST

START_TEST(strstr_4) {
  char h[] = "La-la-la bu-bu-bu gu-gu-gu";
  char n[] = "bu-bu";

  ck_assert_pstr_eq(strstr(h, n), s21_strstr(h, n));
}
END_TEST

START_TEST(strstr_5) {
  char h[] = "La-la-la bu-bu-bu gu-gu-gu";
  char n[] = "asdf";

  ck_assert_pstr_eq(strstr(h, n), s21_strstr(h, n));
}
END_TEST

Suite *test_strstr(void) {
  Suite *s = suite_create("suite_strstr");
  TCase *tc = tcase_create("tc_strstr");

  tcase_add_test(tc, strstr_1);
  tcase_add_test(tc, strstr_2);
  tcase_add_test(tc, strstr_3);
  tcase_add_test(tc, strstr_4);
  tcase_add_test(tc, strstr_5);

  suite_add_tcase(s, tc);
  return s;
}