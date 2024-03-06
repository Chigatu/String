#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t len = 0;
  unsigned char notfound = 1;
  for (const char *s1 = str1; *s1 && notfound; s1++) {
    if (s21_strchr(str2, *s1)) {
      notfound = 0;
    }
    if (notfound) len += 1;
  }
  return len;
}