// Возвращаемое значение:
//   Положительное число, если при сравнении массивов встретился отличный байт и
// байт из массива, на который указывает аргумент arr1, больше байта из массива,
// на который указывает аргумент arr2.
//   Отрицательное число, если при сравнении массивов встретился отличный байт и
// байт из массива, на который указывает аргумент arr1, меньше байта из массива,
// на который указывает аргумент arr2.
//  0 – если сравниваемые части массивов идентичны.

// Описание:
// Функция memcmp побайтно сравнивает два массива (области памяти), на которые
// указывают аргументы arr1 и arr2. Каждый байт массива определяется типом
// unsigned char. Сравнение продолжается, пока не будут проверено n байт или
// пока не встретятся отличающиеся байты.

#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  if (!n) return (0);

  while (--n && *(char *)str1 == *(char *)str2) {
    str1 = (char *)str1 + 1;
    str2 = (char *)str2 + 1;
  }

  return (*((unsigned char *)str1) - *((unsigned char *)str2));
}