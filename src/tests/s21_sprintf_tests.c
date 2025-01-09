#include <check.h>
#include <stdio.h>

#include "../s21_string.h"

START_TEST(sprintf_1) {
  // DEBUG
  // printf("\n\nDEBUG:\n\n(printed chars:)\ndef:%d \ts21:%d \n\n", res1, res2);
  // printf("Original*%s\nS21*%sEND\n", str1, str1);
  char test_case[] =
      "\n%%:%%-END \ns:%s-END \n ld:% ld-END \nc:%c-END \nf:%f-END \nu:%u-END "
      "\n";

  char tstring[] = "SPRINTF_59083475()*&@#$^(*#&)@^NCR&emfohl.";
  long int tdecimal = 253;
  char tchar = 'z';
  float tfloat = -1230.e12;
  unsigned int tuint = 23465;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(
      sprintf(str1, test_case, tstring, tdecimal, tchar, tfloat, tuint),
      s21_sprintf(str2, test_case, tstring, tdecimal, tchar, tfloat, tuint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_2) {
  char test_case[] =
      "\n%%:%%-END \ns:%s-END \nd:%d-END \nc:%c-END \nf:%f-END \nu:%u-END \n";

  char tstring[] = " ";
  int tdecimal = 253;
  char tchar = '\000';
  float tfloat = 1230.e12;
  unsigned int tuint = 1;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(
      sprintf(str1, test_case, tstring, tdecimal, tchar, tfloat, tuint),
      s21_sprintf(str2, test_case, tstring, tdecimal, tchar, tfloat, tuint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_3) {
  char test_case[] =
      "\n%%:%%-END \ns:%s-END \nd:%d-END \nc:%c-END \nf:%f-END \nu:%u-END \n";

  char tstring[] = "";
  int tdecimal = 1;
  char tchar = '\001';
  float tfloat =
      895965478623487.346287396587369074683946980347980798236587901365953426758236874656492378658792345698723465873465893476583568973126489e1;
  unsigned int tuint = -1;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(
      sprintf(str1, test_case, tstring, tdecimal, tchar, tfloat, tuint),
      s21_sprintf(str2, test_case, tstring, tdecimal, tchar, tfloat, tuint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_4) {
  char test_case[] =
      "\n%%:%%-END \ns:%s-END \nd:%d-END \nc:%c-END \nf:%f-END \nu:%u-END \n";

  char tstring[] = "1\t";
  int tdecimal = -1;
  char tchar = '.';
  float tfloat = -1;
  unsigned int tuint = 0;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(
      sprintf(str1, test_case, tstring, tdecimal, tchar, tfloat, tuint),
      s21_sprintf(str2, test_case, tstring, tdecimal, tchar, tfloat, tuint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_5) {
  char test_case[] =
      "\n%%:%%-END \ns:%s-END \nd:%d-END \nc:%c-END \nf:%f-END \nu:%u-END \n";

  char tstring[] = "1\t ";
  int tdecimal = 0;
  char tchar = ' ';
  float tfloat = 1e17;
  unsigned int tuint = 999999999;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(
      sprintf(str1, test_case, tstring, tdecimal, tchar, tfloat, tuint),
      s21_sprintf(str2, test_case, tstring, tdecimal, tchar, tfloat, tuint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_6) {
  char test_case[] =
      "\n%%:%%-END \ns:%s-END \nd:%d-END \nc:%c-END \nf:%f-END \nu:%u-END \n";

  char tstring[] = "999999999";
  int tdecimal = 999999999;
  char tchar = '9';
  float tfloat =
      9999999999.9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999;
  unsigned int tuint = 999999999;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(
      sprintf(str1, test_case, tstring, tdecimal, tchar, tfloat, tuint),
      s21_sprintf(str2, test_case, tstring, tdecimal, tchar, tfloat, tuint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_7) {
  char test_case[] =
      "\n%%:%%-END \ns:%s-END \nd:%d-END \nc:%c-END \nf:%f-END \nu:%u-END \n";

  char tstring[] =
      "go58mmmmmmuy98f5,ypdhcgdxoiiiiiiiiikucfzsdce4tufhmtufhmtufhmtufhmtufhml";
  int tdecimal = 407560;
  char tchar = '\0';
  double tfloat = 407560;
  unsigned int tuint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(
      sprintf(str1, test_case, tstring, tdecimal, tchar, tfloat, tuint),
      s21_sprintf(str2, test_case, tstring, tdecimal, tchar, tfloat, tuint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_8) {
  char test_case[] =
      "\n%%:%%-END \ns:%s-END \nd:%.10d-END \nc:%c-END \nf:%f-END \nu:%u-END "
      "\n";

  char tstring[] =
      "-go58mmmmmmuy98f5,"
      "ypdhcgdxoiiiiiiiiikucfzsdce4tufhmtufhmtufhmtufhmtufhml";
  int tdecimal = 407560;
  char tchar = '\010';
  double tfloat = -407560;
  unsigned int tuint = 0;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(
      sprintf(str1, test_case, tstring, tdecimal, tchar, tfloat, tuint),
      s21_sprintf(str2, test_case, tstring, tdecimal, tchar, tfloat, tuint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_9) {
  char test_case[] =
      "\n%%:%%-END \ns:%s-END \nd:%d-END \nc:%c-END \nf:%f-END \nu:%u-END \n";

  char tstring[] = "-9";
  int tdecimal = -9;
  char tchar = '8';
  float tfloat = -9;
  unsigned int tuint = 9;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(
      sprintf(str1, test_case, tstring, tdecimal, tchar, tfloat, tuint),
      s21_sprintf(str2, test_case, tstring, tdecimal, tchar, tfloat, tuint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_10) {
  char test_case[] =
      "\n%%:%%-END \ns:%s-END \nd:%d-END \nc:%c-END \nf:%f-END \nu:%u-END \n "
      "\n%%:%%-END \ns:%s-END \nd:%d-END \nc:%c-END \nf:%f-END \nu:%u-END \n";

  char tstring[] = "1\t ";
  int tdecimal = 0;
  char tchar = ' ';
  float tfloat = 0;
  unsigned int tuint = 999999999;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(
      sprintf(str1, test_case, tstring, tdecimal, tchar, tfloat, tuint, tstring,
              tdecimal, tchar, tfloat, tuint),
      s21_sprintf(str2, test_case, tstring, tdecimal, tchar, tfloat, tuint,
                  tstring, tdecimal, tchar, tfloat, tuint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_11) {
  char test_case[] =
      "\n%%:%%-END \ns:%s-END \nd:%d-END \nc:%c-END \nf:%f-END \nu:%u-END \n "
      "\n%%:%%-END \ns:%s-END \nd:%d-END \nc:%c-END \nf:%f-END \nu:%u-END \n";

  char tstring[] = "8tt54edh,itudmh,xol,\0\n\0y\tdfg";
  int tdecimal = -1;
  char tchar = '\0';
  float tfloat = -1;
  unsigned int tuint = 0;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(
      sprintf(str1, test_case, tstring, tdecimal, tchar, tfloat, tuint, tstring,
              tdecimal, tchar, tfloat, tuint),
      s21_sprintf(str2, test_case, tstring, tdecimal, tchar, tfloat, tuint,
                  tstring, tdecimal, tchar, tfloat, tuint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_12) {
  char test_case[] =
      "\n%%:%%-END \ns:%s-END \nd:%d-END \nc:%c-END \nf:%f-END \nu:%u-END \n "
      "\n%%:%%-END \ns:%s-END \nd:%d-END \nc:%c-END \nf:%f-END \nu:%u-END \n";

  char tstring[] = "8tt54edh,itudmh,xol,\0\n\0y\tdfg";
  int tdecimal = 1;
  char tchar = '5';
  float tfloat = 1;
  unsigned int tuint = 1;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(
      sprintf(str1, test_case, tstring, tdecimal, tchar, tfloat, tuint, tstring,
              tdecimal, tchar, tfloat, tuint),
      s21_sprintf(str2, test_case, tstring, tdecimal, tchar, tfloat, tuint,
                  tstring, tdecimal, tchar, tfloat, tuint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_13) {
  char test_case[] =
      "\n%%:%%-END \ns:%s-END \nd:%d-END \nc:%c-END \nf:%f-END \nu:%u-END \n "
      "\n%%:%%-END \ns:%s-END \nd:%d-END \nc:%c-END \nf:%f-END \nu:%u-END \n";

  char tstring[] = "8tt54edh,itudmh,xol,\0\n\0y\tdfg";
  int tdecimal = 64567578;
  char tchar = '5';
  double tfloat = 879345034.5438963126;
  unsigned int tuint = 93463215;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(
      sprintf(str1, test_case, tstring, tdecimal, tchar, tfloat, tuint, tstring,
              tdecimal, tchar, tfloat, tuint),
      s21_sprintf(str2, test_case, tstring, tdecimal, tchar, tfloat, tuint,
                  tstring, tdecimal, tchar, tfloat, tuint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_14) {
  char test_case[] =
      "\n%%:%%-END \ns:%s-END \nd:%d-END \nc:%c-END \nf:%f-END \nu:%u-END \n "
      "\n%%:%%-END \ns:%s-END \nd:%d-END \nc:%c-END \nf:%f-END \nu:%u-END \n";

  char tstring[] = "8tt54edh,itudmh,xol,\0\n\0y\tdfg";
  int tdecimal = -64567578;
  char tchar = '5';
  double tfloat = -0.12354;
  unsigned int tuint = 95;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(
      sprintf(str1, test_case, tstring, tdecimal, tchar, tfloat, tuint, tstring,
              tdecimal, tchar, tfloat, tuint),
      s21_sprintf(str2, test_case, tstring, tdecimal, tchar, tfloat, tuint,
                  tstring, tdecimal, tchar, tfloat, tuint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_15) {
  char test_case[] = "\n%%:%%-END\n\nf:%f-END \n\n%s\n";

  char tstring[] = "8954yfodid.p\nkpo\nt4i89sy67\tt458";
  double tfloat = 65687324.534879562893746e7;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tfloat, tfloat, tstring),
                   s21_sprintf(str2, test_case, tfloat, tfloat, tstring));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_16) {
  char test_case[] = "\n%%:%%-END f:%f-END \nf:%f-END %s\n";

  char tstring[] = "8954yfodid.p\nkpo\nt4i89sy67\tt458";
  double tfloat = -155948356767445235.467863874983;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tfloat, tfloat, tstring),
                   s21_sprintf(str2, test_case, tfloat, tfloat, tstring));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_17) {
  char test_case[] = "\n%%:%%-END f:%f-END \nf:%f-END %s\n";

  char tstring[] = "8954yfodid.p\nkpo\nt4i89sy67\tt458";
  double tfloat = 155948356767e4;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tfloat, tfloat, tstring),
                   s21_sprintf(str2, test_case, tfloat, tfloat, tstring));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_18) {
  char test_case[] = "\n%%:%%-END f:%f-END \nf:%f-END %s\n";

  char tstring[] = "8954yfodid.p\nkpo\nt4i89sy67\tt458";
  double tfloat = 15594835;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tfloat, tfloat, tstring),
                   s21_sprintf(str2, test_case, tfloat, tfloat, tstring));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_19) {
  char test_case[] = "";

  char tstring[] = "1\t ";
  int tdecimal = 0;
  char tchar = ' ';
  float tfloat = 0;
  unsigned int tuint = 999999999;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(
      sprintf(str1, test_case, tstring, tdecimal, tchar, tfloat, tuint),
      s21_sprintf(str2, test_case, tstring, tdecimal, tchar, tfloat, tuint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_20) {
  char *str1 = malloc(500);
  char *str2 = malloc(500);

  char *test_case = malloc(10);
  test_case[0] = '0';
  test_case[1] = '\0';

  ck_assert_int_eq(sprintf(str1, test_case, 1),
                   s21_sprintf(str2, test_case, 1));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
  if (test_case != S21_NULL) free(test_case);
}
END_TEST

START_TEST(sprintf_21) {
  char test_case[] = "\n%%f:%%f-END \nf:%.11f-END \n";

  double tfloat = 15594835.12375;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tfloat, tfloat),
                   s21_sprintf(str2, test_case, tfloat, tfloat));

  ck_assert_str_eq(str1, str2);

  // printf("\n\ndef:%s\n\ns21:%s\n\n", str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_22) {
  char test_case[] = "\n%%f:%%f-END \nf:%.11f-END \n";

  double tfloat = 15594835;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tfloat, tfloat),
                   s21_sprintf(str2, test_case, tfloat, tfloat));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_23) {
  char test_case[] = "\n%%f:%%f-END \nf:%.1f-END \n";

  double tfloat = 15594835.678456;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tfloat),
                   s21_sprintf(str2, test_case, tfloat));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_24) {
  char test_case[] = "\n%%f:%%f-END \nf:%.000f-END \n";

  double tfloat = 15.6345634654;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tfloat),
                   s21_sprintf(str2, test_case, tfloat));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_25) {
  char test_case[] = "\n%%f:%%f-END \nf:%.1d-END \n";

  double tfloat = 15.6345634654;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tfloat),
                   s21_sprintf(str2, test_case, tfloat));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_26) {
  char test_case[] = "\n%%f:%%f-END \nf:%.00000000000000121f-END \n";

  double tfloat = 15594835;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tfloat),
                   s21_sprintf(str2, test_case, tfloat));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_27) {
  char test_case[] = "\n%%f:%%f-END \nf:%.r-END \n f:%..-END \n";

  double tfloat = 15594835;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tfloat),
                   s21_sprintf(str2, test_case, tfloat));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_28) {
  char test_case[] = "\n\nd:%.11d-END \n\n";

  int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_29) {
  char test_case[] = "\n\nd:%.d-END \n\n";

  int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_30) {
  char test_case[] = "\n\nd:%.0d-END \n\n";

  int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_31) {
  char test_case[] = "\n%%f:%%f-END \nf:%r-END \n";

  double tfloat = 15594835;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tfloat),
                   s21_sprintf(str2, test_case, tfloat));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_32) {
  char test_case[] = "\n\nd:%.r0d-END \n\n";

  int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_33) {
  char test_case[] = "\n\nd:%.0u-END \n\n";

  unsigned int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_34) {
  char test_case[] = "\n\nd:%.000235413-END \n\n";

  unsigned tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_35) {
  char test_case[] = "\n\nd:%.u-END \n\n";

  unsigned tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_36) {
  char test_case[] = "\n\nd:%.13c\n\n";

  unsigned tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_37) {
  char test_case[] = "\n\nd:%.23541\n\n";

  int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_38) {
  char test_case[] = "\n\nd:%.2\n\n";

  int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_39) {
  char test_case[] = "\n\nd:%.2rd\n\n";

  int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_40) {
  char test_case[] = "\n\nd:%.5s-END \n\n";

  char tstr[] = "asd12345";

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tstr),
                   s21_sprintf(str2, test_case, tstr));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_41) {
  char test_case[] = "\n\nd:%.s-END \n\n";

  char tstr[] = "asd12345";

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tstr),
                   s21_sprintf(str2, test_case, tstr));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_42) {
  char test_case[] = "\n\nd:%.0s-END \n\n";

  char tstr[] = "asd12345";

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tstr),
                   s21_sprintf(str2, test_case, tstr));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_43) {
  char test_case[] = "\n\nd:%.22s-END \n\n";

  char tstr[] = "asd12345";

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tstr),
                   s21_sprintf(str2, test_case, tstr));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_44) {
  char test_case[] = "\n\nd:%.7s-END \n\n";

  char tstr[] = "asd12345";

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tstr),
                   s21_sprintf(str2, test_case, tstr));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_45) {
  char test_case[] = "\n\nd:%.8s-END \n\n";

  char tstr[] = "asd12345";

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tstr),
                   s21_sprintf(str2, test_case, tstr));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_46) {
  char test_case[] = "\n\nd:%.9s-END \n\n";

  char tstr[] = "asd12345";

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tstr),
                   s21_sprintf(str2, test_case, tstr));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_47) {
  char test_case[] = "\n\nd:%f-END \n\n";

  float asd = 22.22;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, asd),
                   s21_sprintf(str2, test_case, asd));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_48) {
  char test_case[] = "\n\nd:%.10s-END \n\n";

  char tstr[] = "asd12345";

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tstr),
                   s21_sprintf(str2, test_case, tstr));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_49) {
  char test_case[] = "\n\nd:%.0rq-END \n\n";

  char tstr[] = "asd12345";

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tstr),
                   s21_sprintf(str2, test_case, tstr));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_50) {
  char test_case[] = "\n\nd:%.rq-END \n\n";

  char tstr[] = "asd12345";

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tstr),
                   s21_sprintf(str2, test_case, tstr));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_51) {
  char test_case[] = "\n\nd:%.f-END \n\n";

  float asd = 22.22;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, asd),
                   s21_sprintf(str2, test_case, asd));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_52) {
  char test_case[] = "\n\nd:%.1f-END \n\n";

  float asd = 42.21;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, asd),
                   s21_sprintf(str2, test_case, asd));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_53) {
  char test_case[] =
      "\n%%:%%-END \ns:%s-END \nd:%.10d-END \nc:%c-END \nf:%.11f-END "
      "\nu:%u-END "
      "\n";

  char tstring[] =
      "-go58mmmmmmuy98f5,"
      "ypdhcgdxoiiiiiiiiikucfzsdce4tufhmtufhmtufhmtufhmtufhml";
  int tdecimal = 407560;
  char tchar = '\010';
  double tfloat = 6451.345;
  unsigned int tuint = 0;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(
      sprintf(str1, test_case, tstring, tdecimal, tchar, tfloat, tuint),
      s21_sprintf(str2, test_case, tstring, tdecimal, tchar, tfloat, tuint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_54) {
  char test_case[] = "\n\nd:%.0f-END \n\n";

  float asd = 22.22;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, asd),
                   s21_sprintf(str2, test_case, asd));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_55) {
  char test_case[] = "\n\nd:%.0f-END \n\n";

  float asd = 22.22;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, asd),
                   s21_sprintf(str2, test_case, asd));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_56) {
  char test_case[] = "\n\ns:%3s-END \n\n";

  char tstr[] = "123";

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tstr),
                   s21_sprintf(str2, test_case, tstr));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_57) {
  char test_case[] = "\n\ns:%2s-END \n\n";

  char tstr[] = "123";

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tstr),
                   s21_sprintf(str2, test_case, tstr));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_58) {
  char test_case[] = "\n\ns:%4s-END \n\n";

  char tstr[] = "123";

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tstr),
                   s21_sprintf(str2, test_case, tstr));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_59) {
  char test_case[] = "\n\ns:%4.1s-END \n\n";

  char tstr[] = "123";

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tstr),
                   s21_sprintf(str2, test_case, tstr));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_60) {
  char test_case[] = "\n\ns:%4.7s-END \n\n";

  char tstr[] = "123";

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tstr),
                   s21_sprintf(str2, test_case, tstr));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_61) {
  char test_case[] = "\n\ns:%4.s-END \n\n";

  char tstr[] = "123";

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tstr),
                   s21_sprintf(str2, test_case, tstr));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_62) {
  char test_case[] = "\n\ns:%.7s-END \n\n";

  char tstr[] = "123";

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tstr),
                   s21_sprintf(str2, test_case, tstr));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_63) {
  char test_case[] = "\n\ns:%0d-END \n\n";

  int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_64) {
  char test_case[] = "\n\ns:%0.d-END \n\n";

  int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_65) {
  char test_case[] = "\n\ns:%0.0d-END \n\n";

  int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_66) {
  char test_case[] = "\n\ns:%2d-END \n\n";

  int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_67) {
  char test_case[] = "\n\ns:%3d-END \n\n";

  int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_68) {
  char test_case[] = "\n\ns:%4d-END \n\n";

  int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_69) {
  char test_case[] = "\n\ns:%10d-END \n\n";

  int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_70) {
  char test_case[] = "\n\ns:%2.4d-END \n\n";

  char tstr[] = "123";

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tstr),
                   s21_sprintf(str2, test_case, tstr));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_71) {
  char test_case[] = "\n\ns:%2.d-END \n\n";

  int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_72) {
  char test_case[] = "\n\ns:%3.d-END \n\n";

  int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_73) {
  char test_case[] = "\n\ns:%4.d-END \n\n";

  int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_74) {
  char test_case[] = "\n\ns:% 5.7ld-END \n\n";

  long int tint = -123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_75) {
  char test_case[] = "\n\ns:% -5.7ld-END \n\n";

  long int tint = 0;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_76) {
  char test_case[] = "\n\ns:%22.7e-END \n\n";

  double tint = 12345678912345.0;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_77) {
  char test_case[] = "\n\ns:%+-5.7ld-END \n\n";

  long int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_78) {
  char test_case[] = "\n\ns:%2.3d-END \n\n";

  int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_79) {
  char test_case[] = "\n\ns:%- 22.7f-END \n\n";

  float tint = 1234545.0;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_80) {
  char test_case[] = "\n\ns:%- 3.3d-END \n\n";

  int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_81) {
  char test_case[] = "\n\ns:%-+4.1d-END \n\n";

  int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_82) {
  char test_case[] = "\n\ns:%4.3d-END \n\n";

  int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_83) {
  char test_case[] = "\n\ns:%0.1d-END \n\n";

  int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_84) {
  char test_case[] = "\n\ns:%0.2d-END \n\n";

  int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_85) {
  char test_case[] = "\n\ns:%0.3d-END \n\n";

  int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_86) {
  char test_case[] = "\n\ns:%2u-END \n\n";

  unsigned int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_87) {
  char test_case[] = "\n\ns:%3u-END \n\n";

  unsigned int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_88) {
  char test_case[] = "\n\ns:%4u-END \n\n";

  unsigned int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_89) {
  char test_case[] = "\n\ns:%2.7u-END \n\n";

  unsigned int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_90) {
  char test_case[] = "\n\ns:%15r-END \n\n";

  unsigned int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_91) {
  char test_case[] = "\n\ns:%.6d-END \n\n";

  int tint = -123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_92) {
  char test_case[] = "\n\ns:%.5d-END \n\n";

  int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_93) {
  char test_case[] = "\n\ns:%+d-END \n\n";

  int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_94) {
  char test_case[] = "\n\ns:%+.5d-END \n\n";

  int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_95) {
  char test_case[] = "\n\ns:%+5.5f-END \n\n";

  float tfloat = 123.23;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tfloat),
                   s21_sprintf(str2, test_case, tfloat));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_96) {
  char test_case[] = "\n\ns:%+1.5u-END \n\n";

  unsigned int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_97) {
  char test_case[] = "\n\ns:%+u-END \n\n";

  unsigned int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_98) {
  char test_case[] = "\n\ns:%+.5u-END \n\n";

  unsigned int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_99) {
  char test_case[] = "\n\ns:%+.5d-END \n\n";

  int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_100) {
  char test_case[] = "\n\ns:%+f-END \n\n";

  float tfloat = 123.2465;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tfloat),
                   s21_sprintf(str2, test_case, tfloat));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_101) {
  char test_case[] = "\n\ns:%3c-END \n\n";

  char tint = '2';

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_102) {
  char test_case[] = "\n\ns:%+d-END \n\n";

  int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_103) {
  char test_case[] = "\n\ns:% d-END \n\n";

  int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_104) {
  char test_case[] = "\n\ns:% u-END \n\n";

  unsigned int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_105) {
  char test_case[] = "\n\ns:%+ d-END \n\n";

  int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_106) {
  char test_case[] = "\n\ns:%+ u-END \n\n";

  unsigned int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_107) {
  char test_case[] = "\n\ns:%+u-END \n\n";

  unsigned int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_108) {
  char test_case[] = "\n\ns:%+d-END \n\n";

  int tint = 0;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_109) {
  char test_case[] = "\n\ns:% f-END \n\n";

  float tint = 123.456;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_110) {
  char test_case[] = "\n\ns:%+ f-EN +D\n\n";

  float tint = 123.456;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_111) {
  char test_case[] = "\n\ns:%d-EN +-D\n\n";

  int tint = 1234;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_112) {
  char test_case[] = "\n\ns:%+ d-EN +-D\n\n";

  int tint = 0;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_113) {
  char test_case[] = "\n\ns:% d-EN +-D\n\n";

  int tint = 0;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_114) {
  char test_case[] = "\n\ns:%+ f-EN +-D\n\n";

  float tint = 0;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_115) {
  char test_case[] = "\n\ns:% f-EN +-D\n\n";

  float tint = 1234;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_116) {
  char test_case[] = "\n\ns:%-7d-EN +-D\n\n";

  int tint = 1234;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_117) {
  char test_case[] = "\n\ns:%-0d-EN +-D\n\n";

  int tint = 1234;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_118) {
  char test_case[] = "\n\ns:%-6u-EN +-D\n\n";

  unsigned int tint = 1234;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_119) {
  char test_case[] = "\n\ns:%-6f-EN +-D\n\n";

  float tint = 1234;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_120) {
  char test_case[] = "\n\ns:%-6.3d-EN +-D\n\n";

  int tint = 0;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_121) {
  char test_case[] = "\n\ns:%Lf-EN +-D\n\n";

  long double tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_122) {
  char test_case[] = "\n\ns:%ludd-EN +-D\n\n";

  long unsigned int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_123) {
  char test_case[] = "\n\ns:%-6.6ld-EN +-D\n\n";

  long int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_124) {
  char test_case[] = "\n\ns:%-6.6luu-EN +-D\n\n";

  long unsigned int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_125) {
  char test_case[] = "\n\ns:%+3ld-EN +-D\n\n";

  long int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_126) {
  char test_case[] = "\n\ns:%hd-EN +-D\n\n";

  short int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_127) {
  char test_case[] = "\n\ns:%-6.6hd-EN +-D\n\n";

  short int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_128) {
  char test_case[] = "\n\ns:%+6.6hd-EN +-D\n\n";

  short int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_129) {
  char test_case[] = "\n\ns:%hu-EN +-D\n\n";

  short unsigned int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_130) {
  char test_case[] = "\n\ns:%-6.6hu-EN +-D\n\n";

  short unsigned int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_131) {
  char test_case[] = "\n\nd:%p-END \n\n";

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  sprintf(str1, test_case, NULL), s21_sprintf(str2, test_case, NULL);

  ck_assert_str_eq(str1, str2);
  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_132) {
  char test_case[] = "\n\nd:%+s-END \n\n";

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, NULL),
                   s21_sprintf(str2, test_case, NULL));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_133) {
  char test_case[] = "\n\nd:%p-END \n\n";

  double *tdbl = malloc(sizeof(double));
  *tdbl = 22.22;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tdbl),
                   s21_sprintf(str2, test_case, tdbl));

  ck_assert_str_eq(str1, str2);

  if (tdbl != S21_NULL) free(tdbl);
  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_134) {
  char test_case[] = "\n\nd:%+s-END \n\n";

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, "asd"),
                   s21_sprintf(str2, test_case, "asd"));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_135) {
  char test_case[] = "\n\nd:%+p-END \n\n";

  double *tdbl = malloc(sizeof(double));
  *tdbl = 22.22;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tdbl),
                   s21_sprintf(str2, test_case, tdbl));

  ck_assert_str_eq(str1, str2);

  if (tdbl != S21_NULL) free(tdbl);
  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_136) {
  char test_case[] = "\n\nd:%-+ 20p-END \n\n";

  double *tdbl = malloc(sizeof(double));
  *tdbl = 22.22;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tdbl),
                   s21_sprintf(str2, test_case, tdbl));

  ck_assert_str_eq(str1, str2);

  if (tdbl != S21_NULL) free(tdbl);
  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_137) {
  char test_case[] = "\n\nd:%.20p-END \n\n";

  double *tdbl = malloc(sizeof(double));
  *tdbl = 22.22;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tdbl),
                   s21_sprintf(str2, test_case, tdbl));

  ck_assert_str_eq(str1, str2);

  if (tdbl != S21_NULL) free(tdbl);
  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_138) {
  char test_case[] = "\n\nd:%20.20p-END \n\n";

  double *tdbl = malloc(sizeof(double));
  *tdbl = 22.22;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tdbl),
                   s21_sprintf(str2, test_case, tdbl));

  ck_assert_str_eq(str1, str2);

  if (tdbl != S21_NULL) free(tdbl);
  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_139) {
  char test_case[] = "\n\nd:% p-END \n\n";

  double *tdbl = malloc(sizeof(double));
  *tdbl = 22.22;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tdbl),
                   s21_sprintf(str2, test_case, tdbl));

  ck_assert_str_eq(str1, str2);

  if (tdbl != S21_NULL) free(tdbl);
  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_140) {
  char test_case[] = "\n\nd:%- 20p-END \n\n";

  double tdbl = 5.123456789;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tdbl),
                   s21_sprintf(str2, test_case, tdbl));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_141) {
  char test_case[] = "\n\nd:%5c-END \n\n";

  char tchar = 'b';

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tchar),
                   s21_sprintf(str2, test_case, tchar));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_142) {
  char test_case[] = "\n\nd:%.5c-END \n\n";

  char tchar = 'b';

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tchar),
                   s21_sprintf(str2, test_case, tchar));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_143) {
  char test_case[] = "\n\nd:%5.5c-END \n\n";

  char tchar = 'b';

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tchar),
                   s21_sprintf(str2, test_case, tchar));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_144) {
  char test_case[] = "\n\nd:%.c-END \n\n";

  char tchar = 'b';

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tchar),
                   s21_sprintf(str2, test_case, tchar));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_145) {
  char test_case[] = "\n\nd:%+5.5c-END \n\n";

  char tchar = 'b';

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tchar),
                   s21_sprintf(str2, test_case, tchar));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_146) {
  char test_case[] = "\n\nd:%-5.5c-END \n\n";

  char tchar = 'b';

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tchar),
                   s21_sprintf(str2, test_case, tchar));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_147) {
  char test_case[] = "\n\nd:% 5.5c-END \n\n";

  char tchar = 'b';

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tchar),
                   s21_sprintf(str2, test_case, tchar));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_148) {
  char test_case[] = "\n\nd:% c-END \n\n";

  char tchar = 'b';

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tchar),
                   s21_sprintf(str2, test_case, tchar));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_149) {
  char test_case[] = "\n\nd:% +-5.5s-END \n\n";

  char *tstr = "asdasdasd";

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tstr),
                   s21_sprintf(str2, test_case, tstr));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_150) {
  char test_case[] = "\n\nd:% +-5.5s-END \n\n";

  char *tstr = "a";

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tstr),
                   s21_sprintf(str2, test_case, tstr));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_151) {
  char test_case[] = "\n\nd:%o-END \n\n";

  unsigned int tuint = 123456789;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tuint),
                   s21_sprintf(str2, test_case, tuint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_152) {
  char test_case[] = "\n\nd:%9o-END \n\n";

  unsigned int tuint = 123456789;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tuint),
                   s21_sprintf(str2, test_case, tuint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_153) {
  char test_case[] = "\n\nd:%.9o-END \n\n";

  unsigned int tuint = 123456789;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tuint),
                   s21_sprintf(str2, test_case, tuint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_154) {
  char test_case[] = "\n\nd:%+9.9o-END \n\n";

  unsigned int tuint = 123456789;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tuint),
                   s21_sprintf(str2, test_case, tuint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_155) {
  char test_case[] = "\n\nd:%-9.9o-END \n\n";

  unsigned int tuint = 123456789;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tuint),
                   s21_sprintf(str2, test_case, tuint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_156) {
  char test_case[] = "\n\nd:%x-END \n\n";

  unsigned int tuint = 123456789;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tuint),
                   s21_sprintf(str2, test_case, tuint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_157) {
  char test_case[] = "\n\nd:%X-END \n\n";

  unsigned int tuint = 123456789;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tuint),
                   s21_sprintf(str2, test_case, tuint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_158) {
  char test_case[] = "\n\nd:%.15x-END \n\n";

  unsigned int tuint = 123456789;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tuint),
                   s21_sprintf(str2, test_case, tuint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_159) {
  char test_case[] = "\n\nd:%15.15X-END \n\n";

  unsigned int tuint = 123456789;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tuint),
                   s21_sprintf(str2, test_case, tuint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_160) {
  char test_case[] = "\n\nd:%0.0x-END \n\n";

  unsigned int tuint = 123456789;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tuint),
                   s21_sprintf(str2, test_case, tuint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_161) {
  char test_case[] = "\n\nd:%0d-END \n\n";

  int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_162) {
  char test_case[] = "\n\nd:%05d-END \n\n";

  int tint = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_163) {
  char test_case[] = "\n\nd:%011f-END \n\n";

  float tint = 123.123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_164) {
  char test_case[] = "\n\nd:%05s-END \n\n";

  char *tstr = "asd";

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tstr),
                   s21_sprintf(str2, test_case, tstr));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_165) {
  char test_case[] = "\n\nd:%011.11s-END \n\n";

  char *tstr = S21_NULL;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tstr),
                   s21_sprintf(str2, test_case, tstr));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_166) {
  char test_case[] = "\n\nd:%01.3p-END \n\n";

  char *tstr = S21_NULL;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  sprintf(str1, test_case, tstr), s21_sprintf(str2, test_case, tstr);

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_167) {
  char test_case[] = "\n\nd:%+0*d-END \n\n";

  int tint = 123;
  int width = 11;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, width, tint),
                   s21_sprintf(str2, test_case, width, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_168) {
  char test_case[] = "\n\nd:%+0*.11d-END \n\n";

  int tint = 123;
  int width = 11;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, width, tint),
                   s21_sprintf(str2, test_case, width, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_169) {
  char test_case[] = "\n\nd:%+ 0*.*d-END \n\n";

  int tint = 123;
  int width = 11;
  int precision = 11;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, width, precision, tint),
                   s21_sprintf(str2, test_case, width, precision, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_170) {
  char test_case[] = "\n\nd:%*.*g-END \n\n";

  float tfloat = -1244567890.123465;
  int width = 11;
  int precision = 11;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, width, precision, tfloat),
                   s21_sprintf(str2, test_case, width, precision, tfloat));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_171) {
  char test_case[] = "\n\nd:%*.*f-END \n\n";

  float tfloat = -1244567890.123465;
  int width = 11;
  int precision = 11;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, width, precision, tfloat),
                   s21_sprintf(str2, test_case, width, precision, tfloat));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_172) {
  char test_case[] = "\n\nd:%*.*f-END \n\n";

  float tfloat = -1244567890.123465;
  int width = 11;
  int precision = 11;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, width, precision, tfloat),
                   s21_sprintf(str2, test_case, width, precision, tfloat));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_173) {
  char test_case[] = "\n\nd:%*.*f-END \n\n";

  float tfloat = -1244567890.123465;
  int width = 11;
  int precision = 11;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, width, precision, tfloat),
                   s21_sprintf(str2, test_case, width, precision, tfloat));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_174) {
  char test_case[] = "\n\nd:%*.*f-END \n\n";

  float tfloat = -1244567890.123465;
  int width = 11;
  int precision = 11;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, width, precision, tfloat),
                   s21_sprintf(str2, test_case, width, precision, tfloat));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_175) {
  char test_case[] = "\n\nd:%*.*c-END \n\n";

  int tchar = 'A';
  int width = 11;
  int precision = 11;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, width, precision, tchar),
                   s21_sprintf(str2, test_case, width, precision, tchar));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_176) {
  char test_case[] = "\n\nd:%*.*s-END \n\n";

  char *tstring = "Hello, World!";
  int width = 11;
  int precision = 11;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, width, precision, tstring),
                   s21_sprintf(str2, test_case, width, precision, tstring));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_177) {
  char test_case[] = "\n\nd:%*.*p-END \n\n";

  void *tptr = (void *)0x12345678;
  int width = 1;
  int precision = 3;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  sprintf(str1, test_case, width, precision, tptr),
      s21_sprintf(str2, test_case, width, precision, tptr);

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_178) {
  char test_case[] = "\n\nd:%*.*u-END \n\n";

  int tint = 1234567890;
  int width = 11;
  int precision = 11;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, width, precision, tint),
                   s21_sprintf(str2, test_case, width, precision, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_179) {
  char test_case[] = "\n\nd:%*.*o-END \n\n";

  int tint = 1234567890;
  int width = 11;
  int precision = 11;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, width, precision, tint),
                   s21_sprintf(str2, test_case, width, precision, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_180) {
  char test_case[] = "\n\nd:%*.*x-END \n\n";

  int tint = 1234567890;
  int width = 11;
  int precision = 11;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, width, precision, tint),
                   s21_sprintf(str2, test_case, width, precision, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_181) {
  char test_case[] = "\n\nd:%-10c-END \n\n";

  int tchar = 'A';

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tchar),
                   s21_sprintf(str2, test_case, tchar));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_182) {
  char test_case[] = "\n\nd:%+10d-END \n\n";

  int tint = 1234567890;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_183) {
  char test_case[] = "\n\nd:% 10f-END \n\n";

  float tfloat = -1244567890.123465;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tfloat),
                   s21_sprintf(str2, test_case, tfloat));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_184) {
  char test_case[] = "\n\nd:%010s-END \n\n";

  char *tstring = "Hello, World!";

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tstring),
                   s21_sprintf(str2, test_case, tstring));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_185) {
  char test_case[] = "\n\nd:%-10u-END \n\n";

  unsigned int tint = 1234567890;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_186) {
  char test_case[] = "\n\nd:%-11d-END \n\n";

  unsigned int tint = 1234567890;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tint),
                   s21_sprintf(str2, test_case, tint));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_187) {
  char test_case[] = "\n\nd:% 10f-END \n\n";

  float tfloat = -1244567890.123465;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tfloat),
                   s21_sprintf(str2, test_case, tfloat));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_188) {
  char test_case[] = "\n\nd:%010f-END \n\n";

  float tfloat = -1244567890.123465;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tfloat),
                   s21_sprintf(str2, test_case, tfloat));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_189) {
  char test_case[] = "\n\nd:%-10f-END \n\n";

  float tfloat = -1244567890.123465;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tfloat),
                   s21_sprintf(str2, test_case, tfloat));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_190) {
  char test_case[] = "\n\nd:%+10f-END \n\n";

  float tfloat = -1244567890.123465;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tfloat),
                   s21_sprintf(str2, test_case, tfloat));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_191) {
  char test_case[] = "\n\nd:%.6e-END \n\n";

  float tfloat = 123.4567;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tfloat),
                   s21_sprintf(str2, test_case, tfloat));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_192) {
  char test_case[] = "\n\nd:%5e-END \n\n";

  float tfloat = 2;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tfloat),
                   s21_sprintf(str2, test_case, tfloat));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_193) {
  char test_case[] = "\n\nd:%.6e-END \n\n";

  float tfloat = -123.4567;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tfloat),
                   s21_sprintf(str2, test_case, tfloat));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_194) {
  char test_case[] = "\n\nd:%5e-END \n\n";

  float tfloat = -2;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tfloat),
                   s21_sprintf(str2, test_case, tfloat));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_195) {
  char test_case[] = "\n\nd:%5e-END \n\n";

  float tfloat = 0;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tfloat),
                   s21_sprintf(str2, test_case, tfloat));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_196) {
  char test_case[] = "\n\nd:%5.0e-END \n\n";

  float tfloat = 0;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tfloat),
                   s21_sprintf(str2, test_case, tfloat));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_197) {
  char test_case[] = "\n\nd:%E-END \n\n";

  float tfloat = 123.4567;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tfloat),
                   s21_sprintf(str2, test_case, tfloat));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_198) {
  char test_case[] = "\n\nd:%E-END \n\n";

  float tfloat = -123.4567;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tfloat),
                   s21_sprintf(str2, test_case, tfloat));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_199) {
  char test_case[] = "\n\nd:%E-END \n\n";

  float tfloat = 0;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tfloat),
                   s21_sprintf(str2, test_case, tfloat));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_200) {
  char test_case[] = "\n\nd:%+- 6.6E-END \n\n";

  float tfloat = 12345678.7894353123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tfloat),
                   s21_sprintf(str2, test_case, tfloat));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_201) {
  char test_case[] = "\n\nd:%-+ 0*.*g-END \n\n";

  int width = 33;
  int precision = 11;
  float tfloat = 6547689234.64565425357;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, width, precision, tfloat),
                   s21_sprintf(str2, test_case, width, precision, tfloat));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_202) {
  char test_case[] = "\n\nd:%.4g-END \n\n";

  float tfloat = 123.4567;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tfloat),
                   s21_sprintf(str2, test_case, tfloat));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_203) {
  char test_case[] = "\n\nd:%.3g-END \n\n";

  float tfloat = 123.4567;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tfloat),
                   s21_sprintf(str2, test_case, tfloat));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_204) {
  char test_case[] = "\n\nd:%.2g-END \n\n";

  float tfloat = 123.4567;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tfloat),
                   s21_sprintf(str2, test_case, tfloat));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_205) {
  char test_case[] = "\n\nd:%.1G-END \n\n";

  float tfloat = 12345.456778;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tfloat),
                   s21_sprintf(str2, test_case, tfloat));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_206) {
  char test_case[] = "\n\nd:%+- 011.0G-END \n\n";

  float tfloat = 123.4567;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tfloat),
                   s21_sprintf(str2, test_case, tfloat));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_207) {
  char test_case[] = "\n\nd:%+ -6.6G-END \n\n";

  float tfloat = 123.4567;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tfloat),
                   s21_sprintf(str2, test_case, tfloat));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_208) {
  char test_case[] = "\n\nd:%6G-END \n\n";

  float tfloat = 12345.456778;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tfloat),
                   s21_sprintf(str2, test_case, tfloat));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_209) {
  char test_case[] = "\n\nd:%.5G-END \n\n";

  float tfloat = 12345.456778;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tfloat),
                   s21_sprintf(str2, test_case, tfloat));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_210) {
  char test_case[] = "\n\nd:%.4G-END \n\n";

  float tfloat = 12345.456778;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tfloat),
                   s21_sprintf(str2, test_case, tfloat));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_211) {
  char test_case[] = "\n\nd:%+- 0#15.0e-END \n\n";

  double tdbl = 123456789;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tdbl),
                   s21_sprintf(str2, test_case, tdbl));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_212) {
  char test_case[] = "\n\nd:%+- 0#15.0G-END \n\n";

  double tdbl = 123456789;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tdbl),
                   s21_sprintf(str2, test_case, tdbl));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_213) {
  char test_case[] = "\n\nd:%+- 0#15.0g-END \n\n";

  double tdbl = 123456789;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tdbl),
                   s21_sprintf(str2, test_case, tdbl));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_214) {
  char test_case[] = "\n\nd:%+- 0#15.0f-END \n\n";

  double tdbl = 123456789;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tdbl),
                   s21_sprintf(str2, test_case, tdbl));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_215) {
  char test_case[] = "\n\nd:%+- 0#15.0E-END \n\n";

  double tdbl = 123456789;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, tdbl),
                   s21_sprintf(str2, test_case, tdbl));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_216) {
  char test_case[] = "\n\nd:%+- 0#15.5X-END \n\n";

  long unsigned int toctal = 0;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, toctal),
                   s21_sprintf(str2, test_case, toctal));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_217) {
  char test_case[] = "\n\nd:%+- 0#0.0x-END \n\n";

  long unsigned int toctal = 123456789;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, toctal),
                   s21_sprintf(str2, test_case, toctal));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_218) {
  char test_case[] = "\n\nd:%+- 0#6.6X-END \n\n";

  long unsigned int toctal = 123;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, toctal),
                   s21_sprintf(str2, test_case, toctal));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_219) {
  char test_case[] = "\n\nd:%.5o-END \n\n";

  long unsigned int toctal = 123456789;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, toctal),
                   s21_sprintf(str2, test_case, toctal));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

