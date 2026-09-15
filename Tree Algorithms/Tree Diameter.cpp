#include <bits/stdc++.h>

using namespace std;

typedef int64_t lint;

int main()
{
    lint n,v,w,D;
    vector <lint> *u;
    lint *d,min,k,*dist, max;
    queue <lint> q;
    bool *p;

    cin >> n;

    u = new vector <lint>[n+1];
    d = new lint[n+1];
    dist = new lint[n+1];
    p = new bool[n+1];

    for (lint i=1;i<=n-1;i++)
    {
        cin >> v;
        cin >> w;
        u[v].push_back(w);
        u[w].push_back(v);
    }

    for (lint i=1;i<=n;i++)
        d[i]=u[i].size();

    min = n, k = 0;
    for (lint i=1;i<=n;i++)
    {
        if (d[i]<min)
        {
            min = d[i];
            k = i;
        }
    }

    max = D = 0;
    do
    {
        if (max > D)
            D = max;

        for (lint i=1;i<=n;i++)
        {
            dist[i] = 0;
            p[i] = false;
        }

        q.push(k);
        p[k] = true;
        while (!q.empty())
        {
            v = q.front();
            q.pop();

            for (auto x : u[v])
                if (!p[x])
                {
                    q.push(x);
                    p[x] = true;
                    dist[x] = dist[v] + 1;
                }
        }

        max = 0;
        for (lint i=1;i<=n;i++)
            if (max < dist[i])
            {
                max = dist[i];
                k = i;
            }

    }while (D!=max);

    cout << D;

    delete[] dist;
    delete[] u;
    delete[] d;
    delete[] p;

    return 0;
}
