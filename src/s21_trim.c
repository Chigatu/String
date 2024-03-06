#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *s_copy = s21_NULL;
  unsigned char ok = 1;
  // если не пустая строка
  if (src == s21_NULL) {
    ok = 0;
  }
  if (trim_chars == s21_NULL) {
    ok = 0;
  }
  // захваить память
  if (ok && !(s_copy = calloc(s21_strlen(src) + 1, sizeof(char)))) {
    ok = 0;
  }
  // скопировать с пропуском начала
  if (ok) {
    const char *p;
    for (p = src; *p && s21_strchr(trim_chars, *p); p++)
      ;
    s21_memcpy(s_copy, p, s21_strlen(p) + 1);
    // замениь кокнчание 0
    for (int i = s21_strlen(s_copy);
         i >= 0 && s21_strchr(trim_chars, s_copy[i]); i--) {
      s_copy[i] = '\0';
    }
  }

  return s_copy;
}
