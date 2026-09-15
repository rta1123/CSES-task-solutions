#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;

int popcount(ll x)
{
    int k = {};

    while (x)
    {
        x ^= (x & (~x+1));
        k++;
    }

    return k;
}

int sgnp(int x)
{
    if ((x % 2) == 1)
        return 1;
    else
        return -1;
}

int main()
{
    ll n, k, m, *p, *d, C;

    cin >> n;
    cin >> k;

    p = new ll[k];

    for (ll i=0; i<k; i++)
        cin >> p[i];

    m = 1 << k;
    d = new ll[m];

    for (ll j=0; j<m; j++)
        d[j] = n;

    for (ll j=0; j<m; j++)
        for (ll i=0; i<k; i++)
            if (j & (1 << i))
                d[j] = d[j] / p[i];
    C = 0;
    for (ll j=1; j<m; j++)
        d[j] *= sgnp(popcount(j));

    for (ll j=1; j<m; j++)
        C += d[j];

    cout << C << endl;

    delete[] p;
    delete[] d;

    return 0;
}
