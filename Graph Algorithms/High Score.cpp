#include <bits/stdc++.h>

using namespace std;

typedef int64_t lint;

lint max(lint u, lint v)
{
    if (u>=v)
        return u;
    else
        return v;
}

void dfs(lint u, vector <lint> *adj, bool *path)
{
    path[u]=true;
    for (auto v:adj[u])
    {
        if (path[v])
            continue;
        dfs(v, adj, path);
    }
}

int main ()
{
    lint n, m, u, v, w, M;
    vector <lint> *adj;
    vector <tuple <lint, lint, lint>> e;
    lint *dist;
    bool *p, *path;
    bool cycle;

    cin >> n;
    cin >> m;

    adj = new vector <lint>[n+1];
    dist = new lint [n+1];
    p = new bool[n+1];
    path = new bool[n+1];

    for (lint i=1;i<=m; i++)
    {
        cin >> u;
        cin >> v;
        cin >> w;
        e.push_back({u, v, w});
        adj[v].push_back(u);
    }
    
    p[1] = true;
    for (lint i=1;i<=n-1;i++)
    {
        for (auto x:e)
        {
            tie (u, v, w) = x;
            if (!p[v] && p[u])
            {
                dist[v]=dist[u]+w;
                p[v]=true;
            }
            else
                if (p[v] && p[u])
                    dist[v] = max(dist[v], dist[u] + w);
        }
    
    }
    
    dfs(n, adj, path);
    
    cycle = false;
    for (auto x:e)
    {
        tie (u, v, w) = x;
        M = dist[v];
        if (!p[v] && p[u])
        {
              dist[v]=dist[u]+w;
              p[v]=true;
        }
        else
            if (p[v] && p[u])
                dist[v] = max(dist[v], dist[u] + w);
        
        if (dist[v]>M && path[v])
            cycle = true;
    }
    
    if (cycle)
        cout << -1;
    else
        cout << dist[n];

    delete[] adj;
    delete[] dist;
    delete[] p;
    delete[] path;

    return 0;
}
