#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;

enum
{
    modulo = 1000000007,
};

ll fe(ll a, ll x)
{
    ll e = 1;

    if (x == 0)
        return e;

    if (x == 1)
        return a;

    if (x % 2)
    {
        e = (a * fe(a, x - 1) % modulo);
    }
    else
    {
        e = (fe(a, x / 2) % modulo);
        e = (e * e % modulo);
    }

    return e;
}

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;

    if (b == 0)
        return a;

    if (a > b)
    {
        return gcd(a % b, b);
    }
    else
        if (a < b)
            return gcd(a, b % a);
        else
            return a;
}

ll inv(ll a)
{
    return fe(a, modulo - 2);
}

int main()
{
    ll n, m, N;

    cin >> n;
    cin >> m;

    N = 0;
    for (ll k=0; k<=n-1; k++)
    {
        N += fe(m, gcd(k, n)) % modulo;
        N %= modulo;
    }

    N = (N * inv(n) % modulo);

    cout << N << endl;

    return 0;
}
