#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;

enum
{
    N = 1000000,
    modulo = 1000000007,
};

ll fe(ll a, ll x)
{
    ll e = 1;

    if (x == 1)
        return a;

    if (x == 0)
        return e;

    if (x % 2)
    {
        e = (a * fe(a, x - 1) % modulo);
    }
    else
    {
        e = fe(a, x / 2);
        e = (e * e % modulo);
    }

    return e;
}

ll inv(ll a)
{
    return fe(a, modulo - 2);
}

int main()
{
    ll n, a, b;
    ll *f, *inv_f;
    queue <ll> ans;

    f = new ll[N+1];
    inv_f = new ll[N+1];

    f[0] = 1;
    for (ll i=1; i<=N; i++)
        f[i] = (f[i-1] * i % modulo);

    inv_f[N] = inv(f[N]);
    for (ll i=N-1; i>=0; i--)
        inv_f[i] = (inv_f[i+1] * (i+1) % modulo);

    cin >> n;

    for (ll i=1; i<=n; i++)
    {
        cin >> a;
        cin >> b;

        ans.push(((f[a] * inv_f[b] % modulo) * inv_f[a-b] % modulo));
    }

    while (!ans.empty())
    {
        cout << ans.front() << endl;
        ans.pop();
    }

    delete[] f;
    delete[] inv_f;

    return 0;
}
