#include "./s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
    int result = 0;
    s21_size_t i;
    const unsigned char* string1 = str1;
    const unsigned char* string2 = str2;
    for (i = 0; i < n; i++) {
        if (*(string1 + i) != *(string2 + i)) {
            result = 1;
            break;
        }
    }
    if (result == 1) {
        result = *(string1 + i) - *(string2 + i);
    }
    return result;
}




char* s21_strncat(char * dest, const char * src, s21_size_t n) {
    char * begin = dest;
    while (*dest) {
        dest++;
    }
    for (s21_size_t i = 0; i < n; i++) {
        *dest = *src;
        dest++;
        src++;
    }
    return begin;
}

int s21_strncmp(const char* str1, const char* str2, s21_size_t n) {
    const char* end = str1 + n;
    int result = 0;
    while (result == 0 && str1 != end && (*str1 || *str2)) {
        result = *(str1++) - *(str2++);
    }
    return result;
}

char* s21_strrchr(const char * str, int c) {
    int a;
    char b = (char)c;
    for (a = 0; *str; a++) {
        str++;
    }
    for (; a > 0; a--) {
        if (*str == b) {
            a = 0;
        } else {
            str--;
        }
    }
    return (char*)(*str == b ? str : s21_NULL);
}

void* s21_memset(void* str, int c, s21_size_t n) {
    char *ptr = str;
    while (n-- > 0) {
        *ptr++ = (char)c;
    }
    return str;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
    if (!src) {
        dest = s21_NULL;
    } else {
        s21_size_t size = 0;
        while (*src && n) {
            dest[size] = *src;
            src++;
            size++;
            dest[size] = '\0';
            n--;
        }
    }
    return dest;
}


char *s21_strtok(char *str, const char *delim) {
    static char *new = s21_NULL;
    if (!str) {
        str = new;
        if (str == s21_NULL) {
            return s21_NULL;
        }
    }

    str += s21_strspn(str, delim);
    if (*str == '\0') {
        new = s21_NULL;
        return new;
    }

    new = str + s21_strcspn(str, delim);
    if (new[0] != '\0') {
        new[0] = '\0';
        new++;
    } else {
        new = s21_NULL;
    }
    return str;
}


void* s21_memmove(void *to, const void *src, s21_size_t n) {
    if (to < src) {
          char *s = (char *)src;
          char *d = (char *)to;
          for (s21_size_t i = 0; i < n; i++) {
              *(d + i) = *(s + i);
          }
      } else {
          char *s = (char *)src + n;
          char *d = (char *)to + n;
          for (int i = n - 1; i >= 0; i--) {
              *--d = *--s;
          }
      }
      return to;
}

s21_size_t s21_strlen(const char *string) {
    s21_size_t count = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        count++;
    }
    return count;
}

int s21_strcmp(const char * s1, const char * s2) {
    for ( ; *s1 && *s1 == *s2; ++s1, ++s2 ) {
    }
    return *s1 - *s2;
}

char *s21_strstr(const char *haystack, const char *needle) {
    char *str = (char *)haystack;
    char *ndl = (char *)needle;
    char *result = s21_NULL;
    if (*ndl == '\0' || !(s21_strcmp(ndl, ""))) result = str;
    for (int i = 0; i < (int)s21_strlen(str); i++) {
        if (str[i] == *ndl) {
            char *tmp = &str[i];
            int tmp_result = s21_strncmp(tmp, ndl, s21_strlen(ndl));
            if (tmp_result == 0) {
                result = &str[i];
                break;
            }
        }
    }
    return result;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
    s21_size_t i = 0;
    char* in = (char*) dest;
    const char* sr = (char*) src;
    while (i < n) {
        *in++ = *sr++;
        i++;
    }
    return dest;
}

s21_size_t s21_strcspn(const char *str, const char *sym) {
    unsigned int str_len = s21_strlen(str);
    unsigned int sym_len = s21_strlen(sym);
    int exit = 0;
    unsigned int i;
    for (i = 0; i < str_len; ) {
        if (exit == 1) {
            break;
        } else {
            for (unsigned  int j = 0; j < sym_len; j++) {
                if (str[i] == sym[j]) {
                    exit = 1;
                }
            }
        }
        if (exit == 0) {
            i++;
        }
    }
    return i;
}

s21_size_t s21_strspn(const char *str, const char *sym) {
    unsigned int str_len = s21_strlen(str);
    unsigned int sym_len = s21_strlen(sym);
    int exit = 0;
    unsigned int i = 0;
    unsigned int j;
    while (i < str_len) {
        if (exit == 1) {
            break;
        } else {
            exit = 1;
            j = 0;
            while (j < sym_len) {
                if (str[i] == sym[j]) {
                    exit = 0;
                }
                j++;
            }
        }
        if (exit == 0) {
            i++;
        }
    }
    return i;
}

void *s21_memchr(const void *str, int c, s21_size_t n) {
    s21_size_t i;
    int flag = 0;
    for (i = 0; i < n; i++) {
        if (*((char*)str + i) == c) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        str = s21_NULL;

    } else {
        str = (char*)str + i;
    }
    return (char*)str;
}

char *s21_strcat(char *dest, const char *src) {
    char* begin = dest;
    while (*dest)
        dest++;
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return begin;
}

char *s21_strcpy(char *dest, const char *src) {
    char *dest1 = dest;
    while (*src) {
        *(dest++) = *(src++);
    }
    *dest = '\0';
    return dest1;
}

char *s21_strpbrk(const char *str1, const char *str2) {
    char *result = s21_NULL;
    for (s21_size_t i = 0; str1[i] != '\0'; i++) {
        for (s21_size_t j = 0; str2[j] != '\0'; j++) {
            if (str1[i] == str2[j]) {
                result = (char *)&str1[i];
                break;
            }
        }
        if (result != s21_NULL) {
            break;
        }
    }
    return result;
}

void *s21_to_upper(const char *str) {
    char* point = (char*)s21_NULL;
    if (str) {
        point = (char*)malloc(s21_strlen(str) + 1);
        if (point) {
            s21_strcpy(point, str);
            char *temp = point;
             do {
                if (*temp >= 97 && *temp <= 122) {
                    *temp -= 32;
                }
            } while (*temp++);
        }
    }
    return (void *)point;
}

