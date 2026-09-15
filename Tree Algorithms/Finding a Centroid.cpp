#include <bits/stdc++.h>

using namespace std;

int dfs1(int u, vector<int> *adj, bool *p, int *c)
{
    p[u] = true;

    for (auto v : adj[u])
        if (!p[v])
            c[u] += 1 + dfs1(v, adj, p, c);

    return c[u];
}

void dfs2(int u, int n, vector<int> *adj, bool *p, int *c, int *C)
{
    int s = {};

    p[u] = true;

    for (auto v : adj[u])
        if (!p[v])
        {
            C[u] = max(C[u], c[v] + 1);
            s += c[v] + 1;
        }

    C[u] = max(C[u], n - 1 - s);

    for (auto v : adj[u])
        if (!p[v])
            dfs2(v, n, adj, p, c, C);
}

int main()
{
    int n, a, b, *c, *C;
    vector <int> *adj;
    bool *p;

    cin >> n;

    adj = new vector<int>[n+1];
    p = new bool[n+1];
    c = new int[n+1];
    C = new int[n+1];

    for (int i=1; i<=n-1; i++)
    {
        cin >> a;
        cin >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i=1; i<=n; i++)
    {
        p[i] = false;
        c[i] = 0;
    }

    dfs1(1, adj, p, c);

    for (int i=1; i<=n; i++)
    {
        p[i] = false;
        C[i] = 0;
    }

    dfs2(1, n, adj, p, c, C);

    for (int i=1; i<=n; i++)
        if (C[i] <= n/2)
        {
            cout << i << endl;
            break;
        }

    delete[] adj;
    delete[] p;
    delete[] c;
    delete[] C;

    return 0;
}
