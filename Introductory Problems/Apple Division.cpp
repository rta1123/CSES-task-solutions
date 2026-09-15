#include <bits/stdc++.h>

typedef int64_t lint;

using namespace std;

lint min(lint u, lint v)
{
    if (u<=v)
        return u;
    else
        return v;
}

lint labs(lint u)
{
    if (u<0)
        return -u;
    return u;
}

int main()
{
    lint n,*p, u, v, m;

    cin >> n;

    p = new lint[n+1];

    for (lint i=0;i<n;i++)
        cin >> p[i];

    m = 1000000001;
    for (lint i = 0, k; i <= (1<< n) - 1; i++)
    {
        u = v = k = 0;
        do
        {
            if (i & (1 << k))
                u += p[k];
            else
                v += p[k];
            k++;
        }
        while (((1<< n )- 1)>>k);

        m = min(m,labs(u-v));
    }

    cout << m;

    delete[] p;

    return 0;
}
