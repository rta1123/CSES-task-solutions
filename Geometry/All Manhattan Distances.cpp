#include <bits/stdc++.h>

using namespace std;

typedef __int64_t ll;
typedef __int128_t lll;

int main()
{
    int n, p, q, kx, ky;
    ll *x, *y;
    lll *Sx, *Sy, S;
    vector <pair <ll, ll>> ux, uy;
    stack <int> ans;

    cin >> n;

    x = new ll[n+1];
    y = new ll[n+1];

    for (int i=1; i<=n; i++)
    {
        cin >> x[i];
        cin >> y[i];
    }

    sort(x+1, x+n+1);
    sort(y+1, y+n+1);

    x[0] = x[1] + 1;
    for (int i=1; i<=n; i++)
    {
        if (x[i] == x[i-1])
            ux.back().second++;
        else
            ux.push_back({x[i], 1});
    }
    p = ux.size();

    y[0] = y[1] + 1;
    for (int i=1; i<=n; i++)
    {
        if (y[i] == y[i-1])
            uy.back().second++;
        else
            uy.push_back({y[i], 1});
    }
    q = uy.size();

    Sx = new lll[p];
    Sy = new lll[q];

    for (int i=0; i<=p-1; i++)
        Sx[i] = 0;

    for (int i=0; i<=q-1; i++)
        Sy[i] = 0;

    kx = 0;
    for (int i=p-1; i>=1; i--)
    {
        kx += ux[i].second;
        Sx[i-1] = (ux[i].first - ux[i-1].first) * kx + Sx[i];
    }

    ky = 0;
    for (int i=q-1; i>=1; i--)
    {
        ky += uy[i].second;
        Sy[i-1] = (uy[i].first - uy[i-1].first) * ky + Sy[i];
    }

    S = 0;
    for (int i=0; i<p-1; i++)
        S += Sx[i]*ux[i].second;

    for (int i=0; i<q-1; i++)
        S += Sy[i]*uy[i].second;

    do
    {
        ans.push(S % 10);
        S /= 10;
    } while (S);

    while (!ans.empty())
    {
        cout << ans.top();
        ans.pop();
    }
    cout << endl;

    delete[] x;
    delete[] y;
    delete[] Sx;
    delete[] Sy;

    return 0;
}
