#include <bits/stdc++.h>

using namespace std;

#define inf 1000000000

int min(int u, int v)
{
    if (u <= v)
        return u;
    else
        return v;
}

int edit_distance(int i, int j, int n, int m, string &p, string &q, int **dist)
{
    int k = inf;

    if ((i == n) and (j == m))
    {
        if (p[i] != q[j])
            return 1;
        else
            return 0;
    }

    if (dist[i][j] != -1)
        return dist[i][j];

    if (i == n)
    {
        if (p[i] != q[j])
        {
            dist[i][j] = edit_distance(i, j+1, n, m, p, q, dist) + 1;
            return dist[i][j];
        }
        else
        {
            dist[i][j] = m - j;
            return dist[i][j];
        }
    }

    if (j == m)
    {
        if (p[i] != q[j])
        {
            dist[i][j] = edit_distance(i+1, j, n, m, p, q, dist) + 1;
            return dist[i][j];
        }
        else
        {
            dist[i][j] = n - i;
            return dist[i][j];
        }
    }

    if (p[i] != q[j])
    {
        k = min(k, edit_distance(i, j+1, n, m, p, q, dist) + 1);
        k = min(k, edit_distance(i+1, j, n, m, p, q, dist) + 1);
        k = min(k, edit_distance(i+1, j+1, n, m, p, q, dist) + 1);
    }
    else
    {
        k = min(k, edit_distance(i, j+1, n, m, p, q, dist) + 1);
        k = min(k, edit_distance(i+1, j, n, m, p, q, dist) + 1);
        k = min(k, edit_distance(i+1, j+1, n, m, p, q, dist));
    }

    dist[i][j] = k;

    return dist[i][j];
}

int main()
{
    int n, m, **dist;
    string p, q;

    cin >> p;
    cin >> q;

    n = p.length();
    m = q.length();

    p = "p" + p;
    q = "q" + q;

    dist = new int*[n+1];
    for (int i=0; i<=n; i++)
        dist[i] = new int[m+1];

    for (int i=0; i<=n; i++)
        for (int j=0; j<=m; j++)
            dist[i][j] = -1;

    cout << edit_distance(1, 1, n, m, p, q, dist) << endl;

    for (int i=0; i<=n; i++)
        delete[] dist[i];
     delete[] dist;

    return 0;
}
