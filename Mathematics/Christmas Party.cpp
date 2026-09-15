#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;

enum
{
    modulo = 1000000007,
};

ll _1(ll n)
{
    if (n % 2)
        return -1;
    else
        return 1;
}

ll M(ll n, ll *m)
{
    if (m[n] != -1)
        return m[n];

    if (n == 1)
    {
        m[n] = 0;
        return m[n];
    }

    m[n] = n * M(n-1, m) + _1(n);

    m[n] %= modulo;
    return m[n];
}

int main()
{
    ll n, *m;

    cin >> n;

    m = new ll[n+1];

    for (ll i=1; i<=n; i++)
        m[i] = -1;

    cout << M(n, m) << endl;

    delete[] m;

    return 0;
}
