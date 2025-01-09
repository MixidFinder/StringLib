#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  va_list arg;
  va_start(arg, format);
  int printed = 0;

  if (format == S21_NULL || str == S21_NULL) {
    if (str != S21_NULL) *str = '\0';
    printed = -1;
  }

  else {
    int i = printed, has_specifier = 0;
    for (; format[i] != '\0'; i++) {
      struct_settings settings =
          s21_sprintf_set_settings(&arg, &format, &i, &has_specifier);

      if (has_specifier) {
        s21_sprintf_check_specifiers(&str, &format, &printed, &i, &settings,
                                     &arg);
      }

      else
        str[i] = format[i];
    }
    str[i] = '\0';
    printed += i;
  }

  va_end(arg);

  if (printed < 0) {
    if (str != S21_NULL) *str = '\0';
    printed = -1;
  }

  return printed;
}

struct_settings s21_sprintf_set_settings(va_list *arg, const char **format,
                                         int *i, int *has_specifier) {
  struct_settings settings = {.precision.flt = DEFAULT_PRECISION_F,
                              .precision.dec = DEFAULT_PRECISION_D,
                              .precision.str = DEFAULT_PRECISION_S,
                              .width.num = 0,
                              .add_plus = 0,
                              .add_space = 0,
                              .minus_width = 0,
                              .zeros_width = 0,
                              .force_output = 0,
                              .length.h_short = 0,
                              .length.l_long = 0,
                              .length.L_double = 0};

  if ((*format)[*i] == '%')
    *has_specifier = 1;
  else
    *has_specifier = 0;

  if (*has_specifier) {
    s21_sprintf_parse_flags(format, i, &settings);

    if (s21_is_number((*format)[*i + 1]) || (*format)[*i + 1] == '*')
      s21_sprintf_setting_width(arg, format, i, &settings);

    if ((*format)[*i + 1] == '.')
      s21_sprintf_setting_precision(arg, format, i, &settings);

    s21_sprintf_parse_length(format, i, &settings);
  }

  return settings;
}

void s21_sprintf_parse_flags(const char **format, int *i,
                             struct_settings *settings) {
  int count = 1;

  while (s21_sprintf_is_flag((*format)[*i + count])) {
    if ((*format)[*i + count] == '+')
      (*settings).add_plus = 1;

    else if ((*format)[*i + count] == ' ')
      (*settings).add_space = 1;

    else if ((*format)[*i + count] == '-')
      (*settings).minus_width = 1;

    else if ((*format)[*i + count] == '0')
      (*settings).zeros_width = 1;

    else if ((*format)[*i + count] == '#')
      (*settings).force_output = 1;

    count++;
  }

  (*format) += count - 1;
}

int s21_sprintf_is_flag(char c) {
  const char *flags = "+ -0#";

  return s21_strchr(flags, c) != NULL;
}

void s21_sprintf_setting_width(va_list *arg, const char **format, int *i,
                               struct_settings *settings) {
  if ((*format)[*i + 1] == '*') {
    (*settings).width.num = va_arg(*arg, int);
    (*format)++;
  }

  else {
    int count = 0;
    char *buff = s21_sprintf_get_numbers_from_string(format, i, &count);

    (*settings).width = s21_sprintf_str_to_int_width(buff, count);

    // Сдвинули на след. символ после цифр
    if (s21_sprintf_parse_specifier(format, i, count)) *format += count;

    if (buff != S21_NULL) free(buff);
  }
}

void s21_sprintf_parse_length(const char **format, int *i,
                              struct_settings *settings) {
  int found = 0;

  while (found != 2 && (*format)[*i + 1] == 'h') {
    (*settings).length.h_short = 1;
    (*format)++;
    found++;
  }

  if ((*settings).length.h_short == 0) {
    while (found != 2 && (*format)[*i + 1] == 'l') {
      (*settings).length.l_long = 1;
      (*format)++;
      found++;
    }
  }

  if ((*settings).length.h_short == 0 && (*settings).length.l_long == 0) {
    while (found != 2 && (*format)[*i + 1] == 'L') {
      (*settings).length.L_double = 1;
      (*format)++;
      found++;
    }
  }
}

