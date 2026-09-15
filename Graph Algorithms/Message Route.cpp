#include <bits/stdc++.h>

using namespace std;

typedef int64_t lint;

int main()
{
    lint n, m, a, b, u;
    vector <lint> *v;
    queue <lint> q;
    bool *p;
    lint *d;
    lint *path;


    cin >> n;
    cin >> m;

    v = new vector<lint>[n+1];
    p = new bool[n+1];
    d = new lint[n+1];
    path = new lint[n+1];

    for (lint i=0;i<m;i++)
    {
        cin >> a;
        cin >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    q.push(1);
    p[1] = true;
    d[1] = 1;
    while (!q.empty())
    {
        u = q.front();
        q.pop();

        for (auto x:v[u])
        {
            if (p[x])
                continue;
            else
            {
                q.push(x);
                p[x] = true;
                d[x] = d[u] + 1;
            }
        }
    }

    if (!d[n])
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        cout << d[n] << endl;

        u = n;
        path[d[n]] = n;

        while (u!=1)
        {
            for (auto x:v[u])
                if (d[x] == d[u] - 1)
                {
                    path[d[x]] = x;
                    u = x;
                    break;
                }
        }

        for (lint i=1;i<=d[n];i++)
            cout << path[i] << " ";
        cout << endl;
    }

    delete[] v;
    delete[] p;
    delete[] d;
    delete[] path;

    return 0;
}
