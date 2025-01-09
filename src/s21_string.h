#ifndef S21_STRING
#define S21_STRING

#include <math.h>
#include <stdarg.h>
#include <stdlib.h>

// BASE STRING
#define S21_NULL ((void *)0)
#define s21_size_t long unsigned int

void *s21_memchr(const void *str, int c, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);

// BONUS STRING
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
char *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

// SPRINTF
#define S21_MAX_FLOAT 3.40282347e+38F

#define DEFAULT_PRECISION_F 6
#define DEFAULT_PRECISION_D 1
#define DEFAULT_PRECISION_S -1

typedef struct {
  int num;
} struct_width;

typedef struct {
  int flt;
  int dec;
  int str;
} struct_precision;

typedef struct {
  int h_short;
  int l_long;
  int L_double;
} struct_length;

typedef struct {
  int add_plus;
  int add_space;
  int minus_width;
  int zeros_width;
  int force_output;
  struct_width width;
  struct_precision precision;
  struct_length length;
} struct_settings;

int s21_sscanf(const char *str, const char *format, ...);
void s21_sscanf_check_specifiers(const char **str, const char **format,
                                 int *printed, int *i,
                                 struct_settings *settings, va_list *arg);
void s21_sscanf_spec_c(char *arg, const char **str, const char **format,
                       int *printed, int i, struct_settings settings);
void s21_sscanf_spec_s(char *tmp, const char **str, const char **format,
                       int *printed, struct_settings settings);
void s21_sscanf_spec_d(int *arg, const char **str, const char **format,
                       int *printed);
void s21_sscanf_spec_d_long(long int *arg, const char **str,
                            const char **format, int *printed);
void s21_sscanf_spec_u(unsigned int *arg, const char **str, const char **format,
                       int *printed);
long long int s21_sscanf_str_to_int(const char **str);
void s21_sscanf_skip_blank(const char **str);
int s21_is_blank(char c);

int s21_sprintf(char *str, const char *format, ...);
struct_settings s21_sprintf_set_settings(va_list *arg, const char **format,
                                         int *i, int *has_specifier);
void s21_sprintf_parse_flags(const char **format, int *i,
                             struct_settings *settings);
int s21_sprintf_is_flag(char c);
void s21_sprintf_setting_width(va_list *arg, const char **format, int *i,
                               struct_settings *settings);
void s21_sprintf_setting_precision(va_list *arg, const char **format, int *i,
                                   struct_settings *settings);
void s21_sprintf_parse_length(const char **format, int *i,
                              struct_settings *settings);
int s21_sprintf_parse_specifier(const char **format, int *i, int count);
char *s21_sprintf_get_numbers_from_string(const char **format, int *i,

                                          int *count);
struct_width s21_sprintf_str_to_int_width(char *buff, int count);
struct_precision s21_sprintf_str_to_int_precision(char *buff, int count);
void s21_sprintf_check_specifiers(char **str, const char **format, int *printed,
                                  int *i, struct_settings *settings,
                                  va_list *arg);
int s21_sprintf_is_valid_spec_or_length(char c);

int s21_is_number(char c);
void s21_reverse_string(char **dst, int j, int i);
void s21_str_shift(char **dst, int dst_size, int steps);
void s21_sprintf_copy_str(char **src, char **dst, const char **format,
                          int *printed, int i);

void s21_sprintf_spec_s(char *tmp, char **str, const char **format,
                        int *printed, int i, struct_settings settings);
void s21_sprintf_spec_c(int arg, char **str, const char **format, int *printed,
                        int i, struct_settings settings);
void s21_sprintf_spec_d(int arg, char **str, const char **format, int *printed,
                        int i, struct_settings settings);
void s21_sprintf_spec_d_long(long int arg, char **str, const char **format,
                             int *printed, int i, struct_settings settings);
void s21_sprintf_spec_u(long unsigned int arg, char **str, const char **format,
                        int *printed, int i, struct_settings settings);
void s21_sprintf_spec_o(long unsigned int arg, char **str, const char **format,
                        int *printed, int i, struct_settings settings);
void s21_sprintf_spec_f(double arg, char **str, const char **format,
                        int *printed, int i, struct_settings settings);
void s21_sprintf_spec_p(void *ptr_arg, char **str, const char **format,
                        int *printed, int i, struct_settings settings);
void s21_sprintf_invalid_spec(char **str, const char **format, int *i);

void s21_sprintf_add_minus(char **tmp);
void s21_sprintf_add_plus(char **tmp);
void s21_sprintf_add_space(char **tmp);
void s21_sprintf_add_symbol(char **tmp, char c);
void s21_sprintf_remove_leading_zeros(char **tmp);
void s21_sprintf_fill_width(char **dst, struct_settings settings);
void s21_sprintf_fill_precision(char **dst, int precision_decimal);

char *s21_sprintf_int_to_str(int arg, struct_settings settings);
char *s21_sprintf_long_int_to_str(long int arg, struct_settings settings);
void s21_sprintf_int_to_str_end(int have_minus, struct_settings settings, int i,
                                int dst_size, char **dst);
char *s21_sprintf_uint_to_str(long unsigned int arg);
char *s21_sprintf_octal_to_str(long unsigned int arg);
char *s21_sprintf_hex_to_str(long unsigned int arg, const char **format, int i);
char *s21_sprintf_ptr_to_str(void *ptr_arg);
void s21_sprintf_convert_to_hex(char **dst, int dst_size, long unsigned int arg,
                                int is_capital);

