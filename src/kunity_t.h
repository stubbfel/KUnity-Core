#ifndef KUNITY_T_H
#define KUNITY_T_H

//{ global include region

#include <linux/export.h>
#include <linux/types.h>

//}
//{ local include region

//}

//{ define region

#ifndef KUNITY_LINE_SIZE
#define KUNITY_LINE_SIZE 1024
#endif

#ifndef KUNITY_DEFAULT_TEST_NAME_PREFIX
#define KUNITY_DEFAULT_TEST_NAME_PREFIX kunity_test_
#endif

#ifndef KUNITY_DEFAULT_TEST_NAME_PREFIX_STR
#define STR(s) #s
#define XSTR(s) STR(s)
#define KUNITY_DEFAULT_TEST_NAME_PREFIX_STR XSTR(KUNITY_DEFAULT_TEST_NAME_PREFIX)
#endif

#ifndef KUNITY_CREATE_TEST_NAME
#define JOIN(x, y) x##y
#define CONCAT(x, y) JOIN(x, y)
#define KUNITY_CREATE_TEST_NAME(function_name) CONCAT(KUNITY_DEFAULT_TEST_NAME_PREFIX, function_name)
#endif

#ifndef KUNITY_TEST
#define KUNITY_TEST(function_name)                                                                    \
    extern result_code_e KUNITY_CREATE_TEST_NAME(function_name)(const ptr_output_functions_s output); \
    static void function_name(void);                                                                  \
                                                                                                      \
    result_code_e KUNITY_CREATE_TEST_NAME(function_name)(const ptr_output_functions_s output)         \
    {                                                                                                 \
        return run_unity_test(function_name, __FILE__, #function_name, __LINE__, output);             \
    }                                                                                                 \
    EXPORT_SYMBOL(KUNITY_CREATE_TEST_NAME(function_name));                                            \
                                                                                                      \
    static void function_name()
#endif

//}

//{ enum region

typedef enum result_code_eTag {
    OK,
    ERROR_NULL_ARGUMENT,
    ERROR_INVALID_ARGUMENT,
    ERROR_INVALID_OPERATION
} result_code_e,
    *ptr_result_code_e;

//}

//{ typedef region

typedef void (*redirect_char)(char a);

typedef void (*unity_test_function_ptr)(void);

//}

//{ struct region

typedef struct output_functions_sTag {
    redirect_char redirect_char;
} output_functions_s, *ptr_output_functions_s;


typedef result_code_e (*kunity_test_function_ptr)(ptr_output_functions_s);

typedef struct test_sTag {
    const char* name;
    const char* modul_name;
    kunity_test_function_ptr test_function;
} test_s, *ptr_test_s;

//}

#endif // KUNITY_T_H
