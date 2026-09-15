#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;

int main()
{
    ll n, *a, *d, r;

    cin >> n;

    a = new ll[n+1];
    d = new ll[n+1];

    r = 0;
    for (ll i=1; i<=n; i++)
    {
        cin >> a[i];
        cin >> d[i];
        r += d[i];
    }

    sort(a + 1, a + n + 1);

    for (ll i=1; i<=n; i++)
        r -= a[i]*(n-i+1);

    cout << r << endl;

    delete[] a;
    delete[] d;

    return 0;
}
