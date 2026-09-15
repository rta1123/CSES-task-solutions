#include <bits/stdc++.h>

using namespace std;

enum { inf = 1000000000000000 };

typedef int64_t ll;

ll min(ll u, ll v)
{
    if (u <= v)
        return u;
    else
        return v;
}

int main()
{
    int n, m;
    ll u, v, w;
    vector <pair<ll, ll>> *adj;
    priority_queue <pair<ll, ll>, vector<pair<ll,ll>>, greater<pair<ll, ll>>> q;
    ll *dist, *dist_discount;
    bool *p;

    cin >> n;
    cin >> m;

    adj = new vector<pair<ll,ll>>[n+1];
    dist = new ll[n+1];
    dist_discount = new ll[n+1];
    p = new bool[n+1];

    for (int i=1; i<=m; i++)
    {
        cin >> u;
        cin >> v;
        cin >> w;

        adj[u].push_back({w, v});
    }

    for (int i=1; i<=n; i++)
    {
        dist[i] = inf;
        p[i] = false;
    }

    dist[1] = 0;
    q.push({dist[1], 1});
    while (!q.empty())
    {
        u = q.top().second;
        q.pop();

        if (p[u])
            continue;
        p[u] = true;

        for (auto e : adj[u])
        {
            tie(w, v) = e;

            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                q.push({dist[v], v});
            }
        }
    }

    for (int i=1; i<=n; i++)
    {
        dist_discount[i] = inf;
        p[i] = false;
    }

    dist_discount[1] = 0;
    q.push({dist_discount[1], 1});
    while (!q.empty())
    {
        u = q.top().second;
        q.pop();

        if (p[u])
            continue;
        p[u] = true;

        for (auto e : adj[u])
        {
            tie(w, v) = e;

            if (dist_discount[v] > min(dist[u] + w / 2, dist_discount[u] + w))
            {
                dist_discount[v] = min(dist[u] + w / 2, dist_discount[u] + w);
                q.push({dist_discount[v], v});
            }
        }
    }

    cout << dist_discount[n] << endl;

    delete[] p;
    delete[] dist_discount;
    delete[] dist;
    delete[] adj;

    return 0;
}
