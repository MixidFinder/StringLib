#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(strpbrk_1) {
  char *str1 = "abcdiefg";
  char *str2 = "lkkb";
  ck_assert_str_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_2) {
  char *str1 = "abcdiefgb";
  char *str2 = "lkkb";
  ck_assert_str_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_3) {
  char *str1 = "abcdiefg";
  char *str2 = "lakb";
  ck_assert_str_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_4) {
  char *str1 = "abcdiefg";
  char *str2 = "j";
  ck_assert_ptr_null(s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strchr_1) {
  char *str1 = "abcdiefg";
  int ch = 'c';
  ck_assert_str_eq(strchr(str1, ch), s21_strchr(str1, ch));
}
END_TEST

START_TEST(strchr_2) {
  char *str1 = "abcdiefg";
  int ch = 'g';
  ck_assert_str_eq(strchr(str1, ch), s21_strchr(str1, ch));
}
END_TEST

START_TEST(strchr_3) {
  char *str1 = "abcdiefg";
  int ch = 'h';
  ck_assert_ptr_null(s21_strchr(str1, ch));
}
END_TEST

START_TEST(strrchr_1) {
  char *str1 = "abcdiefg";
  int str2 = 'b';
  ck_assert_str_eq(strrchr(str1, str2), s21_strrchr(str1, str2));
}
END_TEST

START_TEST(strrchr_2) {
  char *str1 = "abcdiefgb";
  int str2 = 'b';
  ck_assert_str_eq(strrchr(str1, str2), s21_strrchr(str1, str2));
}
END_TEST

START_TEST(strrchr_3) {
  char *str1 = "abcdiefg";
  int ch = 'h';
  ck_assert_ptr_null(s21_strrchr(str1, ch));
}
END_TEST

START_TEST(strstr_1) {
  char *str1 = "Helloworgldworldd!";
  char *str2 = "world";
  ck_assert_str_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_2) {
  char *str1 = "Helloworgldworldd!world";
  char *str2 = "world";
  ck_assert_str_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_3) {
  char *str1 = "sdfsdfsdfsdfwo";
  char *str2 = "world";
  ck_assert_ptr_null(s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_4) {
  char *str1 = "\0";
  char *str2 = "world";
  ck_assert_ptr_null(s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_5) {
  char *str1 = "World";
  char *str2 = "d";
  ck_assert_str_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_6) {
  char *str1 = "World";
  char *str2 = "d";
  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(strlen_1) {
  char *str1 = "Helloworgldworldd!world";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
}
END_TEST

START_TEST(strlen_2) {
  char *str1 = "\0";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
}
END_TEST

START_TEST(strlen_3) {
  char str1[] = "-_-HellO!WORLD-_-";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
}
END_TEST

START_TEST(to_upper_1) {
  char *str1 = "-_-HellO!WORLD-_-";
  char *check_str = "-_-HELLO!WORLD-_-";
  char *res = s21_to_upper(str1);
  ck_assert_str_eq(check_str, res);
  free(res);
}
END_TEST

START_TEST(to_upper_2) {
  char *str1 = "\0";
  char *check_str = "\0";
  char *res = s21_to_upper(str1);
  ck_assert_str_eq(check_str, res);
  free(res);
}
END_TEST

START_TEST(to_upper_3) {
  char *str1 = "123456";
  char *check_str = "123456";
  char *res = s21_to_upper(str1);
  ck_assert_str_eq(check_str, res);
  free(res);
}
END_TEST

START_TEST(to_upper_4) {
  char *str1 = NULL;
  ck_assert_ptr_null(s21_to_upper(str1));
}
END_TEST

START_TEST(to_upper_5) {
  char str1[] = "-_-HellO!WORLD-_-";
  char *check_str = "-_-HELLO!WORLD-_-";
  char *res = s21_to_upper(str1);
  ck_assert_str_eq(check_str, res);
  free(res);
}
END_TEST

START_TEST(to_upper_6) {
  char str1[] = {'-', '_', '-', 'H', 'e', 'l', 'l', 'O', '!',
                 'W', 'O', 'R', 'L', 'D', '-', '_', '-', '\0'};
  char *check_str = "-_-HELLO!WORLD-_-";
  char *res = s21_to_upper(str1);
  ck_assert_str_eq(check_str, res);
  free(res);
}
END_TEST

START_TEST(to_lower_1) {
  char *str1 = "-_-HellO!WORLD-_-";
  char *check_str = "-_-hello!world-_-";
  char *res = s21_to_lower(str1);
  ck_assert_str_eq(check_str, res);
  free(res);
}
END_TEST

START_TEST(to_lower_2) {
  char *str1 = "\0";
  char *check_str = "\0";
  char *res = s21_to_lower(str1);
  ck_assert_str_eq(check_str, res);
  free(res);
}
END_TEST

START_TEST(to_lower_3) {
  char *str1 = "welloworld";
  char *check_str = "welloworld";
  char *res = s21_to_lower(str1);
  ck_assert_str_eq(check_str, res);
  free(res);
}
END_TEST

START_TEST(to_lower_4) {
  char *str1 = NULL;
  ck_assert_ptr_null(s21_to_lower(str1));
}
END_TEST

START_TEST(insert_1) {
  char *str1 = "-_-HellO!WORLD-_-";
  char *str2 = "-_-hello!world-_-";
  char *check_str = "-_-HellO!-_-hello!world-_-WORLD-_-";
  char *res = s21_insert(str1, str2, 9);
  ck_assert_str_eq(check_str, res);
  free(res);
}
END_TEST

START_TEST(insert_2) {
  char *str1 = "\0";
  char *str2 = "\0";
  char *res = s21_insert(str1, str2, 2);
  ck_assert_ptr_null(res);
  free(res);
}
END_TEST

START_TEST(insert_3) {
  char *str1 = "123789";
  char *str2 = "456";
  char *check_str = "123456789";
  char *res = s21_insert(str1, str2, 3);
  ck_assert_str_eq(check_str, res);
  free(res);
}
END_TEST

START_TEST(insert_4) {
  char *str1 = NULL;
  char *str2 = NULL;
  ck_assert_ptr_null(s21_insert(str1, str2, 0));
}
END_TEST

START_TEST(insert_5) {
  char *str1 = "";
  char *str2 = "1";
  char *check_str = "1";
  char *res = s21_insert(str1, str2, 0);
  ck_assert_str_eq(res, check_str);
  free(res);
}
END_TEST

START_TEST(insert_6) {
  char *str1 = "";
  char *str2 = "1";
  char *res = s21_insert(str1, str2, -5);
  ck_assert_ptr_null(res);
}
END_TEST

START_TEST(trim_1) {
  char *str1 = "";
  char *str2 = "1";
  char *res = s21_trim(str1, str2);
  ck_assert_ptr_null(res);
}
END_TEST

START_TEST(trim_2) {
  char *str1 = " 123 ";
  char *str2 = " ";
  char *check_str = "123";
  char *res = s21_trim(str1, str2);
  ck_assert_str_eq(res, check_str);
  free(res);
}
END_TEST

START_TEST(trim_3) {
  char *str1 = " 123  ";
  char *str2 = " ";
  char *check_str = "123";
  char *res = s21_trim(str1, str2);
  ck_assert_str_eq(res, check_str);
  free(res);
}
END_TEST

START_TEST(trim_4) {
  char *str1 = " 1 23 ";
  char *str2 = " ";
  char *check_str = "1 23";
  char *res = s21_trim(str1, str2);
  ck_assert_str_eq(res, check_str);
  free(res);
}
END_TEST

START_TEST(trim_5) {
  char *str1 = " 123     ";
  char *str2 = " ";
  char *check_str = "123";
  char *res = s21_trim(str1, str2);
  ck_assert_str_eq(res, check_str);
  free(res);
}
END_TEST

START_TEST(trim_6) {
  char *str1 = " 123     ";
  char *str2 = "  ";
  char *check_str = " 123 ";
  char *res = s21_trim(str1, str2);
  ck_assert_str_eq(res, check_str);
  free(res);
}
END_TEST

START_TEST(trim_7) {
  char *str1 = "trimdonottrimheretrim";
  char *str2 = "trim";
  char *check_str = "donottrimhere";
  char *res = s21_trim(str1, str2);
  ck_assert_str_eq(res, check_str);
  free(res);
}
END_TEST

START_TEST(trim_8) {
  char *str1 = "trimdonottrimheretrim";
  char *str2 = NULL;
  char *res1 = s21_trim(str1, str2);
  char *res2 = s21_trim(str2, str1);
  ck_assert_ptr_null(res1);
  ck_assert_ptr_null(res2);
}
END_TEST

START_TEST(trim_9) {
  char *str1 = "trimdonottrimheretrim\0";
  char *str2 = "\0";
  char *res1 = s21_trim(str1, str2);
  char *res2 = s21_trim(str2, str1);
  ck_assert_ptr_null(res1);
  ck_assert_ptr_null(res2);
}
END_TEST

START_TEST(memchr_1) {
  char *str1 = "Herejust onespace";
  ck_assert_str_eq(memchr(str1, ' ', 16), s21_memchr(str1, ' ', 16));
}
END_TEST

START_TEST(memchr_2) {
  char *str1 = "Here two spaces";
  ck_assert_str_eq(memchr(str1, ' ', strlen(str1)),
                   s21_memchr(str1, ' ', strlen(str1)));
}
END_TEST

START_TEST(memchr_3) {
  char *str1 = "NULL?";
  ck_assert_ptr_null(s21_memchr(str1, ' ', 15));
}
END_TEST

START_TEST(memchr_4) {
  char *str1 = "NULL?";
  ck_assert_ptr_null(s21_memchr(str1, ' ', strlen(str1)));
}
END_TEST

START_TEST(strtok_1) {
  char str1[] = "Hello, hello1, hello2, hello3, hello4";
  char str2[] = "";
  ck_assert_str_eq(strtok(str1, str2), s21_strtok(str1, str2));
}
END_TEST

START_TEST(strtok_2) {
  char str1[] = "Hello, hello1, hello2, hello3, hello4";
  char str2[] = "He ";

  char tmp1[] = "Hello, hello1, hello2, hello3, hello4";
  char tmp2[] = "He ";

  char *s1 = strtok(str1, str2);
  char *s2 = s21_strtok(tmp1, tmp2);

  ck_assert_str_eq(s1, s2);

  s1 = strtok(NULL, str2);
  s2 = s21_strtok(NULL, tmp2);

  ck_assert_str_eq(s1, s2);

  s1 = strtok(NULL, str2);
  s2 = s21_strtok(NULL, tmp2);
  s1 = strtok(NULL, str2);
  s2 = s21_strtok(NULL, tmp2);

  ck_assert_str_eq(s1, s2);

  s1 = strtok(NULL, str2);
  s2 = s21_strtok(NULL, tmp2);

  ck_assert_str_eq(s1, s2);

  s1 = strtok(NULL, str2);
  s2 = s21_strtok(NULL, tmp2);
  s1 = strtok(NULL, str2);
  s2 = s21_strtok(NULL, tmp2);
  s1 = strtok(NULL, str2);
  s2 = s21_strtok(NULL, tmp2);
  s1 = strtok(NULL, str2);
  s2 = s21_strtok(NULL, tmp2);

  ck_assert_str_eq(s1, s2);

  s1 = strtok(NULL, str2);
  s2 = s21_strtok(NULL, tmp2);

  int correct = 0;
  if (s1 == NULL && s2 == NULL) {
    correct = 1;
  }

  ck_assert_int_eq(correct, 1);
}
END_TEST

START_TEST(strtok_3) {
  char str1[] = "Hello, hello1, hello2, hello3, hello4";
  char str2[] = " ";
  ck_assert_str_eq(strtok(str1, str2), s21_strtok(str1, str2));
}
END_TEST

START_TEST(strtok_4) {
  char str1[] = "Hello, hello1, hello2, hello3, hello4";
  char str2[] = "4";
  ck_assert_str_eq(strtok(str1, str2), s21_strtok(str1, str2));
}
END_TEST

START_TEST(strtok_5) {
  char str1[] = "Hello, hello1, hello2, hello3, hello4";
  char str2[] = "lo4";
  ck_assert_str_eq(strtok(str1, str2), s21_strtok(str1, str2));
}
END_TEST

START_TEST(strtok_6) {
  char str1[] = "Hello, hello1, hello2, hello3, hello4";
  char str2[] = "e";

  char tmp1[] = "Hello, hello1, hello2, hello3, hello4";
  char tmp2[] = "e";

  char *s1 = strtok(str1, str2);
  char *s2 = s21_strtok(tmp1, tmp2);

  ck_assert_str_eq(s1, s2);

  s1 = strtok(NULL, str2);
  s2 = s21_strtok(NULL, tmp2);

  ck_assert_str_eq(s1, s2);

  s1 = strtok(NULL, str2);
  s2 = s21_strtok(NULL, tmp2);
  s1 = strtok(NULL, str2);
  s2 = s21_strtok(NULL, tmp2);

  ck_assert_str_eq(s1, s2);

  s1 = strtok(NULL, str2);
  s2 = s21_strtok(NULL, tmp2);

  ck_assert_str_eq(s1, s2);

  s1 = strtok(NULL, str2);
  s2 = s21_strtok(NULL, tmp2);

  ck_assert_str_eq(s1, s2);

  s1 = strtok(NULL, str2);
  s2 = s21_strtok(NULL, tmp2);

  int correct = 0;
  if (s1 == NULL && s2 == NULL) {
    correct = 1;
  }

  ck_assert_int_eq(correct, 1);
}
END_TEST

START_TEST(strtok_7) {
  char str1[] = "Hello, hello1, hello2, hello3, hello4";
  char str2[] = " h";
  ck_assert_str_eq(strtok(str1, str2), s21_strtok(str1, str2));
}
END_TEST

START_TEST(strtok_8) {
  char str1[] = "Hel";
  char str2[] = "Z";
  ck_assert_str_eq(strtok(str1, str2), s21_strtok(str1, str2));
}
END_TEST

START_TEST(strtok_9) {
  char str1[] = "Hel";
  char str2[] = "Zs  az";
  ck_assert_str_eq(strtok(str1, str2), s21_strtok(str1, str2));
}
END_TEST

START_TEST(strtok_10) {
  char str1[] = "Hel";
  char str2[] = "Zs";
  ck_assert_str_eq(strtok(str1, str2), s21_strtok(str1, str2));
}
END_TEST

START_TEST(strtok_11) {
  char str1[] = "Hel";
  char str2[] = "H";
  ck_assert_str_eq(strtok(str1, str2), s21_strtok(str1, str2));
}
END_TEST

START_TEST(strtok_12) {
  char str1[] = "Hel";
  char str2[] = "e";
  ck_assert_str_eq(strtok(str1, str2), s21_strtok(str1, str2));
}
END_TEST

START_TEST(strtok_13) {
  char str1[] = "Hel";
  char str2[] = "l";
  ck_assert_str_eq(strtok(str1, str2), s21_strtok(str1, str2));
}
END_TEST

START_TEST(strtok_14) {
  char str1[] = "Hel";
  char str2[] = "He      e";
  ck_assert_str_eq(strtok(str1, str2), s21_strtok(str1, str2));
}
END_TEST

START_TEST(strtok_15) {
  char str1[] = "Hel";
  char str2[] = "He4";
  ck_assert_str_eq(strtok(str1, str2), s21_strtok(str1, str2));
}
END_TEST

START_TEST(strtok_16) {
  char str1[] = "Hel";
  char str2[] = "H4l";
  ck_assert_str_eq(strtok(str1, str2), s21_strtok(str1, str2));
}
END_TEST

START_TEST(strtok_17) {
  char str1[] = "Hel";
  char str2[] = "He";
  ck_assert_str_eq(strtok(str1, str2), s21_strtok(str1, str2));
}
END_TEST

START_TEST(strtok_18) {
  char str1[] = "Hel";
  char str2[] = "el";
  ck_assert_str_eq(strtok(str1, str2), s21_strtok(str1, str2));
}
END_TEST

START_TEST(strtok_19) {
  char str1[] = "Hel";
  char str2[] = "e";
  ck_assert_str_eq(strtok(str1, str2), s21_strtok(str1, str2));
}
END_TEST

START_TEST(strtok_20) {
  char str1[] = "Hel";
  char str2[] = "ez";
  ck_assert_str_eq(strtok(str1, str2), s21_strtok(str1, str2));
}
END_TEST

START_TEST(strtok_21) {
  char str1[] = "Hel";
  char str2[] = " ";
  ck_assert_str_eq(strtok(str1, str2), s21_strtok(str1, str2));
}
END_TEST

START_TEST(strtok_22) {
  char str1[] = "Hel";
  char str2[] = "";
  ck_assert_str_eq(strtok(str1, str2), s21_strtok(str1, str2));
}
END_TEST

START_TEST(strtok_23) {
  char str1[] = "Hel";
  char str2[] = "132";
  ck_assert_str_eq(strtok(str1, str2), s21_strtok(str1, str2));
}
END_TEST

START_TEST(strtok_24) {
  char str1[] = "Hel";
  char str2[] = "2    a";
  ck_assert_str_eq(strtok(str1, str2), s21_strtok(str1, str2));
}
END_TEST

START_TEST(strtok_25) {
  char str1[] = "Hel";
  char str2[] = "2      2";
  ck_assert_str_eq(strtok(str1, str2), s21_strtok(str1, str2));
}
END_TEST

START_TEST(strtok_26) {
  char str1[] = "Hel";
  char str2[] = "adsbbthdcvhfgh2p89yyyyyu7591ud3ym";
  ck_assert_str_eq(strtok(str1, str2), s21_strtok(str1, str2));
}
END_TEST

START_TEST(strtok_27) {
  char str1[] = "ASD";
  char str2[] = "AS";
  ck_assert_str_eq(strtok(str1, str2), s21_strtok(str1, str2));
}
END_TEST

START_TEST(strtok_28) {
  char str1[] = "ASD";
  char str2[] = "HIOUPJNS";
  ck_assert_str_eq(strtok(str1, str2), s21_strtok(str1, str2));
}
END_TEST

START_TEST(strtok_29) {
  char str1[] = "ASD";
  char str2[] = "A";
  ck_assert_str_eq(strtok(str1, str2), s21_strtok(str1, str2));
}
END_TEST

START_TEST(strtok_30) {
  char str1[] = "ASD";
  char str2[] = "a";
  ck_assert_str_eq(strtok(str1, str2), s21_strtok(str1, str2));
}
END_TEST

START_TEST(strtok_31) {
  char str1[] = "Hello, hello1, hello2, hello3, hello4";
  char str2[] = "o4";

  char tmp1[] = "Hello, hello1, hello2, hello3, hello4";
  char tmp2[] = "o4";

  char *s1 = strtok(str1, str2);
  char *s2 = s21_strtok(tmp1, tmp2);

  ck_assert_str_eq(s1, s2);

  s1 = strtok(NULL, str2);
  s2 = s21_strtok(NULL, tmp2);

  ck_assert_str_eq(s1, s2);

  s1 = strtok(NULL, str2);
  s2 = s21_strtok(NULL, tmp2);
  s1 = strtok(NULL, str2);
  s2 = s21_strtok(NULL, tmp2);

  ck_assert_str_eq(s1, s2);

  s1 = strtok(NULL, str2);
  s2 = s21_strtok(NULL, tmp2);

  ck_assert_str_eq(s1, s2);

  s1 = strtok(NULL, str2);
  s2 = s21_strtok(NULL, tmp2);

  int correct = 0;
  if (s1 == NULL && s2 == NULL) {
    correct = 1;
  }

  ck_assert_int_eq(correct, 1);
}
END_TEST

START_TEST(strtok_32) {
  char str1[] = "";
  char str2[] = "";

  char tmp1[] = "";
  char tmp2[] = "";

  char *s1 = strtok(str1, str2);
  char *s2 = s21_strtok(tmp1, tmp2);

  int correct = 0;
  if (s1 == NULL && s2 == NULL) {
    correct = 1;
  }

  ck_assert_int_eq(correct, 1);
}
END_TEST

START_TEST(strncpy_1) {
  char str1[] = "abcdiefg";
  char str2[] = "lkkb";
  size_t n = 4;
  ck_assert_str_eq(strncpy(str1, str2, n), s21_strncpy(str1, str2, n));
}
END_TEST

START_TEST(strncpy_2) {
  char str1[] = "abcdiefg";
  char str2[] = "lkkb";
  size_t n = 3;
  ck_assert_str_eq(strncpy(str1, str2, n), s21_strncpy(str1, str2, n));
}
END_TEST

START_TEST(strncpy_3) {
  char str1[] = "abcdiefg";
  char str2[] = "lkkb";
  size_t n = 2;
  ck_assert_str_eq(strncpy(str1, str2, n), s21_strncpy(str1, str2, n));
}
END_TEST

START_TEST(strncpy_4) {
  char str1[] = "abcdiefg";
  char str2[] = "lkkb";
  size_t n = 1;
  ck_assert_str_eq(strncpy(str1, str2, n), s21_strncpy(str1, str2, n));
}
END_TEST

START_TEST(strncpy_5) {
  char str1[] = "abcdiefg";
  char str2[] = "lkkb";
  size_t n = 0;
  ck_assert_str_eq(strncpy(str1, str2, n), s21_strncpy(str1, str2, n));
}
END_TEST

START_TEST(strncpy_6) {
  char str1[] = "HSDI(<{U)&#_<&<YP*DFMZPOSDU<_>UJF})";
  char str2[] = "HSDI(<{U)&#_<&<YP*DFMZPOSDU<_>UJF})";
  size_t n = 35;
  ck_assert_str_eq(strncpy(str1, str2, n), s21_strncpy(str1, str2, n));
}
END_TEST

START_TEST(strncpy_7) {
  char str1[] = "HSDI(<{U)&#_<&<YP*DFMZPOSDU<_>UJF})";
  char str2[] = "HSDI(<{U)&#_<&<YP*DFMZPOSDU<_>UJF})";
  size_t n = 36;
  ck_assert_str_eq(strncpy(str1, str2, n), s21_strncpy(str1, str2, n));
}
END_TEST

START_TEST(strncpy_8) {
  char str1[] = "HSDI(<{U)&#_<&<YP*DFMZPOSDU<_>UJF})";
  char str2[] = "HSDI(<{U)&#_<&<YP*DFMZPOSDU<_>UJF})";
  size_t n = 3;
  ck_assert_str_eq(strncpy(str1, str2, n), s21_strncpy(str1, str2, n));
}
END_TEST

START_TEST(strncpy_9) {
  char str1[] = "HSDI(<{U)&#_<&<YP*DFMZPOSDU<_>UJF})";
  char str2[] = "HSDI(<{U)&#_<&<YP*DFMZPOSDU<_>UJF})";
  size_t n = 0;
  ck_assert_str_eq(strncpy(str1, str2, n), s21_strncpy(str1, str2, n));
}
END_TEST

START_TEST(strncpy_10) {
  char str1[] = "HSDI(<{U)&#_<&<YP*DFMZPOSDU<_>UJF})";
  char str2[] = "HSDI(<{U)&#_<&<YP*DFMZPOSDU<_>UJF})";
  size_t n = 1;
  ck_assert_str_eq(strncpy(str1, str2, n), s21_strncpy(str1, str2, n));
}
END_TEST

START_TEST(strncpy_11) {
  char str1[] = "HSDI(<{U)&#_<&<YP*DFMZPOSDU<_>UJF})";
  char str2[] = "HSDI(<{U)&#_<&<YP*DFMZPOSDU<_>UJF})";
  size_t n = 14;
  ck_assert_str_eq(strncpy(str1, str2, n), s21_strncpy(str1, str2, n));
}
END_TEST

START_TEST(strncpy_12) {
  char str1[] = "lkkb";
  char str2[] = "abcdiefg";
  size_t n = 4;
  ck_assert_str_eq(strncpy(str1, str2, n), s21_strncpy(str1, str2, n));
}
END_TEST

START_TEST(strncpy_13) {
  char str1[] = "";
  char str2[] = "";
  size_t n = 1;
  ck_assert_str_eq(strncpy(str1, str2, n), s21_strncpy(str1, str2, n));
}
END_TEST

START_TEST(strncpy_14) {
  char str1[] = "lkkb";
  char str2[] = "abcdiefg";
  size_t n = 2;
  ck_assert_str_eq(strncpy(str1, str2, n), s21_strncpy(str1, str2, n));
}
END_TEST

START_TEST(strncpy_15) {
  char str1[] = "lkkb";
  char str2[] = "abcdiefg";
  size_t n = 1;
  ck_assert_str_eq(strncpy(str1, str2, n), s21_strncpy(str1, str2, n));
}
END_TEST

START_TEST(strncpy_16) {
  char str1[] = "lkkb";
  char str2[] = "abcdiefg";
  size_t n = 0;
  ck_assert_str_eq(strncpy(str1, str2, n), s21_strncpy(str1, str2, n));
}
END_TEST

START_TEST(strncpy_17) {
  char str1[] = "";
  char str2[] = "abcdiefg";
  size_t n = 0;
  ck_assert_str_eq(strncpy(str1, str2, n), s21_strncpy(str1, str2, n));
}
END_TEST

START_TEST(strncpy_18) {
  char str1[] = "";
  char str2[] = "abcdiefg";
  size_t n = 1;
  ck_assert_str_eq(strncpy(str1, str2, n), s21_strncpy(str1, str2, n));
}
END_TEST

START_TEST(strncpy_19) {
  char str1[] = "abcdiefg";
  char str2[] = "";
  size_t n = 1;
  ck_assert_str_eq(strncpy(str1, str2, n), s21_strncpy(str1, str2, n));
}
END_TEST

START_TEST(strncpy_20) {
  char str1[] = "abcdiefg";
  char str2[] = "";
  size_t n = 0;
  ck_assert_str_eq(strncpy(str1, str2, n), s21_strncpy(str1, str2, n));
}
END_TEST

START_TEST(memcmp_1) {
  const char *str1 = "abcdiefg";
  const char *str2 = "lkkb";
  size_t n = 4;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_2) {
  const char *str1 = "abcdiefg";
  const char *str2 = "lkkb";
  size_t n = 5;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_3) {
  const char *str1 = "abcdiefg";
  const char *str2 = "lkkb";
  size_t n = 0;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_4) {
  const char *str1 = "abcdiefg";
  const char *str2 = "abcdiefg";
  size_t n = 9;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_5) {
  const char *str1 = "abcdiefg";
  const char *str2 = "abcdiefg";
  size_t n = 8;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_6) {
  const char *str1 = "abcdiefg";
  const char *str2 = "abcdiefg";
  size_t n = 1;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_7) {
  const char *str1 = "abcdiefg";
  const char *str2 = "abcdiefgA";
  size_t n = 9;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_8) {
  const char *str1 = "abcdiefg";
  const char *str2 = "Abcdiefg";
  size_t n = 9;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_9) {
  const char *str1 = "abcdiefg";
  const char *str2 = "aBcdiefg";
  size_t n = 9;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_10) {
  const char *str1 = "abcdiefg";
  const char *str2 = "abcDiefg";
  size_t n = 9;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_11) {
  const char *str1 = "abcdiefg";
  const char *str2 = "abcdiefG";
  size_t n = 9;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_12) {
  const char *str1 = "abcdiefg";
  const char *str2 = "abc iefg";
  size_t n = 9;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_13) {
  const char *str1 = "abcdiefg";
  const char *str2 = "zabcdiefg";
  size_t n = 9;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_14) {
  const char *str1 = "asd";
  const char *str2 = "asdgfdh";
  size_t n = 4;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_15) {
  const char *str1 = "asd";
  const char *str2 = "asdgfdh";
  size_t n = 3;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_16) {
  const char *str1 = "asd";
  const char *str2 = "asdgfdh";
  size_t n = 1;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_17) {
  const char *str1 = "asd";
  const char *str2 = "asdgfdh";
  size_t n = 0;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_1) {
  const char *str1 = "abcdiefg";
  const char *str2 = "lkkb";
  size_t n = 4;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_2) {
  const char *str1 = "abcdiefg";
  const char *str2 = "lkkb";
  size_t n = 3;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_3) {
  const char *str1 = "abcdiefg";
  const char *str2 = "lkkb";
  size_t n = 5;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_4) {
  const char *str1 = "abcdiefg";
  const char *str2 = "lkkb";
  size_t n = 1;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_5) {
  const char *str1 = "abcdiefg";
  const char *str2 = "lkkb";
  size_t n = 0;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_6) {
  const char *str1 = "abcdiefg";
  const char *str2 = "abcdiefg";
  size_t n = 9;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_7) {
  const char *str1 = "abcdiefg";
  const char *str2 = "abcdiefg";
  size_t n = 8;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_8) {
  const char *str1 = "abcdiefg";
  const char *str2 = "abcdiefg";
  size_t n = 1;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_9) {
  const char *str1 = "abcdiefg";
  const char *str2 = "abcdiefgA";
  size_t n = 9;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_10) {
  const char *str1 = "abcdiefg";
  const char *str2 = "abcdiSefg";
  size_t n = 9;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_11) {
  const char *str1 = "abcdiefg";
  const char *str2 = "Abcdiefg";
  size_t n = 9;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_12) {
  const char *str1 = "abcdiefg";
  const char *str2 = "aBcdiefg";
  size_t n = 9;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_13) {
  const char *str1 = "abcdiefg";
  const char *str2 = "abcDiefg";
  size_t n = 9;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_14) {
  const char *str1 = "abcdiefg";
  const char *str2 = "abcdiefG";
  size_t n = 9;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_15) {
  const char *str1 = "abcdiefg";
  const char *str2 = "abc iefg";
  size_t n = 9;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_16) {
  const char *str1 = "abcdiefg";
  const char *str2 = "zabcdiefg";
  size_t n = 9;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_17) {
  const char *str1 = "asd";
  const char *str2 = "asdgfdh";
  size_t n = 4;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_18) {
  const char *str1 = "asd";
  const char *str2 = "asdgfdh";
  size_t n = 3;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_19) {
  const char *str1 = "asd";
  const char *str2 = "asdgfdh";
  size_t n = 1;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_20) {
  const char *str1 = "asd";
  const char *str2 = "asdgfdh";
  size_t n = 0;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(memcpy_1) {
  char str1[] = "asdgfdh";
  const char *str2 = "zxcvbn";
  size_t n = 0;
  ck_assert_str_eq(memcpy(str1, str2, n), s21_memcpy(str1, str2, n));
}
END_TEST

START_TEST(memcpy_2) {
  char str1[] = "asdgfdh";
  const char *str2 = "z";
  size_t n = 1;
  ck_assert_str_eq(memcpy(str1, str2, n), s21_memcpy(str1, str2, n));
}
END_TEST

START_TEST(memcpy_3) {
  char str1[] = "        ";
  const char *str2 = "asdzvfgh";
  size_t n = 2;
  ck_assert_str_eq(memcpy(str1, str2, n), s21_memcpy(str1, str2, n));
}
END_TEST

START_TEST(memcpy_4) {
  char str1[] = "        \0";
  const char *str2 = "asdzvfgha";
  size_t n = 10;
  ck_assert_str_eq(memcpy(str1, str2, n), s21_memcpy(str1, str2, n));
}
END_TEST

START_TEST(memset_1) {
  char s[] = "        ";
  char c = '0';
  unsigned long n = 0;
  ck_assert_str_eq(memset(s, c, n), s21_memset(s, c, n));
}
END_TEST

START_TEST(memset_2) {
  char s[] = "        ";
  int c = '0';
  unsigned long n = 1;
  ck_assert_str_eq(memset(s, c, n), s21_memset(s, c, n));
}
END_TEST

START_TEST(memset_3) {
  char s[] = "        ";
  char c = '0';
  unsigned long n = 8;
  ck_assert_str_eq(memset(s, c, n), s21_memset(s, c, n));
}
END_TEST

START_TEST(memset_4) {
  char s[] = "        ";
  char c = ' ';
  unsigned long n = 1;
  ck_assert_str_eq(memset(s, c, n), s21_memset(s, c, n));
}
END_TEST

START_TEST(memset_5) {
  char s[] = "a";
  char c = 'b';
  unsigned long n = 1;
  ck_assert_str_eq(memset(s, c, n), s21_memset(s, c, n));
}
END_TEST

START_TEST(strncat_1) {
  char d[] = "a\0";
  char d1[] = "a\0";
  const char s[] = "b";
  s21_size_t n = 2;
  ck_assert_str_eq(strncat(d, s, n), s21_strncat(d1, s, n));
}
END_TEST

START_TEST(strncat_2) {
  char d[] = "abc\0";
  char d1[] = "abc\0";
  const char s[] = "b";
  s21_size_t n = 1;
  ck_assert_str_eq(strncat(d, s, n), s21_strncat(d1, s, n));
}
END_TEST

START_TEST(strncat_3) {
  char d[] = "a";
  char d1[] = "a";
  const char s[] = "b";
  s21_size_t n = 0;
  ck_assert_str_eq(strncat(d, s, n), s21_strncat(d1, s, n));
}
END_TEST

START_TEST(strncat_4) {
  char d[] = "abc\0\0\0\0\0";
  char d1[] = "abc\0\0\0\0\0";
  const char s[] = "bzx";
  s21_size_t n = 6;
  ck_assert_str_eq(strncat(d, s, n), s21_strncat(d1, s, n));
}
END_TEST

START_TEST(strncat_5) {
  char d[] = "abc\0\0\0\0\0";
  char d1[] = "abc\0\0\0\0\0";
  const char s[] = "bzx";
  s21_size_t n = 4;
  ck_assert_str_eq(strncat(d, s, n), s21_strncat(d1, s, n));
}
END_TEST

START_TEST(strcspn_1) {
  const char *d = "abc";
  const char *s = "abc";

  ck_assert_int_eq(strcspn(d, s), s21_strcspn(d, s));
}
END_TEST

START_TEST(strcspn_2) {
  const char *d = "zxc";
  const char *s = "abc";

  ck_assert_int_eq(strcspn(d, s), s21_strcspn(d, s));
}
END_TEST

START_TEST(strcspn_3) {
  const char *d = "abc";
  const char *s = "a";

  ck_assert_int_eq(strcspn(d, s), s21_strcspn(d, s));
}
END_TEST

START_TEST(strcspn_4) {
  const char *d = "abc";
  const char *s = "b";

  ck_assert_int_eq(strcspn(d, s), s21_strcspn(d, s));
}
END_TEST

START_TEST(strcspn_5) {
  const char *d = "abc";
  const char *s = "cz";

  ck_assert_int_eq(strcspn(d, s), s21_strcspn(d, s));
  ck_assert_int_eq(strcspn(d, s), s21_strcspn(d, s));
  ck_assert_int_eq(strcspn(d, s), s21_strcspn(d, s));
}
END_TEST

int main(void) {
  int failed = 0;
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);

  // srunner_set_fork_status(sr, CK_NOFORK);  // valgrind - make v1

  tcase_add_test(tc1_1, strcspn_1);
  tcase_add_test(tc1_1, strcspn_2);
  tcase_add_test(tc1_1, strcspn_3);
  tcase_add_test(tc1_1, strcspn_4);
  tcase_add_test(tc1_1, strcspn_5);
  tcase_add_test(tc1_1, strncat_1);
  tcase_add_test(tc1_1, strncat_2);
  tcase_add_test(tc1_1, strncat_3);
  tcase_add_test(tc1_1, strncat_4);
  tcase_add_test(tc1_1, strncat_5);
  tcase_add_test(tc1_1, memset_1);
  tcase_add_test(tc1_1, memset_2);
  tcase_add_test(tc1_1, memset_3);
  tcase_add_test(tc1_1, memset_4);
  tcase_add_test(tc1_1, memset_5);
  tcase_add_test(tc1_1, memcpy_1);
  tcase_add_test(tc1_1, memcpy_2);
  tcase_add_test(tc1_1, memcpy_3);
  tcase_add_test(tc1_1, memcpy_4);
  tcase_add_test(tc1_1, strpbrk_1);
  tcase_add_test(tc1_1, strpbrk_2);
  tcase_add_test(tc1_1, strpbrk_3);
  tcase_add_test(tc1_1, strpbrk_4);
  tcase_add_test(tc1_1, strchr_1);
  tcase_add_test(tc1_1, strchr_2);
  tcase_add_test(tc1_1, strchr_3);
  tcase_add_test(tc1_1, strrchr_1);
  tcase_add_test(tc1_1, strrchr_2);
  tcase_add_test(tc1_1, strrchr_3);
  tcase_add_test(tc1_1, strstr_1);
  tcase_add_test(tc1_1, strstr_2);
  tcase_add_test(tc1_1, strstr_3);
  tcase_add_test(tc1_1, strstr_4);
  tcase_add_test(tc1_1, strstr_5);
  tcase_add_test(tc1_1, strstr_6);
  tcase_add_test(tc1_1, strlen_1);
  tcase_add_test(tc1_1, strlen_2);
  tcase_add_test(tc1_1, strlen_3);
  tcase_add_test(tc1_1, to_upper_1);
  tcase_add_test(tc1_1, to_upper_2);
  tcase_add_test(tc1_1, to_upper_3);
  tcase_add_test(tc1_1, to_upper_4);
  tcase_add_test(tc1_1, to_upper_5);
  tcase_add_test(tc1_1, to_upper_6);
  tcase_add_test(tc1_1, to_lower_1);
  tcase_add_test(tc1_1, to_lower_2);
  tcase_add_test(tc1_1, to_lower_3);
  tcase_add_test(tc1_1, to_lower_4);
  tcase_add_test(tc1_1, insert_1);
  tcase_add_test(tc1_1, insert_2);
  tcase_add_test(tc1_1, insert_3);
  tcase_add_test(tc1_1, insert_4);
  tcase_add_test(tc1_1, insert_5);
  tcase_add_test(tc1_1, insert_6);
  tcase_add_test(tc1_1, trim_1);
  tcase_add_test(tc1_1, trim_2);
  tcase_add_test(tc1_1, trim_3);
  tcase_add_test(tc1_1, trim_4);
  tcase_add_test(tc1_1, trim_5);
  tcase_add_test(tc1_1, trim_6);
  tcase_add_test(tc1_1, trim_7);
  tcase_add_test(tc1_1, trim_8);
  tcase_add_test(tc1_1, trim_9);
  tcase_add_test(tc1_1, memchr_1);
  tcase_add_test(tc1_1, memchr_2);
  tcase_add_test(tc1_1, memchr_3);
  tcase_add_test(tc1_1, memchr_4);
  tcase_add_test(tc1_1, strtok_1);
  tcase_add_test(tc1_1, strtok_2);
  tcase_add_test(tc1_1, strtok_3);
  tcase_add_test(tc1_1, strtok_4);
  tcase_add_test(tc1_1, strtok_5);
  tcase_add_test(tc1_1, strtok_6);
  tcase_add_test(tc1_1, strtok_7);
  tcase_add_test(tc1_1, strtok_8);
  tcase_add_test(tc1_1, strtok_9);
  tcase_add_test(tc1_1, strtok_10);
  tcase_add_test(tc1_1, strtok_11);
  tcase_add_test(tc1_1, strtok_12);
  tcase_add_test(tc1_1, strtok_13);
  tcase_add_test(tc1_1, strtok_14);
  tcase_add_test(tc1_1, strtok_15);
  tcase_add_test(tc1_1, strtok_16);
  tcase_add_test(tc1_1, strtok_17);
  tcase_add_test(tc1_1, strtok_18);
  tcase_add_test(tc1_1, strtok_19);
  tcase_add_test(tc1_1, strtok_20);
  tcase_add_test(tc1_1, strtok_21);
  tcase_add_test(tc1_1, strtok_22);
  tcase_add_test(tc1_1, strtok_23);
  tcase_add_test(tc1_1, strtok_24);
  tcase_add_test(tc1_1, strtok_25);
  tcase_add_test(tc1_1, strtok_26);
  tcase_add_test(tc1_1, strtok_27);
  tcase_add_test(tc1_1, strtok_28);
  tcase_add_test(tc1_1, strtok_29);
  tcase_add_test(tc1_1, strtok_30);
  tcase_add_test(tc1_1, strtok_31);
  tcase_add_test(tc1_1, strtok_32);
  tcase_add_test(tc1_1, strncpy_1);
  tcase_add_test(tc1_1, strncpy_2);
  tcase_add_test(tc1_1, strncpy_3);
  tcase_add_test(tc1_1, strncpy_4);
  tcase_add_test(tc1_1, strncpy_5);
  tcase_add_test(tc1_1, strncpy_6);
  tcase_add_test(tc1_1, strncpy_7);
  tcase_add_test(tc1_1, strncpy_8);
  tcase_add_test(tc1_1, strncpy_9);
  tcase_add_test(tc1_1, strncpy_10);
  tcase_add_test(tc1_1, strncpy_11);
  tcase_add_test(tc1_1, strncpy_12);
  tcase_add_test(tc1_1, strncpy_13);
  tcase_add_test(tc1_1, strncpy_14);
  tcase_add_test(tc1_1, strncpy_15);
  tcase_add_test(tc1_1, strncpy_16);
  tcase_add_test(tc1_1, strncpy_17);
  tcase_add_test(tc1_1, strncpy_18);
  tcase_add_test(tc1_1, strncpy_19);
  tcase_add_test(tc1_1, strncpy_20);
  tcase_add_test(tc1_1, strncmp_1);
  tcase_add_test(tc1_1, strncmp_2);
  tcase_add_test(tc1_1, strncmp_3);
  tcase_add_test(tc1_1, strncmp_4);
  tcase_add_test(tc1_1, strncmp_5);
  tcase_add_test(tc1_1, strncmp_6);
  tcase_add_test(tc1_1, strncmp_7);
  tcase_add_test(tc1_1, strncmp_8);
  tcase_add_test(tc1_1, strncmp_9);
  tcase_add_test(tc1_1, strncmp_10);
  tcase_add_test(tc1_1, strncmp_11);
  tcase_add_test(tc1_1, strncmp_12);
  tcase_add_test(tc1_1, strncmp_13);
  tcase_add_test(tc1_1, strncmp_14);
  tcase_add_test(tc1_1, strncmp_15);
  tcase_add_test(tc1_1, strncmp_16);
  tcase_add_test(tc1_1, strncmp_17);
  tcase_add_test(tc1_1, strncmp_18);
  tcase_add_test(tc1_1, strncmp_19);
  tcase_add_test(tc1_1, strncmp_20);
  tcase_add_test(tc1_1, memcmp_1);
  tcase_add_test(tc1_1, memcmp_2);
  tcase_add_test(tc1_1, memcmp_3);
  tcase_add_test(tc1_1, memcmp_4);
  tcase_add_test(tc1_1, memcmp_5);
  tcase_add_test(tc1_1, memcmp_6);
  tcase_add_test(tc1_1, memcmp_7);
  tcase_add_test(tc1_1, memcmp_8);
  tcase_add_test(tc1_1, memcmp_9);
  tcase_add_test(tc1_1, memcmp_10);
  tcase_add_test(tc1_1, memcmp_11);
  tcase_add_test(tc1_1, memcmp_12);
  tcase_add_test(tc1_1, memcmp_13);
  tcase_add_test(tc1_1, memcmp_14);
  tcase_add_test(tc1_1, memcmp_15);
  tcase_add_test(tc1_1, memcmp_16);
  tcase_add_test(tc1_1, memcmp_17);

  suite_add_tcase(s1, tc1_1);

  srunner_run_all(sr, CK_NORMAL);

  failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (failed == 0) ? 0 : 1;
}