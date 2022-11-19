#include <check.h>
#include <stdio.h>
#include <wchar.h>
#include <string.h>

#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...);

#define SOURCE_50 "_THIS is a SOURCE string. Length = (49 + 0) = 50_"
#define SOURCE_50L L"_THIS is a SOURCE string. Length = (49 + 0) = 50_"

#define SRC_NULL "_THIS is a'\0' SOURCE. Length'\0' = (51 + 0) = 51_"
#define DEST_LARGER_55 "------------------------------------------------------"
#define DEST_SMALLER_6 "-----"
#define BRK_CHAR_3 ".=+"
#define CHAR_IN 'i'
#define CHAR_OUT '*'
#define LENGTH0 50
#define LENGTH 49
#define OVERLENGTH 111
#define SPRTR \
    "======================================================================="
#define N_CALL 10



static char test_data_0[] = SOURCE_50;
static void *test_data_1 = (void *)test_data_0;
START_TEST(memchr_legal_range) {
    ck_assert_ptr_eq(s21_memchr(test_data_1, CHAR_IN, LENGTH0),
                     memchr(test_data_1, CHAR_IN, LENGTH0));
}
END_TEST

START_TEST(memchr_empty_string) {
    static char empty_string[] = "";
    test_data_1 = (void *)empty_string;
    ck_assert_ptr_eq(s21_memchr(test_data_1, CHAR_OUT, 1),
                     memchr(test_data_1, CHAR_OUT, 1));
    test_data_1 = (void *)test_data_0;
}
END_TEST

START_TEST(memchr_non_exist) {
    ck_assert_ptr_eq(s21_memchr(test_data_1, CHAR_OUT, LENGTH0),
                     memchr(test_data_1, CHAR_OUT, LENGTH0));
}
END_TEST

START_TEST(memchr_overlength) {
    ck_assert_ptr_eq(s21_memchr(test_data_1, CHAR_IN, OVERLENGTH),
                     memchr(test_data_1, CHAR_IN, OVERLENGTH));
}
END_TEST

START_TEST(memchr_after_null) {
    ck_assert_ptr_eq(s21_memchr(test_data_1, '=', OVERLENGTH),
                     memchr(test_data_1, '=', OVERLENGTH));
}
END_TEST

START_TEST(memchr_null_char) {
    ck_assert_ptr_eq(s21_memchr(test_data_1, '\0', LENGTH0),
                     memchr(test_data_1, '\0', LENGTH0));
}
END_TEST

START_TEST(memchr_null_bytes) {
    ck_assert_ptr_eq(s21_memchr(test_data_1, CHAR_IN, 0),
                     memchr(test_data_1, CHAR_IN, 0));
}
END_TEST

static char str1[] = SOURCE_50;
static char str2_equal[] = SOURCE_50;
static char str2_not_qual[] = DEST_LARGER_55;


START_TEST(memcmp_correct_data) {
    const char arr_1[256] = "qwertyuiop[]asdfghjkl;zxcvbnm<>?";
    const char arr_2[256] = "?><mnbvcxz;lkjhgfdsa][poiuytrewq";
    const char arr_3[24] = "qwertyuiop[]assa][poiuy";
    const char arr_4[24] = "?><mnbvcxz;lkkl;zxxcxcx";
    ck_assert_int_eq(memcmp(arr_1, arr_2, sizeof(arr_1)),
    s21_memcmp(arr_1, arr_2, sizeof(arr_1)));
    ck_assert_int_eq(memcmp(arr_2, arr_1, sizeof(arr_1)),
    s21_memcmp(arr_2, arr_1, sizeof(arr_1)));
    ck_assert_int_eq(memcmp(arr_1, arr_3, sizeof(arr_3)),
    s21_memcmp(arr_1, arr_3, sizeof(arr_3)));
    ck_assert_int_eq(memcmp(arr_2, arr_4, sizeof(arr_4)),
    s21_memcmp(arr_2, arr_4, sizeof(arr_4)));
}
END_TEST

START_TEST(memcmp_n_incorrect) {
    ck_assert(s21_memcmp(str1, str2_not_qual, LENGTH + 3) ==
              memcmp(str1, str2_not_qual, LENGTH + 3));
}
END_TEST

START_TEST(memcmp_negative_values) {
    char str[] = "555";
    str[1] = -1;

    ck_assert(s21_memcmp(str, str2_equal, 3) == memcmp(str, str2_equal, 3));
    ck_assert(s21_memcmp(str1, str, 3) == memcmp(str1, str, 3));
}
END_TEST

START_TEST(memcmp_multiple_nulls) {
    ck_assert(s21_memcmp(SRC_NULL, str2_equal, LENGTH) ==
              memcmp(SRC_NULL, str2_equal, LENGTH));
    ck_assert(s21_memcmp(SRC_NULL, SRC_NULL, LENGTH) ==
              memcmp(SRC_NULL, SRC_NULL, LENGTH));
}
END_TEST

static char d[] = DEST_LARGER_55;

START_TEST(memcpy_correct_data) {
    ck_assert_str_eq(s21_memcpy(d, SOURCE_50, 50), memcpy(d, SOURCE_50, 50));
    ck_assert_str_eq(s21_memcpy(d, DEST_LARGER_55, 55),
                     memcpy(d, DEST_LARGER_55, 55));
}
END_TEST

START_TEST(memcpy_without_null) {
    ck_assert_str_eq(s21_memcpy(d, SOURCE_50, LENGTH),
                     memcpy(d, SOURCE_50, LENGTH));
}
END_TEST

