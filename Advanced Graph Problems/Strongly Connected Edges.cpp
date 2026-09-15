#include <bits/stdc++.h>

using namespace std;

void dfs(int u, vector<int> *adj, set<pair<int,int>> &e, queue <pair<int,int>> &g, stack <int> &s,  bool *p)
{
    p[u] = true;

    for (auto v : adj[u])
        if (!p[v])
        {
            s.push(v);
            g.push({u, v});
            e.insert({u, v});
            e.insert({v, u});
            dfs(v, adj, e, g, s, p);
        }
}

int main()
{
    int n, m, u, v;
    stack <int> s;
    queue <int> q;
    vector <int> *adj, *rev_adj;
    set <pair<int,int>> e;
    queue <pair<int, int>> g;
    bool ans, *p, *r;

    cin >> n;
    cin >> m;

    adj = new vector<int>[n+1];
    rev_adj = new vector<int>[n+1];
    p = new bool[n+1];
    r = new bool[n+1];

    for (int i=1; i<=m; i++)
    {
        cin >> u;
        cin >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i=1; i<=n; i++)
    {
        p[i] = false;
        r[i] = false;
    }

    dfs(1, adj, e, g, s, p);

    ans = true;
    for (int i=1; i<=n; i++)
        if (!p[i])
        {
            ans = false;
            break;
        }

    if (!ans)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        while (!s.empty())
        {
            u = s.top();
            s.pop();

            for (auto v : adj[u])
                if ((e.find({u, v}) == e.end()))
                {
                    g.push({u, v});
                    e.insert({u, v});
                    e.insert({v, u});
                }
        }

        for (int i=1; i<=n; i++)
        {
            p[i] = false;
            r[i] = false;
            adj[i].clear();
        }

        m = g.size();
        for (int i=1; i<=m; i++)
        {
            u = g.front().first;
            v = g.front().second;
            g.pop();

            adj[u].push_back(v);
            rev_adj[v].push_back(u);
        }

        p[1] = true;
        q.push(1);
        while (!q.empty())
        {
            u = q.front();
            q.pop();

            for (auto v : adj[u])
                if (!p[v])
                {
                    p[v] = true;
                    q.push(v);
                }
        }

        for (int i=1; i<=n; i++)
            if (!p[i])
            {
                ans = false;
                break;
            }

        if (!ans)
        {
            cout << "IMPOSSIBLE" << endl;
        }
        else
        {
            r[1] = true;
            q.push(1);
            while (!q.empty())
            {
                u = q.front();
                q.pop();

                for (auto v : rev_adj[u])
                    if (!r[v])
                    {
                        r[v] = true;
                        q.push(v);
                    }
            }

            for (int i=1; i<=n; i++)
                if (!r[i])
                {
                    ans = false;
                    break;
                }

            if (!ans)
            {
                cout << "IMPOSSIBLE" << endl;
            }
            else
            {
                for (int i=1; i<=n; i++)
                    for (auto v : adj[i])
                        cout << i << " " << v << endl;
            }
        }
    }

    delete[] adj;
    delete[] rev_adj;
    delete[] p;
    delete[] r;

    return 0;
}
