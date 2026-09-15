#include <bits/stdc++.h>

using namespace std;

enum
{
    modulo = 1000000007,
};

typedef int64_t ll;

ll max(ll u, ll v)
{
    if (u >= v)
        return u;
    else
        return v;
}

ll fe(ll a, ll x)
{
    ll e = 1;

    if (x == 0)
        return e;

    if (x == 1)
        return a;

    if (x % 2)
        e = a * fe(a, x - 1);
    else
    {
        e = fe(a, x / 2);
        e *= e;
    }

    e %= modulo;
    return e;
}

int main()
{
    ll n, k, *p, c, *P, *E, C;
    vector <ll> *d, ind;
    vector <pair <ll, ll>> *D;
    bool *q, *l;

    cin >> n;

    p = new ll[n+1];
    l = new bool[n+1];
    P = new ll[n+1];
    E = new ll[n+1];
    d = new vector<ll>[n+1];
    D = new vector<pair<ll ,ll>>[n+1];
    q = new bool[n+1];

    for (ll i=1; i<=n; i++)
        cin >> p[i];

    for (ll i=1; i<=n; i++)
    {
        E[i] = 0;
        D[i] = {};
        d[i] = {};
        q[i] = false;
        l[i] = false;
    }

    for (ll i=1; i<=n; i++)
    {
        if (!q[i])
        {
            c = 1;
            k = i;
            while (i != p[k])
            {
                c++;
                q[k] = true;
                k = p[k];
            }

            q[i] = true;
            l[c] = true;
        }
    }

    for (ll i=1; i<=n; i++)
        q[i] = false;

    P[1] = 0;
    for (ll i=2; i<=n; i++)
    {
        if (!q[i])
        {
            q[i] = true;
            P[i] = i;

            for (ll j=2*i; j<=n; j+=i)
            {
                q[j] = true;
                P[j] = i;
            }
        }
    }

    ind = {};
    for (ll i=1; i<=n; i++)
    {
        if (l[i])
        {
            k = i;
            while (P[k])
            {
                d[i].push_back(P[k]);
                k /= P[k];
            }

            ind.push_back(i);
        }
    }

    for (auto i : ind)
    {
        for (ll j=0; j<d[i].size(); j++)
        {
            if (D[i].empty())
            {
                D[i].push_back({d[i][j], 1});
                continue;
            }

            if (d[i][j] == D[i].back().first)
                D[i].back().second++;
            else
                D[i].push_back({d[i][j], 1});
        }
    }

    for (auto i : ind)
        for (auto j : D[i])
            E[j.first] = max(E[j.first], j.second);

    C = 1;
    for (ll i=1; i<=n; i++)
        if (E[i])
        {
            C *= fe(i,E[i]);
            C %= modulo;
        }

    cout << C << endl;

    delete[] p;
    delete[] l;
    delete[] P;
    delete[] E;
    delete[] d;
    delete[] D;
    delete[] q;

    return 0;
}
