# KUnity

KUnity configure the c unit test framework Unity (http://www.throwtheswitch.org/unity) so that it can use in kernel space. The test results will be "shown" by `printk`.

## Add KUnity to a kernel module

```Makefile

# add KUnity and Unity source files
module-objs += lib/KUnity/src/kunity.o
module-objs += lib/KUnity/lib/Unity/src/unity.o

# include KUnity and Unity header
ccflags-y += -I<lib_path>/KUnity/src
ccflags-y += -I<lib_path>/KUnity/lib/Unity/src

# set the unity config by header file flag, which is provided by KUnity
ccflags-y += -DUNITY_INCLUDE_CONFIG_H
```

##  Write and Running test cases

Test can be written like Unity tests, but for the definition of the test function you have to use the  ```KUNITY_TEST``` makro.
When a kunity test should run, its necessary to add the prefix  ```kunity_test_``` to the test function name.

```c
#include <kunity.h>
// ... application includes
KUNITY_TEST(first_simple_test)
{
    TEST_ASSERT_EQUAL(1, 0);
}

// add more tests

// run tests
int module_init(void) {
    int result = 0;
    UNITY_BEGIN();
    RUN_TEST(kunity_test_first_simple_test);
    // ... call the other tests
    result = UNITY_END();
    if ( < 1) {
        // all tests was successful, startup module
        // ...
    }

    return -result;
}
```
For running tests it can also use the [KUnity-Test-Runner-Module](https://github.com/stubbfel/KUnity-Test-Runner-Module)