char *s21_sprintf_flt_to_str(double arg, struct_settings settings,
                             const char **format, int i_format);
void s21_sprintf_spec_e_or_g(int *spec_g, int *spec_e, const char **format,
                             int i_format);
void s21_flt_to_str_entry(double *arg, char **dst, int *i);
void s21_sprintf_move_integers_to_exponent(double *arg, int *exponent);
int s21_flt_to_str_count_integers(double rounded_values);
int s21_flt_to_str_count_floats(double float_values);
void s21_flt_to_str_setting_g(int spec_g, int spec_g_have_no_exponent,
                              int count_integers, int *count_floats,
                              struct_settings *settings);
void s21_flt_to_str_write_to_string(int spec_g, int spec_g_have_no_exponent,
                                    int spec_e, int exponent,
                                    double float_values, int floatingsC,
                                    int count_floats, char **dst, int dst_size,
                                    struct_settings settings,
                                    int count_integers, double rounded_values,
                                    int integersC, int j, int i);
void s21_flt_to_str_write_floats(double float_values, int *floatingsC, int *i,
                                 char **dst, int *dst_size,
                                 struct_settings settings, int spec_g,
                                 int count_integers);
void s21_flt_to_str_write_integers(double rounded_values, int *integersC,
                                   int *i, char **dst, int *dst_size);
void s21_flt_to_str_set_precision(char **dst, int dst_size,
                                  struct_settings settings, int floatingsC);
void s21_flt_to_str_fill_exponent(char **dst, int exponent, int spec_e);
char *s21_sprintf_create_exp_str(int exponent);

// STRERROR
#define EPERM 1
#define ENOENT 2
#define ESRCH 3
#define EINTR 4
#define EIO 5
#define ENXIO 6
#define E2BIG 7
#define ENOEXEC 8
#define EBADF 9
#define ECHILD 10
#define EAGAIN 11
#define ENOMEM 12
#define EACCES 13
#define EFAULT 14
#define ENOTBLK 15
#define EBUSY 16
#define EEXIST 17
#define EXDEV 18
#define ENODEV 19
#define ENOTDIR 20
#define EISDIR 21
#define EINVAL 22
#define ENFILE 23
#define EMFILE 24
#define ENOTTY 25
#define ETXTBSY 26
#define EFBIG 27
#define ENOSPC 28
#define ESPIPE 29
#define EROFS 30
#define EMLINK 31
#define EPIPE 32
#define EDOM 33
#define ERANGE 34
#define EDEADLK 35
#define ENAMETOOLONG 36
#define ENOLCK 37
#define ENOSYS 38
#define ENOTEMPTY 39
#define ELOOP 40
#define EWOULDBLOCK EAGAIN
#define ENOMSG 42
#define EIDRM 43
#define ECHRNG 44
#define EL2NSYNC 45
#define EL3HLT 46
#define EL3RST 47
#define ELNRNG 48
#define EUNATCH 49
#define ENOCSI 50
#define EL2HLT 51
#define EBADE 52
#define EBADR 53
#define EXFULL 54
#define ENOANO 55
#define EBADRQC 56
#define EBADSLT 57
#define EDEADLOCK EDEADLK
#define EBFONT 59
#define ENOSTR 60
#define ENODATA 61
#define ETIME 62
#define ENOSR 63
#define ENONET 64
#define ENOPKG 65
#define EREMOTE 66
#define ENOLINK 67
#define EADV 68
#define ESRMNT 69
#define ECOMM 70
#define EPROTO 71
#define EMULTIHOP 72
#define EDOTDOT 73
#define EBADMSG 74
#define EOVERFLOW 75
#define ENOTUNIQ 76
#define EBADFD 77
#define EREMCHG 78
#define ELIBACC 79
#define ELIBBAD 80
#define ELIBSCN 81
#define ELIBMAX 82
#define ELIBEXEC 83
#define EILSEQ 84
#define ERESTART 85
#define ESTRPIPE 86
#define EUSERS 87
#define ENOTSOCK 88
#define EDESTADDRREQ 89
#define EMSGSIZE 90
#define EPROTOTYPE 91
#define ENOPROTOOPT 92
#define EPROTONOSUPPORT 93
#define ESOCKTNOSUPPORT 94
#define EOPNOTSUPP 95
#define EPFNOSUPPORT 96
#define EAFNOSUPPORT 97
#define EADDRINUSE 98
#define EADDRNOTAVAIL 99
#define ENETDOWN 100
#define ENETUNREACH 101
#define ENETRESET 102
#define ECONNABORTED 103
#define ECONNRESET 104
#define ENOBUFS 105
#define EISCONN 106
#define ENOTCONN 107
#define ESHUTDOWN 108
#define ETOOMANYREFS 109
#define ETIMEDOUT 110
#define ECONNREFUSED 111
#define EHOSTDOWN 112
#define EHOSTUNREACH 113
#define EALREADY 114
#define EINPROGRESS 115
#define ESTALE 116
#define EUCLEAN 117
#define ENOTNAM 118
#define ENAVAIL 119
#define EISNAM 120
#define EREMOTEIO 121
#define EDQUOT 122
#define ENOMEDIUM 123
#define EMEDIUMTYPE 124
#define ECANCELED 125
#define ENOKEY 126
#define EKEYEXPIRED 127
#define EKEYREVOKED 128
#define EKEYREJECTED 129
#define EOWNERDEAD 130
#define ENOTRECOVERABLE 131
#define ERFKILL 132
#define EHWPOISON 133

char *s21_strerror(int errnum);

#endif