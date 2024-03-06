#include "tests.h"

START_TEST(test_cd) {
  char str[100];
  char s21_str[100];

  int sprintf_res = sprintf(str, "Hello SCHOO%c %c%d!", 'L', '2', 1);
  int s21_sprintf_res =
      s21_sprintf(s21_str, "Hello SCHOO%c %c%d!", 'L', '2', 1);
  ck_assert_int_eq(sprintf_res, s21_sprintf_res);
  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(test_d) {
  char str[100];
  char s21_str[100];

  int sprintf_res = sprintf(str, "%-2d %d %3.0d %.0d %07d %07x %07x", -2, 0, 0,
                            0, 23, -0xabf, 0xabf);
  int s21_sprintf_res =
      s21_sprintf(s21_str, "%-2d %d %3.0d %.0d %07d %07x %07x", -2, 0, 0, 0, 23,
                  -0xabf, 0xabf);

  ck_assert_int_eq(sprintf_res, s21_sprintf_res);
  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(test_eEgG) {
  char str[100];
  char s21_str[100];
  int sprintf_res =
      sprintf(str, "%Lg %G, %e %+3.2e %E %g %g %g %3.g %3.g", 2.2L, 2.2,
              -0.245322, -120.245322, -2.2, NAN, INFINITY, 0.0, 0.1, 1e-05);
  int s21_sprintf_res =
      s21_sprintf(s21_str, "%Lg %G, %e %+3.2e %E %g %g %g %3.g %3.g", 2.2L, 2.2,
                  -0.245322, -120.245322, -2.2, NAN, INFINITY, 0.0, 0.1, 1e-05);
  ck_assert_int_eq(sprintf_res, s21_sprintf_res);
  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(test_w_p_eg) {
  char str[100];
  char s21_str[100];

  int sprintf_res = sprintf(str, "%0.3g %0.3G, %4.0e %4.0E %-8.4d", 2.234,
                            2.234, -2.2, -2e+00, -22);
  int s21_sprintf_res = s21_sprintf(s21_str, "%0.3g %0.3G, %4.0e %4.0E %-8.4d",
                                    2.234, 2.234, -2.2, -2e+00, -22);

  ck_assert_int_eq(sprintf_res, s21_sprintf_res);
  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(test_s) {
  char str[100];
  char s21_str[100];

  int sprintf_res = sprintf(str, "%3.2s", "HELLO");
  int s21_sprintf_res = s21_sprintf(s21_str, "%3.2s", "HELLO");

  ck_assert_int_eq(sprintf_res, s21_sprintf_res);
  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(test_f) {
  char str[100];
  char s21_str[100];

  int sprintf_res = sprintf(str, "%Lf %.2Lf %.3Lf %Lf %.0f\n", 123.0L,
                            123.45678L, 123.456789L, -456.789L, 0.2);
  int s21_sprintf_res =
      s21_sprintf(s21_str, "%Lf %.2Lf %.3Lf %Lf %.0f\n", 123.0L, 123.45678L,
                  123.456789L, -456.789L, 0.2);

  ck_assert_int_eq(sprintf_res, s21_sprintf_res);
  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(test_xX) {
  char str[100];
  char s21_str[100];

  int sprintf_res = sprintf(str, "%3.2x - %3.2X - %lx %hX %2.0x %.0x", 0x2f,
                            0x2f, 0x2fl, (unsigned short)0x2f, 0, 0);
  int s21_sprintf_res =
      s21_sprintf(s21_str, "%3.2x - %3.2X - %lx %hX %2.0x %.0x", 0x2f, 0x2f,
                  0x2fl, (unsigned short)0x2f, 0, 0);

  ck_assert_int_eq(sprintf_res, s21_sprintf_res);
  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(test_size) {
  char str[100];
  char s21_str[100];

  int sprintf_res = sprintf(str, "The value is: %Lf %ld %hd\n", -3.14159L,
                            2147483647l, (short)32767);
  int s21_sprintf_res = s21_sprintf(s21_str, "The value is: %Lf %ld %hd\n",
                                    -3.14159L, 2147483647l, (short)32767);
  ck_assert_int_eq(sprintf_res, s21_sprintf_res);
  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(test_sign_1) {
  char str[100];
  char s21_str[100];

  int sprintf_res = sprintf(str, "%-*.*f", 7, 2, 3.222);
  int s21_sprintf_res = s21_sprintf(s21_str, "%-*.*f", 7, 2, 3.222);

  ck_assert_int_eq(sprintf_res, s21_sprintf_res);
  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(test_sign_2) {
  char str[100];
  char s21_str[100];

  int sprintf_res = sprintf(str, "%% % d %+d %+d", 21, -2, 2);
  int s21_sprintf_res = s21_sprintf(s21_str, "%% % d %+d %+d", 21, -2, 2);

  ck_assert_int_eq(sprintf_res, s21_sprintf_res);
  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(test_sign_3) {
  char str[100];
  char s21_str[100];

  int sprintf_res = sprintf(str, "%#X %#o", 0x21, 022);
  int s21_sprintf_res = s21_sprintf(s21_str, "%#X %#o", 0x21, 022);

  ck_assert_int_eq(sprintf_res, s21_sprintf_res);
  ck_assert_str_eq(str, s21_str);
}
END_TEST

Suite *test_sprintf(void) {
  Suite *s = suite_create("suite_sprintf");
  TCase *tc = tcase_create("tc_sprintf");

  tcase_add_test(tc, test_cd);
  tcase_add_test(tc, test_eEgG);
  tcase_add_test(tc, test_w_p_eg);
  tcase_add_test(tc, test_s);
  tcase_add_test(tc, test_d);
  tcase_add_test(tc, test_f);
  // tcase_add_test(tc, test_ou);
  tcase_add_test(tc, test_xX);
  tcase_add_test(tc, test_sign_1);
  tcase_add_test(tc, test_sign_2);
  tcase_add_test(tc, test_sign_3);
  tcase_add_test(tc, test_size);

  suite_add_tcase(s, tc);

  return s;
}
