#include "tests.h"

START_TEST(insert_1) {
  char src[] = "Hello World!";
  char insert[] = "People!";
  size_t ind = 6;
  char result[] = "Hello People!";

  char *s21 = s21_insert(src, insert, ind);

  ck_assert_str_eq(s21, result);
  free(s21);
}
END_TEST

START_TEST(insert_2) {
  char *src = NULL;
  char insert[] = "People!";
  size_t ind = 1;

  char *s21 = s21_insert(src, insert, ind);

  ck_assert_ptr_null(s21);
}
END_TEST

START_TEST(insert_3) {
  char src[] = "Hello World!";
  char *insert = NULL;
  size_t ind = 6;

  char *s21 = s21_insert(src, insert, ind);

  ck_assert_ptr_null(s21);
}
END_TEST

START_TEST(insert_4) {
  char src[] = "Hello World!";
  char insert[] = "People!";
  size_t ind = sizeof(src);

  char *s21 = s21_insert(src, insert, ind);

  ck_assert_ptr_null(s21);
}
END_TEST

START_TEST(insert_5) {
  char src[] = "Hello World!";
  char insert[] = "People!";
  size_t ind = 0;
  char result[] = "People!";

  char *s21 = s21_insert(src, insert, ind);

  ck_assert_str_eq(s21, result);
  free(s21);
}
END_TEST

START_TEST(insert_6) {
  char src[] = "Hello World!";
  char insert[] = "People!";
  size_t ind = sizeof(src) - 1;
  char result[] = "Hello World!People!";

  char *s21 = s21_insert(src, insert, ind);

  ck_assert_str_eq(s21, result);
  free(s21);
}
END_TEST

START_TEST(insert_7) {
  char src[] = "Hello World!";
  char insert[] = "\tPeople! World! Animals!.......";
  size_t ind = 6;
  char result[] = "Hello \tPeople! World! Animals!.......";

  char *s21 = s21_insert(src, insert, ind);

  ck_assert_str_eq(s21, result);
  free(s21);
}
END_TEST

START_TEST(insert_8) {
  char *src = NULL;
  char *insert = NULL;
  size_t ind = 100;

  char *s21 = s21_insert(src, insert, ind);

  ck_assert_ptr_null(s21);
}
END_TEST

Suite *test_insert(void) {
  Suite *s = suite_create("suite_insert");
  TCase *tc = tcase_create("tc_insert");

  tcase_add_test(tc, insert_1);
  tcase_add_test(tc, insert_2);
  tcase_add_test(tc, insert_3);
  tcase_add_test(tc, insert_4);
  tcase_add_test(tc, insert_5);
  tcase_add_test(tc, insert_6);
  tcase_add_test(tc, insert_7);
  tcase_add_test(tc, insert_8);

  suite_add_tcase(s, tc);
  return s;
}