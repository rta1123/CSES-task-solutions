#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;

ll max(ll u, ll v)
{
    if (u >= v)
        return u;
    else
        return v;
}

bool successed(ll n, ll k, ll S, ll *x)
{
    ll s {};

    for (ll i=1; i<=n; i++)
    {
        s += x[i];

        if (s > S)
        {
            k--;
            s = x[i];

            if (k < 0)
                return false;
        }
    }

    if (s > S)
    {
        k--;
        if (k < 0)
            return false;
    }

    return true;
}

int main()
{
    ll n, k, *x, *y, s, S, h, H;

    cin >> n;
    cin >> k;

    x = new ll[n+1];
    y = new ll[n+1];

    for (ll i=1; i<=n; i++)
        cin >> x[i];

    S = 0;
    for (ll i=1; i<=n; i++)
    {
        y[i] = x[i];
        S += x[i];
    }

    sort(y+1, y+n+1);

    H = S;
    for (ll i=1; i<=k-1; i++)
        H -= y[i];

    h = max(S / k, y[n]);

    do
    {
        s = (H + h) / 2;

        if (successed(n, k-1, s, x))
            H = s;
        else
            h = s;

    }while ((H - h) > 1);

    if (successed(n, k-1, h, x))
        cout << h << endl;
    else
        cout << H << endl;

    delete[] x;
    delete[] y;

    return 0;
}