START_TEST(memcpy_null_byte) {
    ck_assert_str_eq(s21_memcpy(d, SOURCE_50, 0), memcpy(d, SOURCE_50, 0));
}
END_TEST

START_TEST(memcpy_empty2empty) {
    char d0[] = "";
    ck_assert_str_eq(s21_memcpy(d0, "", 0), memcpy(d0, "", 0));
}
END_TEST

static char src[] = SOURCE_50;
static char dst[] = DEST_LARGER_55;
static void *src_void = (void *)src;
static void *dst_void = (void *)dst;
static s21_size_t n = LENGTH0;

START_TEST(memmove_correct_data) {
    ck_assert_str_eq(s21_memmove(dst_void, src_void, n),
                     memmove(dst_void, src_void, n));
}
END_TEST

START_TEST(memmove_dst_smaller) {
    static char dst_smaller[] = DEST_SMALLER_6;
    dst_void = (void *)dst_smaller;
    ck_assert_str_eq(s21_memmove(dst_void, src_void, n),
                     memmove(dst_void, src_void, n));
    dst_void = dst;
}
END_TEST

START_TEST(memmove_multiple_nulls) {
    static char src_null[] = SRC_NULL;
    src_void = (void *)src_null;
    ck_assert_str_eq(s21_memmove(dst_void, src_void, n),
                     memmove(dst_void, src_void, n));
    src_void = (void *)src;
}
END_TEST

START_TEST(memmove_null_n) {
    n = 0;
    ck_assert_str_eq(s21_memmove(dst_void, src_void, n),
                     memmove(dst_void, src_void, n));
    n = LENGTH0;
}
END_TEST

static char memset_d[] = DEST_LARGER_55;

START_TEST(memset_correct_data) {
    ck_assert_str_eq(s21_memset(memset_d, 'x', 11),
                     s21_memset(memset_d, 'x', 11));
}
END_TEST

START_TEST(memset_c_negative) {
    ck_assert_str_eq(s21_memset(memset_d, -11, 11),
                     s21_memset(memset_d, -11, 11));
}
END_TEST

START_TEST(memset_null_n) {
    ck_assert_str_eq(s21_memset(memset_d, 'x', 0), s21_memset(memset_d, 'x', 0));
}
END_TEST

START_TEST(memset_null2null) {
    memset_d[0] = '\0';
    ck_assert_str_eq(s21_memset(memset_d, 'x', 0), s21_memset(memset_d, 'x', 0));
}
END_TEST

static char strcat_d[2222] = DEST_LARGER_55;

START_TEST(strcat_correct_data) {
    ck_assert_str_eq(s21_strcat(strcat_d, SOURCE_50),
                     strcat(strcat_d, SOURCE_50));
}
END_TEST

START_TEST(strcat_empty_add) {
    ck_assert_str_eq(s21_strcat(strcat_d, ""), strcat(strcat_d, ""));
}
END_TEST

static char strncat_d[] = SRC_NULL;
static char strncat_s[] = DEST_SMALLER_6;

START_TEST(strncat_correct_data) {
    (s21_strncat(strncat_d, strncat_s, 6), strncat(strncat_d, strncat_s, 6));
}
END_TEST

START_TEST(strncat_empty_src) {
    ck_assert_str_eq(s21_strncat(strncat_d, "", 11), strncat(strncat_d, "", 11));
}
END_TEST

START_TEST(strncat_src_bigger_n) {
    ck_assert_str_eq(s21_strncat(strncat_d, strncat_s, 3),
                     strncat(strncat_d, strncat_s, 3));
}
END_TEST

START_TEST(strncat_n_null) {
    ck_assert_str_eq(s21_strncat(strncat_d, strncat_s, 0),
                     s21_strncat(strncat_d, strncat_s, 0));
}
END_TEST

START_TEST(strncat_empty_strings) {
    char d1[] = "";
    char s1[] = "";
    ck_assert_str_eq(s21_strncat(d1, s1, 11), s21_strncat(d1, s1, 11));
    ck_assert_str_eq(s21_strncat(d1, s1, 0), s21_strncat(d1, s1, 0));
}
END_TEST

START_TEST(strncat_n_bigger_src) {
    ck_assert_str_eq(s21_strncat(strncat_d, strncat_s, 11),
                     s21_strncat(strncat_d, strncat_s, 11));
}
END_TEST

static char s1[] = SOURCE_50;
static char s1_equal[] = SOURCE_50;
static char empty_s1[] = "";
static char empty_s2[] = "";

START_TEST(strcmp_empty_strings) {
    ck_assert(s21_strcmp(empty_s1, empty_s2) == strcmp(empty_s1, empty_s2));
    ck_assert(s21_strcmp(empty_s1, s1) == strcmp(empty_s1, s1));
    ck_assert(s21_strcmp(s1, empty_s1) == strcmp(s1, empty_s1));
}
END_TEST

START_TEST(strcmp_correct_data) {
    ck_assert(s21_strcmp(s1, s1_equal) == strcmp(s1, s1_equal));
    ck_assert(s21_strcmp(s1, "-----") == strcmp(s1, "-----"));
}
END_TEST

static char strncmp_s1[] = SOURCE_50;
static char strncmp_s1_equal[] = SOURCE_50;
static char strncmp_s2[] = DEST_LARGER_55;
static char strncmp_empty_s1[] = "";
static char strncmp_empty_s2[] = "";

