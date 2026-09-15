#include <bits/stdc++.h>

using namespace std;

void canc(int u, int *anc, vector <int> *adj)
{
    for (auto v : adj[u])
        if (anc[v] == -1)
        {
            anc[v] = u;
            canc(v, anc, adj);
        }
}

void cb(int u, int vb, int *b, int *anc)
{
    b[u] = vb;

    if (b[anc[u]] == -1)
        cb(anc[u], vb, b, anc);
}

int cba(int u, int *b, int *ba, int *anc)
{
    if (ba[u] != -1)
        return ba[u];

    if (b[u] == 1)
    {
        ba[u] = anc[u];
        return ba[u];
    }

    if (b[u] == b[anc[u]])
        ba[u] = cba(anc[u], b, ba, anc);
    else
        ba[u] = anc[u];

    return ba[u];
}

int lca(int u, int v, int *b, int *ba, int *h)
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
    int n, k, m, *b, *ba, *h, *p, *anc, u, v, w, d;
    vector <int> *adj;
    queue <int> ans, q;

    cin >> n;
    cin >> k;

    adj = new vector<int>[n+1];
    b = new int[n+1];
    ba = new int[n+1];
    h = new int[n+1];
    p = new int[n+1];
    anc = new int[n+1];

    for (int i=1; i<=n-1; i++)
    {
        cin >> u;
        cin >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i=1; i<=n; i++)
    {
        p[i] = -1;
        h[i] = -1;
        b[i] = -1;
        ba[i] = -1;
        anc[i] = -1;
    }

    m = 1;
    h[1] = 1;
    p[m] = 1;
    q.push(1);

    while (!q.empty())
    {
        auto u = q.front();
        q.pop();

        for (auto v : adj[u])
            if (h[v] == -1)
            {
                m++;
                p[m] = v;
                h[v] = h[u] + 1;
                q.push(v);
            }
    }

    anc[1] = 1; canc(1, anc, adj);

    for (int i=n, j=1; i>=1; i--)
        if (b[p[i]] == -1)
        {
            cb(p[i], j, b, anc);
            j++;
        }

    for (int i=n; i>=1; i--)
        if (ba[p[i]] == -1)
            cba(p[i], b, ba, anc);

    for (int i=1; i<=k; i++)
    {
        cin >> u;
        cin >> v;

        w = lca(u, v, b, ba, h);

        if ((w == u) or (w == v))
            d = abs(h[u] - h[v]);
        else
            d = abs(h[w] - h[u]) + abs(h[w] - h[v]);

        ans.push(d);
    }

    while (!ans.empty())
    {
        cout << ans.front() << endl;
        ans.pop();
    }

    delete[] adj;
    delete[] b;
    delete[] ba;
    delete[] h;
    delete[] p;
    delete[] anc;

    return 0;
}