int s21_sprintf_parse_specifier(const char **format, int *i, int count) {
  int result = 0;
  int have_dot = 0;

  while (s21_is_number((*format)[*i + count]) ||
         ((*format)[*i + count] == '.' && !have_dot)) {
    if ((*format)[*i + count] == '.') have_dot = 1;
    count++;
  }
  if (s21_sprintf_is_valid_spec_or_length((*format)[*i + count])) result = 1;

  return result;
}

void s21_sprintf_setting_precision(va_list *arg, const char **format, int *i,
                                   struct_settings *settings) {
  int count = 1;

  if ((*format)[*i + 2] == '*') {
    int arg_value = va_arg(*arg, int);
    (*settings).precision.dec = arg_value;
    (*settings).precision.flt = arg_value;
    (*settings).precision.str = arg_value;

    (*format) += 2;
  }

  else {
    char *buff = s21_sprintf_get_numbers_from_string(format, i, &count);

    if (count)
      (*settings).precision = s21_sprintf_str_to_int_precision(buff, count);
    else
      s21_memset(&((*settings).precision), 0, sizeof(struct_precision));

    if (s21_sprintf_is_valid_spec_or_length((*format)[*i + 2 + count]))
      *format += count + 1;

    if (buff != S21_NULL) free(buff);
  }
}
char *s21_sprintf_get_numbers_from_string(const char **format, int *i,
                                          int *count) {
  int bsize = 12;
  char *buff = calloc(bsize, sizeof(char));
  int shift = 1;
  if (*count) shift = 2, (*count)--;

  while (s21_is_number((*format)[*i + shift + *count])) {
    if (*count % 10 == 0) {
      buff = realloc(buff, (bsize + *count) * sizeof(char));
      s21_memset(buff + *count, '\0', bsize * sizeof(char));
    }
    buff[*count] = (*format)[*i + shift + *count];

    (*count)++;
  }

  return buff;
}

int s21_sprintf_is_valid_spec_or_length(char c) {
  return c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X' ||
         c == 'g' || c == 'G' || c == 'e' || c == 'E' || c == 'f' || c == 's' ||
         c == 'c' || c == 'p' || c == 'l' || c == 'h' || c == 'L';
}

int s21_is_number(char c) { return (c >= '0' && c <= '9'); }

struct_width s21_sprintf_str_to_int_width(char *buff, int count) {
  int result = 0;

  int multiplier = 1;
  int i = 0;
  s21_reverse_string(&buff, 0, count);
  while (buff[i]) {
    result += (buff[i] - '0') * multiplier;

    multiplier *= 10;
    i++;
  }

  struct_width width = {.num = result};

  return width;
}

struct_precision s21_sprintf_str_to_int_precision(char *buff, int count) {
  int result = 0;

  int multiplier = 1;
  int i = 0;
  s21_reverse_string(&buff, 0, count);
  while (buff[i]) {
    result += (buff[i] - '0') * multiplier;

    multiplier *= 10;
    i++;
  }

  struct_precision precision = {.flt = result, .dec = result, .str = result};

  return precision;
}

void s21_sprintf_check_specifiers(char **str, const char **format, int *printed,
                                  int *i, struct_settings *settings,
                                  va_list *arg) {
  if ((*format)[*i + 1] == '%')
    (*str)[*i] = (*format)[*i], (*format)++;

  else if ((*format)[*i + 1] == 'c')
    s21_sprintf_spec_c((char)va_arg(*arg, int), str, format, printed, *i,
                       *settings);

  else if ((*format)[*i + 1] == 's')
    s21_sprintf_spec_s(va_arg(*arg, char *), str, format, printed, *i,
                       *settings);

  else if ((*format)[*i + 1] == 'd' || (*format)[*i + 1] == 'i')
    if ((*settings).length.l_long)
      s21_sprintf_spec_d_long(va_arg(*arg, long int), str, format, printed, *i,
                              *settings);
    else
      s21_sprintf_spec_d(va_arg(*arg, int), str, format, printed, *i,
                         *settings);

  else if ((*format)[*i + 1] == 'u')
    s21_sprintf_spec_u(va_arg(*arg, long unsigned int), str, format, printed,
                       *i, *settings);

  else if ((*format)[*i + 1] == 'o' || (*format)[*i + 1] == 'x' ||
           (*format)[*i + 1] == 'X')
    s21_sprintf_spec_o(va_arg(*arg, long unsigned int), str, format, printed,
                       *i, *settings);

  else if ((*format)[*i + 1] == 'f' || (*format)[*i + 1] == 'e' ||
           (*format)[*i + 1] == 'E' || (*format)[*i + 1] == 'g' ||
           (*format)[*i + 1] == 'G')
    if ((*settings).length.L_double)
      s21_sprintf_spec_f(va_arg(*arg, long double), str, format, printed, *i,
                         *settings);
    else
      s21_sprintf_spec_f(va_arg(*arg, double), str, format, printed, *i,
                         *settings);

  else if ((*format)[*i + 1] == 'p')
    s21_sprintf_spec_p(va_arg(*arg, void *), str, format, printed, *i,
                       *settings);

  else {
    s21_sprintf_invalid_spec(str, format, i);
    *printed = -100000;
  }
}