void *s21_to_lower(const char *str) {
    char* point = (char*)s21_NULL;
    if (str) {
        point = (char*)malloc(s21_strlen(str) + 1);
        if (point) {
            s21_strcpy(point, str);
            char *temp = point;
             do {
                if (*temp >= 65 && *temp <= 90) {
                    *temp += 32;
                }
            } while (*temp++);
        }
    }
    return (void *)point;
}

void *s21_insert(const char *src, const char *str, size_t start_index) {
    char *point = (char*)s21_NULL;
    if (src && str && s21_strlen(src) >= start_index) {
        point = (char*)malloc(s21_strlen(src)+s21_strlen(str) + 1);
        if (point) {
            s21_strncpy(point, src, start_index);
            *(point + start_index) = '\0';
            s21_strcat(point, str);
            s21_strcat(point, src + start_index);
        }
    }
    return (void*)point;
}

void *s21_trim(const char *src, const char *trim_chars) {
    char *src_new = s21_NULL;
    if (src != s21_NULL && trim_chars != s21_NULL) {
        int size = s21_strlen(src) + 1;
        src_new = malloc(size * sizeof(char));
        int i = 0, k = size - 2, flag = 1, l;
        while (src[i] && flag) {
            flag = 0;
            for (int j = 0; trim_chars[j]; j++) {
                if (src[i] == trim_chars[j]) {
                    flag = 1;
                    i++;
                    break;
                }
            }
        }
        flag = 1;
        while (k >=0 && flag) {
            flag = 0;
            for (int j = 0; trim_chars[j]; j++) {
                if (src[k] == trim_chars[j]) {
                    flag = 1;
                    k--;
                    break;
                }
            }
        }
        k = k - i;
        for (l = 0; l <= k; i++, l++)
            src_new[l] = src[i];
        src_new[l] = '\0';
    }
    return src_new;
}


char *s21_strerror(int errnum) {
    char *error = s21_NULL;
    static char result[42];
    char digit[12] = "";
    char *s21_error[] = s21_errors;
    if (errnum <= s21_N_error && errnum >= 0) {
        s21_strcpy(result, s21_error[errnum]);
        error = result;
    } else {
        #if defined(__APPLE__) && defined(__MACH__)
            s21_strcpy(result, "Unknown error: ");
        #elif defined(__linux__)
            s21_strcpy(result, "Unknown error ");
        #endif
        if (errnum < 0) {
            s21_strcat(digit, "-");
            errnum *= -1;
        }
        s21_itoa(errnum, &digit[s21_strlen(digit)]);
        s21_strcat(result, digit);
        error = result;
    }
    return error;
}



char *s21_strchr(const char *str, int c) {
    char *ch = 0;
    int len = s21_strlen(str) + 1;
    for (int i = 0; i < len; i++) {
        if (str[i] == (char)c) {
            ch = (char*)&str[i];
            break;
        }
    }
    return ch;
}



void s21_itoa(unsigned long long int m, char *str) {
    if (m == 0) {
        *str++ = '0';
        *str = '\0';
        return;
    }
    unsigned long long int power = 0, j = 0;
    j = m;
    for (power = 1; j >= 10; j /= 10)
        power = power * 10;
    for (; power > 0; power /= 10) {
        *str++ = '0' + m / power;
        m %= power;
    }
    *str = '\0';
}

static char specif_list[16] = "cdifsuxXgGeEopn%";

int search_length_flag(char c) {
    return (c == 'l' || c == 'h');
}

int search_digit(char c) {
    return c >= '0' && c <= '9';
}

void shift_end(char *str, int *count) {
    while (str[*count]) {
        *count+=1;
    }
}

void in_att_end(char *str, char c) {
    int count = 0;
    shift_end(str, &count);
    str[count] = c;
    str[count + 1] = '\0';
}

int search_specif(char c) {
    int exit = 0;
    if (s21_strchr(specif_list, c) != s21_NULL) {
        exit = 1;
    }
    return exit;
}

void fullfill_struct(paramlist *parameters) {
    parameters->accuracy = 0;
    parameters->accuracy_true = 0;
    parameters->length = 0;
    parameters->width = 0;
    parameters->minus = 0;
    parameters->plus = 0;
    parameters->space = 0;
    parameters->zero = 0;
    parameters->sharp = 0;
    parameters->ldouble = 0;
}

void if_li_less_zero(long int *dig) {
    if (*dig < 0) {
        *dig *= -1;
    }
}

void li_decimal_determine(long int *dig,  int *decimal) {
    while (*dig > 0) {
        *decimal+=1;
        *dig /= 10;
    }
}

int decimal_numbers(long int dig) {
    int decimal = 0;
    decimal = dig == 0 ? 1: 0;
    if_li_less_zero(&dig);
    li_decimal_determine(&dig, &decimal);
    return decimal;
}

void find_parametrs(char *str, paramlist *parameters, int *i) {
    for (*i += 1; s21_strchr("-+ 0#", str[*i]) != s21_NULL ; *i+=1) {
        if (str[*i] == '-') {
            parameters->minus = 1;
        } else if (str[*i] == '+') {
            parameters->plus = 1;
        } else if (str[*i] == ' ') {
            parameters->space = 1;
        } else if (str[*i] == '0') {
            parameters->zero = 1;
        } else if (str[*i] == '#') {
            parameters->sharp = 1;
        }
    }
}

void length_true(paramlist *parameters, int i, const char *str) {
    if (str[i] == 'h') {
        parameters->length = str[i];
    } else if (str[i] == 'l') {
        parameters->length = str[i];
    }
}

void L_true(paramlist *parameters, int i, const char *str) {
    if (str[i] == 'L') {
        parameters->ldouble = 1;
    }
}

void specif_t_a_i_m_len(int *i, char *str) {
    if (!search_specif(str[*i]) && *i < (int)s21_strlen(str)) {
        *i+=1;
    }
}

void before_dot_num(paramlist *parameters, int *i, char *str) {
    int lstr = (int)s21_strlen(str);
    for (; !search_specif(str[*i]) && *i < lstr && !search_length_flag(str[*i])
    && search_digit(str[*i]); *i+=1) {
        parameters->accuracy = parameters->accuracy * 10 + (str[*i] - 48);
    }
}

void accuracy_star_true(va_list vl, paramlist *parameters) {
    parameters->accuracy = va_arg(vl, int);
    parameters->accuracy = parameters->accuracy < 0 ? 0 :  parameters->accuracy;
    parameters->accuracy_true = parameters->accuracy < 0 ? 0 : parameters->accuracy_true;
}

