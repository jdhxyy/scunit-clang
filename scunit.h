// Copyright 2019-2021 The jdh99 Authors. All rights reserved.
// Unit test for C
// Authors: jdh99 <jdh821@163.com>

#ifndef SCUNIT_H
#define SCUNIT_H

#include <stdio.h>
#include "stdbool.h"
#include "stdint.h"
#include "stdlib.h"
#include "string.h"            
#include "stdarg.h"

typedef void (*ScunitPrintFunc)(char *format, ...);
typedef void (*ScunitFunc)(void);

// ScunitLoad module load
void ScunitLoad(ScunitPrintFunc func);

// ScunitAddSuite add suite
void ScunitAddSuite(char *name);

// ScunitAddTest add test case
void ScunitAddTest(char *name, ScunitFunc func);

// ScunitAssert assert
void ScunitAssert(bool condition, char *tag);

// ScunitAssertMessage assert with message
void ScunitAssertMessage(bool condition, char *tag, char *message);

// ScunitPrint print message
void ScunitPrint(char *format, ...);

#endif
