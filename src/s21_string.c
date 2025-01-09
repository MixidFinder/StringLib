#include "s21_string.h"

/* Находит первый символ в строке str1, который соответствует любому символу,
 * указанному в str2.*/
char *s21_strpbrk(const char *str1, const char *str2) {
  char *ch = S21_NULL;

  while (*str2 && ch == S21_NULL) {
    ch = s21_strchr(str1, *str2);
    str2++;
  }
  return ch;
}

/*Выполняет поиск первого вхождения символа c (беззнаковый тип) в строке, на
 * которую указывает аргумент str.*/
char *s21_strchr(const char *str, int c) {
  char *ch = S21_NULL;

  while (*str && ch == S21_NULL) {
    if (*str == c) {
      ch = (char *)str;
    }
    str++;
  }

  return ch;
}

/*Выполняет поиск последнего вхождения символа c (беззнаковый тип) в строке, на
 * которую указывает аргумент str.*/
char *s21_strrchr(const char *str, int c) {
  char *ch = S21_NULL;

  while (*str) {
    if (*str == c) {
      ch = (char *)str;
    }
    str++;
  }

  return ch;
}

/* Находит первое вхождение всей строки needle (не включая завершающий нулевой
   символ), которая появляется в строке haystack. */
char *s21_strstr(const char *haystack, const char *needle) {
  char *ch = S21_NULL;
  int find = 0;

  while (*haystack && !find) {
    const char *tempH = haystack;
    const char *tempN = needle;
    while (*tempH && *tempH == *tempN) {
      tempH++;
      tempN++;
    }

    if (*tempN == '\0') {
      ch = (char *)haystack;
      find = 1;
    }

    haystack++;
  }

  return ch;
}

/*Вычисляет длину строки str, не включая завершающий нулевой символ.*/
s21_size_t s21_strlen(const char *str) {
  s21_size_t len = 0;

  for (const char *i = str; *i != '\0'; i++) {
    len++;
  }

  return len;
}

/*Возвращает копию строки (str), преобразованной в верхний регистр. В случае
 * какой-либо ошибки следует вернуть значение NULL.*/
void *s21_to_upper(const char *str) {
  if (str == S21_NULL) {
    return S21_NULL;
  }

  s21_size_t len = s21_strlen(str) + 1;
  char *ch = calloc(len, sizeof(char));

  for (s21_size_t i = 0; i < len && ch; i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      ch[i] = str[i] - 32;
    } else {
      ch[i] = str[i];
    }
  }

  return ch;
}

/*Возвращает копию строки (str), преобразованной в нижний регистр. В случае
 * какой-либо ошибки следует вернуть значение NULL.*/
void *s21_to_lower(const char *str) {
  if (str == S21_NULL) {
    return S21_NULL;
  }

  s21_size_t len = s21_strlen(str) + 1;
  char *ch = calloc(len, sizeof(char));

  for (s21_size_t i = 0; i < len && ch; i++) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      ch[i] = str[i] + 32;
    } else {
      ch[i] = str[i];
    }
  }

  return ch;
}

/*Возвращает новую строку, в которой указанная строка (str) вставлена в
 * указанную позицию (start_index) в данной строке (src). В случае какой-либо
 * ошибки следует вернуть значение NULL.*/
char *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if (src == S21_NULL || str == S21_NULL || start_index > s21_strlen(src)) {
    return S21_NULL;
  }

  s21_size_t str_len = s21_strlen(str);
  s21_size_t ch_len = s21_strlen(src) + str_len + 1;

  char *ch = calloc(ch_len, sizeof(char));

  for (s21_size_t i = 0, k = 0; i < ch_len && ch;) {
    if (i == start_index) {
      for (s21_size_t j = 0; j < str_len; j++, i++) {
        ch[i] = str[j];
      }
    } else {
      ch[i] = src[k];
      i++;
      k++;
    }
  }

  return ch;
}

/*Возвращает новую строку, в которой удаляются все начальные и конечные
 * вхождения набора заданных символов (trim_chars) из данной строки (src). В
 * случае какой-либо ошибки следует вернуть значение NULL. */