void width_star_true(va_list vl, paramlist *parameters) {
    parameters->width = va_arg(vl, int);
    parameters->width = parameters->width < 0 ? -parameters->width : parameters->width;
    parameters->minus = parameters->width < 0 ? 1 : parameters->minus;
}

int parse_parameters(char *str, int i, va_list vl, paramlist *parameters) {
    if (i + 1 < (int)s21_strlen(str) && !search_specif(str[i + 1])) {
        find_parametrs(str, parameters, &i);
        while (!search_specif(str[i]) && i < (int)s21_strlen(str)) {
            if ((search_digit(str[i]) || str[i] == '*') && !parameters->accuracy_true) {
                if (str[i] == '*') {
                    width_star_true(vl, (paramlist *)parameters);
                } else {
                    while (!search_specif(str[i]) && str[i] && str[i] != '.' && !search_length_flag(str[i])
                    && search_digit(str[i])) {
                        parameters->width = parameters->width * 10 + str[i] - 48;
                        i++;
                    }
                }
            }
            if (str[i] == '.') {
                i++;
                parameters->accuracy_true = 1;
                if (str[i] == '*') {
                    accuracy_star_true(vl, (paramlist *)parameters);
                } else {
                    before_dot_num((paramlist *)parameters, &i, str);
                }
            }
            length_true((paramlist *)parameters, i, str);
            L_true((paramlist *)parameters, i, str);
            specif_t_a_i_m_len(&i, str);
        }
    }
    return i;
}

int len_of_int(paramlist *parameters, int dig) {
    int len = decimal_numbers(dig);
    len = parameters->accuracy > len ? parameters->accuracy : len;
    if (dig < 0) {
        len++;
    }
    if (parameters->plus && dig > 0) {
        parameters->space = 0;
        len++;
    }
    if (parameters->space && dig > 0 && !parameters->plus) {
        len++;
    }
    return len;
}

void terminate_str(char *str, paramlist *parameters) {
    for (int i = 0; i < parameters->index; i++) {
        str[i] = '\0';
    }
}

int s21_sprintf(char *restrict str, const char *restrict format, ...) {
    va_list vl;
    va_start(vl, format);
    paramlist *parameters = (paramlist *)malloc(sizeof(paramlist));
    parameters->index = 0;
    int ret = s21_parse(str, (char *)format, vl, parameters);
    va_end(vl);
    if (ret != -1) {
        if (str != s21_NULL)
            ret = (int)s21_strlen(str);
    } else {
        if (str != s21_NULL)
            terminate_str(str, parameters);
    }
    free(parameters);
    return ret;
}

int recast(int otricale, paramlist *parameters) {
    int tmp = otricale;
    if (!otricale && parameters->plus)
        tmp = !otricale && parameters->plus;
    if (!otricale && parameters->space)
        tmp = !otricale && parameters->space;
    return tmp;
}

int p_exit(paramlist *parameters) {
    return (parameters->error || parameters->exit_sprintf);
}

int s21_parse(char *str, char *format, va_list vl, paramlist *parameters) {
    int flaglen;
    parameters->error = 0;
    parameters->exit_sprintf = 0;
    fullfill_struct(parameters);
    for (int i = 0; i < (int)s21_strlen(format) && !p_exit(parameters); i++) {
        if (i < (int)s21_strlen(format) && format[i] == '%') {
            fullfill_struct(parameters);
            flaglen = parse_parameters(format, i, vl, parameters);
            i = i < flaglen ? flaglen : i + 1;
            if (format[i] == 'd' || format[i] == 'i') s21_d_func(str, vl, parameters);
            if (format[i] == 'c') s21_c_func(str, vl, parameters);
            if (format[i] == 's') s21_s_func(str, vl, parameters);
            if (format[i] == '%') percent_func(str, parameters);
            if (format[i] == 'u') s21_u_func(str, vl, parameters);
            if (format[i] == 'f') s21_parse_f(str, vl, parameters);
            if (format[i] == 'x' || format[i] == 'X') s21_parse_xo(str, vl, parameters, format[i], 16);
            if (format[i] == 'o') s21_parse_xo(str, vl, parameters, format[i], 8);
            if (format[i] == 'p') s21_parse_p(str, vl, parameters, format[i], 16);
            if (format[i] == 'n') s21_parse_n(vl, parameters);
            if (format[i] == 'e' || format[i] == 'E') s21_parse_e(str, vl, parameters, format[i]);
        } else {
            str[parameters->index++] = format[i];
        }
    }
    str[parameters->index++] = '\0';
    int ret = parameters->error;
    return ret;
}

void percent_func(char *str, paramlist *parameters) {
    str[parameters->index++] = '%';
    str[parameters->index] = '\0';
}

void wchar_recast(char *destination, const wchar_t *source, int size, paramlist *parameters) {
    for (int i = 0; i < size && source[i] != '\0'; i++) {
        destination[parameters->index++] = source[i];
    }
    destination[parameters->index] = '\0';
}

void s21_c_func(char *str, va_list vl, paramlist *parameters) {
    int i = 0;
    char c = '\n';
    wchar_t tmp = 12;
    if (!parameters->length)
        c = va_arg(vl, int);
    else
        tmp = va_arg(vl, wchar_t);
    if (parameters->width && !parameters->minus && (!parameters->length || tmp <= 255)) {
        while (i < parameters->width - 1) {
            str[parameters->index++] = ' ';
            i++;
        }
    }
    if (!parameters->length) {
        str[parameters->index++] = c;
    } else {
        wchar_t s[2] = {0};
        if ((int)tmp > 255) {
            tmp = 0;
            parameters->error = 1;
        }
        s[0] = tmp;
        wchar_recast(str, s, 2, parameters);
    }
    if (c == '\0' || tmp == '\0') {
        parameters->exit_sprintf = -1;
    } else if (parameters->width && parameters->minus && (!parameters->length || tmp <= 255)) {
        while (i < parameters->width - 1) {
            str[parameters->index++] = ' ';
            i++;
        }
    }
    str[parameters->index] = '\0';
}

