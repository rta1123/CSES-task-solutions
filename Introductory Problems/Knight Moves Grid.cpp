#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, **dist;
    vector <pair<int,int>> **adj;
    queue <pair<int,int>> q;

    cin >> n;

    adj = new vector<pair<int,int>>*[n+1];
    for (int i=0; i<=n; i++)
        adj[i] = new vector<pair<int,int>>[n+1];

    dist = new int*[n+1];
    for (int i=0; i<=n; i++)
        dist[i] = new int[n+1];

    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            dist[i][j] = -1;

    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
        {
            if (((i + 2) <= n) and ((j + 1) <= n))
            {
                adj[i][j].push_back({i+2, j+1});
                adj[i+2][j+1].push_back({i, j});
            }

            if (((i + 1) <= n) and ((j + 2) <= n))
            {
                adj[i][j].push_back({i+1, j+2});
                adj[i+1][j+2].push_back({i, j});
            }

            if (((i - 2) >= 1) and ((j + 1) <= n))
            {
                adj[i][j].push_back({i-2, j+1});
                adj[i-2][j+1].push_back({i, j});
            }

            if (((i - 1) >= 1) and ((j + 2) <= n))
            {
                adj[i][j].push_back({i-1, j+2});
                adj[i-1][j+2].push_back({i, j});
            }

            if (((i + 2) <= n) and ((j - 1) >= 1))
            {
                adj[i][j].push_back({i+2, j-1});
                adj[i+2][j-1].push_back({i, j});
            }

            if (((i + 1) <= n) and ((j - 2) >= 1))
            {
                adj[i][j].push_back({i+1, j-2});
                adj[i+1][j-2].push_back({i, j});
            }

            if (((i - 2) >= 1) and ((j - 1) >= 1))
            {
                adj[i][j].push_back({i-2, j-1});
                adj[i-2][j-1].push_back({i, j});
            }

            if (((i - 1) >= 1) and ((j - 2) >= 1))
            {
                adj[i][j].push_back({i-1, j-2});
                adj[i-1][j-2].push_back({i, j});
            }
        }

    dist[1][1] = 0;
    q.push({1,1});

    while (!q.empty())
    {
        auto u = q.front();
        q.pop();

        for (auto v : adj[u.first][u.second])
        {
            if (dist[v.first][v.second] == -1)
            {
                dist[v.first][v.second] =  dist[u.first][u.second] + 1;
                q.push(v);
            }
        }
    }

    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
            cout << dist[i][j] << " ";
        cout << endl;
    }

    for (int i=0; i<=n; i++)
        delete[] dist[i];
    delete[] dist;

    for (int i=0; i<=n; i++)
        delete[] adj[i];
    delete[] adj;

    return 0;
}
