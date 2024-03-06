#include "s21_string.h"

typedef struct {
  bool plus;
  bool minus;
  bool space;
  int width;
  int precision;
  bool star_sign_width;
  bool star_sign_precision;
  bool hash_sign;
  bool null_sign;
  bool point;
  bool l;
  bool h;
  bool L;
  bool c;
  bool d;
  bool e;  // числа в формате 1.234e+01
  bool g;  // числа в формате 12.34
  bool E;
  bool f;
  bool G;
  bool o;
  bool s;
  bool u;
  bool x;
  bool X;
  bool p;
  bool percent;
} specs_struct;

char int_to_digit(int c) { return (c + '0'); }
bool is_digit(const char c) { return c >= '0' && c <= '9'; }

void parse_flags(specs_struct *specs, const char *format, int *idx) {
  char *format_flags = "-+ #0";
  char flag;
  while (s21_strchr(format_flags, (flag = format[*idx])) != NULL) {
    switch (flag) {
      case '-':
        specs->minus = true;
        break;
      case '+':
        specs->plus = true;
        break;
      case ' ':
        specs->space = true;
        break;
      case '#':
        specs->hash_sign = true;
        break;
      case '0':
        specs->null_sign = true;
        break;
    }
    *idx = *idx + 1;
  }
}

void precision_process(char *res, specs_struct specs, char param) {
  int prec = 0;
  int form_prec = specs.precision;
  if (!specs.point) return;
  if (s21_strchr("diouxX", param) != NULL) {
    char temp[2048] = "";
    int minus = res[0] == '-' ? 1 : 0;
    int len = (int)s21_strlen(res) - minus;
    if (form_prec > len) prec = form_prec - (int)s21_strlen(res) + minus;
    for (int i = 0; i < len; i++) {
      temp[i] = res[i + minus];
    }
    if (minus) {
      res[0] = '-';
    }
    for (int i = 0; i < prec; i++) {
      res[i + minus] = '0';
    }
    for (int i = 0; i < len; i++) {
      res[prec + i + minus] = temp[i];
    }
    if (form_prec == 0 && param == '0') res[0] = '\0';
  }
  if (s21_strchr("eEf", param) != NULL) {
    prec = form_prec;
    if (form_prec != 0) {
      int index = 0;
      while (res[index] != '.') index++;
      res[index + prec + 1] = '\0';
    }
  }
  if (s21_strchr("s", param) != NULL) {
    res[form_prec] = '\0';
  }
  res[s21_strlen(res)] = '\0';
}

int convert_str_to_d(char const *str) {
  int result = 0;
  int sign = 1;
  int i = 0;

  for (; str[i] != '\0'; i++) {
    result = result * 10 + (str[i] - '0');
  }
  return result * sign;
}

void convert_d_to_str(long long int num, char *res) {
  int sign_st = 0;
  if (num < 0) {
    sign_st = 1;
    num = -num;
  }
  int i = 0;
  char temp[2048] = "";
  if (num == 0) {
    res[0] = '0';
    res[1] = '\0';
    return;
  }
  while (num > 0) {
    int digit;
    digit = num % 10;
    temp[i] = digit + '0';
    num /= 10;
    i++;
  }
  temp[i + 1] = '\0';
  if (sign_st) res[0] = '-';
  for (int j = 0; j <= i; j++) {
    if (sign_st)
      res[j + 1] = temp[i - j - 1];
    else
      res[j] = temp[i - j - 1];
  }
}

void parse_width(specs_struct *specs, const char *format, int *idx) {
  char str_number[2048] = {0};
  int str_index = 0;
  if (format[*idx] == '*') {
    specs->star_sign_width = true;
    *idx = *idx + 1;
  }
  while (is_digit(format[*idx])) {
    str_index++;
    *idx = *idx + 1;
  }
  s21_strncpy((char *)str_number, format + *idx - str_index, str_index);
  if (str_index != 0) {
    specs->width = convert_str_to_d(str_number);
  }
}

