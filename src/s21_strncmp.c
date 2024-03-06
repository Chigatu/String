#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  if (!n) return 0;
  const char *temp_str1 = str1;
  const char *temp_str2 = str2;

  while (*temp_str1 && *temp_str1 == *temp_str2 && --n) {
    temp_str1++;
    temp_str2++;
  }
  return (*(unsigned char *)temp_str1 - *(unsigned char *)temp_str2);
}