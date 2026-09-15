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
        if (a < b)
        {
            L = new sgt(a, (a + b)/2, u);
            R = new sgt(1 + (a + b)/2, b, u);

            c = {};
            l = L->l;
            r = R->r;
        }
        else
        {
            c = {};
            l = u[a];
            r = u[a];
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
        }

        if ((R != nullptr) and (R->l <= x) and (x <= R->r))
        {
            R->add(x);
            c++;
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
        }

        if ((R != nullptr) and (R->l <= x) and (x <= R->r))
        {
            R->rmv(x);
            c--;
        }
    }

    ll Me(ll k)
    {
        ll ans {};

        if ((L != nullptr) and (R != nullptr))
        {
            if (L->c >= k)
                ans = L->Me(k);
            else
                ans = R->Me(k - L->c);

            return ans;
        }
        else
            return l;
    }

    ll searchE(ll x)
    {
        ll ans {};

        if ((L == nullptr) and (R == nullptr))
            return c;

        if ((L != nullptr) and (L->l <= x) and (x <= L->r))
            ans = L->searchE(x);

        if ((R != nullptr) and (R->l <= x) and (x <= R->r))
            ans = R->searchE(x);

        return ans;
    }

    ll searchH(ll x)
    {
        ll ans {};

        if ((L != nullptr) and (x < L->l))
            return c;

        if ((L != nullptr) and (L->l <= x) and (x <= L->r))
            ans += L->searchH(x);

        if ((R != nullptr) and (x < R->l))
            ans += R->c;

        if ((R != nullptr) and (R->l <= x) and (x <= R->r))
            ans = R->searchH(x);

        return ans;
    }

    ll searchL(ll x)
    {
        ll ans {};

        if ((R != nullptr) and (x > R->r))
            return c;

        if ((R != nullptr) and (R->l <= x) and (x <= R->r))
            ans += R->searchL(x);

        if ((L != nullptr) and (x > L->r))
            ans += L->c;

        if ((L != nullptr) and (L->l <= x) and (x <= L->r))
            ans = L->searchL(x);

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
    ll n, k, C, nH, nL, nE, H, L, E, Me, nMe, *x;
    queue <ll> ans, w;
    vector <ll> u;
    sgt *t;

    cin >> n;
    cin >> k;

    x = new ll[n+1];

    for (ll i=1; i<=n; i++)
    {
        cin >> x[i];
        u.push_back(x[i]);
    }

    sort(u.begin(), u.end());
    u.erase(unique(u.begin(), u.end()), u.end());

    t = new sgt(0, u.size() - 1, u);

    for (ll i=1; i<=k; i++)
        t->add(x[i]);

    C = {}, Me = t->Me(k/2 + k%2);
    for (ll i=1; i<=k; i++)
        C += abs(x[i] - Me);
    ans.push(C);

    for (ll i=k+1; i<=n; i++)
    {
        C -= abs(x[i-k] - Me);
        t->rmv(x[i-k]);

        t->add(x[i]);
        nMe = t->Me(k/2 + k%2);
        t->rmv(x[i]);

        nH = t->searchH(nMe);
        nL = t->searchL(nMe);
        nE = t->searchE(nMe);
        H = t->searchH(Me);
        L = t->searchL(Me);
        E = t->searchE(Me);

        if (nMe > Me)
            C -= (nMe - Me) * (nH + nE - E - L);
        else
            C -= (nMe - Me) * (H + E - nE - nL);

        t->add(x[i]);
        C += abs(x[i] - nMe);

        Me = nMe;

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
