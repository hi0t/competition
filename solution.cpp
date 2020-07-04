#include <bits/stdc++.h>

using ll = long long;

using namespace std;

void solve(ll n, ll r)
{
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
        int n, r;
        cin >> n >> r;
        solve(n, r);
    }

    return 0;
}