void parse_length(specs_struct *specs, const char *format, int *idx) {
  char *format_specifiers = "hLl";
  char spec = format[*idx];
  if (s21_strchr(format_specifiers, spec) != NULL) {
    switch (format[*idx]) {
      case 'h':
        specs->h = true;
        break;
      case 'L':
        specs->L = true;
        break;
      case 'l':
        specs->l = true;
        break;
    }
    *idx = *idx + 1;
  }
}

void parse_precision(specs_struct *specs, const char *format, int *idx) {
  char str_number[2048] = {0};
  int str_index = 0;
  if (format[*idx] == '.') {
    specs->point = true;
    *idx = *idx + 1;
  }
  if (format[*idx] == '*') {
    specs->star_sign_precision = true;
    *idx = *idx + 1;
  }
  while (is_digit(format[*idx])) {
    str_index++;
    *idx = *idx + 1;
  }
  s21_strncpy((char *)str_number, format + *idx - str_index, str_index);
  if (str_index != 0) {
    specs->precision = convert_str_to_d(str_number);
  }
}

int parse_spec(specs_struct *specs, const char *format, int const *idx) {
  char *format_specifiers = "cdieEfgGosuxXpn%";
  char spec = format[*idx];
  int res = 0;
  if (s21_strchr(format_specifiers, spec) != NULL) {
    switch (spec) {
      case 'c':
        specs->c = true;
        break;
      case 'd':
        specs->d = true;
        break;
      case 'e':
        specs->e = true;
        break;
      case 'E':
        specs->E = true;
        break;
      case 'f':
        specs->f = true;
        break;
      case 'g':
        specs->g = true;
        break;
      case 'G':
        specs->G = true;
        break;
      case 'o':
        specs->o = true;
        break;
      case 's':
        specs->s = true;
        break;
      case 'u':
        specs->u = true;
        break;
      case 'x':
        specs->x = true;
        break;
      case 'X':
        specs->X = true;
        break;
      case 'p':
        specs->p = true;
        break;
      case '%':
        specs->percent = true;
        break;
    }
    res = 1;
  }
  return res;
}

void flags_process(char *res, specs_struct specs) {
  if (specs.hash_sign && !(res[0] == '0' && res[1] == '\0')) {
    char buff[2048] = "";
    int deploy = 0;
    if (specs.p || specs.x || specs.X) {
      buff[0] = '0';
      buff[1] = 'x';
      if (specs.X) buff[1] = 'X';
      deploy = 2;
    }
    if (specs.o && (specs.precision < (int)s21_strlen(res))) {
      buff[0] = '0';
      deploy = 1;
    }
    s21_strncpy(buff + deploy, res, s21_strlen(res));
    s21_strncpy(res, buff, s21_strlen(buff));
    res[s21_strlen(res)] = '\0';
  }
  if (specs.plus || specs.space) {
    char temp[2048] = "";
    bool minus = (res[0] == '-') ? 1 : 0;
    bool d_spec = specs.x || specs.X || specs.u || specs.o;
    s21_strncpy(temp, res, s21_strlen(res));
    if (!minus && specs.plus && !d_spec)
      res[0] = '+';
    else if (!minus && specs.space && !d_spec)
      res[0] = ' ';
    if (minus || d_spec) {
      s21_strncpy(res, temp, s21_strlen(temp));
    } else {
      s21_strncpy(res + 1, temp, s21_strlen(temp));
    }
    res[s21_strlen(res)] = '\0';
  }
  res[s21_strlen(res)] = '\0';
}

void fill_with_width(char *res, specs_struct specs) {
  char temp[2048] = "";
  int len = (int)s21_strlen(res);
  if (specs.width <= len) return;
  if (specs.minus) {
    for (int i = 0; i < specs.width - len; i++) {
      res[i + len] = ' ';
    }
    res[specs.width] = '\0';
  } else {
    for (int i = 0; i < len; i++) {
      temp[i] = res[i];
    }
    for (int i = 0; i < specs.width - len; i++) {
      if (specs.null_sign && !specs.c && !specs.s)
        res[i] = '0';
      else
        res[i] = ' ';
    }
    for (int i = 0; i < len; i++) {
      res[i + (specs.width - len)] = temp[i];
    }
    res[specs.width] = '\0';
  }
  res[s21_strlen(res)] = '\0';
}