void s21_sprintf_spec_c(int arg, char **str, const char **format, int *printed,
                        int i, struct_settings settings) {
  settings.zeros_width = 0;
  if (!settings.width.num) {
    (*str)[i] = arg;
    (*format)++;
  }

  else {
    char *tmp = calloc(2, sizeof(char));
    tmp[0] = arg;
    tmp[1] = '\0';

    s21_sprintf_fill_width(&tmp, settings);

    s21_sprintf_copy_str(&tmp, str, format, printed, i);

    if (tmp != S21_NULL) free(tmp);
  }
}

void s21_sprintf_spec_s(char *tmp, char **str, const char **format,
                        int *printed, int i, struct_settings settings) {
  settings.zeros_width = 0;

  if (tmp != S21_NULL) {
    int len = s21_strlen(tmp);

    char *tmpCopy = malloc((len + 1 + settings.width.num) * sizeof(char));
    s21_memset(tmpCopy, '0', len + 1);
    s21_strncpy(tmpCopy, tmp, len + 1);

    if (settings.precision.str != -1 && len > settings.precision.str) {
      tmpCopy[settings.precision.str] = '\0';
    }

    s21_sprintf_fill_width(&tmpCopy, settings);

    s21_sprintf_copy_str(&tmpCopy, str, format, printed, i);

    if (tmpCopy != S21_NULL) free(tmpCopy);
  }

  else {
    char *tmpN = malloc(sizeof(char) * 7);
    s21_memset(tmpN, '0', 7);
    s21_strncpy(tmpN, "(null)", 7);

    s21_sprintf_fill_width(&tmpN, settings);

    s21_sprintf_copy_str(&tmpN, str, format, printed, i);
    if (tmpN != S21_NULL) free(tmpN);
  }
}

void s21_sprintf_spec_d(int arg, char **str, const char **format, int *printed,
                        int i, struct_settings settings) {
  char *tmp = s21_sprintf_int_to_str(arg, settings);

  s21_sprintf_fill_precision(&tmp, settings.precision.dec);

  if (arg < 0 && (s21_size_t)settings.precision.dec + 1 > s21_strlen(tmp))
    s21_sprintf_add_minus(&tmp);

  if (settings.minus_width) {
    if (settings.add_plus == 1 && arg >= 0)
      s21_sprintf_add_plus(&tmp);
    else if (settings.add_space == 1 && arg >= 0)
      s21_sprintf_add_space(&tmp);
  } else {
    if (settings.add_plus) settings.width.num--;
  }

  s21_sprintf_fill_width(&tmp, settings);

  if (!settings.minus_width) {
    if (settings.add_plus == 1 && arg >= 0)
      s21_sprintf_add_plus(&tmp);
    else if (settings.add_space == 1 && arg >= 0)
      s21_sprintf_add_space(&tmp);
  }

  s21_sprintf_copy_str(&tmp, str, format, printed, i);

  if (tmp != S21_NULL) free(tmp);
}