void determine_hl_param(char *str, va_list vl, paramlist *parameters, char *digit, char spec) {
    long int dig, otricale = 0;
    if (spec == 'h')
        dig = (short int)va_arg(vl, int);
    else
        dig = va_arg(vl, long int);
    int len = len_of_int(parameters, dig);
    if (!parameters->minus && !parameters->zero)
        add_spaces(str, parameters, len);
    if (parameters->plus && dig > 0)
        str[parameters->index++] = '+';
    if (dig < 0) {
        str[parameters->index++] = '-';
        dig *= -1;
        otricale = 1;
    }
    s21_itoa(dig, digit);
    if (parameters->zero && parameters->space && (int)s21_strlen(digit) > 0 && !otricale)
        str[parameters->index++] = ' ';
    if (!parameters->minus && parameters->zero)
        add_spaces(str, parameters, len);
    if (parameters->space && (int)s21_strlen(digit) > 0 && !otricale && !parameters->zero)
        str[parameters->index++] = ' ';
    int size = (int)s21_strlen(digit);
    while (size < parameters->accuracy) {
        size++;
        str[parameters->index++] = '0';
    }
    for (s21_size_t i = 0; i < s21_strlen(digit); i++)
        str[parameters->index++] = digit[i];
    if (parameters->minus)
        add_spaces(str, parameters, len);
    str[parameters->index] = '\0';
}

void s21_d_func(char *str, va_list vl, paramlist *parameters) {
    char digit[20] = "";
    if (parameters->length == 'h') {
        determine_hl_param(str, vl, parameters, digit, 'h');
    } else if (parameters->length == 'l') {
        determine_hl_param(str, vl, parameters, digit, 'l');
    } else {
        write_d_func(str, vl, parameters, digit);
    }
}

void write_d_func(char *str, va_list vl, paramlist *parameters, char *digit) {
    int dig = va_arg(vl, int), otricale = 0;
    int len = len_of_int(parameters, dig);
    if (!parameters->minus && !parameters->zero)
        add_spaces(str, parameters, len);
    if (dig < 0 && dig != -2147483648) {
        dig *= -1;
        otricale = 1;
    }
    if (dig == -2147483648) {
        otricale = 1;
        s21_strcat(digit, "2147483648");
    } else {
        s21_itoa(dig, digit);
    }
    if (parameters->space && parameters->zero && (int)s21_strlen(digit) > 0 && !otricale)
        str[parameters->index++] = ' ';
    if (parameters->zero && len < parameters->width && otricale)
        str[parameters->index++] = '-';
    if (parameters->plus && dig >= 0 && parameters->zero && len < parameters->width && !otricale)
        str[parameters->index++] = '+';
    if (!parameters->minus && parameters->zero)
        add_spaces(str, parameters, len);
    if (parameters->space && (int)s21_strlen(digit) > 0 && !otricale && !parameters->zero)
        str[parameters->index++] = ' ';
    int size = (int)s21_strlen(digit);
    if (parameters->accuracy >= size && otricale)
        str[parameters->index++] = '-';
    if (parameters->accuracy >= size && parameters->plus && dig >= 0 && !otricale)
        str[parameters->index++] = '+';
    while (size < parameters->accuracy) {
        size++;
        str[parameters->index++] = '0';
    }
    if (parameters->accuracy < size && !parameters->zero && otricale)
        str[parameters->index++] = '-';
    if (parameters->accuracy < size && !parameters->zero && parameters->plus && dig >= 0 && !otricale)
        str[parameters->index++] = '+';
    if (!parameters->accuracy_true && !parameters->minus && (parameters->zero &&
    parameters->width <= (int)s21_strlen(digit)) &&
    ((int)s21_strlen(digit) >= parameters->accuracy && parameters->plus && !otricale))
        str[parameters->index++] = '+';
    if (!parameters->accuracy_true && !parameters->minus && (parameters->zero &&
    parameters->width <= (int)s21_strlen(digit)) &&
    ((int)s21_strlen(digit) >= parameters->accuracy && otricale))
        str[parameters->index++] = '-';
    for (s21_size_t i = 0; i < s21_strlen(digit); i++)
        str[parameters->index++] = digit[i];
    if (parameters->minus)
        add_spaces(str, parameters, len);
    str[parameters->index] = '\0';
}

void s21_s_func_l_param(char *str, va_list vl, paramlist *parameters) {
    wchar_t *res = va_arg(vl, wchar_t*);
    for (int i = 0; res != s21_NULL && res[i] != '\0'; i++) {
        if (res[i] < 0 || res[i] > 255) {
            parameters->error = -1;
            return;
        }
    }
    int size = 0, tmp_size;
    while (res != s21_NULL && res[size] != '\0')
        size++;
    if (res == s21_NULL)
        size = 6;
    if (parameters->accuracy_true && parameters->accuracy < size)
        size = parameters->accuracy;
    tmp_size = size;
    if (!parameters->minus)
        add_spaces(str, parameters, tmp_size);
    if (res != s21_NULL) {
        wchar_recast(str, res, size, parameters);
    } else {
        char null_s[7] = "";
        s21_strncpy(null_s, "(null)", size + 1);
        for (s21_size_t i = 0; i < s21_strlen(null_s); i++)
            str[parameters->index++] = null_s[i];
    }
    if (parameters->minus)
        add_spaces(str, parameters, tmp_size);
    str[parameters->index] = '\0';
}

void s21_s_func(char *str, va_list vl, paramlist *parameters) {
    if (parameters->length) {
        s21_s_func_l_param(str, vl, parameters);
        return;
    }
    char *new;
    new = va_arg(vl, char *);
    int len;
    if (parameters->accuracy_true && new != s21_NULL) {
        len = parameters->accuracy <= (int)s21_strlen(new) ? parameters->accuracy : (int)s21_strlen(new);
    } else if (new != s21_NULL) {
        len = s21_strlen(new);
    } else {
        len = parameters->accuracy <= 6 ? parameters->accuracy : 6;
    }
    char *result_string = (char *)malloc((len * sizeof(char)) + 1);
    for (int i = 0; new != s21_NULL && i < len; i++)
        result_string[i] = new[i];
    if (new == s21_NULL)
        s21_strncpy(result_string, "(null)", len + 1);
    result_string[len] = '\0';
    if (parameters->minus) {
        for (s21_size_t i = 0; i < s21_strlen(result_string); i++)
            str[parameters->index++] = result_string[i];
        add_spaces(str, parameters, len);
    } else {
        add_spaces(str, parameters, len);
        for (s21_size_t i = 0; i < s21_strlen(result_string); i++)
            str[parameters->index++] = result_string[i];
    }
    free(result_string);
    str[parameters->index] = '\0';
}

