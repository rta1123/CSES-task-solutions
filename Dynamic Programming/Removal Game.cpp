#include <bits/stdc++.h>

using namespace std;

enum
{
    first_player = 0,
    second_player = 1,
};

typedef int64_t ll;

pair <ll,ll> S(ll l, ll r, ll *x, ll p, pair <ll,ll> **s, bool **w)
{
    if (l == r)
    {
        if (p == first_player)
            return {x[l], 0};
        else
            return {0, x[l]};
    }

    if (w[l][r])
        return s[l][r];

    if (p == first_player)
    {
        auto s1 = S(l+1, r, x, second_player, s, w);
        auto s2 = S(l, r-1, x, second_player, s, w);

        if ((s1.first + x[l]) >= (s2.first + x[r]))
            s[l][r] = {s1.first + x[l], s1.second};
        else
            s[l][r] = {s2.first + x[r], s2.second};
    }
    else
    {
        auto s1 = S(l+1, r, x, first_player, s, w);
        auto s2 = S(l, r-1, x, first_player, s, w);

        if ((s1.second + x[l]) >= (s2.second + x[r]))
            s[l][r] = {s1.first, s1.second + x[l]};
        else
            s[l][r] = {s2.first, s2.second + x[r]};
    }

    w[l][r] = true;
    return s[l][r];
}

int main()
{
    ll n, *x;
    pair <ll, ll> **s;
    bool **w;

    cin >> n;

    x = new ll[n+1];

    s = new pair <ll, ll>*[n+1];
    for (ll i=0; i<=n; i++)
        s[i] = new pair <ll, ll>[n+1];

    w = new bool*[n+1];
    for (ll i=0; i<=n; i++)
        w[i] = new bool[n+1];

    for (ll i=1; i<=n; i++)
        cin >> x[i];

    for (ll i=0; i<=n; i++)
        for (ll j=0; j<=n; j++)
        {
            s[i][j] = {0, 0};
            w[i][j] = false;
        }

    cout << S(1, n, x, first_player, s, w).first << endl;

    for (ll i=0; i<=n; i++)
        delete[] w[i];
    delete[] w;

    for (ll i=0; i<=n; i++)
        delete[] s[i];
    delete[] s;

    delete[] x;

    return 0;
}
