#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;

ll cncn(ll u, vector<ll> *adj, bool *p, ll *c)
{
    p[u] = true;

    for (auto v : adj[u])
        if (!p[v])
            c[u] += 1 + cncn(v, adj, p, c);

    return c[u];
}

ll cnd(ll u, vector<ll> *adj, bool *p, ll *d, ll *c)
{
    p[u] = true;

    for (auto v : adj[u])
        if (!p[v])
            d[u] = d[u] + 1 + c[v] + cnd(v, adj, p, d, c);

    return d[u];
}

void cnD(ll u, vector<ll> *adj, bool *p, ll *d, ll *D, ll *c, ll *C)
{
    p[u] = true;

    for (auto v : adj[u])
        if (!p[v])
        {
            D[v] = C[v] + (D[u] - d[v] - c[v] - 1);
            D[v] += d[v];

            cnD(v, adj, p, d, D, c, C);
        }
}

int main()
{
    ll n, a, b, *c, *C, *d, *D;
    vector <ll> *adj;
    bool *p;

    cin >> n;

    adj = new vector<ll>[n+1];
    p = new bool[n+1];
    c = new ll[n+1];
    C = new ll[n+1];
    d = new ll[n+1];
    D = new ll[n+1];

    for (ll i=1; i<=n-1; i++)
    {
        cin >> a;
        cin >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (ll i=1; i<=n; i++)
    {
        p[i] = {};
        c[i] = {};
    }

    cncn(1, adj, p, c);

    for (ll i=1; i<=n; i++)
    {
        p[i] = {};
        d[i] = {};
    }

    cnd(1, adj, p, d, c);

    for (ll i=1; i<=n; i++)
    {
        p[i] = {};
        C[i] = n - 1 - c[i];
        D[i] = {};
    }

    D[1] = d[1];
    cnD(1, adj, p, d, D, c, C);

    for (ll i=1; i<=n; i++)
        cout << D[i] << " ";
    cout << endl;

    delete[] adj;
    delete[] p;
    delete[] c;
    delete[] C;
    delete[] d;
    delete[] D;

    return 0;
}
