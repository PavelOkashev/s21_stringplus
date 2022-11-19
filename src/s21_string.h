#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <stdarg.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned long s21_size_t;
#define s21_NULL ((void *)0)

typedef struct parameters {
    int accuracy;
    int accuracy_true;
    int width;
    char length;
    int plus;
    int minus;
    int space;
    int zero;
    int sharp;
    int error;
    int ldouble;
    int exit_sprintf;
    int index;
}paramlist;

void *s21_memchr(const void *ptr, int c, s21_size_t count);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strcat(char *dest, const char *src);
char *s21_strchr(const char *str, int c);
int s21_strcmp(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);
s21_size_t s21_strlen(const char *str);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
s21_size_t s21_strspn(const char *str1, const char *str2);
void *s21_trim(const char *src, const char *trim_chars);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_to_lower(const char *str);
void *s21_to_upper(const char *str);
char *s21_strtok(char *str, const char *delim);
char *s21_strerror(int errnum);
void s21_itoa(unsigned long long int m, char *str);

int s21_sprintf(char *str, const char *format, ...);
void add_spaces(char *str, paramlist *parameters, int str_len);
void in_att_end(char *str, char c);
int s21_parse(char *str, char *format, va_list vl, paramlist *parameters);
void s21_parse_e(char *str, va_list vl, paramlist *parameters, char format);
void s21_parse_n(va_list vl, paramlist *parameters);
void s21_parse_xo(char *str, va_list vl, paramlist *parameters, char format, int radix);
void s21_parse_p(char *str, va_list vl, paramlist *parameters, char format, int radix);
void s21_parse_g(char *str, va_list vl, paramlist *parameters, char format);
int parse_parameters(char *str, int i, va_list vl, paramlist *parameters);
void s21_parse_f(char *str, va_list vl, paramlist *parameters);
void s21_u_func(char *str, va_list vl, paramlist *parameters);
void s21_s_func(char *str, va_list vl, paramlist *parameters);
void write_d_func(char *str, va_list vl, paramlist *parameters, char *digit);
void s21_d_func(char *str, va_list vl, paramlist *parameters);
void s21_c_func(char *str, va_list vl, paramlist *parameters);
void l_case(char *str, va_list vl, paramlist *parameters);
void percent_func(char *str, paramlist *parameters);
void find_parametrs(char *str, paramlist *parameters, int *i);
int radtoa(char *digit, unsigned long int dig, char format, int radix, int i);
int len_of_int(paramlist *parameters, int dig);
int search_digit(char c);
int search_length_flag(char c);
int search_specif(char c);
void shift_end(char *str, int *count);
void fullfill_struct(paramlist *parameters);
int decimal_numbers(long int dig);
void if_li_less_zero(long int *dig);
void li_decimal_determine(long int *dig,  int *decimal);
void length_true(paramlist *parameters, int i, const char *str);
void L_true(paramlist *parameters, int i, const char *str);
void specif_t_a_i_m_len(int *i, char *str);
void before_dot_num(paramlist *parameters, int *i, char *str);
void accuracy_star_true(va_list vl, paramlist *parameters);
void width_star_true(va_list vl, paramlist *parameters);
int recast(int otricale, paramlist *parameters);
int p_exit(paramlist *parameters);
void wchar_recast(char *destination, const wchar_t *source, int size, paramlist *parameters);
void determine_hl_param(char *str, va_list vl, paramlist *parameters, char *digit, char spec);
void s21_s_func_l_param(char *str, va_list vl, paramlist *parameters);
int true_sing(double *f, int *str_len);

#if defined (__inix__) || defined(__APPLE__) && defined(__MACH__)
#define s21_N_error 106
#define s21_errors {"Undefined error: 0", \
                "Operation not permitted", \
                "No such file or directory", \
                "No such process", \
                "Interrupted system call", \
                "Input/output error", \
                "Device not configured", \
                "Argument list too long", \
                "Exec format error", \
                "Bad file descriptor", \
                "No child processes", \
                "Resource deadlock avoided", \
                "Cannot allocate memory", \
                "Permission denied", \
                "Bad address", \
                "Block device required", \
                "Resource busy", \
                "File exists", \
                "Cross-device link", \
                "Operation not supported by device", \
                "Not a directory", \
                "Is a directory", \
                "Invalid argument", \
                "Too many open files in system", \
                "Too many open files", \
                "Inappropriate ioctl for device", \
                "Text file busy", \
                "File too large", \
                "No space left on device", \
                "Illegal seek", \
                "Read-only file system", \
                "Too many links", \
                "Broken pipe", \
                "Numerical argument out of domain", \
                "Result too large", \
                "Resource temporarily unavailable", \
                "Operation now in progress", \
                "Operation already in progress", \
                "Socket operation on non-socket", \
                "Destination address required", \
                "Message too long", \
                "Protocol wrong type for socket", \
                "Protocol not available", \
                "Protocol not supported", \
                "Socket type not supported", \
                "Operation not supported", \
                "Protocol family not supported", \
                "Address family not supported by protocol family", \
                "Address already in use", \
                "Can't assign requested address", \
                "Network is down", \
                "Network is unreachable", \
                "Network dropped connection on reset", \
                "Software caused connection abort", \
                "Connection reset by peer", \
                "No buffer space available", \
                "Socket is already connected", \
                "Socket is not connected", \
                "Can't send after socket shutdown", \
                "Too many references: can't splice", \
                "Operation timed out", \
                "Connection refused", \
                "Too many levels of symbolic links", \
                "File name too long", \
                "Host is down", \
                "No route to host", \
                "Directory not empty", \
                "Too many processes", \
                "Too many users", \
                "Disc quota exceeded", \
                "Stale NFS file handle", \
                "Too many levels of remote in path", \
                "RPC struct is bad", \
                "RPC version wrong", \
                "RPC prog. not avail", \
                "Program version wrong", \
                "Bad procedure for program", \
                "No locks available", \
                "Function not implemented", \
                "Inappropriate file type or format", \
                "Authentication error", \
                "Need authenticator", \
                "Device power is off", \
                "Device error", \
                "Value too large to be stored in data type", \
                "Bad executable (or shared library)", \
                "Bad CPU type in executable", \
                "Shared library version mismatch", \
                "Malformed Mach-o file", \
                "Operation canceled", \
                "Identifier removed", \
                "No message of desired type", \
                "Illegal byte sequence", \
                "Attribute not found", \
                "Bad message", \
                "EMULTIHOP (Reserved)", \
                "No message available on STREAM", \
                "ENOLINK (Reserved)", \
                "No STREAM resources", \
                "Not a STREAM", \
                "Protocol error", \
                "STREAM ioctl timeout", \
                "Operation not supported on socket", \
                "Policy not found", \
                "State not recoverable", \
                "Previous owner died", \
                "Interface output queue is full"}
