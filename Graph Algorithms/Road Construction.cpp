#include <bits/stdc++.h>

using namespace std;

std::ostream& operator <<(std::ostream &os, const pair <int, int> &arg)
{
    return (os << arg.first << " " << arg.second << endl);
}

int max(int u, int v)
{
    if (u >= v)
        return u;
    else
        return v;
}

bool Find(int *p, int v, int u)
{
    while (v != p[v])
    {
        p[v] = p[p[v]];
        v = p[v];
    }

    while (u != p[u])
    {
        p[u] = p[p[u]];
        u = p[u];
    }

    if (u == v)
        return true;
    else
        return false;
}

void Union(int *p, int *s, int *h, int u, int v, int &k, int &S)
{
    int Pu, Pv;

    if (Find(p, u, v))
        return;

    Pu = u;
    while (Pu != p[Pu])
        Pu = p[Pu];

    Pv = v;
    while (Pv != p[Pv])
        Pv = p[Pv];

    k--;
    if (h[Pu] > h[Pv])
    {
        p[Pv] = Pu;
        s[Pu] += s[Pv];
        S = s[Pu];
    }
    else
        if (h[Pu] < h[Pv])
        {
            p[Pu] = Pv;
            s[Pv] += s[Pu];
            S = s[Pv];
        }
        else
        {
            p[Pv] = Pu;
            h[Pu]++;
            s[Pu] += s[Pv];
            S = s[Pu];
        }
}

int main()
{
    int n, m, u, v, k, S, maxS, *s, *p, *h;
    queue <pair<int, int>> ans;

    cin >> n;
    cin >> m;

    p = new int[n+1];
    s = new int[n+1];
    h = new int[n+1];

    k = n;
    for (int i=1; i<=n; i++)
    {
        p[i] = i;
        s[i] = 1;
        h[i] = 1;
    }

    maxS = -1;
    S = 1;
    for (int i=1; i<=m; i++)
    {
        cin >> u;
        cin >> v;

        Union(p, s, h, u, v, k, S);

        maxS = max(maxS, S);

        ans.push({k, maxS});
    }

    while (!ans.empty())
    {
        cout << ans.front();
        ans.pop();
    }

    delete[] p;
    delete[] s;
    delete[] h;

    return 0;
}
