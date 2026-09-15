#include <bits/stdc++.h>

using namespace std;

int max(int u, int v)
{
    if (u >= v)
        return u;
    else
        return v;
}

void find_dist(int w, int *d, vector <int> *adj)
{
    queue <int> q {};

    d[w] = 0;
    q.push(w);
    while (!q.empty())
    {
        auto u = q.front();
        q.pop();

        for (auto v : adj[u])
            if (d[v] == -1)
            {
                d[v] = d[u] + 1;
                q.push(v);
            }
    }
}

int main()
{
    int n, u, v, w, *D, *D1, *D2;
    vector <int> *adj;

    cin >> n;

    adj = new vector<int>[n+1];
    D = new int[n+1];
    D1 = new int[n+1];
    D2 = new int[n+1];

    for (int i=1; i<=n-1; i++)
    {
        cin >> u;
        cin >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i=1; i<=n; i++)
    {
        D[i] = -1;
        D1[i] = -1;
        D2[i] = -1;
    }

    w = 1;

    find_dist(w, D, adj);
    for (int i=1; i<=n; i++)
        if (D[i] > D[w])
            w = i;

    find_dist(w, D1, adj);
    for (int i=1; i<=n; i++)
        if (D1[i] > D1[w])
            w = i;

    find_dist(w, D2, adj);

    for (int i=1; i<=n; i++)
        D[i] = max(D1[i], D2[i]);

    for (int i=1; i<=n; i++)
        cout << D[i] << " ";
    cout << endl;

    delete[] adj;
    delete[] D;
    delete[] D1;
    delete[] D2;

    return 0;
}