void s21_sprintf_spec_d_long(long int arg, char **str, const char **format,
                             int *printed, int i, struct_settings settings) {
  char *tmp = s21_sprintf_long_int_to_str(arg, settings);

  s21_sprintf_fill_precision(&tmp, settings.precision.dec);

  if (arg < 0 && (s21_size_t)settings.precision.dec + 1 > s21_strlen(tmp))
    s21_sprintf_add_minus(&tmp);

  if (settings.minus_width) {
    if (settings.add_plus == 1 && arg >= 0)
      s21_sprintf_add_plus(&tmp);
    else if (settings.add_space == 1 && arg >= 0)
      s21_sprintf_add_space(&tmp);
  } else {
    if (settings.add_plus) settings.width.num--;
  }

  s21_sprintf_fill_width(&tmp, settings);

  if (!settings.minus_width) {
    if (settings.add_plus == 1 && arg >= 0)
      s21_sprintf_add_plus(&tmp);
    else if (settings.add_space == 1 && arg >= 0)
      s21_sprintf_add_space(&tmp);
  }

  s21_sprintf_copy_str(&tmp, str, format, printed, i);

  if (tmp != S21_NULL) free(tmp);
}

void s21_sprintf_spec_f(double arg, char **str, const char **format,
                        int *printed, int i, struct_settings settings) {
  char *tmp = s21_sprintf_flt_to_str(arg, settings, format, i);

  if (settings.minus_width) {
    if (settings.add_plus == 1 && arg >= 0)
      s21_sprintf_add_plus(&tmp);
    else if (settings.add_space == 1 && arg >= 0)
      s21_sprintf_add_space(&tmp);
  } else {
    if (settings.add_plus) settings.width.num--;
  }

  s21_sprintf_fill_width(&tmp, settings);

  if (!settings.minus_width) {
    if (settings.add_plus == 1 && arg >= 0)
      s21_sprintf_add_plus(&tmp);
    else if (settings.add_space == 1 && arg >= 0)
      s21_sprintf_add_space(&tmp);
  }

  s21_sprintf_copy_str(&tmp, str, format, printed, i);

  if (tmp != S21_NULL) free(tmp);
}

void s21_sprintf_spec_u(long unsigned int arg, char **str, const char **format,
                        int *printed, int i, struct_settings settings) {
  char *tmp = s21_sprintf_uint_to_str(arg);
  s21_sprintf_fill_precision(&tmp, settings.precision.dec);
  s21_sprintf_fill_width(&tmp, settings);
  s21_sprintf_copy_str(&tmp, str, format, printed, i);
  if (tmp != S21_NULL) free(tmp);
}

void s21_sprintf_spec_o(long unsigned int arg, char **str, const char **format,
                        int *printed, int i, struct_settings settings) {
  char *tmp = NULL;
  int spec_x = 0;
  if ((*format)[i + 1] == 'x')
    spec_x = 1;
  else if ((*format)[i + 1] == 'X')
    spec_x = 2;

  if (!spec_x)
    tmp = s21_sprintf_octal_to_str(arg);
  else
    tmp = s21_sprintf_hex_to_str(arg, format, i);

  s21_sprintf_fill_precision(&tmp, settings.precision.dec);

  if (settings.force_output && !spec_x && tmp[0] != '0')
    s21_sprintf_add_symbol(&tmp, '0');

  else if (settings.force_output && spec_x && arg != 0) {
    if (spec_x == 1)
      s21_sprintf_add_symbol(&tmp, 'x');
    else
      s21_sprintf_add_symbol(&tmp, 'X');

    s21_sprintf_add_symbol(&tmp, '0');
  }

  s21_sprintf_fill_width(&tmp, settings);
  s21_sprintf_copy_str(&tmp, str, format, printed, i);
  if (tmp != S21_NULL) free(tmp);
}

