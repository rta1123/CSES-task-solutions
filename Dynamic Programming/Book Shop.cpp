#include <bits/stdc++.h>

using namespace std;

typedef int64_t lint;

lint max(lint u, lint v)
{
    if (u>=v)
        return u;
    else
        return v;
}

int main()
{
    lint n, x, *h, *s, *prev, *next;

    cin >> n;
    cin >> x;

    h = new lint[n+1];
    s = new lint[n+1];
    prev = new lint[x+1];
    next = new lint[x+1];

    for (lint i=1;i<=n;i++)
        cin >> h[i];

    for (lint i=1;i<=n;i++)
        cin >> s[i];

    for (lint j=1;j<=n;j++)
    {
        for (lint i=1;i<=x;i++)
        {
            if (i>=h[j])
                next[i] = prev[i-h[j]] + s[j];

            next[i] = max(next[i],prev[i]);
        }

        for (lint i=1;i<=x;i++)
            prev[i] = next[i];
    }

    cout << next[x];

    delete[] h;
    delete[] s;
    delete[] prev;
    delete[] next;

    return 0;
}
