#include "s21_string.h"

char* s21_strtok(char* str, const char* delim) {
  static char* local;
  char* tok = s21_NULL;
  int jd = 0;
  if (str) {
    local = str;
  }

  while (s21_strchr(delim, *local) != s21_NULL && *local != '\0') {
    local++;
  };
  tok = local;

  for (; *local != '\0'; local++) {
    if (s21_strchr(delim, *local) != s21_NULL) {
      if (jd == 0) {
        tok++;
      } else {
        *local = '\0';
        local++;
        break;
      }
    }
    jd++;
  }
  if (tok == local) return (s21_NULL);
  return tok;
}
