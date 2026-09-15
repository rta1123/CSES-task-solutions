#include <bits/stdc++.h>

using namespace std;

bool dfs(int u, int *c, vector <int> *adj)
{
    if (c[u] == -1)
    {
        c[u] = 1;

        for (auto v : adj[u])
            if (dfs(v, c, adj))
                return true;
    }
    else
        if (c[u] == 1)
        {
            c[u] = 3;
            return true;
        }

    c[u] = 2;

    return false;
}

bool dfs2(int u, int v, int *c, vector <int> *adj, stack <int> &s)
{
    if (u == v)
        return true;

    c[u] = 1;

    for (auto w : adj[u])
        if (c[w] == -1)
        {
            if (dfs2(w, v, c, adj, s))
            {
                s.push(u);
                return true;
            }
        }

    return false;
}

int main()
{
    int n, m, u, v, *c;
    vector <int> *adj;
    stack <int> s;

    cin >> n;
    cin >> m;

    adj = new vector<int>[n+1];
    c = new int[n+1];

    for (int i=1; i<=m; i++)
    {
        cin >> u;
        cin >> v;
        adj[u].push_back(v);
    }

    for (int i=1; i<=n; i++)
        c[i] = -1;

    for (int i=1; i<=n; i++)
        if (c[i] == -1)
            if (dfs(i, c, adj))
                break;

    v = {};
    for (int i=1; i<=n; i++)
        if (c[i] == 3)
        {
            v = i;
            break;
        }

    if (v)
    {
        for (int i=1; i<=n; i++)
            c[i] = -1;

        s.push(v);
        for (auto u : adj[v])
            if (c[u] == -1)
                if (dfs2(u, v, c, adj, s))
                    break;
        s.push(v);

        cout << s.size() << endl;
        while (!s.empty())
        {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }
    else
        cout << "IMPOSSIBLE" << endl;

    delete[] adj;
    delete[] c;

    return 0;
}
