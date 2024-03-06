#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  const char *temp = str;
  char *last = s21_NULL;
  while (*temp) {
    if (*temp == c) last = (char *)temp;
    temp++;
  }
  if (c == 0) last = (char *)temp;
  return last;
}