START_TEST(strncmp_empty_strings) {
    ck_assert(s21_strncmp(strncmp_empty_s1, strncmp_empty_s2, 0) ==
              strncmp(strncmp_empty_s1, strncmp_empty_s2, 0));
    ck_assert(s21_strncmp(strncmp_empty_s1, strncmp_s1, 0) ==
              strncmp(strncmp_empty_s1, strncmp_s1, 0));
    ck_assert(s21_strncmp(strncmp_s1, strncmp_empty_s1, 0) ==
              strncmp(strncmp_s1, strncmp_empty_s1, 0));
}
END_TEST

START_TEST(strncmp_correct_data) {
    ck_assert(s21_strncmp(strncmp_s1, strncmp_s1_equal, 11) ==
              strncmp(strncmp_s1, strncmp_s1_equal, 11));
    ck_assert(s21_strncmp(strncmp_s1, strncmp_s2, 11) ==
              strncmp(strncmp_s1, strncmp_s2, 11));
}
END_TEST

START_TEST(strncmp_string_smaller_n) {
    ck_assert(s21_strncmp(strncmp_s1, strncmp_s2, 51) ==
              strncmp(strncmp_s1, strncmp_s2, 51));
}
END_TEST

static char strcpy_d[] = DEST_LARGER_55;
static char strcpy_s[] = SOURCE_50;
static char strcpy_s_equal[] = SOURCE_50;
static char dss[] = DEST_SMALLER_6;


START_TEST(strcpy_correct_data) {
    ck_assert_str_eq(s21_strcpy(strcpy_d, strcpy_s), strcpy(strcpy_d, strcpy_s));
}
END_TEST

START_TEST(strcpy_dest_smaller_src) {
    ck_assert_str_eq(s21_strcpy(dss, strcpy_s), s21_strcpy(dss, strcpy_s));
}
END_TEST

START_TEST(strcpy_overlap) {
    ck_assert_str_eq(s21_strcpy(strcpy_s, (strcpy_s + 33)),
                     strcpy(strcpy_s_equal, (strcpy_s_equal + 33)));
}
END_TEST

static char strncpy_d[] = DEST_LARGER_55;
static char strncpy_d_equal[] = DEST_LARGER_55;

START_TEST(strncpy_correct_data) {
    s21_strncpy(strncpy_d, SOURCE_50, 55);
    strncpy(strncpy_d_equal, SOURCE_50, 55);
    ck_assert(strncpy_d[54] == strncpy_d_equal[54]);

    ck_assert_str_eq(s21_strncpy(strncpy_d, SOURCE_50, 50),
                     strncpy(strncpy_d, SOURCE_50, 50));
}
END_TEST

START_TEST(strncpy_empty_string) {
    ck_assert_str_eq(s21_strncpy(strncpy_d, "", 1), strncpy(strncpy_d, "", 1));
}
END_TEST

START_TEST(strncpy_null_bytes) {
    ck_assert_str_eq(s21_strncpy(strncpy_d, "", 0), strncpy(strncpy_d, "", 0));
}
END_TEST

static char strcspn_str1[] = SOURCE_50;
static char strcspn_str2[] = DEST_SMALLER_6;
static char strcspn_str21[] = "= (49 + 0)";


START_TEST(strcspn_correct_data) {
    ck_assert(s21_strcspn(strcspn_str1, strcspn_str21) ==
              strcspn(strcspn_str1, strcspn_str21));
    ck_assert(s21_strcspn(strcspn_str1, strcspn_str2) ==
              strcspn(strcspn_str1, strcspn_str2));
}
END_TEST

START_TEST(strcspn_empty_strings) {
    ck_assert(s21_strcspn("", strcspn_str21) == strcspn("", strcspn_str21));
    ck_assert(s21_strcspn(strcspn_str1, "") == strcspn(strcspn_str1, ""));
}
END_TEST

START_TEST(strcspn_multiple_nulls) {
    char s1[52] = "_THIS is a'\0' SOURCE. Length'\0' = (51 + 0) = 51_";
    char s2[52] = "_THIS is a'\0' SOURCE. Length'\0' = (51 + 0) = 51_";
    ck_assert(s21_strcspn(s1, strcspn_str21) == strcspn(s1, strcspn_str21));
    ck_assert(s21_strcspn(str1, s2) == strcspn(str1, s2));
}
END_TEST

START_TEST(strcspn_infinite_string1) {
    char *x;
    x = (char *)malloc(LENGTH);
    strncpy(x, strcspn_str1, LENGTH);
    ck_assert(s21_strcspn(x, strcspn_str2) == strcspn(x, strcspn_str2));
    free(x);
}
END_TEST

START_TEST(strcspn_infinite_string2) {
    char *x;
    x = (char *)malloc(LENGTH);
    strncpy(x, strcspn_str1, LENGTH);
    ck_assert(s21_strcspn(strcspn_str1, x) == strcspn(strcspn_str1, x));
    free(x);
}
END_TEST

START_TEST(strcspn_infinite_strings) {
    char *x;
    char *y;
    x = (char *)malloc(LENGTH);
    strncpy(x, strcspn_str1, LENGTH);
    y = (char *)malloc(LENGTH);
    strncpy(y, strcspn_str1, LENGTH);
    ck_assert(s21_strcspn(x, y) == strcspn(x, y));
    free(x);
    free(y);
}
END_TEST

START_TEST(strerror_all) {
    ck_assert_str_eq(s21_strerror(0), strerror(0));
    ck_assert_str_eq(s21_strerror(111), strerror(111));
}
END_TEST

