#include "util.h"
#define main mainFn
#include "solution.cpp"
#undef main

const string test = R"(
5
5
7
11
1
2000000000000

)";

const string want = R"(
8
11
19
1
3999999999987
)";

int main()
{
    ASSERT(check(mainFn, test, want));

    return 0;
}
