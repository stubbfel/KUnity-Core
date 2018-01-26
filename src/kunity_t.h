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

#ifndef KUNITY_TEST
#define KUNITY_TEST(function_name) \
    extern void function_name (void); \
    EXPORT_SYMBOL(function_name); \
    void function_name()
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
