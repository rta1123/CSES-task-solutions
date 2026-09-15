#include <bits/stdc++.h>

using namespace std;

typedef unsigned int uint;

uint min(uint u, uint v)
{
    if (u<=v)
        return u;
    else
        return v;
}

uint MIN(uint a, uint b, uint *m, uint k)
{
    a+=k - 1, b+=k - 1;

    uint M = 1000000000;

    while (a<=b)
    {
        if (a%2 == 1)
            M = min(M, m[a++]);
        if (b%2 == 0)
            M = min(M, m[b--]);

        a /=2; b/=2;
    }

    return M;
}

struct D
{
    uint a;
    uint b;
};

int main()
{
    uint n, cD, *a, *m, k;
    D *d;

    cin >> n;
    cin >> cD;

    k = pow(2,ceil(log2(n)));

    a = new uint[k + 1];
    d = new D[cD + 1];
    m = new uint[2 * k];

    for (uint i = 1; i <= n; i++)
        cin >> a[i];

    for (uint i = n + 1; i <= k; i++)
        a[i] = 1000000000;

    for (uint i = 1; i <= cD; i++)
    {
        cin >> d[i].a;
        cin >> d[i].b;
    }

    for (uint i=2*k-1; i>=k; i--)
        m[i] = a[i-k+1];

    for (int i=2*k-1; i>=2; i-=2)
        m[i/2] = min(m[i],m[i-1]);

    for (uint i=1; i<=cD; i++)
        cout << MIN(d[i].a, d[i].b, m, k) << endl;

    delete[] a;
    delete[] d;
    delete[] m;

    return 0;
}