void s21_utoa(unsigned long int m, char *str) {
    unsigned long int power = 0, j = 0, i = 0;
    j = m;
    for (power = 1; j >= 10; j /= 10)
        power *= 10;
    for (; power > 0; power /= 10) {
        str[i++] = '0' + m / power;
        m %= power;
    }
    str[i] = '\0';
}

void s21_u_func(char *str, va_list vl, paramlist *parameters) {
    char digit[30] = "";
    unsigned long int dig;
    if (parameters->length == 'h') {
        dig = (unsigned short int)va_arg(vl, int);
    } else if (parameters->length == 'l') {
        dig = va_arg(vl, unsigned long int);
    } else {
        dig = va_arg(vl, unsigned int);
    }
    s21_utoa(dig, digit);
    int diff;
    int size = (int)s21_strlen(digit);
    diff = parameters->accuracy > size ? parameters->accuracy : size;
    if (!parameters->minus)
        add_spaces(str, parameters, diff);
    while (parameters->accuracy > size) {
        str[parameters->index++] = '0';
        size++;
    }
    for (s21_size_t i = 0; i < s21_strlen(digit); i++)
        str[parameters->index++] = digit[i];
    if (parameters->minus)
        add_spaces(str, parameters, diff);
    str[parameters->index] = '\0';
}

int true_sing(double *f, int *str_len) {
    int tmp = 0;
    if (*f < 0) {
        tmp = 1;
        *f *= -1;
        *str_len += 1;
    }
    return tmp;
}

int rounding(char *fl_s, int size, int last_number, paramlist *parameters) {
    int first = 1;
    if (parameters->accuracy_true && size > parameters->accuracy + 1)
        size = parameters->accuracy;
    if (!parameters->accuracy_true && size > 6)
        size = 6;
    while (last_number > 4 && size >= 0 && (int)s21_strlen(fl_s) > parameters->accuracy) {
        if (size < (int)s21_strlen(fl_s) && first && fl_s[size] <= '4') {
            size++;
            break;
        }
        fl_s[size] += 1;
        if (size < (int)s21_strlen(fl_s) &&
        ((parameters->accuracy_true && size <= parameters->accuracy) ||
        (!parameters->accuracy_true && size <= 6)) && fl_s[size] < '5') {
            break;
        } else {
            size--;
            if (size < (int)s21_strlen(fl_s) && fl_s[size + 1] == ':' && size + 1 != 0)
                fl_s[size + 1] = '0';
            else if ((parameters->accuracy_true && size + 1 < parameters->accuracy) ||
            (!parameters->accuracy_true && size + 1 < 6))
                break;
        }
        first = 0;
    }
    return size;
}

unsigned long long int get_num_of_digits(paramlist *parameters, char *fl_s, unsigned long long int integer,
unsigned long long int *in_fl, double fl) {
    double pow = parameters->accuracy > 7 ? parameters->accuracy : 7.0;
    unsigned long int mn = 1, zeros = 0;
    while (pow-- > 0)
        mn *= 1E1;
    *in_fl = round(fl * mn), integer = *in_fl;
    for (int i = 0; i < 6 - parameters->accuracy && parameters->accuracy_true && *in_fl > 0; i++)
        *in_fl /= 10;
    s21_itoa(*in_fl, fl_s);
    while (integer * 10 / mn < 1 && integer != 0) {
        integer *= 10;
        zeros++;
    }
    return zeros;
}

void fill_zeroarr(int zeros, char *zero_arr, char *fl_s) {
    for (int i = 0; i < (int)zeros; i++)
        in_att_end(zero_arr, '0');
    int i = 0;
    while (zero_arr[i])
        i++;
    for (int j = 0; fl_s[j]; j++) {
        if (fl_s[j] == ':')
            zero_arr[i] = '0';
        else
            zero_arr[i] = fl_s[j];
        i++;
    }
    s21_strcat(zero_arr, fl_s);
}

int check_last_num(char *fl_s, paramlist *parameters, int otricale) {
    int first_num = 0;
    if (fl_s[0] > '4' && parameters->accuracy_true && parameters->accuracy == 0 && !otricale) {
        first_num++;
    } else if (fl_s[0] == ':') {
        fl_s[0] = '0';
        first_num++;
    }
    return first_num;
}

int fill_result_arr1(paramlist *parameters, unsigned long long int first_num, char *in_s,
char *result) {
    s21_itoa(first_num, in_s);
    s21_strcat(result, in_s);
    if (!parameters->accuracy_true || (parameters->accuracy == 0 && parameters->sharp) ||
    parameters->accuracy > 0)
        in_att_end(result, '.');
    int len = !parameters->accuracy_true ? 6 : parameters->accuracy;
    return len;
}

void zero_f(char *str, paramlist *parameters) {
    if (!parameters->accuracy_true && parameters->accuracy == 0)
        parameters->accuracy = 6;
    int size_of_spaces = parameters->accuracy + 1;
    if (!(!parameters->sharp && parameters->accuracy_true && parameters->accuracy == 0))
        size_of_spaces++;
    if (parameters->plus && !(parameters->zero && size_of_spaces + 1 < parameters->width))
        size_of_spaces++;
    if (parameters->plus && parameters->zero)
        str[parameters->index++] = '+';
    if ((size_of_spaces < parameters->width || parameters->minus) && parameters->space && !parameters->plus
    && parameters->zero)
        str[parameters->index++] = ' ';
    if (!parameters->minus)
        add_spaces(str, parameters, size_of_spaces);
    if (parameters->plus && !parameters->zero)
        str[parameters->index++] = '+';
    if ((size_of_spaces < parameters->width || parameters->minus) && parameters->space && !parameters->plus
    && !parameters->zero)
        str[parameters->index++] = ' ';
    if (parameters->width == 0 && parameters->space)
        str[parameters->index++] = ' ';
    if (!parameters->zero)
        str[parameters->index++] = '0';
    if (!(parameters->accuracy_true && parameters->accuracy == 0 && !parameters->sharp))
        str[parameters->index++] = '.';
    for (int i = 0; i < parameters->accuracy; i++)
        str[parameters->index++] = '0';
    if (parameters->space)
        size_of_spaces++;
    if (parameters->minus)
        add_spaces(str, parameters, size_of_spaces);
    str[parameters->index] = '\0';
}

int true_singl(long double *f, int *str_len) {
    int otricale = 0;
    if (*f < 0) {
        otricale = 1;
        *f *= -1;
        *str_len += 1;
    }
    return otricale;
}

