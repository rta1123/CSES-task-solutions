#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;

ll max(ll u, ll v)
{
    if (u >= v)
        return u;
    else
        return v;
}

ll find_MCV(vector <int> *g, int u, ll *MCV, ll *K, bool *P)
{
    ll MV = {};
    P[u] = true;

    for (auto v : g[u])
        if (!P[v])
            MV = max(MV, find_MCV(g, v, MCV, K, P));
        else
            if (v != u)
                MV = max(MV, MCV[v]);

    MCV[u] += MV;

    return MCV[u];
}

int main()
{
    int n, m, u, v, *c, C;
    ll *k, *K, *MCV, max_coin;
    vector <int> *adj, *inv_adj, *g;
    queue <int> q, inv_q;
    bool *p, *inv_p, *P;

    cin >> n;
    cin >> m;

    k = new ll[n+1];
    adj = new vector<int>[n+1];
    inv_adj = new vector<int>[n+1];
    p = new bool[n+1];
    inv_p = new bool[n+1];
    c = new int[n+1];

    for (int i=1; i<=n; i++)
        cin >> k[i];

    for (int i=1; i<=m; i++)
    {
        cin >> u;
        cin >> v;

        adj[u].push_back(v);
        inv_adj[v].push_back(u);
    }

    C = 0;
    for (int i=1; i<=n; i++)
    {
        if (!p[i])
        {
            C++;

            p[i] = true;
            q.push(i);
            while (!q.empty())
            {
                u = q.front();
                q.pop();

                for (auto v : adj[u])
                    if (!p[v])
                    {
                        p[v] = true;
                        q.push(v);
                        inv_q.push(v);
                    }
            }

            inv_p[i] = true;
            q.push(i);
            while (!q.empty())
            {
                u = q.front();
                q.pop();

                for (auto v : inv_adj[u])
                    if (p[v] and !inv_p[v])
                    {
                        inv_p[v] = true;
                        q.push(v);
                        c[v] = C;
                    }
            }

            c[i] = C;

            while (!inv_q.empty())
            {
                u = inv_q.front();
                if (!inv_p[u])
                    p[u] = false;
                inv_q.pop();
            }
        }
    }

    K = new ll[C+1];
    g = new vector<int>[C+1];
    P = new bool[C+1];
    MCV = new ll[C+1];

    for (int i=1; i<=C; i++)
    {
        P[i] = false;
        K[i] = 0;
    }

    for (int i=1; i<=n; i++)
        K[c[i]] += k[i];

    for (int i=1; i<=n; i++)
        for (auto j : adj[i])
            g[c[i]].push_back(c[j]);

    for (int i=1; i<=C; i++)
        MCV[i] = K[i];

    for (int i=1; i<=C; i++)
        if (!P[i])
            find_MCV(g, i, MCV, K, P);

    max_coin = 0;
    for (int i=1; i<=C; i++)
        max_coin = max(max_coin, MCV[i]);

    cout << max_coin << endl;

    delete[] k;
    delete[] adj;
    delete[] inv_adj;
    delete[] p;
    delete[] inv_p;
    delete[] c;
    delete[] K;
    delete[] g;
    delete[] P;
    delete[] MCV;

    return 0;
}
