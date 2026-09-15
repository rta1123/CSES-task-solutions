#include <bits/stdc++.h>

using namespace std;

enum {inf = 1000000};

int min(int u, int v)
{
    if (u <= v)
        return u;
    else
        return v;
}

int main()
{
    int n, m, *d, *a, D, u, v;
    vector <int> *adj;
    queue <int> q;
    bool *c, *p;

    cin >> n;
    cin >> m;

    d = new int[n+1];
    a = new int[n+1];
    c = new bool[n+1];
    adj = new vector<int>[n+1];
    p = new bool[n+1];

    for (int i=1; i<=m; i++)
    {
        cin >> u;
        cin >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    D = inf;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            p[j] = false;
            c[j] = false;
            d[j] = inf;
            a[j] = j;
        }

        for (auto v : adj[i])
            c[v] = true;

        for (int j=1; j<=n; j++)
            if (c[j])
                for (auto v : adj[j])
                    if (v != i)
                    {
                        if (!c[v])
                        {
                            a[v] = j;
                            if (!p[v])
                                q.push(v);
                            p[v] = true;
                        }

                        d[v] = 1;

                        if (c[v])
                            D = min(D, d[v] + 2);
                    }

        while (!q.empty())
        {
            u = q.front();
            q.pop();

            for (auto v : adj[u])
            {
                if (v == i)
                    continue;

                if (!c[v] and (d[v] > d[u] + 1))
                {
                    d[v] = d[u] + 1;
                    a[v] = a[u];
                    q.push(v);
                }
                else
                {
                    if (c[v])
                    {
                        if (a[v] != a[u])
                        {
                            d[a[v]] = min(d[a[v]], d[u] + 1);
                            d[a[u]] = min(d[a[u]], d[u] + 1);

                            D = min(D, d[a[u]] + 2);
                            D = min(D, d[a[v]] + 2);
                        }

                    }
                    else
                    {
                        if (a[v] != a[u])
                        {
                            d[a[v]] = min(d[a[v]], d[u] + d[v] + 1);
                            d[a[u]] = min(d[a[u]], d[u] + d[v] + 1);

                            D = min(D, d[a[u]] + 2);
                            D = min(D, d[a[v]] + 2);
                        }
                    }
                }
            }
        }
    }

    cout << ((D == inf) ? - 1 : D) << endl;

    delete[] d;
    delete[] a;
    delete[] adj;
    delete[] c;
    delete[] p;

    return 0;
}
