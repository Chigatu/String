#include "s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *tmp = s21_NULL;
  if (str != s21_NULL) {
    tmp = str;
    for (s21_size_t i = 0; i < n; i++) {
      tmp[i] = (unsigned char)c;
    }
  }
  return tmp;
}
