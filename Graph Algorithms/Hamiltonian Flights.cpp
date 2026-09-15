#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;

enum {modulo = 1000000007};

ll C(int u, int v, vector <int> *adj, ll **c, int s)
{
    ll ans = 0;

    if (u == v)
    {
        if (s == 0)
            return 1;
        else
            return 0;
    }

    if (c[u][s] != -1)
        return c[u][s];

    for (auto w : adj[u])
    {
        if ((w != u) and (s & (1 << (w - 1))))
        {
            ans += C(w, v, adj, c, s ^ (1 << (w - 1)));
            ans %= modulo;
        }
    }

    c[u][s] = ans;
    return c[u][s];
}

int main()
{
    int n, m, u, v, s;
    vector <int> *adj;
    ll **c;

    cin >> n;
    cin >> m;

    adj = new vector<int>[n+1];
    c = new ll*[n+1];
    for (int i=0; i<=n; i++)
        c[i] = new ll[(1<<n)];

    for (int i=1; i<=m; i++)
    {
        cin >> u;
        cin >> v;

        adj[u].push_back(v);
    }

    s = 0;
    for (int i=0; i<n; i++)
        s |= (1 << i);

    for (int i=0; i<=n; i++)
        for (int j=0; j<(1<<n); j++)
            c[i][j] = -1;

    cout << C(1, n, adj, c, s ^ 1) << endl;

    delete[] adj;

    for (int i=0; i<=n; i++)
        delete[] c[i];
    delete[] c;

    return 0;
}