unsigned long long int get_num_of_digitsl(paramlist *parameters, char *fl_s, unsigned long long int integer,
unsigned long long int *in_fl, long double fl) {
    long double pow = parameters->accuracy > 7 ? parameters->accuracy : 7.0;
    unsigned long long int mn = 1, zeros = 0;
    while (pow-- > 0)
        mn *= 1E1;
    *in_fl = round(fl * mn), integer = *in_fl;
    for (int i = 0; i < 6 - parameters->accuracy && parameters->accuracy_true && *in_fl > 0; i++)
        *in_fl /= 10;
    s21_itoa(*in_fl, fl_s);
    while (integer * 10 / mn < 1 && integer != 0) {
        integer *= 10;
        zeros++;
    }
    return zeros;
}

void lf_case(char *str, va_list vl, paramlist *parameters) {
    long double f = va_arg(vl, long double);
    if (f == 0.0) {
        zero_f(str, parameters);
    } else {
        int str_len = 0, otricale = true_singl(&f, &str_len);
        unsigned long long int integer = (unsigned long long int)f, in_fl = 0, first_num = integer, zeros = 0;
        long double fl = f - integer;
        char in_s[12] = "", fl_s[20] = "", zero_arr[20] = "", result[100] = "";
        zeros = get_num_of_digitsl(parameters, fl_s, integer, &in_fl, fl);
        fill_zeroarr(zeros, zero_arr, fl_s);
        rounding(zero_arr, s21_strlen(zero_arr) - 1, in_fl % 10, parameters);
        first_num += check_last_num(zero_arr, parameters, otricale);
        int len = fill_result_arr1(parameters, first_num, in_s, result);
        for (int size = 1; s21_strlen(zero_arr) == 1 && *zero_arr == '0' && size < len; size++)
            in_att_end(result, '0');
        if (!parameters->accuracy_true || parameters->accuracy != 0)
            s21_strcat(result, zero_arr);
        if (!parameters->accuracy_true)
            parameters->accuracy = 6;
        for (int i = 0; parameters->accuracy > 0 && zeros-- > 0; i++)
            in_att_end(result, zero_arr[i]);
        result[parameters->accuracy + s21_strlen(in_s) + 1] = '\0';
        if (parameters->zero && otricale)
            str[parameters->index++] = '-';
        if (parameters->zero && parameters->plus && !otricale)
            str[parameters->index++] = '+';
        if (parameters->zero && parameters->space && !otricale)
            str[parameters->index++] = ' ';
        if (!parameters->minus)
            add_spaces(str, parameters, s21_strlen(result) + recast(otricale, parameters));
        if (!parameters->zero && otricale)
            str[parameters->index++] = '-';
        if (!parameters->zero && parameters->plus && !otricale)
            str[parameters->index++] = '+';
        if (!parameters->zero && parameters->space && !otricale)
            str[parameters->index++] = ' ';
        if (parameters->minus) {
            for (s21_size_t i = 0; i < s21_strlen(result); i++)
                str[parameters->index++] = result[i];
            add_spaces(str, parameters, s21_strlen(result) + recast(otricale, parameters));
        } else {
            for (s21_size_t i = 0; i < s21_strlen(result); i++)
                str[parameters->index++] = result[i];
        }
    }
    str[parameters->index] = '\0';
}

void s21_parse_f(char *str, va_list vl, paramlist *parameters) {
    if (parameters->ldouble) {
        lf_case(str, vl, parameters);
        return;
    }
    double f = va_arg(vl, double);
    if (f == 0.0) {
        zero_f(str, parameters);
    } else {
        int str_len = 0, otricale = true_sing(&f, &str_len);
        unsigned long long int integer = (unsigned long long int)f, in_fl = 0, first_num = integer, zeros = 0;
        double fl = f - integer;
        char in_s[12] = "", fl_s[20] = "", zero_arr[20] = "", result[100] = "";
        zeros = get_num_of_digits(parameters, fl_s, integer, &in_fl, fl);
        fill_zeroarr(zeros, zero_arr, fl_s);
        rounding(zero_arr, s21_strlen(zero_arr) - 1, in_fl % 10, parameters);
        first_num += check_last_num(zero_arr, parameters, otricale);
        int len = fill_result_arr1(parameters, first_num, in_s, result);
        for (int size = 1; s21_strlen(zero_arr) == 1 && *zero_arr == '0' && size < len; size++)
            in_att_end(result, '0');
        if (!parameters->accuracy_true || parameters->accuracy != 0)
            s21_strcat(result, zero_arr);
        if (!parameters->accuracy_true)
            parameters->accuracy = 6;
        int i = 0;
        for (; parameters->accuracy > 0 && zeros-- > 0; i++) {
            in_att_end(result, zero_arr[i]);
        }
        for (; i < parameters->accuracy; i++)
            in_att_end(result, '0');
        result[parameters->accuracy + s21_strlen(in_s) + 1] = '\0';
        if (parameters->zero && otricale)
            str[parameters->index++] = '-';
        if (parameters->zero && parameters->plus && !otricale)
            str[parameters->index++] = '+';
        if (parameters->zero && parameters->space && !otricale)
            str[parameters->index++] = ' ';
        if (!parameters->minus)
            add_spaces(str, parameters, s21_strlen(result) + recast(otricale, parameters));
        if (!parameters->zero && otricale)
            str[parameters->index++] = '-';
        if (!parameters->zero && parameters->plus && !otricale)
            str[parameters->index++] = '+';
        if (!parameters->zero && parameters->space && !otricale)
            str[parameters->index++] = ' ';
        if (parameters->minus) {
            for (s21_size_t in = 0; in < s21_strlen(result); in++)
                str[parameters->index++] = result[in];
            add_spaces(str, parameters, s21_strlen(result) + recast(otricale, parameters));
        } else {
            for (s21_size_t in = 0; in < s21_strlen(result); in++)
                str[parameters->index++] = result[in];
        }
    }
    str[parameters->index] = '\0';
}

int radtoa(char *digit, unsigned long int dig, char format, int radix, int i) {
    if (dig == 0) {
        digit[i] = '0';
        i += 1;
    }
    while (dig > 0 && radix != 0) {
        if (dig % (unsigned)radix >= 10) {
            if (format == 'x' || format == 'p')
                digit[i] = dig % (unsigned)radix + 87;
            else
                digit[i] = dig % (unsigned)radix + 55;
        } else {
            digit[i] = dig % (unsigned)radix + 48;
        }
        dig /= (unsigned)radix;
        i += 1;
    }
    return i;
}