START_TEST(sprintf_220) {
  char test_case[] = "\n\nd:%+- 0#15.5o-END \n\n";

  long unsigned int toctal = 123456789;

  char *str1 = malloc(500);
  char *str2 = malloc(500);

  ck_assert_int_eq(sprintf(str1, test_case, toctal),
                   s21_sprintf(str2, test_case, toctal));

  ck_assert_str_eq(str1, str2);

  if (str1 != S21_NULL) free(str1);
  if (str2 != S21_NULL) free(str2);
}
END_TEST

int main(void) {
  int failed = 0;
  Suite *s1 = suite_create("sprintf()_tests");
  TCase *tc1_1 = tcase_create("sprintf()_tests");
  SRunner *sr = srunner_create(s1);

  // srunner_set_fork_status(sr, CK_NOFORK);

  tcase_add_test(tc1_1, sprintf_1);
  tcase_add_test(tc1_1, sprintf_2);
  tcase_add_test(tc1_1, sprintf_3);
  tcase_add_test(tc1_1, sprintf_4);
  tcase_add_test(tc1_1, sprintf_5);
  tcase_add_test(tc1_1, sprintf_6);
  tcase_add_test(tc1_1, sprintf_7);
  tcase_add_test(tc1_1, sprintf_8);
  tcase_add_test(tc1_1, sprintf_9);
  tcase_add_test(tc1_1, sprintf_10);
  tcase_add_test(tc1_1, sprintf_11);
  tcase_add_test(tc1_1, sprintf_12);
  tcase_add_test(tc1_1, sprintf_13);
  tcase_add_test(tc1_1, sprintf_14);
  tcase_add_test(tc1_1, sprintf_15);
  tcase_add_test(tc1_1, sprintf_16);
  tcase_add_test(tc1_1, sprintf_17);
  tcase_add_test(tc1_1, sprintf_18);
  tcase_add_test(tc1_1, sprintf_19);
  tcase_add_test(tc1_1, sprintf_20);
  tcase_add_test(tc1_1, sprintf_21);
  tcase_add_test(tc1_1, sprintf_22);
  tcase_add_test(tc1_1, sprintf_23);
  tcase_add_test(tc1_1, sprintf_24);
  tcase_add_test(tc1_1, sprintf_25);
  tcase_add_test(tc1_1, sprintf_26);
  tcase_add_test(tc1_1, sprintf_27);
  tcase_add_test(tc1_1, sprintf_28);
  tcase_add_test(tc1_1, sprintf_29);
  tcase_add_test(tc1_1, sprintf_30);
  tcase_add_test(tc1_1, sprintf_31);
  tcase_add_test(tc1_1, sprintf_32);
  tcase_add_test(tc1_1, sprintf_33);
  tcase_add_test(tc1_1, sprintf_34);
  tcase_add_test(tc1_1, sprintf_35);
  tcase_add_test(tc1_1, sprintf_36);
  tcase_add_test(tc1_1, sprintf_37);
  tcase_add_test(tc1_1, sprintf_38);
  tcase_add_test(tc1_1, sprintf_39);
  tcase_add_test(tc1_1, sprintf_40);
  tcase_add_test(tc1_1, sprintf_41);
  tcase_add_test(tc1_1, sprintf_42);
  tcase_add_test(tc1_1, sprintf_43);
  tcase_add_test(tc1_1, sprintf_44);
  tcase_add_test(tc1_1, sprintf_45);
  tcase_add_test(tc1_1, sprintf_46);
  tcase_add_test(tc1_1, sprintf_47);
  tcase_add_test(tc1_1, sprintf_48);
  tcase_add_test(tc1_1, sprintf_49);
  tcase_add_test(tc1_1, sprintf_50);
  tcase_add_test(tc1_1, sprintf_51);
  tcase_add_test(tc1_1, sprintf_52);
  tcase_add_test(tc1_1, sprintf_53);
  tcase_add_test(tc1_1, sprintf_54);
  tcase_add_test(tc1_1, sprintf_55);
  tcase_add_test(tc1_1, sprintf_56);
  tcase_add_test(tc1_1, sprintf_57);
  tcase_add_test(tc1_1, sprintf_58);
  tcase_add_test(tc1_1, sprintf_59);
  tcase_add_test(tc1_1, sprintf_60);
  tcase_add_test(tc1_1, sprintf_61);
  tcase_add_test(tc1_1, sprintf_62);
  tcase_add_test(tc1_1, sprintf_63);
  tcase_add_test(tc1_1, sprintf_64);
  tcase_add_test(tc1_1, sprintf_65);
  tcase_add_test(tc1_1, sprintf_66);
  tcase_add_test(tc1_1, sprintf_67);
  tcase_add_test(tc1_1, sprintf_68);
  tcase_add_test(tc1_1, sprintf_69);
  tcase_add_test(tc1_1, sprintf_70);
  tcase_add_test(tc1_1, sprintf_71);
  tcase_add_test(tc1_1, sprintf_72);
  tcase_add_test(tc1_1, sprintf_73);
  tcase_add_test(tc1_1, sprintf_74);
  tcase_add_test(tc1_1, sprintf_75);
  tcase_add_test(tc1_1, sprintf_76);
  tcase_add_test(tc1_1, sprintf_77);
  tcase_add_test(tc1_1, sprintf_78);
  tcase_add_test(tc1_1, sprintf_79);
  tcase_add_test(tc1_1, sprintf_80);
  tcase_add_test(tc1_1, sprintf_81);
  tcase_add_test(tc1_1, sprintf_82);
  tcase_add_test(tc1_1, sprintf_83);
  tcase_add_test(tc1_1, sprintf_84);
  tcase_add_test(tc1_1, sprintf_85);
  tcase_add_test(tc1_1, sprintf_86);
  tcase_add_test(tc1_1, sprintf_87);
  tcase_add_test(tc1_1, sprintf_88);
  tcase_add_test(tc1_1, sprintf_89);
  tcase_add_test(tc1_1, sprintf_90);
  tcase_add_test(tc1_1, sprintf_91);
  tcase_add_test(tc1_1, sprintf_92);
  tcase_add_test(tc1_1, sprintf_93);
  tcase_add_test(tc1_1, sprintf_94);
  tcase_add_test(tc1_1, sprintf_95);
  tcase_add_test(tc1_1, sprintf_96);
  tcase_add_test(tc1_1, sprintf_97);
  tcase_add_test(tc1_1, sprintf_98);
  tcase_add_test(tc1_1, sprintf_99);
  tcase_add_test(tc1_1, sprintf_100);
  tcase_add_test(tc1_1, sprintf_101);
  tcase_add_test(tc1_1, sprintf_102);
  tcase_add_test(tc1_1, sprintf_103);
  tcase_add_test(tc1_1, sprintf_104);
  tcase_add_test(tc1_1, sprintf_105);
  tcase_add_test(tc1_1, sprintf_106);
  tcase_add_test(tc1_1, sprintf_107);
  tcase_add_test(tc1_1, sprintf_108);
  tcase_add_test(tc1_1, sprintf_109);
  tcase_add_test(tc1_1, sprintf_110);
  tcase_add_test(tc1_1, sprintf_111);
  tcase_add_test(tc1_1, sprintf_112);
  tcase_add_test(tc1_1, sprintf_113);
  tcase_add_test(tc1_1, sprintf_114);
  tcase_add_test(tc1_1, sprintf_115);
  tcase_add_test(tc1_1, sprintf_116);
  tcase_add_test(tc1_1, sprintf_117);
  tcase_add_test(tc1_1, sprintf_118);
  tcase_add_test(tc1_1, sprintf_119);
  tcase_add_test(tc1_1, sprintf_120);
  tcase_add_test(tc1_1, sprintf_121);
  tcase_add_test(tc1_1, sprintf_122);
  tcase_add_test(tc1_1, sprintf_123);
  tcase_add_test(tc1_1, sprintf_124);
  tcase_add_test(tc1_1, sprintf_125);
  tcase_add_test(tc1_1, sprintf_126);
  tcase_add_test(tc1_1, sprintf_127);
  tcase_add_test(tc1_1, sprintf_128);
  tcase_add_test(tc1_1, sprintf_129);
  tcase_add_test(tc1_1, sprintf_130);
  tcase_add_test(tc1_1, sprintf_131);
  tcase_add_test(tc1_1, sprintf_132);
  tcase_add_test(tc1_1, sprintf_133);
  tcase_add_test(tc1_1, sprintf_134);
  tcase_add_test(tc1_1, sprintf_135);
  tcase_add_test(tc1_1, sprintf_136);
  tcase_add_test(tc1_1, sprintf_137);
  tcase_add_test(tc1_1, sprintf_138);
  tcase_add_test(tc1_1, sprintf_139);
  tcase_add_test(tc1_1, sprintf_140);
  tcase_add_test(tc1_1, sprintf_141);
  tcase_add_test(tc1_1, sprintf_142);
  tcase_add_test(tc1_1, sprintf_143);
  tcase_add_test(tc1_1, sprintf_144);
  tcase_add_test(tc1_1, sprintf_145);
  tcase_add_test(tc1_1, sprintf_146);
  tcase_add_test(tc1_1, sprintf_147);
  tcase_add_test(tc1_1, sprintf_148);
  tcase_add_test(tc1_1, sprintf_149);
  tcase_add_test(tc1_1, sprintf_150);
  tcase_add_test(tc1_1, sprintf_151);
  tcase_add_test(tc1_1, sprintf_152);
  tcase_add_test(tc1_1, sprintf_153);
  tcase_add_test(tc1_1, sprintf_154);
  tcase_add_test(tc1_1, sprintf_155);
  tcase_add_test(tc1_1, sprintf_156);
  tcase_add_test(tc1_1, sprintf_157);
  tcase_add_test(tc1_1, sprintf_158);
  tcase_add_test(tc1_1, sprintf_159);
  tcase_add_test(tc1_1, sprintf_160);
  tcase_add_test(tc1_1, sprintf_161);
  tcase_add_test(tc1_1, sprintf_162);
  tcase_add_test(tc1_1, sprintf_163);
  tcase_add_test(tc1_1, sprintf_164);
  tcase_add_test(tc1_1, sprintf_165);
  tcase_add_test(tc1_1, sprintf_166);
  tcase_add_test(tc1_1, sprintf_167);
  tcase_add_test(tc1_1, sprintf_168);
  tcase_add_test(tc1_1, sprintf_169);
  tcase_add_test(tc1_1, sprintf_170);
  tcase_add_test(tc1_1, sprintf_171);
  tcase_add_test(tc1_1, sprintf_172);
  tcase_add_test(tc1_1, sprintf_173);
  tcase_add_test(tc1_1, sprintf_174);
  tcase_add_test(tc1_1, sprintf_175);
  tcase_add_test(tc1_1, sprintf_176);
  tcase_add_test(tc1_1, sprintf_177);
  tcase_add_test(tc1_1, sprintf_178);
  tcase_add_test(tc1_1, sprintf_179);
  tcase_add_test(tc1_1, sprintf_180);
  tcase_add_test(tc1_1, sprintf_181);
  tcase_add_test(tc1_1, sprintf_182);
  tcase_add_test(tc1_1, sprintf_183);
  tcase_add_test(tc1_1, sprintf_184);
  tcase_add_test(tc1_1, sprintf_185);
  tcase_add_test(tc1_1, sprintf_186);
  tcase_add_test(tc1_1, sprintf_187);
  tcase_add_test(tc1_1, sprintf_188);
  tcase_add_test(tc1_1, sprintf_189);
  tcase_add_test(tc1_1, sprintf_190);
  tcase_add_test(tc1_1, sprintf_191);
  tcase_add_test(tc1_1, sprintf_192);
  tcase_add_test(tc1_1, sprintf_193);
  tcase_add_test(tc1_1, sprintf_194);
  tcase_add_test(tc1_1, sprintf_195);
  tcase_add_test(tc1_1, sprintf_196);
  tcase_add_test(tc1_1, sprintf_197);
  tcase_add_test(tc1_1, sprintf_198);
  tcase_add_test(tc1_1, sprintf_199);
  tcase_add_test(tc1_1, sprintf_200);
  tcase_add_test(tc1_1, sprintf_201);
  tcase_add_test(tc1_1, sprintf_202);
  tcase_add_test(tc1_1, sprintf_203);
  tcase_add_test(tc1_1, sprintf_204);
  tcase_add_test(tc1_1, sprintf_205);
  tcase_add_test(tc1_1, sprintf_206);
  tcase_add_test(tc1_1, sprintf_207);
  tcase_add_test(tc1_1, sprintf_208);
  tcase_add_test(tc1_1, sprintf_209);
  tcase_add_test(tc1_1, sprintf_210);
  tcase_add_test(tc1_1, sprintf_211);
  tcase_add_test(tc1_1, sprintf_212);
  tcase_add_test(tc1_1, sprintf_213);
  tcase_add_test(tc1_1, sprintf_214);
  tcase_add_test(tc1_1, sprintf_215);
  tcase_add_test(tc1_1, sprintf_216);
  tcase_add_test(tc1_1, sprintf_217);
  tcase_add_test(tc1_1, sprintf_218);
  tcase_add_test(tc1_1, sprintf_219);
  tcase_add_test(tc1_1, sprintf_220);

  suite_add_tcase(s1, tc1_1);

  srunner_run_all(sr, CK_NORMAL);

  failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (failed == 0) ? 0 : 1;
}
