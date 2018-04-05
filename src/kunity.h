#ifndef KUNITY_H
#define KUNITY_H
#include "kunity_t.h"

//{ global include region

#include <unity.h>

//}

//{ function region

extern void putchark(/* in */ char a);

extern result_code_e create_default_test_output(/* out*/ ptr_test_session_control_block_s* output_location);

extern result_code_e run_unity_test(/* in */ const unity_test_function_ptr test_function, /* in */ const char* file_name, /* in */ const char* test_name, /* in */ int line_number, /* in */ const ptr_test_session_control_block_s output);

extern result_code_e run_unity_printk_test(/* in */ const kunity_test_function_ptr test_function);

//}

#endif // KUNITY_H
