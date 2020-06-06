#include <bits/stdc++.h>

using namespace std;

void solution(int64_t n)
{
    int64_t p = 2 * n;
    int64_t cnt = 0;

    while (n)
    {
        cnt += n & 1;
        n >>= 1;
    }

    cout << p - cnt << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int64_t n;
        cin >> n;
        solution(n);
    }

    return 0;
}
