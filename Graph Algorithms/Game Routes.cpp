#include <bits/stdc++.h>

using namespace std;

enum
{
    modulo = 1000000007,
};

int C(vector <int> *inv_adj, int v, int *c, bool *p)
{
    if (p[v])
        return c[v];

    if (v == 1)
    {
        p[v] = true;
        c[v] = 1;
        return c[v];
    }

    c[v] = {};
    for (auto u : inv_adj[v])
    {
        c[v] += C(inv_adj, u, c, p);
        c[v] %= modulo;
    }

    p[v] = true;
    return c[v];
}

int main()
{
    int n, m, a, b, *c;
    vector <int> *inv_adj;
    bool *p;

    cin >> n;
    cin >> m;

    c = new int[n+1];
    inv_adj = new vector<int>[n+1];
    p = new bool[n+1];

    for (int i=1; i<=m; i++)
    {
        cin >> a;
        cin >> b;

        inv_adj[b].push_back(a);
    }

    for (int i=1; i<=n; i++)
        p[i] = 0;

    cout << C(inv_adj, n, c, p) << endl;

    delete[] c;
    delete[] inv_adj;
    delete[] p;

    return 0;
}
