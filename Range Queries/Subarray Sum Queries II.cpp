#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;

#define null nullptr

enum {inf = -1000000000000000};

struct sgi
{
    ll pfx, sfx, sum, max_sum;

    sgi(ll pfx, ll sfx, ll sum, ll max_sum) : pfx(pfx), sfx(sfx), sum(sum), max_sum(max_sum) {}
    sgi() : pfx(0), sfx(0), sum(0), max_sum(0) {}
};

struct sgt
{
    ll l, r, pfx, sfx, sum, max_sum;
    sgt *L, *R;

    sgt()
    {
        l = {};
        r = {};
        pfx = {};
        sfx = {};
        sum = {};
        max_sum = {};
        L = {};
        R = {};
    }

    sgt(ll a, ll b, ll *x)
    {
        l = a;
        r = b;

        if (a < b)
        {
            L = new sgt(a, (a + b)/2, x);
            R = new sgt(1 + (a + b)/2, b, x);

            sum = L->sum + R->sum;
            pfx = max(L->pfx, max(sum, L->sum + R->pfx));
            sfx = max(R->sfx, max(sum, L->sfx + R->sum));
            max_sum = max(sum, max(L->max_sum, max(R->max_sum, max(L->sfx + R->sum, max(L->sum + R->pfx, L->sfx + R->pfx)))));
        }
        else
        {
            pfx = x[a];
            sfx = x[a];
            sum = x[a];
            max_sum = x[a];
            L = {};
            R = {};
        }
    }

    sgi search(ll a, ll b)
    {
        sgi ansL {}, ansR {}, ans {};

        ansL = sgi(inf, inf, inf, inf);
        ansR = sgi(inf, inf, inf, inf);

        if ((l == a) and (r == b))
            return {pfx, sfx, sum, max_sum};

        if ((L != null) and (L->l <= a) and (L->r >= a))
            ansL = L->search(a, min(L->r, b));

        if ((R != null) and (R->l <= b) and (R->r >= b))
            ansR = R->search(max(R->l, a), b);

        ans.sum = ((ansL.sum == inf) ? 0 : ansL.sum) + ((ansR.sum == inf) ? 0 : ansR.sum);
        ans.pfx = max(ansL.pfx, max(ansL.sum + ansR.pfx, ans.sum));
        ans.sfx = max(ansR.sfx, max(ansL.sfx + ansR.sum, ans.sum));
        ans.max_sum = max(ans.sum, max(ansL.max_sum, max(ansR.max_sum, max(ansL.sfx + ansR.sum, max(ansL.sum + ansR.pfx, ansL.sfx + ansR.pfx)))));

        return ans;
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
    ll n, q, a, b, m, *x;
    queue <ll> ans;
    sgt *t;

    cin >> n;
    cin >> q;

    x = new ll[n];

    for (ll i=1; i<=n; i++)
        cin >> x[i];

    t = new sgt(1, n, x);

    for (ll i=1; i<=q; i++)
    {
        cin >> a;
        cin >> b;

        m = t->search(a, b).max_sum;
        ans.push(((m > 0) ? m : 0));
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
