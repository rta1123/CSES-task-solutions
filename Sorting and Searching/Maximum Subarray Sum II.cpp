#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;

enum {inf = 1000000000000000000};

struct sgt
{
private:
    sgt *L, *R;
    ll l, r, s, pfx;

public:

    sgt()
    {
        L = {};
        R = {};
        l = {};
        r = {};
        pfx = {};
        s = {};
    }

    sgt(ll a, ll b, ll *x)
    {
        l = a;
        r = b;
        if (a < b)
        {
            L = new sgt(a, (a+b)/2, x);
            R = new sgt((a+b)/2 + 1, b, x);

            pfx = max(L->s + R->s, max(L->pfx, L->s + R->pfx));
            s = L->s + R->s;
        }
        else
        {
            s = x[a];
            pfx = x[a];
            L = {};
            R = {};
        }
    }

    pair<ll,ll> search(ll a, ll b)
    {
        pair<ll,ll> ansL {}, ansR {}, ans{};

        if ((l == a) and (r == b))
            return {pfx, s};

        if ((L != nullptr) and (L->l <= a) and (a <= L->r))
            ansL = L->search(a, min(b, L->r));

        if ((R != nullptr) and (R->l <= b) and (b <= R->r))
            ansR = R->search(max(a, R->l), b);

        ans.first =  max(ansL.second + ansR.second, max(ansL.first, ansL.second + ansR.first));
        ans.second = ansL.second + ansR.second;

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
    ll n, a, b, *s, *x, ans;
    sgt *t;

    cin >> n;
    cin >> a;
    cin >> b;

    x = new ll[n+1];
    s = new ll[n-a+1+1];

    for (ll i=1; i<=n; i++)
        cin >> x[i];

    s[0] = 0;
    for (ll i=1; i<=a; i++)
        s[1] += x[i];

    for (ll i=a+1; i<=n; i++)
        s[i-a+1] = s[i-a] - x[i-a] + x[i];

    t = new sgt(1, n, x);

    ans = -inf;
    for (ll i=a; i<=n; i++)
        ans = max(ans, s[i-a+1]);

    if (b > a)
        for (ll i=1; i<=n-a+1; i++)
            ans = max(ans, max(s[i], s[i] + t->search(i+a, min(n, i+b-1)).first));

    cout << ans << endl;

    t->free();
    delete t;
    delete[] x;
    delete[] s;

    return 0;
}