void print_d(va_list args, specs_struct format, char *temp, int *flag) {
  long long c = 0;
  if (format.h) {
    c = (short)va_arg(args, int);
  } else if (format.l) {
    c = va_arg(args, long long);
  } else {
    c = va_arg(args, int);
  }
  convert_d_to_str(c, temp);
  precision_process(temp, format, 'd');
  flags_process(temp, format);
  fill_with_width(temp, format);
  if (format.precision == 0 && format.point && c == 0) {
    *flag = 1;
    if (format.width != 0)
      temp[s21_strlen(temp) - 1] = ' ';
    else
      temp[s21_strlen(temp) - 1] = '\0';
  }
}

int get_f_len(long double x) {
  int count = 0;
  if (x == 0 || x == 1) return 1;
  while (x >= 1) {
    count++;
    x /= 10.0L;
  }
  return count;
}

void convert_f_to_str(long double num, char *res, int round_idx,
                      specs_struct specs) {
  int minus = 0;
  long double frac, int_part = 0.0L;
  char temp[2048] = "";
  if (num < 0) {
    num = -num;
    minus = 1;
  }
  frac = modfl(num, &int_part);
  int len_frac = round_idx;
  for (int i = 0; i < len_frac; i++) {
    frac *= 10.0L;
  }
  if ((int)(fmodl(frac * 10.0L, 10.0L)) >= 5) {
    frac = frac + 1.0L;
  }
  if ((get_f_len(frac) > len_frac && len_frac != 0) ||
      (len_frac == 0 && (int)(fmodl(frac * 10.0L, 10.0L)) >= 5)) {
    int_part = int_part + 1.0L;
  }
  int len_int = get_f_len(int_part);
  for (int i = 0; i < len_frac; i++) {
    int digit = (int)(fmodl(frac, 10.0L));
    temp[i] = digit + '0';
    frac /= 10.0L;
  }
  if (round_idx != 0 || specs.hash_sign) {
    temp[len_frac] = '.';
  }
  for (int i = 0; i < len_int; i++) {
    int digit = (int)(fmodl(int_part, 10.0L));
    temp[i + len_frac + 1] = digit + '0';
    int_part /= 10.0L;
  }
  if (minus) res[0] = '-';
  for (int i = 0; i < len_frac + len_int + 1; i++) {
    res[i + minus] = temp[len_frac + len_int - i];
  }
  res[minus + len_frac + len_int + 1] = '\0';
}

void print_f(va_list args, specs_struct specs, char *temp) {
  long double c;
  if (specs.L)
    c = va_arg(args, long double);
  else
    c = va_arg(args, double);

  int round_index = (!specs.point) ? 6 : specs.precision;

  convert_f_to_str(c, temp, round_index, specs);
  precision_process(temp, specs, 'f');
  flags_process(temp, specs);
  fill_with_width(temp, specs);
}

void print_s(va_list args, specs_struct specs, char *temp, int *flag) {
  int len;
  char *c = NULL;
  c = va_arg(args, char *);
  len = (int)s21_strlen(c);
  for (int i = 0; i < len; i++) {
    temp[i] = c[i];
  }
  temp[len] = '\0';
  precision_process(temp, specs, 's');
  fill_with_width(temp, specs);
  if (s21_strlen(temp) == 0) {
    *flag = 1;
  }
}

void convert_oupx_to_str(unsigned long long num, char *res, specs_struct specs,
                         int base) {
  char temp[2048];
  int count = 0;

  if (base == 0) return;
  if (num == 0) {
    res[0] = '0';
    res[1] = '\0';
    return;
  }
  while (num != 0) {
    int remainder = num % base;
    if (remainder < 10) {
      temp[count] = remainder + '0';
    } else {
      if (specs.x || specs.p) temp[count] = remainder - 10 + 'a';
      if (specs.X) temp[count] = remainder - 10 + 'A';
    }
    num /= base;
    count++;
  }
  for (int i = 0; i < count; i++) {
    res[i] = temp[count - i - 1];
  }
  res[count] = '\0';
}

