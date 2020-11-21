#include <bits/stdc++.h>

using ll = long long;

using namespace std;

void solve()
{
    ll n, r;
    cin >> n >> r;

    ll res = 0;
    if (n > r)
    {
        res = r * (r + 1) / 2;
    }
    else
    {
        res = n * (n - 1) / 2 + 1;
    }
    cout << res << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