START_TEST(strlen_correct_data) {
    ck_assert(s21_strlen(SOURCE_50) == strlen(SOURCE_50));
}
END_TEST

static char strpbrk_str1[] = SOURCE_50;
static char strpbrk_str2[] = BRK_CHAR_3;
static char strpbrk_str3[] = DEST_SMALLER_6;
static char strpbrk_empty[] = "";

START_TEST(strpbrk_correct_data) {
    ck_assert(s21_strpbrk(strpbrk_str1, strpbrk_str2) ==
              strpbrk(strpbrk_str1, strpbrk_str2));
    ck_assert(s21_strpbrk(strpbrk_str1, strpbrk_str3) ==
              strpbrk(strpbrk_str1, strpbrk_str3));
}
END_TEST

START_TEST(strpbrk_empty_strings) {
    ck_assert(s21_strpbrk(strpbrk_str1, strpbrk_empty) ==
              strpbrk(strpbrk_str1, strpbrk_empty));
    ck_assert(s21_strpbrk(strpbrk_empty, strpbrk_str3) ==
              strpbrk(strpbrk_empty, strpbrk_str3));
}
END_TEST

static char strrchr_s[222] = SOURCE_50;

START_TEST(strrchr_correct_data) {
    ck_assert(s21_strrchr(strrchr_s, CHAR_IN) == strrchr(strrchr_s, CHAR_IN));
    ck_assert(s21_strrchr(strrchr_s, CHAR_OUT) == strrchr(strrchr_s, CHAR_OUT));
}
END_TEST

START_TEST(strrchr_null_search) {
    ck_assert(s21_strrchr(strrchr_s, '\0') == strrchr(strrchr_s, '\0'));
}
END_TEST

START_TEST(strrchr_empty_string) {
    char strrchr_s1[] = "";
    ck_assert(s21_strrchr(strrchr_s1, CHAR_IN) == strrchr(strrchr_s1, CHAR_IN));
    ck_assert(s21_strrchr(strrchr_s, '\0') == strrchr(strrchr_s, '\0'));
}
END_TEST

char strspn_str1[] = SOURCE_50;
char strspn_str2[] = SRC_NULL;
char strspn_str3[] = DEST_SMALLER_6;

START_TEST(strspn_correct_data) {
    ck_assert(s21_strspn(strspn_str1, strspn_str1) ==
              strspn(strspn_str1, strspn_str1));
    ck_assert(s21_strspn(strspn_str1, strspn_str2) ==
              strspn(strspn_str1, strspn_str2));
    ck_assert(s21_strspn(strspn_str2, strspn_str1) ==
              strspn(strspn_str2, strspn_str1));
    ck_assert(s21_strspn(strspn_str1, strspn_str3) ==
              strspn(strspn_str1, strspn_str3));
}
END_TEST

START_TEST(strspn_s1_empty_string) {
    ck_assert(s21_strspn("", strspn_str1) == strspn("", strspn_str1));
}
END_TEST

START_TEST(strspn_s2_empty_string) {
    ck_assert(s21_strspn(strspn_str1, "") == strspn(strspn_str1, ""));
}
END_TEST

START_TEST(strspn_infinite_string1) {
    char *x;
    x = (char *)malloc(LENGTH);
    strncpy(x, strspn_str1, LENGTH);
    ck_assert(s21_strspn(x, strspn_str1) == strspn(x, strspn_str1));
    free(x);
}
END_TEST

START_TEST(strspn_infinite_string2) {
    char *x;
    x = (char *)malloc(LENGTH);
    strncpy(x, strspn_str1, LENGTH);
    ck_assert(s21_strspn(strspn_str1, x) == strspn(strspn_str1, x));
    free(x);
}
END_TEST

START_TEST(strspn_infinite_strings) {
    char *x;
    char *y;
    x = (char *)malloc(LENGTH);
    strncpy(x, strspn_str1, LENGTH);
    y = (char *)malloc(LENGTH);
    strncpy(y, strspn_str1, LENGTH);
    ck_assert(s21_strspn(x, y) == strspn(x, y));
    free(x);
    free(y);
}
END_TEST
/*strspn. END TESTS*/

/*strstr. START TESTS*/
static char haystack[] = SOURCE_50;
static char needle_exist[] = "string";
static char needle_nexist[] = "mole";

START_TEST(strstr_correct_data) {
    ck_assert(s21_strstr(haystack, needle_exist) ==
              strstr(haystack, needle_exist));
    ck_assert(s21_strstr(haystack, needle_nexist) ==
              strstr(haystack, needle_nexist));
}
END_TEST

START_TEST(strstr_empty_strings) {
    char empty_needle[] = "";
    char empty_haystack[] = "";
    ck_assert(s21_strstr(haystack, empty_needle) ==
              strstr(haystack, empty_needle));
    ck_assert(s21_strstr(empty_haystack, needle_exist) ==
              strstr(empty_haystack, needle_exist));
    ck_assert(s21_strstr(empty_haystack, empty_needle) ==
              strstr(empty_haystack, empty_needle));
}
END_TEST

static char delimiters[] = "_ .";

START_TEST(strtok_correct_data) {
    char string[] = SOURCE_50;
    char ystring[] = SOURCE_50;
    int i;
    i = 0;

    ck_assert_str_eq(s21_strtok(string, delimiters), strtok(ystring, delimiters));
    while (i < N_CALL) {
        ck_assert_str_eq(s21_strtok(s21_NULL, delimiters),
                         strtok(s21_NULL, delimiters));
        i++;
    }
}
END_TEST