void s21_sprintf_spec_p(void *ptr_arg, char **str, const char **format,
                        int *printed, int i, struct_settings settings) {
  if (ptr_arg != S21_NULL) {
    char *tmp = s21_sprintf_ptr_to_str(ptr_arg);

    if (settings.precision.dec == 1) s21_sprintf_remove_leading_zeros(&tmp);

    s21_sprintf_fill_precision(&tmp, settings.precision.dec);

    s21_sprintf_add_symbol(&tmp, 'x');
    s21_sprintf_add_symbol(&tmp, '0');

    s21_sprintf_fill_width(&tmp, settings);

    s21_sprintf_copy_str(&tmp, str, format, printed, i);

    if (tmp != S21_NULL) free(tmp);
  }

  else {
    char *tmp = malloc(sizeof(void *) * 2 + 1);
    s21_memset(tmp, '0', sizeof(void *) * 2);
    if (settings.precision.dec != 1)
      tmp[sizeof(void *) * 2] = '\0';
    else
      tmp[1] = '\0';

    s21_sprintf_fill_width(&tmp, settings);

    s21_sprintf_copy_str(&tmp, str, format, printed, i);
    if (tmp != S21_NULL) free(tmp);
  }
}

void s21_sprintf_copy_str(char **src, char **dst, const char **format,
                          int *printed, int i) {
  s21_strncpy(*dst + i, *src, s21_strlen(*src) + 1);
  int len = s21_strlen(*src) - 1;
  *printed += len;
  *dst += len, (*format)++;
}

void s21_sprintf_add_minus(char **tmp) { s21_sprintf_add_symbol(tmp, '-'); }

void s21_sprintf_add_plus(char **tmp) { s21_sprintf_add_symbol(tmp, '+'); }

void s21_sprintf_add_space(char **tmp) { s21_sprintf_add_symbol(tmp, ' '); }

void s21_sprintf_add_symbol(char **tmp, char c) {
  s21_size_t len = s21_strlen(*tmp);
  *tmp = realloc(*tmp, len + 2);

  (*tmp)[len] = c;
  s21_str_shift(tmp, len + 1, 1);
  (*tmp)[len + 1] = '\0';
}

void s21_sprintf_remove_leading_zeros(char **tmp) {
  int count = 0;
  for (; *(*tmp + count) == '0'; count++) {
    ;
  }

  if (count) {
    int len = (int)s21_strlen(*tmp);

    s21_strncpy(*tmp, *tmp + count, len - count);
    *(*tmp + len - count) = '\0';
  }
}

char *s21_sprintf_uint_to_str(long unsigned int arg) {
  int dst_size = 11;
  char *dst = calloc(dst_size, sizeof(char));
  int i = 0, j = 0;

  if (arg == 0) {
    dst[i] = '0';
    i++;
  } else {
    while (arg > 0) {
      if (i % 10 == 0) {
        dst = realloc(dst, sizeof(char) * (i + dst_size));
      }
      dst[i] = '0' + arg % 10;
      arg /= 10;
      i++;
    }
  }
  dst[i] = '\0';

  s21_reverse_string(&dst, j, i);

  return dst;
}

char *s21_sprintf_octal_to_str(long unsigned int arg) {
  long unsigned int octal = 0;

  while (arg > 0) {
    octal = octal * 10 + arg % 8;
    arg /= 8;
  }

  char *tmp = s21_sprintf_uint_to_str(octal);

  s21_reverse_string(&tmp, 0, s21_strlen(tmp));

  return tmp;
}

char *s21_sprintf_hex_to_str(long unsigned int arg, const char **format,
                             int i) {
  char *tmp = s21_sprintf_uint_to_str(arg);
  int len = s21_strlen(tmp);
  if (tmp != NULL) free(tmp);

  char *result = calloc(1, len + 3);

  s21_sprintf_convert_to_hex(&result, len, arg, ((*format)[i + 1] == 'X'));
  result[len] = '\0';

  s21_sprintf_remove_leading_zeros(&result);

  return result;
}

char *s21_sprintf_ptr_to_str(void *ptr_arg) {
  unsigned long arg = (unsigned long)ptr_arg;

  int len = (sizeof(void *) * 2);

  char *tmp = calloc(1, len + 3);

  s21_sprintf_convert_to_hex(&tmp, len, arg, 0);
  tmp[len + 2] = '\0';

  return tmp;
}

