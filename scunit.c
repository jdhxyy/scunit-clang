// Copyright 2019-2021 The jdh99 Authors. All rights reserved.
// Unit test for C
// Authors: jdh99 <jdh821@163.com>

#include "scunit.h"                  

static ScunitPrintFunc print = NULL;
static char *func_name = NULL;

// ScunitLoad module load
void ScunitLoad(ScunitPrintFunc func) {
    print = func;
}

// ScunitAddSuite add suite
void ScunitAddSuite(char *name) {
    print("\nSuite:%s\n", name);
}

// ScunitAddTest add test case
void ScunitAddTest(char *name, ScunitFunc func) {
    func_name = name;
    print("-------------------->case:%s begin\n", func_name);
    func();
    print("-------------------->case:%s end\n\n", func_name);
}    

// ScunitAssert assert
void ScunitAssert(bool condition, char *tag) {
   if (condition) {
       print("%s tag:%s SCUNIT_ASSERT pass\n", func_name, tag);
   } else {
       print("%s tag:%s SCUNIT_ASSERT fail\n", func_name, tag);
   }
}

// ScunitAssertMessage assert with message
void ScunitAssertMessage(bool condition, char *tag, char *message) {
    if (condition) {
       print("%s tag:%s SCUNIT_ASSERT pass\n", func_name, tag);
   } else {
       print("%s tag:%s SCUNIT_ASSERT fail:%s\n", func_name, tag, message);
   }
}

// ScunitPrint print message
void ScunitPrint(char *format, ...) {
    static char buf[SCUNIT_PRINT_SIZE_MAX];
    
	va_list args;
	va_start(args, format);
    
    int length = vsnprintf(buf, sizeof(buf) - 1, format, args);
    if (length > SCUNIT_PRINT_SIZE_MAX - 1) {
        length = SCUNIT_PRINT_SIZE_MAX - 1;
    }
    buf[length] = 0;
    
    print(buf);
    print("\n");
    
	va_end(args);
}
