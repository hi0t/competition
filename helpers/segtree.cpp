#include <bits/stdc++.h>

using ll = long long;

using namespace std;

class segtree
{
public:
    segtree(int n)
    {
        size = 1;
        while (size < n)
        {
            size *= 2;
        }
        tree.resize(2 * size - 1);
    }

    void set(int i, int v)
    {
        set(i, v, 0, 0, size);
    }

    ll sum(int l, int r)
    {
        return sum(l, r, 0, 0, size);
    }

private:
    vector<ll> tree;
    int size;

    void set(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            tree[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m)
        {
            set(i, v, 2 * x + 1, lx, m);
        }
        else
        {
            set(i, v, 2 * x + 2, m, rx);
        }
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }
    ll sum(int l, int r, int x, int lx, int rx)
    {
        if (l >= rx || lx >= r)
        {
            return 0;
        }
        if (lx >= l && rx <= r)
        {
            return tree[x];
        }
        int m = (lx + rx) / 2;
        ll s1 = sum(l, r, 2 * x + 1, lx, m);
        ll s2 = sum(l, r, 2 * x + 2, m, rx);
        return s1 + s2;
    }
};