void s21_sprintf_convert_to_hex(char **dst, int dst_size, long unsigned int arg,
                                int is_capital) {
  static const char hex_capital[] = "0123456789ABCDEF";
  static const char hex[] = "0123456789abcdef";

  if (is_capital) {
    for (int i = 0; i < dst_size; i++) {
      (*dst)[dst_size - i - 1] = hex_capital[arg % 16];
      arg /= 16;
    }
  }

  else {
    for (int i = 0; i < dst_size; i++) {
      (*dst)[dst_size - i - 1] = hex[arg % 16];
      arg /= 16;
    }
  }
}

char *s21_sprintf_int_to_str(int arg, struct_settings settings) {
  int dst_size = 11;
  char *dst = calloc(dst_size, sizeof(char));
  int i = 0, have_minus = 0;

  if (arg < 0) {
    dst[i] = '-';
    arg = -arg;
    i++, have_minus = 1;
  }

  if (arg == 0) {
    dst[i] = '0';
    i++;
  }

  else {
    while (arg > 0) {
      if (i % 10 == 0) {
        dst = realloc(dst, sizeof(char) * (i + dst_size));
      }
      dst[i] = '0' + arg % 10;
      arg /= 10;
      i++;
    }
  }
  dst[i] = '\0';

  s21_sprintf_int_to_str_end(have_minus, settings, i, dst_size, &dst);

  return dst;
}

char *s21_sprintf_long_int_to_str(long int arg, struct_settings settings) {
  int dst_size = 11;
  char *dst = calloc(dst_size, sizeof(char));
  int i = 0, have_minus = 0;

  if (arg < 0) {
    dst[i] = '-';
    arg = -arg;
    i++, have_minus = 1;
  }

  if (arg == 0) {
    dst[i] = '0';
    i++;
  }

  else {
    while (arg > 0) {
      if (i % 10 == 0) {
        dst = realloc(dst, sizeof(char) * (i + dst_size));
      }
      dst[i] = '0' + arg % 10;
      arg /= 10;
      i++;
    }
  }
  dst[i] = '\0';

  s21_sprintf_int_to_str_end(have_minus, settings, i, dst_size, &dst);

  return dst;
}

void s21_sprintf_int_to_str_end(int have_minus, struct_settings settings, int i,
                                int dst_size, char **dst) {
  if (have_minus == 1 && settings.precision.dec > (int)s21_strlen((*dst))) {
    (*dst) = realloc((*dst), sizeof(char) * (i + dst_size) + 1);
    **dst = '0';
    (*dst)[i + 1] = '\0';
    s21_reverse_string(dst, 1, i);
  }

  else {
    s21_reverse_string(dst, 0, i);
  }
}

void s21_sprintf_fill_width(char **dst, struct_settings settings) {
  int len = s21_strlen(*dst);

  if (settings.width.num > len) {
    *dst = realloc(*dst, (len + 1 + (settings.width.num - len)) * sizeof(char));
    if (settings.zeros_width && !settings.minus_width)
      s21_memset(*dst + len, '0', settings.width.num - len);
    else
      s21_memset(*dst + len, ' ', settings.width.num - len);

    while (settings.width.num > len) {
      if (settings.minus_width == 0)
        s21_str_shift(dst, len + 1, 1);
      else
        s21_str_shift(dst, len + 1, len + 1);

      len++;
    }

    (*dst)[len] = '\0';
  }
}

void s21_sprintf_fill_precision(char **dst, int precision_decimal) {
  int len = s21_strlen(*dst);

  if (precision_decimal > len) {
    *dst = realloc(*dst, (len + 1 + (precision_decimal - len)) * sizeof(char));
    s21_memset(*dst + len, '0', precision_decimal - len);

    s21_str_shift(dst, precision_decimal, precision_decimal - len);
    (*dst)[precision_decimal] = '\0';
  }
}

void s21_str_shift(char **dst, int dst_size, int steps) {
  dst_size--;
  for (int i = 0; i < steps; i++) {
    for (int j = 0; j < dst_size; j++) {
      char tmp = (*dst)[dst_size - j];
      (*dst)[dst_size - j] = (*dst)[dst_size - j - 1];
      (*dst)[dst_size - j - 1] = tmp;
    }
  }
}

