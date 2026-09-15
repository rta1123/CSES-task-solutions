#include <bits/stdc++.h>
 
using namespace std;
 
int k = 0;
 
void toposort(int u, vector<int> *adj, bool *p, int *N)
{
    for (auto v : adj[u])
    {
        if (p[v])
            continue;
 
        p[v] = true;
 
        toposort(v, adj, p, N);
    }
 
    N[u] = k;
    k--;
}
 
int max(int u, int v)
{
    if (u >= v)
        return u;
    else
        return v;
}
 
bool find_path(int u, vector<int> *adj_rev, int *dist, int *N, queue<int> &path)
{
    if (u == 1)
        return true;
 
    for (auto v : adj_rev[u])
        if ((dist[N[v]] + 1) == dist[N[u]])
            if (find_path(v, adj_rev, dist, N, path))
            {
                path.push(v);
                return true;
            }
 
    return false;
}
 
int main()
{
    int n, m, a, b, *dist, *N;
    vector <int> *adj, *adj_topo, *adj_rev;
    queue <int> path;
    bool *p;
 
    cin >> n;
    cin >> m;
 
    dist = new int[n+1];
    N = new int[n+1];
    adj = new vector<int>[n+1];
    adj_topo = new vector<int>[n+1];
    adj_rev = new vector<int>[n+1];
    p = new bool[n+1];
 
    for (int i=1; i<=n; i++)
    {
        dist[i] = 0;
        N[i] = 0;
        p[i] = 0;
    }
 
    for (int i=1; i<=m; i++)
    {
        cin >> a;
        cin >> b;
 
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }
 
    k = n;
    toposort(1, adj, p, N);
 
    for (int i=1; i<=n; i++)
        if (N[i])
            for (auto v : adj[i])
                adj_topo[N[i]].push_back(N[v]);
 
    for (int i=1; i<=n; i++)
        if (!adj_topo[i].empty())
            for (auto v : adj_topo[i])
                dist[v] = max(dist[v], dist[i] + 1);
 
    if (dist[N[n]] == 0)
        cout << "IMPOSSIBLE" << endl;
    else
    {
        find_path(n, adj_rev, dist, N, path);
        path.push(n);
 
        cout << dist[N[n]] + 1 << endl;
 
        while (!path.empty())
        {
            cout << path.front() << ' ';
            path.pop();
        }
 
        cout << endl;
    }
 
    delete[] dist;
    delete[] N;
    delete[] p;
    delete[] adj;
    delete[] adj_topo;
    delete[] adj_rev;
 
    return 0;
}
