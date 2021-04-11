# Scunit

## 介绍
Scunit: Simple C Language Unit Test Framework.适合于C语言的简单测试框架。

主流语言都有测试框架，在嵌入式领域特别是资源紧缺的单片机工程中没有合适的测试框架。Scunit是一种简单的C语言测试框架，可以应用于嵌入式领域。

## 开源
- [github上的项目地址](https://github.com/jdhxyy/scunit-clang)
- [gitee上的项目地址](https://github.com/jdhxyy/scunit-clang)

## API
```c
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
```

## 测试
```c
#include <stdio.h>
#include "scunit.h"

static void testCase0(void);
static void testCase1(void);

int main() {
    ScunitLoad((ScunitPrintFunc)printf);
    ScunitAddSuite("test_routing_table");
    ScunitAddTest("case0", testCase0);
    ScunitAddTest("case1", testCase1);
    return 0;
}

static void testCase0(void) {
    ScunitAssert(1 == 1, "1");
    ScunitAssert(1 == 2, "2");
}

static void testCase1(void) {
    ScunitPrint("test case2!");
    ScunitAssertMessage(1 == 1, "1", "message1");
    ScunitAssertMessage(1 == 2, "2", "message2");
}
```

输出:
```text

Suite:test_routing_table
-------------------->case:case0 begin
case0 tag:1 SCUNIT_ASSERT pass
case0 tag:2 SCUNIT_ASSERT fail
-------------------->case:case0 end
-------------------->case:case1 begin
test case2!
case1 tag:1 SCUNIT_ASSERT pass
case1 tag:2 SCUNIT_ASSERT fail:message2
-------------------->case:case1 end
```