void print_xXp(va_list args, specs_struct specs, char *temp, int *flag) {
  unsigned long long c;
  if (specs.p) {
    c = va_arg(args, unsigned long long);
    specs.hash_sign = true;
  } else if (specs.h) {
    c = (unsigned short)va_arg(args, unsigned int);
  } else if (specs.l) {
    c = va_arg(args, unsigned long long);
  } else {
    c = va_arg(args, unsigned int);
  }

  if (specs.p && c == 0) {
    char buff[] = "(nil)\0";
    s21_strncpy(temp, buff, s21_strlen(buff));
    fill_with_width(temp, specs);
  } else {
    convert_oupx_to_str(c, temp, specs, 16);
    precision_process(temp, specs, 'x');
    flags_process(temp, specs);
    fill_with_width(temp, specs);
    if (specs.precision == 0 && specs.point && c == 0) {
      *flag = 1;
      if (specs.width != 0)
        temp[s21_strlen(temp) - 1] = ' ';
      else
        temp[s21_strlen(temp) - 1] = '\0';
    }
  }
}

void convert_e_to_str(long double num, char *res, int round_index,
                      specs_struct format) {
  bool e_minus = false, sign_minus = false;
  char temp[2048] = "";
  int len, count = 0;
  if (num < 0) {
    sign_minus = true;
    num = -num;
  }
  while (num < 1 && num != 0) {
    e_minus = true;
    num *= 10.0;
    count++;
  }
  while (num > 10) {
    num /= 10.0;
    count++;
  }
  convert_f_to_str(num, temp, round_index, format);
  len = s21_strlen(temp);
  s21_strncpy(res, temp, s21_strlen(temp));
  res[len] = 'e';
  if (format.E || format.G) res[len] = 'E';
  if (e_minus)
    res[len + 1] = '-';
  else
    res[len + 1] = '+';
  if (count < 100) {
    res[len + 2] = int_to_digit(count / 10);
    res[len + 3] = int_to_digit(count % 10);
  }
  res[s21_strlen(res)] = '\0';
  if (sign_minus) {
    for (int i = s21_strlen(res); i > 0; i--) {
      res[i] = res[i - 1];
    }
    res[0] = '-';
  }
}

void convert_g_to_str(long double num, char *res, specs_struct specs) {
  int p, idx, x = 0;
  long double temp_idx;
  char temp_str[2048] = {0};
  int prec_number = specs.precision;
  int is_prec = specs.point;
  if (num == INFINITY) {
    char temp[] = "inf\0";
    s21_strncpy(res, temp, s21_strlen(temp));
    return;
  }
  if (isnan(num)) {
    char temp[] = "nan\0";
    s21_strncpy(res, temp, s21_strlen(temp));
    return;
  }
  if (num == 0) {
    char temp[] = "0\0";
    s21_strncpy(res, temp, s21_strlen(temp));
    return;
  }
  if (is_prec && prec_number != 0)
    p = prec_number;
  else if (is_prec)
    p = 1;
  else
    p = 6;
  temp_idx = num;
  if (temp_idx < 0) {
    temp_idx = -temp_idx;
  }
  while (temp_idx < 1) {
    temp_idx *= 10.0;
    x--;
  }
  while (temp_idx > 10) {
    temp_idx /= 10.0;
    x++;
  }
  if (p > x && x >= -4) {
    p = p - (x + 1);
    convert_f_to_str(num, temp_str, p, specs);
    idx = s21_strlen(temp_str) - 1;
    while (temp_str[idx] == '0' && !specs.hash_sign && p != 0) {
      temp_str[idx] = '\0';
      idx--;
    }
    if (temp_str[idx] == '.' && !specs.hash_sign)
      temp_str[idx] = '\0';
    else
      temp_str[idx + 1] = '\0';
  } else {
    int temp_len;
    p = p - 1;
    convert_e_to_str(num, temp_str, p, specs);
    idx = s21_strlen(temp_str) - 1 - 2 - 2;
    temp_idx = idx;
    temp_len = s21_strlen(temp_str);
    while (temp_str[idx] == '0' && !specs.hash_sign) {
      temp_str[idx] = '\0';
      idx--;
    }
    if (temp_str[idx] == '.' && !specs.hash_sign) {
      temp_str[idx] = '\0';
      idx--;
    }
    for (int i = temp_idx + 1; i < temp_len; i++) {
      temp_str[idx + 1] = temp_str[i];
      idx++;
    }
    temp_str[idx + 1] = '\0';
  }
  s21_strncpy(res, temp_str, s21_strlen(temp_str));
}