char *s21_sprintf_flt_to_str(double arg, struct_settings settings,
                             const char **format, int i_format) {
  int spec_e = 0, spec_g = 0;
  s21_sprintf_spec_e_or_g(&spec_g, &spec_e, format, i_format);

  if (settings.precision.flt == 0) arg = round(arg);

  int dst_size = 13;
  char *dst = calloc(dst_size, sizeof(char));
  int i = 0, j = 0, integersC = 0, floatingsC = 0;

  s21_flt_to_str_entry(&arg, &dst, &i);

  int count_integers = s21_flt_to_str_count_integers(arg);

  int spec_g_have_no_exponent =
      (spec_g && settings.precision.flt >= count_integers);

  int exponent = 0;
  if (spec_e || (spec_g && !spec_g_have_no_exponent))
    s21_sprintf_move_integers_to_exponent(&arg, &exponent);

  double rounded_values = 0;
  double float_values = modf(arg, &rounded_values);

  int count_floats = s21_flt_to_str_count_floats(float_values);

  s21_flt_to_str_setting_g(spec_g, spec_g_have_no_exponent, count_integers,
                           &count_floats, &settings);

  s21_flt_to_str_write_to_string(
      spec_g, spec_g_have_no_exponent, spec_e, exponent, float_values,
      floatingsC, count_floats, &dst, dst_size, settings, count_integers,
      rounded_values, integersC, j, i);

  return dst;
}

void s21_sprintf_spec_e_or_g(int *spec_g, int *spec_e, const char **format,
                             int i_format) {
  if ((*format)[i_format + 1] == 'g')
    *spec_g = 1;
  else if ((*format)[i_format + 1] == 'G')
    *spec_g = 2;

  if ((*format)[i_format + 1] == 'e')
    *spec_e = 1;
  else if ((*format)[i_format + 1] == 'E')
    *spec_e = 2;
}

void s21_flt_to_str_entry(double *arg, char **dst, int *i) {
  if (*arg < 0) {
    (*dst)[*i] = '-';
    *arg = -(*arg);
    (*i)++;
  }
}

void s21_sprintf_move_integers_to_exponent(double *arg, int *exponent) {
  while (*arg >= 10.0) {
    *arg /= 10.0;
    (*exponent)++;
  }
}

int s21_flt_to_str_count_integers(double rounded_values) {
  long long_value = lround(rounded_values);
  int result = 0;

  while (long_value > 0) {
    long_value /= 10, result++;
  }

  return result;
}

int s21_flt_to_str_count_floats(double float_values) {
  int result = 0;

  while (trunc(float_values) != float_values) {
    float_values *= 10;
    result++;
  }

  return result;
}

void s21_flt_to_str_setting_g(int spec_g, int spec_g_have_no_exponent,
                              int count_integers, int *count_floats,
                              struct_settings *settings) {
  if (spec_g) {
    if (spec_g_have_no_exponent) (*settings).precision.flt -= count_integers;

    if (!spec_g_have_no_exponent && (*settings).precision.flt > 0)
      (*settings).precision.flt--, (*count_floats)--;
  }
}

void s21_flt_to_str_write_to_string(int spec_g, int spec_g_have_no_exponent,
                                    int spec_e, int exponent,
                                    double float_values, int floatingsC,
                                    int count_floats, char **dst, int dst_size,
                                    struct_settings settings,
                                    int count_integers, double rounded_values,
                                    int integersC, int j, int i) {
  s21_flt_to_str_write_floats(float_values, &floatingsC, &i, dst, &dst_size,
                              settings, spec_g, count_integers);

  s21_flt_to_str_write_integers(rounded_values, &integersC, &i, dst, &dst_size);

  s21_reverse_string(dst, j, i);

  s21_flt_to_str_set_precision(dst, dst_size, settings, count_floats);

  int spec_e_or_g = (spec_g && !spec_g_have_no_exponent) ? spec_g : spec_e;

  s21_flt_to_str_fill_exponent(dst, exponent, spec_e_or_g);
}

