#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;

#define null nullptr

struct sgt
{
    ll l, r, pfx, sfx, sum, max_sum;
    sgt *L, *R;

    sgt()
    {
        L = {};
        R = {};
        l = {};
        r = {};
        pfx = {};
        sfx = {};
        sum = {};
        max_sum = {};
    }

    sgt(ll a, ll b, ll *x)
    {
        l = a;
        r = b;

        if (a < b)
        {
            L = new sgt(a, (a + b)/2, x);
            R = new sgt(1 + (a + b) / 2, b, x);
            sum = L->sum + R->sum;
            pfx = max(L->pfx, max(L->sum + R->pfx, sum));
            sfx = max(R->sfx, max(R->sum + L->sfx, sum));
            max_sum = max(L->max_sum, max(R->max_sum, max(sum, max(L->sfx + R->sum, max(R->pfx + L->sum, L->sfx + R->pfx)))));
        }
        else
        {
            L = {};
            R = {};
            pfx = x[a];
            sfx = x[a];
            sum = x[a];
            max_sum = x[a];
        }
    }

    void update(ll k, ll u)
    {
        if ((L == null) and (R == null) and (l == k) and (r == k))
        {
            sum = u;
            pfx = u;
            sfx = u;
            max_sum = u;
            return;
        }

        if ((L != null) and (L->l <= k) and (L->r >= k))
        {
            L->update(k, u);
            sum = L->sum + R->sum;
            pfx = max(L->pfx, max(L->sum + R->pfx, sum));
            sfx = max(R->sfx, max(R->sum + L->sfx, sum));
            max_sum = max(L->max_sum, max(R->max_sum, max(sum, max(L->sfx + R->sum, max(R->pfx + L->sum, L->sfx + R->pfx)))));
            return;
        }

        if ((R != null) and (R->l <= k) and (R->r >= k))
        {
            R->update(k, u);
            sum = L->sum + R->sum;
            pfx = max(L->pfx, max(L->sum + R->pfx, sum));
            sfx = max(R->sfx, max(R->sum + L->sfx, sum));
            max_sum = max(L->max_sum, max(R->max_sum, max(sum, max(L->sfx + R->sum, max(R->pfx + L->sum, L->sfx + R->pfx)))));
            return;
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

};

int main()
{
    ll n, m, k, u, *x;
    sgt *t {};
    queue <ll> ans;

    cin >> n;
    cin >> m;

    x = new ll[n+1];

    for (ll i=1; i<=n; i++)
        cin >> x[i];

    t = new sgt(1, n, x);

    for (ll i=1; i<=m; i++)
    {
        cin >> k;
        cin >> u;

        t->update(k, u);
        ans.push(((t->max_sum < 0) ? 0 : t->max_sum));
    }

    while (!ans.empty())
    {
        cout << ans.front() << endl;
        ans.pop();
    }

    t->free();
    delete t;
    delete[] x;

    return 0;
}
