#ifndef KUNITY_T_H
#define KUNITY_T_H

//{ global include region
#include <linux/types.h>

#ifndef KUNITY_TEST_RUNNER_APP
#include <linux/export.h>
#endif

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
#define JOIN(x,y) x ## y
#define CONCAT(x,y) JOIN(x,y)
#define KUNITY_CREATE_TEST_NAME(function_name) CONCAT(KUNITY_DEFAULT_TEST_NAME_PREFIX, function_name)
#endif

#ifndef KUNITY_TEST
#define KUNITY_TEST(function_name) \
    extern void KUNITY_CREATE_TEST_NAME(function_name) (void); \
    EXPORT_SYMBOL(KUNITY_CREATE_TEST_NAME(function_name)); \
    void KUNITY_CREATE_TEST_NAME(function_name)()
#endif


//}


//{ enum region

//}


//{ typedef region

//}

//{ struct region

#pragma pack(push, 1)
typedef struct string_builder_sTag
{
    size_t write_postion;
    char buffer[KUNITY_LINE_SIZE];
} string_builder_s, ptr_string_builder_s;
#pragma pack(pop)


//}

#endif // KUNITY_T_H
