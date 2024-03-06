#include "s21_string.h"

void *s21_insert(const char *src, const char *str, size_t start_index) {
  unsigned char ok = 1;
  char *s_copy = s21_NULL;
  s21_size_t len_src;
  s21_size_t len_str;

  if (src == s21_NULL)
    ok = 0;
  else
    len_src = s21_strlen(src);
  if (ok && start_index > len_src) ok = 0;
  if (str == s21_NULL)
    ok = 0;
  else
    len_str = s21_strlen(str);
  if (ok && !(s_copy = calloc(start_index + len_str + 1, sizeof(char)))) ok = 0;
  if (ok) {
    // скопировать начало из src
    s21_strncpy(s_copy, src, start_index);
    //  добавить хвост из str
    s21_strncpy(s_copy + start_index, str, len_str);
  }
  return s_copy;
}
