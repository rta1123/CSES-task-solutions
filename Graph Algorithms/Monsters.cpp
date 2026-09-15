#include <bits/stdc++.h>

using namespace std;

enum {inf = 1000000};

bool find_path(pair <int, int> u, vector <pair<int,int>> **adj, char **map, stack <pair<int, int>> &path, pair<int,int> **s, bool **p)
{
    p[u.first][u.second] = true;
    if (map[u.first][u.second] == 'A')
    {
        path.push({u.first, u.second});
        return true;
    }

    for (auto v : adj[u.first][u.second])
    {
        if (!p[v.first][v.second] and (s[v.first][v.second].first == 1) and ((s[v.first][v.second].second + 1) == s[u.first][u.second].second))
        {
            if (find_path(v, adj,  map, path, s, p))
            {
                path.push({u.first, u.second});
                return true;
            }
        }
    }

    return false;
}

int main()
{
    int n, m;
    char **map;
    vector <pair<int,int>> **adj;
    pair<int,int> **s;
    bool **p;
    bool exist_path;
    pair <int, int> E, A;
    queue <pair<int, int>> q;
    stack <pair<int,int>> path, inv_path;

    cin >> n;
    cin >> m;

    map = new char*[n+1];
    for (int i=0; i<=n; i++)
        map[i] = new char[m+1];

    adj = new vector<pair<int,int>>*[n+1];
    for (int i=0; i<=n; i++)
        adj[i] = new vector<pair<int,int>>[m+1];

    s = new pair<int,int>*[n+1];
    for (int i=0; i<=n; i++)
        s[i] = new pair<int,int>[m+1];

    p = new bool*[n+1];
    for (int i=0; i<=n; i++)
        p[i] = new bool[m+1];

    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            cin >> map[i][j];

    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        {
            if ((i>=1) and (i<=n) and (j>=1) and (j<=m-1) and (map[i][j] != '#') and (map[i][j+1] != '#'))
            {
                adj[i][j].push_back({i, j+1});
                adj[i][j+1].push_back({i, j});
            }

            if ((i>=1) and (i<=n-1) and (j>=1) and (j<=m) and (map[i][j] != '#') and (map[i+1][j] != '#'))
            {
                adj[i][j].push_back({i+1, j});
                adj[i+1][j].push_back({i, j});
            }
        }

    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        {
            p[i][j] = false;

            if (map[i][j] == 'M')
            {
                s[i][j] = {0, 0};
                q.push({i, j});
            }
            else
                if (map[i][j] == 'A')
                {
                    s[i][j] = {1, 0};
                    A = {i, j};
                }
                else
                    s[i][j] = {-1, inf};
        }

    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            p[i][j] = false;

    while (!q.empty())
    {
        auto u = q.front();
        q.pop();

        for (auto v : adj[u.first][u.second])
            if  (!p[v.first][v.second])
            {
                p[v.first][v.second] = true;

                if (s[u.first][u.second].second + 1 < s[v.first][v.second].second)
                    s[v.first][v.second] = {s[u.first][u.second].first, s[u.first][u.second].second + 1};

                q.push(v);
            }
    }

    q.push(A);
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            p[i][j] = false;

    while (!q.empty())
    {
        auto u = q.front();
        q.pop();

        for (auto v : adj[u.first][u.second])
            if  (!p[v.first][v.second])
            {
                p[v.first][v.second] = true;

                if (s[u.first][u.second].second + 1 < s[v.first][v.second].second)
                    s[v.first][v.second] = {s[u.first][u.second].first, s[u.first][u.second].second + 1};

                q.push(v);
            }
    }

    exist_path = false;
    for (int i=1; i<=n; i++)
    {
        if (s[i][1].first == 1)
        {
            exist_path = true;
            E = {i, 1};
            break;
        }

        if (s[i][m].first == 1)
        {
            exist_path = true;
            E = {i, m};
            break;
        }
    }

    for (int j=1; j<=m; j++)
    {
        if (s[1][j].first == 1)
        {
            exist_path = true;
            E = {1, j};
            break;
        }

        if (s[n][j].first == 1)
        {
            exist_path = true;
            E = {n, j};
            break;
        }
    }

    if (!exist_path)
        cout << "NO" <<  endl;
    else
    {
        cout << "YES" << endl;

        for (int i=1; i<=n; i++)
            for (int j=1; j<=m; j++)
                p[i][j] = false;

        find_path(E, adj, map, inv_path, s, p);

        cout << inv_path.size() - 1 << endl;

        while (!inv_path.empty())
        {
            path.push(inv_path.top());
            inv_path.pop();
        }

        auto u = path.top();
        path.pop();

        while (!path.empty())
        {
            auto v = path.top();
            path.pop();

            if (u.first == v.first and u.second > v.second)
                cout << "L";
            if (u.first == v.first and u.second < v.second)
                cout << "R";
            if (u.first > v.first and u.second == v.second)
                cout << "U";
            if (u.first < v.first and u.second == v.second)
                cout << "D";

            u = v;
        }

        cout << endl;
    }

    for (int i=0; i<=n; i++)
        delete[] map[i];
    delete[] map;

    for (int i=0; i<=n; i++)
        delete[] adj[i];
    delete[] adj;

    for (int i=0; i<=n; i++)
        delete[] s[i];
    delete[] s;

    for (int i=0; i<=n; i++)
        delete[] p[i];
    delete[] p;

    return 0;
}
