#ifndef UNITY_CONFIG_H
#define UNITY_CONFIG_H


#include <linux/kernel.h>
#ifndef UNITY_EXCLUDE_SETJMP_H
#define UNITY_EXCLUDE_SETJMP_H
#endif

#ifndef UNITY_EXCLUDE_MATH_H
#define UNITY_EXCLUDE_MATH_H
#endif

#ifndef UNITY_EXCLUDE_LIMITS_H
#define UNITY_EXCLUDE_LIMITS_H
#endif

#ifndef UNITY_EXCLUDE_STDINT_H
#define UNITY_EXCLUDE_STDINT_H
#endif

#ifndef UNITY_EXCLUDE_FLOAT
#define UNITY_EXCLUDE_FLOAT
#endif

#ifndef UNITY_OUTPUT_CHAR
#define UNITY_OUTPUT_CHAR(a) putchark(a)
#endif

#ifndef UNITY_OUTPUT_CHAR_HEADER_DECLARATION
#define UNITY_OUTPUT_CHAR_HEADER_DECLARATION putchark(char a)
#endif

#ifndef UNITY_INT_WIDTH
#define UNITY_INT_WIDTH (32)
#endif

#endif // UNITY_CONFIG_H
