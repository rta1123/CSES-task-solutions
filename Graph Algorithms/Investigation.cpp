#include <bits/stdc++.h>

using namespace std;

enum
{
    inf = 1000000000000000000,
    modulo = 1000000007,
};

typedef uint64_t ull;

ull min(ull u, ull v)
{
    if (u <= v)
        return u;
    else
        return v;
}

ull find_max_length_route(ull v, vector <pair<ull, ull>> *inv_adj, bool *p, ull *d, ull *L)
{
    if (p[v])
        return L[v];
    else
        p[v] = true;

    if (v == 1)
    {
        p[v] = 1;
        L[v] = 0;
        return L[v];
    }

    for (auto u : inv_adj[v])
        if ((d[u.first] + u.second) == d[v])
            L[v] = max(L[v], 1 + find_max_length_route(u.first, inv_adj, p, d, L));

    return L[v];
}


ull find_min_length_route(ull v, vector <pair<ull, ull>> *inv_adj, bool *p, ull *d, ull *l)
{
    if (p[v])
        return l[v];
    else
        p[v] = true;

    if (v == 1)
    {
        p[v] = 1;
        l[v] = 0;
        return l[v];
    }

    for (auto u : inv_adj[v])
        if ((d[u.first] + u.second) == d[v])
            l[v] = min(l[v], 1 + find_min_length_route(u.first, inv_adj, p, d, l));

    return l[v];
}

ull find_count_routes(ull v, vector <pair<ull, ull>> *inv_adj, bool *p, ull *d, ull *c)
{
    if (p[v])
        return c[v];
    else
        p[v] = true;

    if (v == 1)
    {
        p[v] = 1;
        c[v] = 1;
        return c[v];
    }

    for (auto u : inv_adj[v])
    {
        if ((d[u.first] + u.second) == d[v])
        {
            c[v] += find_count_routes(u.first, inv_adj, p, d, c);
            c[v] %= modulo;
        }
    }

    return c[v];
}

int main()
{
    ull n, m, u, v, w;
    priority_queue <pair<ull, ull>, vector <pair<ull, ull>>, greater<pair<ull, ull>>> q;
    vector <pair<ull, ull>> *adj, *inv_adj;
    bool *p;
    ull *d, *c, *l, *L;

    cin >> n;
    cin >> m;

    adj = new vector<pair<ull,ull>>[n+1];
    inv_adj = new vector<pair<ull,ull>>[n+1];
    p = new bool[n+1];
    d = new ull[n+1];
    c = new ull[n+1];
    l = new ull[n+1];
    L = new ull[n+1];

    for (ull i=1; i<=m; i++)
    {
        cin >> u;
        cin >> v;
        cin >> w;

        adj[u].push_back({v, w});
        inv_adj[v].push_back({u, w});
    }

    for (ull i=1; i<=n; i++)
    {
        p[i] = {};
        d[i] = inf;
        c[i] = {};
        l[i] = inf;
        L[i] = {};
    }

    {
        d[1] = 0;
        q.push({0, 1});

        while (!q.empty())
        {
            v = q.top().second;
            q.pop();

            if (p[v])
                continue;

            p[v] = true;
            for (auto x : adj[v])
            {
                u = x.first, w = x.second;
                if (d[v] + w < d[u])
                {
                    d[u] = d[v] + w;
                    q.push({d[u], u});
                }
            }
        }

        cout << d[n] << " ";
    }

    for (ull i=1; i<=n; i++)
        p[i] = {};

    cout << find_count_routes(n, inv_adj, p, d, c) << " ";

    for (ull i=1; i<=n; i++)
        p[i] = {};

    cout << find_min_length_route(n, inv_adj, p, d, l) << " ";

    for (ull i=1; i<=n; i++)
        p[i] = {};

    cout << find_max_length_route(n, inv_adj, p, d, L) << endl;

    delete[] adj;
    delete[] inv_adj;
    delete[] p;
    delete[] d;
    delete[] c;
    delete[] l;
    delete[] L;

    return 0;
}
