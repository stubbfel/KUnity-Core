#include "kunity.h"
//{ global include region

#include <linux/slab.h>
#include <linux/string.h>

//}
//{ local include region

//}

//{ local define region

//}

//{ local enum region

//}

//{ local typedef region

//}

//{local struct region

typedef struct string_builder_sTag {
    size_t write_postion;
    char buffer[KUNITY_LINE_SIZE];
} string_builder_s, ptr_string_builder_s;

//}

//{ local function prototype region

static void printk_put_char(char /* letter */);

static result_code_e set_test_output(/*in */ const ptr_test_session_control_block_s output);

//}

//{ local  var region

static test_session_control_block_s prink_output = { printk_put_char,0 ,0 };

static ptr_test_session_control_block_s kunity_output = &prink_output;

static string_builder_s string_builder;

static size_t sizeof_output = sizeof(test_session_control_block_s);

//}

//{ global function implements region

void putchark(/* in */ char a)
{
    kunity_output->redirect_char(a);
}

result_code_e create_default_test_output(/* out*/ ptr_test_session_control_block_s* output_location)
{
    ptr_test_session_control_block_s tmp_output = NULL;
    if (output_location == NULL) {
        return ERROR_NULL_ARGUMENT;
    }

    if (*output_location != NULL) {
        return ERROR_INVALID_ARGUMENT;
    }

    tmp_output = kmalloc(sizeof_output, GFP_KERNEL);
    if (tmp_output == NULL) {
        return ERROR_INVALID_OPERATION;
    }

    *output_location = tmp_output;
    return OK;
}

result_code_e run_unity_test(/* in */ const unity_test_function_ptr test_function, /* in */ const char* file_name, /* in */ const char* test_name, /* in */ int line_number, /* in */ const ptr_test_session_control_block_s output)
{
    result_code_e result;
    if (output == NULL) {
        return ERROR_NULL_ARGUMENT;
    }

    result = set_test_output(output);
    if (result != OK) {
        return result;
    }

    if (output->_skip_start){
        Unity.TestFile = file_name;
    } else {
        UnityBegin(file_name);
    }

    UnityDefaultTestRun(test_function, test_name, line_number);
    if (!output->_skip_end){
        UNITY_END();
    }

    return result;
}

result_code_e run_unity_printk_test(/* in */ const kunity_test_function_ptr test_function)
{
    if (test_function == NULL) {
        return ERROR_NULL_ARGUMENT;
    }
    return test_function(&prink_output);
}

//}

//{ local function implements region

static void printk_put_char(char letter)
{
    if (letter == '\n') {
        const char* c = (const char*)&string_builder.buffer[0];
        printk(c);
        string_builder.write_postion = 0;
        memset(string_builder.buffer, 0, KUNITY_LINE_SIZE);
        return;
    }

    string_builder.buffer[string_builder.write_postion] = letter;
    string_builder.write_postion = (string_builder.write_postion + 1) % KUNITY_LINE_SIZE;
}

static result_code_e set_test_output(/* in */ const ptr_test_session_control_block_s output)
{
    if (output == NULL) {
        return ERROR_NULL_ARGUMENT;
    }

    if (output->redirect_char == NULL) {
        return ERROR_INVALID_ARGUMENT;
    }

    kunity_output = output;
    return OK;
}
//}