void s21_flt_to_str_write_floats(double float_values, int *floatingsC, int *i,
                                 char **dst, int *dst_size,
                                 struct_settings settings, int spec_g,
                                 int count_integers) {
  int have_precision = settings.precision.flt;
  while (trunc(float_values) != float_values) {
    float_values *= 10;
    (*floatingsC)++;
  }
  long tmp = trunc(float_values);
  int floatingsCopy = *floatingsC;

  if (!(spec_g && settings.precision.flt > floatingsCopy - count_integers)) {
    if (floatingsCopy > settings.precision.flt) {
      for (int j = 0; j < floatingsCopy - settings.precision.flt; j++) {
        float_values /= 10;
        tmp = lround(float_values);
      }
    }

    while (!(tmp < 1)) {
      *dst_size += *i;
      if (*i % 10 == 0) {
        *dst = realloc(*dst, sizeof(char) * (*dst_size));
      }
      (*dst)[*i] = '0' + tmp % 10;
      tmp /= 10;
      (*i)++, floatingsCopy--;
    }
    if (have_precision) (*dst)[(*i)++] = '.';
  }
}

void s21_flt_to_str_write_integers(double rounded_values, int *integersC,
                                   int *i, char **dst, int *dst_size) {
  if (rounded_values >= 0 && rounded_values < 1) {
    (*dst)[*i] = '0';
    (*i)++, (*integersC)++;
  }

  while (!(rounded_values < 1)) {
    *dst_size += *i + 1;
    if (*i % 10 == 0) {
      *dst = realloc(*dst, sizeof(char) * (*dst_size));
    }
    (*dst)[*i] = '0' + (int)fmod(trunc(rounded_values), 10.0);
    rounded_values /= 10.0;
    (*i)++;
  }
  (*dst)[*i] = '\0';
}

void s21_reverse_string(char **dst, int j, int i) {
  if ((*dst)[0] == '-') {
    j++;
  }

  for (i--; j < i; j++, i--) {
    char tmp = (*dst)[j];
    (*dst)[j] = (*dst)[i];
    (*dst)[i] = tmp;
  }
}

void s21_flt_to_str_set_precision(char **dst, int dst_size,
                                  struct_settings settings, int floatingsC) {
  if (settings.precision.flt < 0) settings.precision.flt = 0;

  *dst = realloc(*dst, sizeof(char) * (dst_size + settings.precision.flt + 1));
  char *tmp = S21_NULL;
  if (dst != S21_NULL) tmp = s21_strchr(*dst, '.');

  if (tmp != S21_NULL) {
    s21_memset(tmp + 1 + floatingsC, '0', settings.precision.flt);
    tmp++;
    tmp[settings.precision.flt] = '\0';
  }

  else if (settings.force_output) {
    int len = s21_strlen(*dst);
    (*dst)[len] = '.';
  }
}

void s21_flt_to_str_fill_exponent(char **dst, int exponent, int spec_e) {
  if (spec_e) {
    char *exp = s21_sprintf_create_exp_str(exponent);  // "e+00", "e+01"...
    if (spec_e == 2) exp[0] = 'E';

    s21_size_t len = s21_strlen(*dst);
    *dst = realloc(*dst, (len + 5) * sizeof(char));
    s21_memset(*dst + len, '0', 4);
    s21_strncpy(*dst + len, exp, 4);

    (*dst)[len + 4] = '\0';

    if (exp != S21_NULL) free(exp);
  }
}

char *s21_sprintf_create_exp_str(int exponent) {
  char *exponent_string = malloc(5 * sizeof(char));
  s21_strncpy(exponent_string, "e+00", 5);

  if (exponent) {
    if (exponent >= 10) {
      exponent_string[2] = '0' + (exponent / 10);
      exponent %= 10;
    }

    exponent_string[3] = '0' + exponent;
  }

  return exponent_string;
}

void s21_sprintf_invalid_spec(char **str, const char **format, int *i) {
  (*str)[*i] = (*format)[*i], (*i)++;

  (*str)[*i] = (*format)[*i], (*i)++;

  while ((*format)[*i] == '0') (*format)++;

  if ((*str)[*i - 1] == '.' && !s21_is_number((*format)[*i])) {
    (*str)[*i] = '0';
    (*i)++, (*format)--;
  }

  for (; (*format)[*i] != 0 && (*format)[*i] != '%'; (*i)++) {
    (*str)[*i] = (*format)[*i];
  }
  (*i)--;
}
