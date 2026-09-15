#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, u, v;
    vector <int> *adj;
    vector <int> *inv_adj;
    bool exist_solution, *p;
    queue<int> q;

    cin >> n;
    cin >> m;

    adj = new vector<int>[n+1];
    inv_adj = new vector<int>[n+1];
    p = new bool[n+1];

    for (int i=1; i<=m; i++)
    {
        cin >> u;
        cin >> v;

        adj[u].push_back(v);
    }

    for (int i=1; i<=n; i++)
        for (auto v : adj[i])
            inv_adj[v].push_back(i);

    for (int i=1; i<=n; i++)
        p[i] = false;

    exist_solution = true;
    q.push(1);
    p[1] = true;
    while (!q.empty())
    {
        u = q.front();
        q.pop();

        for (auto v : adj[u])
            if (!p[v])
            {
                q.push(v);
                p[v] = true;
            }
    }

    for (int i=1; i<=n; i++)
        if (!p[i])
        {
            u = 1;
            v = i;
            exist_solution = false;
            break;
        }

    if (!exist_solution)
    {
        cout << "NO" << endl;
        cout << u << " " << v << endl;
    }
    else
    {
        for (int i=1; i<=n; i++)
            p[i] = false;

        q.push(1);
        p[1] = true;
        while (!q.empty())
        {
            u = q.front();
            q.pop();

            for (auto v : inv_adj[u])
                if (!p[v])
                {
                    q.push(v);
                    p[v] = true;
                }
        }

        for (int i=1; i<=n; i++)
            if (!p[i])
            {
                u = i;
                v = 1;
                exist_solution = false;
                break;
            }

        if (!exist_solution)
        {
            cout << "NO" << endl;
            cout << u << " " << v << endl;
        }
        else
            cout << "YES" << endl;
    }

    delete[] adj;
    delete[] inv_adj;
    delete[] p;

    return 0;
}