START_TEST(strtok_multiple_delims) {
    char string[] = "__THIS  is  a  SOURCE string..... Length = (49 + 0) =  50__";
    char ystring[] =
        "__THIS  is  a  SOURCE string..... Length = (49 + 0) =  50__";
    int i;
    i = 0;

    ck_assert_str_eq(s21_strtok(string, delimiters), strtok(ystring, delimiters));
    while (i < N_CALL) {
        ck_assert_str_eq(s21_strtok(s21_NULL, delimiters),
                         strtok(s21_NULL, delimiters));
        i++;
    }
}
END_TEST

START_TEST(strtok_repeated_delims) {
    char string[] = SOURCE_50;
    char ystring[] = SOURCE_50;
    char delims[] = " _. _. _.";
    int i;
    i = 0;

    ck_assert_str_eq(s21_strtok(string, delims), strtok(ystring, delims));
    while (i < N_CALL) {
        ck_assert_str_eq(s21_strtok(s21_NULL, delims), strtok(s21_NULL, delims));
        i++;
    }
}
END_TEST

START_TEST(s21_sprintf_test1) {
    char string1[50] = "";
    char string2[50] = "";
    void *p = (void *)0x3456;
    int n1, n2;
    int r1 = sprintf(string1, "%e%f%u%x%X%n[%p]%%\n", 25.2587321, 4325.23434,
                     12345u, 8342, 1235, &n1, p);
    int r2 = s21_sprintf(string2, "%e%f%u%x%X%n[%p]%%\n", 25.2587321, 4325.23434,
                         12345u, 8342, 1235, &n2, p);
    ck_assert_str_eq(string1, string2);
    ck_assert_int_eq(n1, n2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test2) {
    char string1[100] = "";
    char string2[100] = "";
    int r1 = sprintf(string1, "%+-25.3d%25.15o[%#10.f][%015d]\n", 252, 243, 256.34, 15);
    int r2 = s21_sprintf(string2, "%+-25.3d%25.15o[%#10.f][%015d]\n", 252, 243, 256.34, 15);
    ck_assert_str_eq(string1, string2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test3) {
    char string1[75] = "";
    char string2[75] = "";
    int r1 = sprintf(string1, "[%#-10x]%#15.1o%25.10s", 1234, 4567, "HELLOMYDEARFRIEND");
    int r2 = s21_sprintf(string2, "[%#-10x]%#15.1o%25.10s", 1234, 4567, "HELLOMYDEARFRIEND");
    ck_assert_str_eq(string1, string2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test4) {
    char string1[100] = "";
    char string2[100] = "";
    void *p = (void *)43252342;
    int r1 = sprintf(string1, "%#24.e%-15.20i[%20p]%020u", 43253242.4342, 4567899, p, 43252342u);
    int r2 = s21_sprintf(string2, "%#24.e%-15.20i[%20p]%020u", 43253242.4342, 4567899, p, 43252342u);
    ck_assert_str_eq(string1, string2);
    ck_assert_int_eq(r1, r2);
    char str3[50] = "";
    char str4[100] = "";
    int r3 = sprintf(str3, "[%*.0f][%5.5f][%.3f]", 25, 25432.34345, 0.0, 1.4568);
    int r4 = s21_sprintf(str4, "[%*.0f][%5.5f][%.3f]", 25, 25432.34345, 0.0, 1.4568);
    ck_assert_str_eq(str3, str4);
    ck_assert_int_eq(r3, r4);
}
END_TEST

START_TEST(s21_sprintf_test_d) {
    char string1[200] = "";
    char string2[200] = "";
    short h = 34;
    int r1 = sprintf(string1,
    "% -25.10ld%030d%- 10.12d% 011d%*d%*.*d%+-25.*d%+10.2ld%-11.*hd% d%d%d%+.5d",
    (long)-253, -335, 1234, 34, 10, 25, 5, 15, 345, 5, 666, 456789l, 5, h, 2142, 0, (int)-2147483648, 12);
    int r2 = s21_sprintf(string2,
    "% -25.10ld%030d%- 10.12d% 011d%*d%*.*d%+-25.*d%+10.2ld%-11.*hd% d%d%d%+.5d",
    (long)-253, -335, 1234, 34, 10, 25, 5, 15, 345, 5, 666, 456789l, 5, h, 2142, 0, (int)-2147483648, 12);
    ck_assert_str_eq(string1, string2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_i) {
    char string1[200] = "";
    char string2[200] = "";
    short h = 34;
    long l = 2353423523424;
    int r2 = s21_sprintf(string2, "%+50.hi%-10.20i%10.i%012i%*.*i%-10.*i%+10.1li%*.25hi%+06i% 5i% i",
            (short int)34567, 225, 5230, 125, 10, 5, 456, 10, 377, l, 12, h, 123, 321, 4221);
    int r1 = sprintf(string1, "%+50.hi%-10.20i%10.i%012i%*.*i%-10.*i%+10.1li%*.25hi%+06i% 5i% i",
            (short int)34567, 225, 5230, 125, 10, 5, 456, 10, 377, l, 12, h, 123, 321, 4221);
    ck_assert_str_eq(string1, string2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_c) {
    char string1[250] = "";
    char string2[250] = "";
    wint_t c1 = 'T', c2 = 'Z';
    int r1 = sprintf(string1, "[%10c][%-10c][%25c][%-30c][%25c][%*c][%2c][%*c]%lc%-50lc",
        'a', 'e', 'f', 'R', 'Q', 10, 'P', 'L', 20, 'x', c1, c2);
    int r2 = s21_sprintf(string2, "[%10c][%-10c][%25c][%-30c][%25c][%*c][%2c][%*c]%lc%-50lc",
        'a', 'e', 'f', 'R', 'Q', 10, 'P', 'L', 20, 'x', c1, c2);
    ck_assert_str_eq(string1, string2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_e) {
    char string1[100] = "";
    char string2[100] = "";
    int r1 = sprintf(string1, "[%10.4e], [%+-*.*E], [%15e]%-15e", 21.8924, 30, 6, 0.0007812, 0.0,
    0.);
    int r2 = s21_sprintf(string2, "[%10.4e], [%+-*.*E], [%15e]%-15e", 21.8924, 30, 6, 0.0007812, 0.0,
    0.);
    ck_assert_str_eq(string1, string2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_E) {
    char string1[150] = "";
    char string2[150] = "";
    int r1 = sprintf(string1, "[%+-25.4E][%15.*E][%E]%10.3Le%-5Le%+e%+Le% Le", 3456.4325, 3, 194.74543, 0.0,
    (long double)58787.878958, (long double)0.2, 0., (long double)0., (long double)0.);
    int r2 = s21_sprintf(string2, "[%+-25.4E][%15.*E][%E]%10.3Le%-5Le%+e%+Le% Le", 3456.4325, 3, 194.74543,
    0.0, (long double)58787.878958, (long double)0.2, 0., (long double)0., (long double)0.);
    ck_assert_str_eq(string1, string2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_f) {
    char string1[150] = "";
    char string2[150] = "";
    int r1 = sprintf(string1, "%+-10.5f%+10.2f%15.7f%+*.6f%.2f%.3f%10.3Lf%-10Lf%+f% f%+Lf%+012Lf%012Lf",
            2546.4324, -3452.999, 5678.43256, 25, 456789.243242, 2.009, 0.0000099,
            (long double)58787.878958, (long double)-0.12, 0., 0., (long double)0.2, (long double)0.2,
            (long double)-0.2);
    int r2 = s21_sprintf(string2, "%+-10.5f%+10.2f%15.7f%+*.6f%.2f%.3f%10.3Lf%-10Lf%+f% f%+Lf%+012Lf%012Lf",
            2546.4324, -3452.999, 5678.43256, 25, 456789.243242, 2.009, 0.0000099,
            (long double)58787.878958, (long double)-0.12, 0., 0., (long double)0.2, (long double)0.2,
            (long double)-0.2);
    ck_assert_str_eq(string1, string2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_o) {
    char string1[150] = "";
    char string2[150] = "";
    unsigned short h = 253;
    unsigned long l = 4325234324242l;
    int r1 = sprintf(string1, "%-25.10o%-10o%#-30.2o%#*.10o%#*.*o%25.*o%#.10ho%*lo",
                     12345, 6532, 43522, 10, 64342, 15, 2, 343, 6, 678, h, 10, l);
    int r2 = s21_sprintf(string2, "%-25.10o%-10o%#-30.2o%#*.10o%#*.*o%25.*o%#.10ho%*lo",
                         12345, 6532, 43522, 10, 64342, 15, 2, 343, 6, 678, h, 10, l);
    ck_assert_str_eq(string1, string2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_x) {
    char string1[250] = {'\0'};
    char string2[250] = {'\0'};
    unsigned short h = 345;
    unsigned long l = 52342353242l;
    int integer = 2100, n2 = -21;
    long int lg = 12345678912345, lg1 = -12345678912345;
    int r1 = sprintf(string1,
    "[%#10x][%#-10x][%#10.5x][%-25.34x][%#-10.2x][%*.*x][%*.10x][%20.*x][%#10.*x][%*.5hx][%10.25lx]",
    3456, 12345, 222234, 68432, 34567, 10, 15, 3452, 8, 23452, 10, 34254, 3, 33334, 10, h, l);
    int r2 = s21_sprintf(string2,
    "[%#10x][%#-10x][%#10.5x][%-25.34x][%#-10.2x][%*.*x][%*.10x][%20.*x][%#10.*x][%*.5hx][%10.25lx]",
    3456, 12345, 222234, 68432, 34567, 10, 15, 3452, 8, 23452, 10, 34254, 3, 33334, 10, h, l);
    ck_assert_str_eq(string1, string2);
    ck_assert_int_eq(r1, r2);
    char string3[250] = {'\0'};
    char string4[250] = {'\0'};
    ck_assert_int_eq(
    s21_sprintf(string3,
                "%#x %#x %#10x %#10x %-#10x %0#10x %0#10x %-10.5x %lx %lx",
                integer, n2, 21, 0, 42, 21, 0, -65, lg, lg1),
    sprintf(string4, "%#x %#x %#10x %#10x %-#10x %0#10x %0#10x %-10.5x %lx %lx",
            integer, n2, 21, 0, 42, 21, 0, -65, lg, lg1));
}
END_TEST

START_TEST(s21_sprintf_test_X) {
    char string1[200] = "";
    char string2[200] = "";
    unsigned short h = 234;
    unsigned long l = 4325243132l;
    int r1 = sprintf(string1,
    "[%#-15X][%#20.3X][%-30.12X][%#-12.3X][%*.*X][%*.15X][%21.*X][%#12.*X][%*.8hx][%14.12lX]",
    12345, 222234, 68432, 34567, 10, 15, 3452, 8, 23452, 10, 34254, 3, 33334, 10, h, l);
    int r2 = s21_sprintf(string2,
    "[%#-15X][%#20.3X][%-30.12X][%#-12.3X][%*.*X][%*.15X][%21.*X][%#12.*X][%*.8hx][%14.12lX]",
    12345, 222234, 68432, 34567, 10, 15, 3452, 8, 23452, 10, 34254, 3, 33334, 10, h, l);
    ck_assert_str_eq(string1, string2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_u) {
    char string1[175] = "";
    char string2[175] = "";
    unsigned short h = 115;
    unsigned long l = 123325242342l;
    int r1 = sprintf(string1, "%u%15u%-20u%010u%-15.10u%20.*u%*.*u%*.10u%-20.12lu%19hu",
                     4321u, 34567u, 2342u, 12346u, 234542u, 10, 234523u, 10, 5, 2345u, 20, 2432u, l, h);
    int r2 = s21_sprintf(string2, "%u%15u%-20u%010u%-15.10u%20.*u%*.*u%*.10u%-20.12lu%19hu",
                         4321u, 34567u, 2342u, 12346u, 234542u, 10, 234523u, 10, 5, 2345u, 20, 2432u, l, h);
    ck_assert_str_eq(string1, string2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_s) {
    char string1[250] = "";
    char string2[250] = "";
    char s[10] = {'h', 'e', 'l', 'l', 'o'};
    wchar_t st[10] = {'h', 'e', 'l', 'l', 'o'};
    int r1 = sprintf(string1,
                     "%-10.4s%23s%-15s%10.s%15.2s%16.*s%*.*s%*s%15s%-10s%15ls%15.3ls",
                     "aboba", "helloworld", "ABOBA", "ABOBBAAA", "AAABOBA", 10, "QWERTY",
                     15, 4, "AAAAABOOOOOBAAA", 10, "ABOBAAAAA", s, s, st, st);
    int r2 = s21_sprintf(string2,
                         "%-10.4s%23s%-15s%10.s%15.2s%16.*s%*.*s%*s%15s%-10s%15ls%15.3ls",
                         "aboba", "helloworld", "ABOBA", "ABOBBAAA", "AAABOBA", 10, "QWERTY",
                         15, 4, "AAAAABOOOOOBAAA", 10, "ABOBAAAAA", s, s, st, st);
    ck_assert_str_eq(string1, string2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_p) {
    char string1[125] = "";
    char string2[125] = "";
    void *p1 = (void *)0x123456789;
    void *p2 = (void *)4325234;
    void *p3 = (void *)0x123f324b;
    void *p4 = (void *)432520;
    int r1 = sprintf(string1, "%p%20p%-15p%10p%-15p%*p%10p%*p",
                     p1, p2, p3, p4, p2, 10, p3, p1, 10, p4);
    int r2 = s21_sprintf(string2, "%p%20p%-15p%10p%-15p%*p%10p%*p",
                         p1, p2, p3, p4, p2, 10, p3, p1, 10, p4);
    ck_assert_str_eq(string1, string2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_percent) {
    char string1[20] = "";
    char string2[20] = "";
    int r1 = sprintf(string1, "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
    int r2 = s21_sprintf(string2, "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
    ck_assert_str_eq(string1, string2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(to_upper_case) {
    char *dest;
    dest = s21_to_upper("qwert");
    ck_assert_str_eq(dest, "QWERT");
    free(dest);
    dest = s21_to_upper("1q2w3e4r5");
    ck_assert_str_eq(dest, "1Q2W3E4R5");
    free(dest);
    dest = s21_to_upper("!@#!$^");
    ck_assert_str_eq(dest, "!@#!$^");
    free(dest);
    dest = s21_to_upper("\n0\\n");
    ck_assert_str_eq(dest, "\n0\\N");
    free(dest);
    dest = s21_to_upper("");
    ck_assert_str_eq(dest, "");
    free(dest);
}
END_TEST

START_TEST(to_lower_case) {
    char *dest;
    dest = s21_to_lower("");
    ck_assert_str_eq(dest, "");
    free(dest);
    dest = s21_to_lower("QWERT");
    ck_assert_str_eq(dest, "qwert");
    free(dest);
    dest = s21_to_lower("1Q2W3E4R5");
    ck_assert_str_eq(dest, "1q2w3e4r5");
    free(dest);
    dest = s21_to_lower("!@#!$^");
    ck_assert_str_eq(dest, "!@#!$^");
    free(dest);
    dest = s21_to_lower("\n0\\N");
    ck_assert_str_eq(dest, "\n0\\n");
    free(dest);
}
END_TEST

START_TEST(s21_trim_case) {
    char *dest;
    dest = s21_trim(" abra kadabra ", "a");
    ck_assert_str_eq(dest, " abra kadabra ");
    free(dest);
}
END_TEST

START_TEST(s21_insert_case) {
    char *dest = s21_NULL;
    dest = s21_insert("abrabra", "a kad", 3);
    ck_assert_str_eq(dest, "abra kadabra");
    free(dest);
    char *dest1 = s21_NULL;
    dest1 = s21_insert("abra", " hoba", 4);
    ck_assert_str_eq(dest1, "abra hoba");
    free(dest1);
}
END_TEST

int main() {
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    suite_add_tcase(s1, tc1_1);

    tcase_add_test(tc1_1, memchr_legal_range);
    tcase_add_test(tc1_1, memchr_empty_string);
    tcase_add_test(tc1_1, memchr_non_exist);
    tcase_add_test(tc1_1, memchr_overlength);
    tcase_add_test(tc1_1, memchr_after_null);
    tcase_add_test(tc1_1, memchr_null_char);
    tcase_add_test(tc1_1, memchr_null_bytes);

    tcase_add_test(tc1_1, memcmp_correct_data);
    tcase_add_test(tc1_1, memcmp_n_incorrect);
    tcase_add_test(tc1_1, memcmp_negative_values);
    tcase_add_test(tc1_1, memcmp_multiple_nulls);

    tcase_add_test(tc1_1, memcpy_correct_data);
    tcase_add_test(tc1_1, memcpy_without_null);
    tcase_add_test(tc1_1, memcpy_null_byte);
    tcase_add_test(tc1_1, memcpy_empty2empty);

    tcase_add_test(tc1_1, memmove_correct_data);
    tcase_add_test(tc1_1, memmove_dst_smaller);
    tcase_add_test(tc1_1, memmove_multiple_nulls);
    tcase_add_test(tc1_1, memmove_null_n);

    tcase_add_test(tc1_1, memset_null2null);
    tcase_add_test(tc1_1, memset_null_n);
    tcase_add_test(tc1_1, memset_c_negative);
    tcase_add_test(tc1_1, memset_correct_data);

    tcase_add_test(tc1_1, strcat_empty_add);
    tcase_add_test(tc1_1, strcat_correct_data);

    tcase_add_test(tc1_1, strncat_correct_data);
    tcase_add_test(tc1_1, strncat_empty_src);
    tcase_add_test(tc1_1, strncat_src_bigger_n);
    tcase_add_test(tc1_1, strncat_n_null);
    tcase_add_test(tc1_1, strncat_empty_strings);
    tcase_add_test(tc1_1, strncat_n_bigger_src);

    tcase_add_test(tc1_1, strcmp_empty_strings);
    tcase_add_test(tc1_1, strcmp_correct_data);

    tcase_add_test(tc1_1, strncmp_empty_strings);
    tcase_add_test(tc1_1, strncmp_correct_data);
    tcase_add_test(tc1_1, strncmp_string_smaller_n);

    tcase_add_test(tc1_1, strcpy_dest_smaller_src);
    tcase_add_test(tc1_1, strcpy_correct_data);
    tcase_add_test(tc1_1, strcpy_overlap);

    tcase_add_test(tc1_1, strncpy_null_bytes);
    tcase_add_test(tc1_1, strncpy_empty_string);
    tcase_add_test(tc1_1, strncpy_correct_data);

    tcase_add_test(tc1_1, strcspn_correct_data);
    tcase_add_test(tc1_1, strcspn_empty_strings);
    tcase_add_test(tc1_1, strcspn_multiple_nulls);
    tcase_add_test(tc1_1, strcspn_infinite_string1);
    tcase_add_test(tc1_1, strcspn_infinite_string2);
    tcase_add_test(tc1_1, strcspn_infinite_strings);

    tcase_add_test(tc1_1, strerror_all);

    tcase_add_test(tc1_1, strlen_correct_data);

    tcase_add_test(tc1_1, strpbrk_correct_data);
    tcase_add_test(tc1_1, strpbrk_empty_strings);

    tcase_add_test(tc1_1, strrchr_correct_data);
    tcase_add_test(tc1_1, strrchr_null_search);
    tcase_add_test(tc1_1, strrchr_empty_string);

    tcase_add_test(tc1_1, strspn_correct_data);
    tcase_add_test(tc1_1, strspn_s1_empty_string);
    tcase_add_test(tc1_1, strspn_s2_empty_string);
    tcase_add_test(tc1_1, strspn_infinite_string1);
    tcase_add_test(tc1_1, strspn_infinite_string2);
    tcase_add_test(tc1_1, strspn_infinite_strings);

    tcase_add_test(tc1_1, strstr_correct_data);
    tcase_add_test(tc1_1, strstr_empty_strings);

    tcase_add_test(tc1_1, strtok_correct_data);
    tcase_add_test(tc1_1, strtok_multiple_delims);
    tcase_add_test(tc1_1, strtok_repeated_delims);

    tcase_add_test(tc1_1, s21_sprintf_test1);
    tcase_add_test(tc1_1, s21_sprintf_test2);
    tcase_add_test(tc1_1, s21_sprintf_test3);
    tcase_add_test(tc1_1, s21_sprintf_test4);
    tcase_add_test(tc1_1, s21_sprintf_test_d);
    tcase_add_test(tc1_1, s21_sprintf_test_i);
    tcase_add_test(tc1_1, s21_sprintf_test_c);
    tcase_add_test(tc1_1, s21_sprintf_test_e);
    tcase_add_test(tc1_1, s21_sprintf_test_E);
    tcase_add_test(tc1_1, s21_sprintf_test_f);
    tcase_add_test(tc1_1, s21_sprintf_test_o);
    tcase_add_test(tc1_1, s21_sprintf_test_x);
    tcase_add_test(tc1_1, s21_sprintf_test_X);
    tcase_add_test(tc1_1, s21_sprintf_test_u);
    tcase_add_test(tc1_1, s21_sprintf_test_s);
    tcase_add_test(tc1_1, s21_sprintf_test_p);
    tcase_add_test(tc1_1, s21_sprintf_test_percent);

    tcase_add_test(tc1_1, to_upper_case);
    tcase_add_test(tc1_1, to_lower_case);
    tcase_add_test(tc1_1, s21_trim_case);
    tcase_add_test(tc1_1, s21_insert_case);

    srunner_run_all(sr, CK_VERBOSE);
    int errors = srunner_ntests_failed(sr);
    srunner_free(sr);
    return errors == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
