#ifndef S21_STRING_H
#define S21_STRING_H

#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>

#define s21_NULL ((void *)0)
typedef long unsigned int s21_size_t;

void *s21_memchr(const void *str, unsigned int c, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strtok(char *str, const char *delim);
s21_size_t s21_strlen(const char *str);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strchr(const char *str, int ch);
char *s21_strstr(const char *haystack, const char *needle);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strrchr(const char *str, int c);
// bonus func
int s21_sprintf(char *str, const char *format, ...);
int s21_sscanf();
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_trim(const char *src, const char *trim_chars);
void *s21_insert(const char *src, const char *str, size_t start_index);
// support function
bool is_digit(const char c);
void s21_errn(int val, char *ret);

#endif
