#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *s = s21_NULL;
  unsigned char found = 0;
  for (s21_size_t i = 0; i <= s21_strlen(str) && !found; i++) {
    if (str[i] == c) {
      s = ((char *)str) + i;
      found = 1;
    }
  }

  return s;
}
