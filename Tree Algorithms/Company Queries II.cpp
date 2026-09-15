#include <bits/stdc++.h>

using namespace std;

void dfs_b(int *e, int u, int vb, int *b)
{
    if (b[u] == -1)
        b[u] = vb;

    if (b[e[u]] == -1)
        dfs_b(e, e[u], vb, b);
}

int dfs_nb(int *e, int u, int *b, int *ba)
{
    if (ba[u] != -1)
        return ba[u];

    if (b[u] == 1)
    {
        ba[u] = e[u];
        return ba[u];
    }

    if (b[u] == b[e[u]])
        ba[u] = dfs_nb(e, e[u], b, ba);
    else
        ba[u] = e[u];

    return ba[u];
}

int lca(int u, int v, int *h, int *b, int *ba)
{
    stack <int> su {}, sv {};

    while (b[u] != 1)
    {
        su.push(u);
        u = ba[u];
    }
    su.push(u);

    while (b[v] != 1)
    {
        sv.push(v);
        v = ba[v];
    }
    sv.push(v);

    while (!su.empty() and !sv.empty())
    {
        if (b[su.top()] == b[sv.top()])
        {
            u = su.top();
            v = sv.top();

            su.pop();
            sv.pop();
        }
        else
            break;
    }

    if (h[u] < h[v])
        return u;
    else
        return v;
}

int main()
{
    int n, k, m, *e, *h, *p, *b, *ba, u, v;
    queue <int> ans, q;
    vector <int> *t;

    cin >> n;
    cin >> k;

    e = new int[n+1];
    h = new int[n+1];
    p = new int[n+1];
    b = new int[n+1];
    ba = new int[n+1];
    t = new vector<int>[n+1];

    e[1] = 1;
    for (int i=2; i<=n; i++)
        cin >> e[i];

    for (int i=2; i<=n; i++)
    {
        t[e[i]].push_back(i);
        t[i].push_back(e[i]);
    }

    for (int i=1; i<=n; i++)
    {
        p[i] = {};
        h[i] = -1;
        b[i] = -1;
        ba[i] = -1;
    }

    m = 1;
    p[m] = 1;
    h[1] = 1;
    q.push(1);
    m++;
    while (!q.empty())
    {
        auto u = q.front();
        q.pop();

        for (auto v : t[u])
            if (h[v] == -1)
            {
                p[m] = v;
                h[v] = h[u] + 1;
                q.push(v);
                m++;
            }
    }

    for (int i=n, j=1; i>=1; i--)
        if (b[p[i]] == -1)
        {
            dfs_b(e, p[i], j, b);
            j++;
        }

    for (int i=n; i>=1; i--)
        if (ba[p[i]] == -1)
            dfs_nb(e, p[i], b, ba);

    for (int i=1; i<=k; i++)
    {
        cin >> u;
        cin >> v;

        ans.push(lca(u, v, h, b, ba));
    }

    while (!ans.empty())
    {
        cout << ((ans.front() == 0) ? 1 : ans.front()) << endl;
        ans.pop();
    }

    delete[] e;
    delete[] h;
    delete[] p;
    delete[] b;
    delete[] ba;
    delete[] t;

    return 0;
}
