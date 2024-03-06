#include "s21_string.h"

void* s21_memchr(void const* str, unsigned int c, s21_size_t n) {
  int fl = 0;
  s21_size_t i = 0;
  for (; i < n && fl == 0; i++) {
    if (*((unsigned char*)(str) + i) == (unsigned char)c) {
      fl = 1;
    }
  }
  return (fl == 1) ? ((unsigned char*)str + i - 1) : s21_NULL;
}