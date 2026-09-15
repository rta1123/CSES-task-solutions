#include <bits/stdc++.h>

using namespace std;

#define null nullptr

typedef int64_t ll;

struct sgt
{
    ll l, r, s;
    sgt *L, *R;

    sgt()
    {
        l = {};
        r = {};
        s = {};
        L = null;
        R = null;
    }

    sgt(ll a, ll b, ll *v)
    {
        l = a;
        r = b;

        if (a < b)
        {
            L = new sgt(a, (a + b)/2, v);
            R = new sgt(1 + (a + b)/2, b, v);
            s = L->s + R->s;
        }
        else
        {
            s = v[a];
            L = null;
            R = null;
        }
    }

    void free()
    {
        if (L != null)
            L->free();
        if (R != null)
            R->free();

        delete L;
        delete R;
    }

    void update(ll i, ll x)
    {
        if ((L == null) and (R == null) and l == i)
        {
            s = x;

            return;
        }

        if ((L != null) and (L->l <= i) and (L->r >= i))
        {
            L->update(i, x);

            if (R != null)
                s = R->s + L->s;
            else
                s = L->s;

            return;
        }

        if ((R != null) and (R->l <= i) and (R->r >= i))
        {
            R->update(i, x);

            if (L != null)
                s = R->s + L->s;
            else
                s = R->s;

            return;
        }
    }

    ll search(ll a, ll b)
    {
        ll ans = {};

        if ((l == a) and (r == b))
            return s;

        if ((L != null) and (L->l <= a) and (L->r >= a))
            ans += L->search(a, min(L->r, b));

        if ((R != null) and (R->l <= b) and (R->r >= b))
            ans += R->search(max(R->l, a), b);

        return ans;
    }

};

ll tt(ll u, vector <ll> *adj, ll *p, ll *c, bool *r, ll &ptr)
{
    ll pst = ptr;

    r[u] = true;
    p[u] = pst;

    ptr++;
    for (auto v : adj[u])
        if (!r[v])
            c[u] += tt(v, adj, p, c, r, ptr);

    return c[u] + 1;
}

int main()
{
    ll n, q, a, b, s, x, op, *v, *p, *c, ptr, *V;
    vector <ll> *adj;
    queue <ll> ans;
    bool *r;
    sgt *t;

    cin >> n;
    cin >> q;

    v = new ll[n+1];
    adj = new vector<ll>[n+1];
    p = new ll[n+1];
    c = new ll[n+1];
    V = new ll[n+1];
    r = new bool[n+1];

    for (ll i=1; i<=n; i++)
        cin >> v[i];

    for (ll i=1; i<=n-1; i++)
    {
        cin >> a;
        cin >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (ll i=1; i<=n; i++)
    {
        r[i] = false;
        c[i] = {};
    }

    ptr = 1; tt(1, adj, p, c, r, ptr);

    for (ll i=1; i<=n; i++)
        V[p[i]] = v[i];

    t = new sgt(1, n, V);

    for (ll i=1; i<=q; i++)
    {
        cin >> op;

        if (op == 1)
        {
            cin >> s;
            cin >> x;

            t->update(p[s], x);
        }
        else
        {
            cin >> s;

            ans.push(t->search(p[s], p[s] + c[s]));
        }
    }

    while (!ans.empty())
    {
        cout << ans.front() << endl;
        ans.pop();
    }

    t->free();
    delete t;
    delete[] v;
    delete[] adj;
    delete[] p;
    delete[] c;
    delete[] V;
    delete[] r;

    return 0;
}