void print_e_g(va_list args, specs_struct specs, char *temp) {
  long double c;
  if (specs.L)
    c = va_arg(args, long double);
  else
    c = va_arg(args, double);

  if (specs.g || specs.G)
    convert_g_to_str(c, temp, specs);
  else {
    int round_idx = (!specs.point) ? 6 : specs.precision;
    convert_e_to_str(c, temp, round_idx, specs);
  }
  flags_process(temp, specs);
  fill_with_width(temp, specs);
}

void print_ou(va_list args, specs_struct format, char *temp, int *flag) {
  unsigned long long c;
  int base = 10;
  if (format.o) base = 8;

  if (format.h)
    c = (unsigned short)va_arg(args, unsigned int);
  else if (format.l) {
    c = va_arg(args, unsigned long long);
  } else {
    c = va_arg(args, unsigned int);
  }
  convert_oupx_to_str(c, temp, format, base);
  precision_process(temp, format, 'x');
  flags_process(temp, format);
  fill_with_width(temp, format);
  if (format.precision == 0 && format.point && c == 0) {
    *flag = 1;
    if (format.width != 0)
      temp[s21_strlen(temp) - 1] = ' ';
    else
      temp[s21_strlen(temp) - 1] = '\0';
  }
}

void print_c(va_list args, specs_struct specs, char *temp) {
  char c = va_arg(args, int);
  temp[0] = c;
  temp[1] = '\0';
  fill_with_width(temp, specs);
}

void choose_print_spec(va_list args, specs_struct specs, char *res,
                       int *res_idx) {
  int flag = 0;
  char temp[2048] = "";
  if (specs.star_sign_width) {
    specs.width = va_arg(args, int);
  }
  if (specs.star_sign_precision) {
    specs.precision = va_arg(args, int);
  }
  if (specs.percent) {
    temp[0] = '%';
    temp[1] = '\0';
  }
  if (specs.c) {
    print_c(args, specs, temp);
  } else if (specs.d) {
    print_d(args, specs, temp, &flag);
  } else if (specs.f) {
    print_f(args, specs, temp);
  } else if (specs.s) {
    print_s(args, specs, temp, &flag);
  } else if (specs.x || specs.X || specs.p) {
    print_xXp(args, specs, temp, &flag);
  } else if (specs.g || specs.G || specs.e || specs.E) {
    print_e_g(args, specs, temp);
  } else if (specs.o || specs.u) {
    print_ou(args, specs, temp, &flag);
  }
  for (size_t i = 0; i < s21_strlen(temp); i++) {
    res[*res_idx] = temp[i];
    *res_idx = *res_idx + 1;
  }
}

int parse_format_string(const char *format, va_list args, char *result) {
  int idx = 0;
  char temp[2048] = "";
  char c;
  int res_idx = 0;
  while ((c = format[idx]) != '\0') {
    if (c == '%') {
      specs_struct specs = {0};
      idx++;
      parse_flags(&specs, format, &idx);
      parse_width(&specs, format, &idx);
      parse_precision(&specs, format, &idx);
      parse_length(&specs, format, &idx);
      if (parse_spec(&specs, format, &idx)) {
        choose_print_spec(args, specs, temp, &res_idx);
      }
    } else {
      temp[res_idx] = format[idx];
      res_idx++;
    }
    idx++;
  }
  temp[res_idx] = '\0';
  for (int i = 0; i < res_idx + 1; i++) {
    result[i] = temp[i];
  }
  return res_idx;
}

int s21_sprintf(char *str, const char *string, ...) {
  va_list args;
  va_start(args, string);
  int c = parse_format_string(string, args, str);
  va_end(args);
  return c;
}