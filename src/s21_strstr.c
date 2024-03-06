#include "s21_string.h"

char *s21_strstr(const char *highstack, const char *needle) {
  unsigned char found = 0;
  const char *result = s21_NULL;
  const char *p = highstack;
  s21_size_t len = s21_strlen(needle);

  if (len == 0) {
    found = 1;
    result = highstack;
  }
  while (*p && found == 0) {
    if (s21_strncmp(p, needle, len) == 0) {
      result = p;
      found = 1;
    }
    p++;
  }
  return found ? (char *)result : s21_NULL;
}
