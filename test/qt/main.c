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
