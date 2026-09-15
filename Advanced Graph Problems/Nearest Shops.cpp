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
    int n, m, k, *s, *d, *p, u, v;
    vector <int> *adj;
    bool *a;
    queue <int> q;

    cin >> n;
    cin >> m;
    cin >> k;

    adj = new vector <int>[n+1];
    s = new int[k+1];
    d = new int[n+1];
    a = new bool[n+1];
    p = new int[n+1];

    for (int i=1; i<=n; i++)
    {
        a[i] = false;
        d[i] = inf;
        p[i] = i;
    }

    for (int i=1; i<=k; i++)
    {
        cin >> s[i];
        a[s[i]] = true;
    }

    for (int i=1; i<=m; i++)
    {
        cin >> u;
        cin >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i=1; i<=k; i++)
    {
        for (auto v : adj[s[i]])
        {
            d[v] = 1;

            if (!a[v])
            {
                p[v] = p[s[i]];
                q.push(v);
            }
        }
    }

    while (!q.empty())
    {
        u = q.front();
        q.pop();

        for (auto v : adj[u])
        {
            if (!a[v] and (d[v] > d[u] + 1))
            {
                p[v] = p[u];
                d[v] = d[u] + 1;
                q.push(v);
            }
            else
            {
                if (a[v])
                {
                    if (p[v] != p[u])
                    {
                        d[p[u]] = min(d[p[u]], d[u] + 1);
                        d[p[v]] = min(d[p[v]], d[u] + 1);
                    }
                }
                else
                {
                    if (p[v] != p[u])
                    {
                        d[p[u]] = min(d[p[u]], d[u] + d[v] + 1);
                        d[p[v]] = min(d[p[v]], d[u] + d[v] + 1);
                    }
                }
            }
        }
    }

    for (int i=1; i<=n; i++)
        if (d[i] == inf)
            d[i] = -1;

    for (int i=1; i<=n; i++)
        cout << d[i] << " ";
    cout << endl;

    delete[] adj;
    delete[] s;
    delete[] d;
    delete[] a;
    delete[] p;

    return 0;
}
