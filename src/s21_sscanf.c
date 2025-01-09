#include "s21_string.h"

int s21_sscanf(const char *str, const char *format, ...) {
  va_list arg;
  va_start(arg, format);
  int printed = 0;

  if (format == S21_NULL || str == S21_NULL) {
    printed = -1;
  }

  else {
    int i = printed, has_specifier = 0;
    for (; format[i] != '\0'; i++) {
      struct_settings settings =
          s21_sprintf_set_settings(&arg, &format, &i, &has_specifier);

      if (has_specifier) {
        s21_sscanf_check_specifiers(&str, &format, &printed, &i, &settings,
                                    &arg);
      }
    }
  }

  va_end(arg);

  return printed;
}

void s21_sscanf_check_specifiers(const char **str, const char **format,
                                 int *printed, int *i,
                                 struct_settings *settings, va_list *arg) {
  if ((*format)[*i + 1] == 'c')
    s21_sscanf_spec_c((char *)va_arg(*arg, int *), str, format, printed, *i,
                      *settings);

  else if ((*format)[*i + 1] == 's')
    s21_sscanf_spec_s(va_arg(*arg, char *), str, format, printed, *settings);

  else if ((*format)[*i + 1] == 'd' || (*format)[*i + 1] == 'i') {
    if ((*settings).length.l_long)
      s21_sscanf_spec_d_long(va_arg(*arg, long int *), str, format, printed);
    else
      s21_sscanf_spec_d(va_arg(*arg, int *), str, format, printed);
  }

  else if ((*format)[*i + 1] == 'u')
    s21_sscanf_spec_u(va_arg(*arg, unsigned int *), str, format, printed);
}

void s21_sscanf_spec_c(char *arg, const char **str, const char **format,
                       int *printed, int i, struct_settings settings) {
  if (arg != S21_NULL) {
    if (i >= 1 && s21_is_blank((*format)[i - 1])) s21_sscanf_skip_blank(str);

    if (!settings.width.num) *arg = *str[0];

    (*format)++, (*str)++;
    (*printed)++;
  }
}

void s21_sscanf_spec_s(char *tmp, const char **str, const char **format,
                       int *printed, struct_settings settings) {
  if (tmp != S21_NULL) {
    s21_sscanf_skip_blank(str);

    int len = 0;
    while (!s21_is_blank((*str)[len])) len++;

    s21_sprintf(tmp, "%*.*s", settings.width, len, *str);

    (*format)++, (*str) += len;
    (*printed)++;
  }
}

void s21_sscanf_spec_d(int *arg, const char **str, const char **format,
                       int *printed) {
  if (arg != S21_NULL) {
    if (s21_is_blank(**str)) s21_sscanf_skip_blank(str);

    int len = 0;
    while (s21_is_number((*str)[len])) len++;

    *arg = (int)s21_sscanf_str_to_int(str);

    (*format)++, (*str) += len;
    (*printed)++;
  }
}

void s21_sscanf_spec_d_long(long int *arg, const char **str,
                            const char **format, int *printed) {
  if (arg != S21_NULL) {
    if (s21_is_blank(**str)) s21_sscanf_skip_blank(str);

    int len = 0;
    while (s21_is_number((*str)[len])) len++;

    *arg = (long int)s21_sscanf_str_to_int(str);

    (*format)++, (*str) += len;
    (*printed)++;
  }
}

void s21_sscanf_spec_u(unsigned int *arg, const char **str, const char **format,
                       int *printed) {
  if (arg != S21_NULL) {
    if (s21_is_blank(**str)) s21_sscanf_skip_blank(str);

    int len = 0;
    while (s21_is_number((*str)[len])) len++;

    *arg = (unsigned int)s21_sscanf_str_to_int(str);

    (*format)++, (*str) += len;
    (*printed)++;
  }
}

long long int s21_sscanf_str_to_int(const char **str) {
  int result = 0;

  int i = 0;
  while (s21_is_number((*str)[i])) {
    result = result * 10 + (*str)[i] - '0';
    i++;
  }

  return result;
}

void s21_sscanf_skip_blank(const char **str) {
  while (s21_is_blank(**str)) (*str)++;
}

int s21_is_blank(char c) { return (c == '\0' || c <= ' ' || c == 127); }