void *s21_trim(const char *src, const char *trim_chars) {
  if (src == S21_NULL || trim_chars == S21_NULL || *src == '\0' ||
      *trim_chars == '\0') {
    return S21_NULL;
  }

  const char *start = src;
  const char *end = src + s21_strlen(src);
  s21_size_t trim_len = s21_strlen(trim_chars);

  while (start && s21_strstr(start, trim_chars) == start) {
    start += trim_len;
  }

  while (end && s21_strstr(end - trim_len, trim_chars) == end - trim_len) {
    end -= trim_len;
  }

  size_t len = end - start;

  char *ch = calloc(len + 1, sizeof(char));

  for (size_t i = 0; i < len && ch; i++) {
    ch[i] = start[i];
  }

  return ch;
}

/*Сравнивает не более первых n байтов str1 и str2.*/
int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  s21_size_t i = 0;
  int result = 0;

  if (str1 && str2 && n > 0) {
    for (n--; i < n && (str1[i] && str2[i]) && str1[i] == str2[i]; i++) {
    }

    result = str1[i] - str2[i];

    // При valgrind для прохождения тестов нужно это
    // if (result > 0)
    //   result = 1;
    // else if (result < 0)
    //   result = -1;
  }

  return result;
}

/*Копирует до n символов из строки, на которую указывает src, в dest.*/
char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t i = 0;

  while (dest && i < n) {
    if (!src[i])
      for (; dest && i < n; i++) dest[i] = '\0';

    else
      dest[i] = src[i];

    i++;
  }

  return dest;
}

/*Разбивает строку str на ряд токенов, разделенных delim.*/
char *s21_strtok(char *str, const char *delim) {
  static char *token = S21_NULL;
  char *ptr = (str != S21_NULL) ? str : token;
  char *ptr_res = ptr;
  int found_delim = 0;
  int prev_delim = (str != S21_NULL) ? 1 : 0;

  while (ptr && *ptr && !found_delim) {
    for (s21_size_t i = 0; delim[i]; i++) {
      if (*ptr == delim[i] && prev_delim) {
        i = 0, prev_delim = 1;
        ptr_res++;
        ptr++;
      } else if (*ptr == delim[i]) {
        i = 0, found_delim = 1;
        *ptr = '\0';
        ptr++;
      }
    }
    prev_delim = 0;

    if (found_delim)
      token = ptr;
    else if (*ptr)
      ptr++;
  }

  if (ptr != S21_NULL) {
    if (!found_delim)
      token = S21_NULL;
    else if (*ptr == '\0')
      token = S21_NULL;

    if (*ptr_res == '\0') {
      ptr_res = S21_NULL;
      token = S21_NULL;
    }
  }
  return ptr_res;
}

/*Вычисляет длину начального сегмента str1, который полностью состоит из
 * символов, не входящих в str2.*/
s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t len = 0;

  if (str1 && str2) {
    int found = 0;

    while (str1[len] && !found) {
      for (s21_size_t i = 0; str2[i]; i++) {
        if (str1[len] == str2[i]) {
          found = 1;
        }
      }
      if (!found) len++;
    }
  }

  return len;
}

/*Выполняет поиск первого вхождения символа c (беззнаковый тип) в первых n
 * байтах строки, на которую указывает аргумент str.*/
void *s21_memchr(const void *str, int c, s21_size_t n) {
  if (!str || c < 0 || n > s21_strlen(str)) {
    return S21_NULL;
  }

  const unsigned char *ch = (const unsigned char *)str;
  int find = 0;

  for (size_t i = 0; i < n && !find; i++) {
    if (ch[i] == c) {
      find = 1;
      ch += i;
    }
  }

  return find ? (void *)ch : S21_NULL;
}

/*Сравнивает первые n байтов str1 и str2.*/
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const unsigned char *ptr1 = (const unsigned char *)str1;
  const unsigned char *ptr2 = (const unsigned char *)str2;

  int check = 0;

  for (s21_size_t i = 0; i < n && !check; i++) {
    check = ptr1[i] - ptr2[i];
  }

  return check;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  if (dest != S21_NULL && src != S21_NULL) {
    unsigned char *ptr_dest = (unsigned char *)dest;
    const unsigned char *ptr_src = (const unsigned char *)src;

    for (s21_size_t i = 0; ptr_dest && ptr_src && i < n; i++) {
      ptr_dest[i] = ptr_src[i];
    }
  }
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  if (str != S21_NULL) {
    unsigned char *ptr = (unsigned char *)str;

    for (s21_size_t i = 0; ptr && i < n; i++) {
      ptr[i] = c;
    }
  }
  return str;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  if (dest && src) {
    s21_size_t len = s21_strlen(dest);
    s21_strncpy(dest + len, src, n);
  }
  return dest;
}