unsigned long int get_type(paramlist *parameters, va_list vl, char format) {
    unsigned long int digit;
    if (parameters->length == 'h') {
        digit = (unsigned short int)va_arg(vl, int);
    } else if (parameters->length == 'l') {
        digit = va_arg(vl, unsigned long int);
    } else if (format == 'p') {
        digit = (unsigned long int)va_arg(vl, void *);
    } else {
        digit = (long unsigned int)va_arg(vl, unsigned int);
    }
    return digit;
}

int check_parameters(paramlist *parameters, char format, char *str, unsigned long int dig, int *size) {
    int id = 0;
    int diff = parameters->accuracy > *size ? parameters->accuracy : *size;
    if (format != 'o' && parameters->sharp)
        diff += 1;
    if (!parameters->minus && !parameters->zero) {
        for (int i = 0; i < parameters->width - diff - parameters->sharp; i++) {
            str[id++] = ' ';
        }
    }
    int put_x = 0;
    if (!parameters->minus && parameters->zero) {
        for (int i = 0; i < parameters->width - diff - parameters->sharp; i++) {
            if (put_x == 1 && format != 'o')
                str[id++] = format;
            str[id++] = '0';
            put_x++;
        }
    }
    if (parameters->sharp && !parameters->accuracy_true && dig != 0) {
        put_x++;
        str[id++] = '0';
    }
    if (parameters->sharp && parameters->accuracy_true && dig != 0) {
        str[id++] = '0';
        *size += 1;
        put_x++;
    }
    if (put_x == 1 && format != 'o')
        str[id++] = format;
    if ((format == 'x' || format == 'X') && parameters->sharp && dig != 0) {
        *size -= 1;
    }
    str[id] = '\0';
    return diff;
}

void x_equals_0_case(char *str, paramlist *parameters) {
    if (!parameters->minus)
        add_spaces(str, parameters, 1);
    if (!(parameters->accuracy_true && parameters->accuracy == 0)) {
        str[parameters->index++] = '0';
    }
    if (parameters->minus)
        add_spaces(str, parameters, 1);
    str[parameters->index] = '\0';
}

void s21_parse_xo(char *str, va_list vl, paramlist *parameters, char format, int radix) {
    char digit[100] = "";
    char reverse[100] = "";
    unsigned long int dig = get_type(parameters, vl, format);
    if (dig == 0) {
        x_equals_0_case(str, parameters);
        return;
    }
    char buf[300] = "";
    s21_utoa(dig, digit);
    int i = 0, j = 0;
    i = radtoa(digit, dig, format, radix, i);
    int diff, size = i;
    diff = check_parameters(parameters, format, buf, dig, &size);
    int put_x = 0;
    while (parameters->accuracy_true && parameters->accuracy > size) {
        if (!parameters->zero && put_x == 1 && format != 'o' && parameters->sharp && s21_strlen(buf) == 1)
            in_att_end(buf, format);
        in_att_end(buf, '0');
        size++;
        put_x++;
    }
    if (i == 0 && digit[0] == '0')
        reverse[j] = '0';
    while (--i >= 0)
        reverse[j++] = digit[i];
    if (reverse[0] == '0' && parameters->accuracy_true && parameters->accuracy == 0)
        reverse[0] = '\0';
    s21_strcat(buf, reverse);
    if (parameters->minus) {
        for (int in = 0; in < parameters->width - diff - parameters->sharp; in++) {
            if (parameters->zero == 0 || parameters->minus)
                in_att_end(buf, ' ');
            else
                in_att_end(buf, '0');
        }
    }
    for (s21_size_t in = 0; in < s21_strlen(buf); in++)
        str[parameters->index++] = buf[in];
    str[parameters->index] = '\0';
}

void s21_parse_p(char *str, va_list vl, paramlist *parameters, char format, int radix) {
    char digit[35] = "";
    char reverse[35] = "";
    unsigned long int dig = get_type(parameters, vl, format);
    s21_utoa(dig, digit);
    int i = 0, j = 2;
    i = radtoa(digit, dig, format, radix, i);
    s21_strcat(reverse, "0x");
    while (--i >= 0)
        reverse[j++] = digit[i];
    reverse[j] = '\0';
    if (!parameters->minus)
        add_spaces(str, parameters, s21_strlen(reverse));
    for (s21_size_t in = 0; in < s21_strlen(reverse); in++)
            str[parameters->index++] = reverse[in];
    if (parameters->minus)
        add_spaces(str, parameters, s21_strlen(reverse));
}

void s21_parse_n(va_list vl, paramlist *parameters) {
    int *i = va_arg(vl, int *);
    *i = parameters->index;
}

int normalize(double *val) {
    int exponent = 0;
    double value = *val;
    while (value >= 1.0) {
        value /= 10.0;
        ++exponent;
    }
    while (value < 0.1) {
        value *= 10.0;
        --exponent;
    }
    *val = value;
    return exponent;
}

void zero_e(char *str, paramlist *parameters, char format) {
    if (!parameters->accuracy_true)
        parameters->accuracy = 6;
    char result[250] = "";
    in_att_end(result, '0');
    if (!(parameters->accuracy_true && parameters->accuracy == 0 && !parameters->sharp))
        in_att_end(result, '.');
    while (parameters->accuracy-- > 0)
        in_att_end(result, '0');
    in_att_end(result, format);
    s21_strcat(result, "+00");
    if (parameters->plus && parameters->zero)
        str[parameters->index++] = '+';
    if ((parameters->width > (int)s21_strlen(result) || parameters->minus) &&
    !parameters->plus && parameters->zero)
        str[parameters->index++] = ' ';
    if ((parameters->minus || !parameters->width) && !parameters->plus && parameters->space)
        str[parameters->index++] = ' ';
    while (parameters->width > (int)s21_strlen(result) + ((parameters->zero && parameters->space)
    || (parameters->zero && parameters->plus) || (!parameters->zero && parameters->plus)) &&
    !parameters->minus) {
        if (!parameters->zero)
            str[parameters->index++] = ' ';
        else
            str[parameters->index++] = '0';
        parameters->width--;
    }
    if (parameters->plus && !parameters->zero)
        str[parameters->index++] = '+';
    for (s21_size_t i = 0; i < s21_strlen(result); i++)
        str[parameters->index++] = result[i];
    if (parameters->space || parameters->plus)
        parameters->width--;
    while (parameters->width > (int)s21_strlen(result) && parameters->minus) {
        str[parameters->index++] = ' ';
        parameters->width--;
    }
    str[parameters->index] = '\0';
}

