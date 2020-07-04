#include "util.h"
#define main mainFn
#include "solution.cpp"
#undef main

const string test = R"(
5
3 4
3 2
3 1
13 7
1010000 9999999
)";

const string want = R"(
4
3
1
28
510049495001
)";

int main()
{
    ASSERT(check(mainFn, test, want));

    return 0;
}
