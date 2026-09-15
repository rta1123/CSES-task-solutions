#include <bits/stdc++.h>

using namespace std;

uint64_t find(uint64_t x, uint64_t *X, uint64_t n)
{
    uint64_t l {}, r {}, m {};

    l = 0;
    r = n + 1;
    m = (l + r)/2;
    while ((r - l) > 1)
    {
        if (X[m] >= x)
            r = m;
        else
            l = m;

        m = (l + r) / 2;
    }

    return l;
}

int main()
{
    uint64_t n, m, M, *t, x, *p, *q, c, u, v, *P, *Q;

    cin >> n;
    cin >> x;

    t = new uint64_t[n+1];

    for (uint64_t i=1; i<=n; i++)
        cin >> t[i];

    m = (1 << (n/2));
    M = (1 << (n - (n/2)));

    sort(t+1, t+n+1);

    p = new uint64_t[m + 1];
    q = new uint64_t[M + 1];

    for (uint64_t j=1; j<=m; j++)
        p[j] = 0;

    for (uint64_t i=1; i<=n/2; i++)
        for (uint64_t j=(1 << (i-1)); j<=m; j+=(1 << i))
            for (uint64_t k=0; k<(1 << (i-1)); k++)
                p[j+k] += t[i];

    for (uint64_t j=1; j<=M; j++)
        q[j] = 0;

    for (uint64_t i=1; i<=(n - n/2); i++)
        for (uint64_t j=(1 << (i-1)); j<=M; j+=(1 << i))
            for (uint64_t k=0; k<(1 << (i-1)); k++)
                q[j+k] += t[n/2 + i];

    u = {}, v = {}, c = {};
    for (uint64_t i=1; i<=m; i++)
    {
        if (p[i] == 0)
            continue;

        if (p[i] < x)
            u++;
        else
            if (p[i] == x)
            {
                c++;
                p[i] = {};
            }
            else
                if (p[i] > x)
                    p[i] = {};
    }

    for (uint64_t i=1; i<=M; i++)
    {
        if (q[i] == 0)
            continue;

        if (q[i] < x)
            v++;
        else
            if (q[i] == x)
            {
                c++;
                q[i] = {};
            }
            else
                if (q[i] > x)
                    q[i] = {};
    }

    P = new uint64_t[u+1];
    Q = new uint64_t[v+1];

    for (uint64_t i=1, j=1; i<=m; i++)
        if (p[i])
        {
            P[j] = p[i];
            j++;
        }

    for (uint64_t i=1, j=1; i<=M; i++)
        if (q[i])
        {
            Q[j] = q[i];
            j++;
        }

    sort(Q+1, Q+v+1);

    for (uint64_t i=1; i<=u; i++)
        c += (find(x-P[i]+1, Q, v) - find(x-P[i], Q, v));

    cout << c << endl;

    delete[] P;
    delete[] Q;
    delete[] p;
    delete[] q;
    delete[] t;

    return 0;
}
