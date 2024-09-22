#include <stdio.h>
#include <string.h>
#include "strlib.h"
#include "strlib_test.h"

int main() {
    run_test("test_str_pad_start", test_str_pad_start);
    run_test("test_str_repeat", test_str_repeat);
    run_test("test_str_slice", test_str_slice);
    run_test("test_str_starts_with", test_str_starts_with);
    run_test("test_str_substring", test_str_substring);
    run_test("test_str_to_lower", test_str_to_lower);
    run_test("test_str_to_upper", test_str_to_upper);
    run_test("test_str_trim", test_str_trim);
    run_test("test_str_trim_end", test_str_trim_end);
    run_test("test_str_trim_start", test_str_trim_start);
    run_test("test_str_value_of", test_str_value_of);
    run_test("test_str_length", test_str_length);

    return 0;
}


void run_test(const char *test_name, int (*test_func)()) {
    if (test_func()) {
        printf("%s: OK\n", test_name);
    } else {
        printf("%s: FAIL\n", test_name);
    }
}

int assert_eq(int expected, int actual) {
    if(expected != actual){
        printf("Expected: %d\n", expected);
        printf("Actual: %d\n", actual);
    }
    return expected == actual;
}

int assert_str_eq(const char *expected, const char *actual) {
    if(strcmp(expected, actual) != 0){
        printf("Expected: %s\n", expected);
        printf("Actual: %s\n", actual);
    }
    return strcmp(expected, actual) == 0;
}

// Test cases
int test_str_pad_start() {
    char dest[50];
    str_pad_start("Hello", 10, '*', dest);
    return assert_str_eq("*****Hello", dest);
}

int test_str_repeat() {
    char dest[50];
    str_repeat("Hi", 3, dest);
    return assert_str_eq("HiHiHi", dest);
}

int test_str_slice() {
    char dest[50];
    str_slice("Hello, World!", 7, 12, dest);
    return assert_str_eq("World", dest);
}

int test_str_starts_with() {
    return assert_eq(1, str_starts_with("Hello, World!", "Hello")) &&
           assert_eq(0, str_starts_with("Hello, World!", "World"));
}

int test_str_substring() {
    char dest[50];
    str_substring("Hello, World!", 7, 12, dest);
    return assert_str_eq("World", dest);
}

int test_str_to_lower() {
    char dest[50];
    str_to_lower("HELLO", dest);
    return assert_str_eq("hello", dest);
}

int test_str_to_upper() {
    char dest[50];
    str_to_upper("hello", dest);
    return assert_str_eq("HELLO", dest);
}

int test_str_trim() {
    char dest[50];
    str_trim("  Hello  ", dest);
    return assert_str_eq("Hello", dest);
}

int test_str_trim_end() {
    char dest[50];
    str_trim_end("Hello  ", dest);
    return assert_str_eq("Hello", dest);
}

int test_str_trim_start() {
    char dest[50];
    str_trim_start("  Hello", dest);
    return assert_str_eq("Hello", dest);
}

int test_str_value_of() {
    return assert_eq(123, str_value_of("123"));
}

int test_str_length() {
    return assert_eq(13, str_length("Hello, World!"));
}
