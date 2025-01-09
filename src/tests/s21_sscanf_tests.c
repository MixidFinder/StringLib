#include <check.h>
#include <stdio.h>

#include "../s21_string.h"

START_TEST(sscanf_1) {
  const char str[] = "a B c";
  const char format[] = "%c %c %c";

  char a, B, c;
  char a1, B1, c1;

  ck_assert_int_eq(sscanf(str, format, &a, &B, &c),
                   s21_sscanf(str, format, &a1, &B1, &c1));

  ck_assert_int_eq(a, a1);
  ck_assert_int_eq(B, B1);
  ck_assert_int_eq(c, c1);
}
END_TEST

START_TEST(sscanf_2) {
  const char str[] = "a B c";
  const char format[] = "%c%c%c";

  char a, B, c;
  char a1, B1, c1;

  ck_assert_int_eq(sscanf(str, format, &a, &B, &c),
                   s21_sscanf(str, format, &a1, &B1, &c1));

  ck_assert_int_eq(a, a1);
  ck_assert_int_eq(B, B1);
  ck_assert_int_eq(c, c1);
}
END_TEST

START_TEST(sscanf_3) {
  const char str[] = "asd123 456zxc s";
  const char format[] = "%s%s%c";

  char *s1 = malloc(sizeof(char) * 7);
  char *ts1 = malloc(sizeof(char) * 7);

  char *s2 = malloc(sizeof(char) * 7);
  char *ts2 = malloc(sizeof(char) * 7);

  char c1;
  char tc1;

  ck_assert_int_eq(sscanf(str, format, s1, s2, &c1),
                   s21_sscanf(str, format, ts1, ts2, &tc1));

  ck_assert_str_eq(s1, ts1);
  ck_assert_str_eq(s2, ts2);
  ck_assert_int_eq(c1, tc1);

  if (s1 != S21_NULL) free(s1);
  if (ts1 != S21_NULL) free(ts1);
  if (s2 != S21_NULL) free(s2);
  if (ts2 != S21_NULL) free(ts2);
}
END_TEST

START_TEST(sscanf_4) {
  const char str[] = "asd123 456zxc s";
  const char format[] = "%s %s %c";

  char *s1 = malloc(sizeof(char) * 7);
  char *ts1 = malloc(sizeof(char) * 7);

  char *s2 = malloc(sizeof(char) * 7);
  char *ts2 = malloc(sizeof(char) * 7);

  char c1;
  char tc1;

  ck_assert_int_eq(sscanf(str, format, s1, s2, &c1),
                   s21_sscanf(str, format, ts1, ts2, &tc1));

  ck_assert_str_eq(s1, ts1);
  ck_assert_str_eq(s2, ts2);
  ck_assert_int_eq(c1, tc1);

  if (s1 != S21_NULL) free(s1);
  if (ts1 != S21_NULL) free(ts1);
  if (s2 != S21_NULL) free(s2);
  if (ts2 != S21_NULL) free(ts2);
}
END_TEST

START_TEST(sscanf_5) {
  const char str[] = "12765 M 6549089 asdx14 11 m 1 12345";
  const char format[] = "%d %c %u %s %d %c %d %ld %%";

  char *s1 = malloc(sizeof(char) * 7);
  char ca, cb;
  int ia, ib, ic;
  long int la;
  unsigned int ua;

  char *ts1 = malloc(sizeof(char) * 7);
  char tca, tcb;
  int tia, tib, tic;
  long int tla;
  unsigned int tua;

  ck_assert_int_eq(
      sscanf(str, format, &ia, &ca, &ua, s1, &ib, &cb, &ic, &la),
      s21_sscanf(str, format, &tia, &tca, &tua, ts1, &tib, &tcb, &tic, &tla));

  ck_assert_int_eq(ia, tia);
  ck_assert_int_eq(ib, tib);
  ck_assert_int_eq(ic, tic);
  ck_assert_int_eq(ua, tua);
  ck_assert_str_eq(s1, ts1);
  ck_assert_int_eq(ca, tca);
  ck_assert_int_eq(cb, tcb);

  if (s1 != S21_NULL) free(s1);
  if (ts1 != S21_NULL) free(ts1);
}
END_TEST

int main(void) {
  int failed = 0;
  Suite *s1 = suite_create("sscanf()_tests");
  TCase *tc1_1 = tcase_create("sscanf()_tests");
  SRunner *sr = srunner_create(s1);

  tcase_add_test(tc1_1, sscanf_1);
  tcase_add_test(tc1_1, sscanf_2);
  tcase_add_test(tc1_1, sscanf_3);
  tcase_add_test(tc1_1, sscanf_4);
  tcase_add_test(tc1_1, sscanf_5);

  suite_add_tcase(s1, tc1_1);

  srunner_run_all(sr, CK_NORMAL);

  failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (failed == 0) ? 0 : 1;
}
