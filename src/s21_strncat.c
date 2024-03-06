#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t memlen = s21_strlen(dest);
  s21_size_t i = 0;
  while ((i < n) && src[i] != '\0') {
    dest[memlen + i] = src[i];
    i++;
  }
  dest[memlen + i] = '\0';
  return dest;
}