void fill_result_arr2(int exponent, char *result, char *in_s, char format) {
    in_att_end(result, format);
    if (exponent < 0) {
        in_att_end(result, '-');
        exponent *= -1;
    } else {
        in_att_end(result, '+');
    }
    if (exponent < 10)
        in_att_end(result, '0');
    s21_itoa(exponent, in_s);
    s21_strcat(result, in_s);
}

int normalizel(long double *val) {
    int exponent = 0;
    long double value = *val;
    while (value >= 1.0) {
        value /= 10.0;
        ++exponent;
    }
    while (value < 0.1) {
        value *= 10.0;
        --exponent;
    }
    *val = value;
    return exponent;
}

void check_zero_arr(char *zero_arr, paramlist *parameters) {
    int size = parameters->accuracy_true ? parameters->accuracy : 6;
    for (int i = 0; i < size; i++) {
        if (!zero_arr[i])
            zero_arr[i] = '0';
    }
}

void le_case(char *str, va_list vl, paramlist *parameters, char format) {
    long double f = va_arg(vl, long double);
    int str_len = 0, otricale = true_singl(&f, &str_len);
    if (f == 0.0) {
        zero_e(str, parameters, format);
    } else {
        char in_s[10] = "", fl_s[20] = "", zero_arr[20] = "", result[100] = "";
        int exponent = normalizel(&f) - 1;
        f *= 1E1;
        unsigned long long int integer = f, in_fl = 0, first_num = integer, zeros = 0;
        long double fl = f - integer;
        zeros = get_num_of_digits(parameters, fl_s, integer, &in_fl, fl);
        fill_zeroarr(zeros, zero_arr, fl_s);
        rounding(zero_arr, s21_strlen(zero_arr) - 1, in_fl % 10, parameters);
        first_num += check_last_num(fl_s, parameters, otricale);
        fill_result_arr1(parameters, first_num, in_s, result);
        if (parameters->accuracy != 0)
            zero_arr[parameters->accuracy] = '\0';
        else if (!parameters->accuracy_true)
            zero_arr[6] = '\0';
        check_zero_arr(zero_arr, parameters);
        if (!parameters->accuracy_true || parameters->accuracy != 0)
            s21_strcat(result, zero_arr);
        if (!parameters->accuracy_true)
            parameters->accuracy = 6;
        fill_result_arr2(exponent, result, in_s, format);
        if (otricale && parameters->zero)
            str[parameters->index++] = '-';
        if (parameters->zero && parameters->plus && !otricale)
            str[parameters->index++] = '+';
        if (parameters->zero && parameters->space && !otricale)
            str[parameters->index++] = ' ';
        if (!parameters->minus)
            add_spaces(str, parameters, s21_strlen(result) + recast(otricale, parameters));
        if (otricale && !parameters->zero)
            str[parameters->index++] = '-';
        if (!parameters->zero && parameters->plus && !otricale)
            str[parameters->index++] = '+';
        if (!parameters->zero && parameters->space && !otricale)
            str[parameters->index++] = ' ';
        for (s21_size_t i = 0; i < s21_strlen(result); i++)
            str[parameters->index++] = result[i];
        if (parameters->minus)
            add_spaces(str, parameters, s21_strlen(result) + recast(otricale, parameters));
    }
    str[parameters->index] = '\0';
}

void s21_parse_e(char *str, va_list vl, paramlist *parameters, char format) {
    if (parameters->ldouble) {
        le_case(str, vl, parameters, format);
        return;
    }
    double f = va_arg(vl, double);
    int str_len = 0, otricale = true_sing(&f, &str_len);
    if (f == 0.0) {
        zero_e(str, parameters, format);
    } else {
        char in_s[10] = "", fl_s[20] = "", zero_arr[20] = "", result[100] = "";
        int exponent = normalize(&f) - 1;
        f *= 1E1;
        unsigned long long int integer = (int)f, in_fl = 0, first_num = integer, zeros = 0;
        double fl = f - integer;
        zeros = get_num_of_digits(parameters, fl_s, integer, &in_fl, fl);
        fill_zeroarr(zeros, zero_arr, fl_s);
        rounding(zero_arr, s21_strlen(zero_arr) - 1, in_fl % 10, parameters);
        first_num += check_last_num(fl_s, parameters, otricale);
        fill_result_arr1(parameters, first_num, in_s, result);
        if (parameters->accuracy != 0)
            zero_arr[parameters->accuracy] = '\0';
        else if (!parameters->accuracy_true)
            zero_arr[6] = '\0';
        check_zero_arr(zero_arr, parameters);
        if (!parameters->accuracy_true || parameters->accuracy != 0)
            s21_strcat(result, zero_arr);
        if (!parameters->accuracy_true)
            parameters->accuracy = 6;
        fill_result_arr2(exponent, result, in_s, format);
        if (otricale && parameters->zero)
            str[parameters->index++] = '-';
        if (parameters->zero && parameters->plus && !otricale)
            str[parameters->index++] = '+';
        if (parameters->zero && parameters->space && !otricale)
            str[parameters->index++] = ' ';
        if (!parameters->minus)
            add_spaces(str, parameters, s21_strlen(result) + recast(otricale, parameters));
        if (otricale && !parameters->zero)
            str[parameters->index++] = '-';
        if (!parameters->zero && parameters->plus && !otricale)
            str[parameters->index++] = '+';
        if (!parameters->zero && parameters->space && !otricale)
            str[parameters->index++] = ' ';
        for (s21_size_t i = 0; i < s21_strlen(result); i++)
            str[parameters->index++] = result[i];
        if (parameters->minus)
            add_spaces(str, parameters, s21_strlen(result) + recast(otricale, parameters));
    }
    str[parameters->index] = '\0';
}

void add_spaces(char *str, paramlist *parameters, int str_len) {
    for (int i = 0; i < parameters->width - str_len; i++) {
        if (parameters->zero == 0 || parameters->minus)
            str[parameters->index++] = ' ';
        else
            str[parameters->index++] = '0';
    }
}
