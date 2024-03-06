#include "s21_string.h"

void *s21_to_lower(const char *str) {
  char *s_copy = s21_NULL;
  char diff = 'A' - 'a';
  if (str != s21_NULL) {
    s21_size_t len = s21_strlen(str);
    s_copy = malloc(sizeof(char) * (len + 1));
    if (s_copy) {
      for (s21_size_t i = 0; i < len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
          s_copy[i] = str[i] - diff;
        } else {
          s_copy[i] = str[i];
        }
      }
      s_copy[len] = '\0';
    }
  }
  return s_copy;
}
