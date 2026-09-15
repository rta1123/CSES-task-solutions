#include <bits/stdc++.h>

using namespace std;

void D(int v, int *t, int *d, int *c, int &dist)
{
    if (c[v] >= 1)
    {
        return;
    }
    else
        if (c[v] == 0)
        {
            c[v] = 1;
            dist++;
        }
        else
            c[v] = 0;

    D(t[v], t, d, c, dist);
}

void sD(int v, int *t, int *d, int *c, int dist)
{
    if (c[v] == 0)
    {
        sD(t[v], t, d, c, dist);
        d[v] = d[t[v]] + 1;
        c[v] = 2;
        return;
    }
    else
        if (c[v] == 1)
        {
            c[v] = 2;
            d[v] = dist;
            sD(t[v], t, d, c, dist);
            return;
        }
        else
            if (c[v] == 2)
                return;
}

int main()
{
    int n, *t, *d, *c, dist;

    cin >> n;

    t = new int[n+1];
    d = new int[n+1];
    c = new int[n+1];

    for (int i=1; i<=n; i++)
        cin >> t[i];

    for (int i=1; i<=n; i++)
    {
        d[i] = -1;
        c[i] = -1;
    }

    for (int i=1; i<=n; i++)
    {
        if (c[i] == -1)
        {
            dist = {};
            D(i, t, d, c, dist);
            sD(i, t, d, c, dist);
        }
    }

    for (int i=1; i<=n; i++)
        cout << d[i] << " ";
    cout << endl;

    delete[] t;
    delete[] d;
    delete[] c;

    return 0;
}
