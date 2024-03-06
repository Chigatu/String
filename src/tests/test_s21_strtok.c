#include "tests.h"

START_TEST(strtok_1) {
  char str[] = "";
  char s21_str[] = "";
  char delim[] = "";

  ck_assert_pstr_eq(strtok(str, delim), s21_strtok(s21_str, delim));
}
END_TEST

START_TEST(strtok_2) {
  char str[] = "qwertyuiop";
  char s21_str[] = "qwertyuiop";
  char delim[] = "";

  ck_assert_pstr_eq(strtok(str, delim), s21_strtok(s21_str, delim));
}
END_TEST

START_TEST(strtok_3) {
  char str[] = "";
  char s21_str[] = "";
  char delim[] = "asddasd";

  ck_assert_pstr_eq(strtok(str, delim), s21_strtok(s21_str, delim));
}
END_TEST

START_TEST(strtok_4) {
  char str[] = "A u nas est gaz!A u vas?";
  char s21_str[] = "A u nas est gaz!A u vas?";
  char delim[] = " !.?";

  char *tok;
  char *s21_tok;

  tok = strtok(str, delim);
  s21_tok = s21_strtok(s21_str, delim);
  ck_assert_pstr_eq(tok, s21_tok);

  while (tok != NULL || s21_tok != NULL) {
    tok = strtok(NULL, delim);
    s21_tok = s21_strtok(NULL, delim);
    ck_assert_pstr_eq(tok, s21_tok);
  }
}
END_TEST

START_TEST(strtok_5) {
  char str[] = "A u nas est gaz!!! A  u vas?";
  char s21_str[] = "A u nas est gaz!!! A  u vas?";
  char delim[] = " !.?";

  char *tok;
  char *s21_tok;

  tok = strtok(str, delim);
  s21_tok = s21_strtok(s21_str, delim);
  ck_assert_pstr_eq(tok, s21_tok);

  while (tok != NULL || s21_tok != NULL) {
    tok = strtok(NULL, delim);
    s21_tok = s21_strtok(NULL, delim);
    ck_assert_pstr_eq(tok, s21_tok);
  }
}
END_TEST

START_TEST(strtok_6) {
  char str[] = "  A u nas est gaz!!! A  u vas??";
  char s21_str[] = "  A u nas est gaz!!! A  u vas??";
  char delim[] = " !.?";

  char *tok;
  char *s21_tok;

  tok = strtok(str, delim);
  s21_tok = s21_strtok(s21_str, delim);
  ck_assert_pstr_eq(tok, s21_tok);

  while (tok != NULL || s21_tok != NULL) {
    tok = strtok(NULL, delim);
    s21_tok = s21_strtok(NULL, delim);
    ck_assert_pstr_eq(tok, s21_tok);
  }
}
END_TEST

START_TEST(strtok_7) {
  char str[] = "!!!...???   !!!";
  char s21_str[] = "!!!...???   !!!";
  char delim[] = " !.?";

  char *tok;
  char *s21_tok;

  tok = strtok(str, delim);
  s21_tok = s21_strtok(s21_str, delim);
  ck_assert_pstr_eq(tok, s21_tok);

  while (tok != NULL || s21_tok != NULL) {
    tok = strtok(NULL, delim);
    s21_tok = s21_strtok(NULL, delim);
    ck_assert_pstr_eq(tok, s21_tok);
  }
}
END_TEST

Suite *test_strtok(void) {
  Suite *s = suite_create("suite_strtok");
  TCase *tc = tcase_create("tc_strtok");

  tcase_add_test(tc, strtok_1);
  tcase_add_test(tc, strtok_2);
  tcase_add_test(tc, strtok_3);
  tcase_add_test(tc, strtok_4);
  tcase_add_test(tc, strtok_5);
  tcase_add_test(tc, strtok_6);
  tcase_add_test(tc, strtok_7);

  suite_add_tcase(s, tc);
  return s;
}