#elif defined (__linux__)
#define s21_N_error 133
#define s21_errors {"Success", \
                "Operation not permitted", \
                "No such file or directory", \
                "No such process", \
                "Interrupted system call", \
                "Input/output error", \
                "No such device or address", \
                "Argument list too long", \
                "Exec format error", \
                "Bad file descriptor", \
                "No child processes", \
                "Resource temporarily unavailable", \
                "Cannot allocate memory", \
                "Permission denied", \
                "Bad address", \
                "Block device required", \
                "Device or resource busy", \
                "File exists", \
                "Invalid cross-device link", \
                "No such device", \
                "Not a directory", \
                "Is a directory", \
                "Invalid argument", \
                "Too many open files in system", \
                "Too many open files", \
                "Inappropriate ioctl for device", \
                "Text file busy", \
                "File too large", \
                "No space left on device", \
                "Illegal seek", \
                "Read-only file system", \
                "Too many links", \
                "Broken pipe", \
                "Numerical argument out of domain", \
                "Numerical result out of range", \
                "Resource deadlock avoided", \
                "File name too long", \
                "No locks available", \
                "Function not implemented", \
                "Directory not empty", \
                "Too many levels of symbolic links", \
                "Unknown error 41", \
                "No message of desired type", \
                "Identifier removed", \
                "Channel number out of range", \
                "Level 2 not synchronized", \
                "Level 3 halted", \
                "Level 3 reset", \
                "Link number out of range", \
                "Protocol driver not attached", \
                "No CSI structure available", \
                "Level 2 halted", \
                "Invalid exchange", \
                "Invalid request descriptor", \
                "Exchange full", \
                "No anode", \
                "Invalid request code", \
                "Invalid slot", \
                "Unknown error 58", \
                "Bad font file format", \
                "Device not a stream", \
                "No data available", \
                "Timer expired", \
                "Out of streams resources", \
                "Machine is not on the network", \
                "Package not installed", \
                "Object is remote", \
                "Link has been severed", \
                "Advertise error", \
                "Srmount error", \
                "Communication error on send", \
                "Protocol error", \
                "Multihop attempted", \
                "RFS specific error", \
                "Bad message", \
                "Value too large for defined data type", \
                "Name not unique on network", \
                "File descriptor in bad state", \
                "Remote address changed", \
                "Can not access a needed shared library", \
                "Accessing a corrupted shared library", \
                ".lib section in a.out corrupted", \
                "Attempting to link in too many shared libraries", \
                "Cannot exec a shared library directly", \
                "Invalid or incomplete multibyte or wide character", \
                "Interrupted system call should be restarted", \
                "Streams pipe error", \
                "Too many users", \
                "Socket operation on non-socket", \
                "Destination address required", \
                "Message too long", \
                "Protocol wrong type for socket", \
                "Protocol not available", \
                "Protocol not supported", \
                "Socket type not supported", \
                "Operation not supported", \
                "Protocol family not supported", \
                "Address family not supported by protocol", \
                "Address already in use", \
                "Cannot assign requested address", \
                "Network is down", \
                "Network is unreachable", \
                "Network dropped connection on reset", \
                "Software caused connection abort", \
                "Connection reset by peer", \
                "No buffer space available", \
                "Transport endpoint is already connected", \
                "Transport endpoint is not connected", \
                "Cannot send after transport endpoint shutdown", \
                "Too many references: cannot splice", \
                "Connection timed out", \
                "Connection refused", \
                "Host is down", \
                "No route to host", \
                "Operation already in progress", \
                "Operation now in progress", \
                "Stale file handle", \
                "Structure needs cleaning", \
                "Not a XENIX named type file", \
                "No XENIX semaphores available", \
                "Is a named type file", \
                "Remote I/O error", \
                "Disk quota exceeded", \
                "No medium found", \
                "Wrong medium type", \
                "Operation canceled", \
                "Required key not available", \
                "Key has expired", \
                "Key has been revoked", \
                "Key was rejected by service", \
                "Owner died", \
                "State not recoverable", \
                "Operation not possible due to RF-kill", \
                "Memory page has hardware error"}
#endif
#endif  // SRC_S21_STRING_H_
