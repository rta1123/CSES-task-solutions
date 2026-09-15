#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;

struct sgt
{
    ll l, r, c;
    sgt *L, *R;

    sgt()
    {
        l = {};
        r = {};
        c = {};
        L = {};
        R = {};
    }

    sgt(ll a, ll b, const vector<ll> &u)
    {
        c = {};

        if (a < b)
        {
            L = new sgt(a, (a + b)/2, u);
            R = new sgt(1 + (a + b)/2, b, u);

            l = L->l;
            r = R->r;
        }
        else
        {
            l = u[a];
            r = u[b];

            L = {};
            R = {};
        }
    }

    void add(ll x)
    {
        if ((L == nullptr) and (R == nullptr))
        {
            c++;
            return;
        }

        if ((L != nullptr) and (L->l <= x) and (x <= L->r))
        {
            L->add(x);
            c++;
            return;
        }

        if ((R != nullptr) and (R->l <= x) and (x <= R->r))
        {
            R->add(x);
            c++;
            return;
        }
    }

    void rmv(ll x)
    {
        if ((L == nullptr) and (R == nullptr))
        {
            c--;
            return;
        }

        if ((L != nullptr) and (L->l <= x) and (x <= L->r))
        {
            L->rmv(x);
            c--;
            return;
        }

        if ((R != nullptr) and (R->l <= x) and (x <= R->r))
        {
            R->rmv(x);
            c--;
            return;
        }
    }

    ll cntH(ll x)
    {
        ll ans {};

        if (l > x)
            return c;

        if ((L != nullptr) and (L->r > x))
            ans += L->cntH(x);

        if ((R != nullptr) and (R->r > x))
            ans += R->cntH(x);

        return ans;
    }

    ll cntL(ll x)
    {
        ll ans {};

        if (r < x)
            return c;

        if ((L != nullptr) and (L->l < x))
            ans += L->cntL(x);

        if ((R != nullptr) and (R->l < x))
            ans += R->cntL(x);

        return ans;
    }

    void free()
    {
        if (L != nullptr)
            L->free();

        if (R != nullptr)
            R->free();

        delete L;
        delete R;
    }
};

int main()
{
    ll n, k, C, *x;
    vector <ll> u;
    queue <ll> ans;
    sgt *t;

    cin >> n;
    cin >> k;

    x = new ll[n+1];
    u = vector <ll>(n+1, 0);

    for (ll i=1; i<=n; i++)
    {
        cin >> x[i];
        u[i] = x[i];
    }

    sort(u.begin(), u.end());
    u.erase(unique(u.begin(),u.end()), u.end());
    t = new sgt(1, u.size() - 1, u);

    C = {};
    for (ll i=1; i<=k; i++)
    {
        t->add(x[i]);

        C += t->cntH(x[i]);
    }

    ans.push(C);
    for (ll i=k+1; i<=n; i++)
    {
        C -= t->cntL(x[i-k]);
        t->rmv(x[i-k]);

        t->add(x[i]);
        C += t->cntH(x[i]);
        ans.push(C);
    }

    while (!ans.empty())
    {
        cout << ans.front() << " ";
        ans.pop();
    }
    cout << endl;

    t->free();
    delete t;
    delete[] x;

    return 0;
}
