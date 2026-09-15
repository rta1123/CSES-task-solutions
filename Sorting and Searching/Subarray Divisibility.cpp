#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;

int main()
{
    ll n, *a, *s, k, C;

    cin >> n;

    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }

    a = new ll[n+1];
    s = new ll[n+1];

    for (ll i=1; i<=n; i++)
        cin >> a[i];

    s[0] = 0;
    for (ll i=1; i<=n; i++)
        s[i] = (s[i-1] + a[i]) % n;

    for (ll i=0; i<=n; i++)
        if (s[i] < 0)
            s[i] += n;

    sort(s+1, s+n+1);

    C = k = 0;
    for (ll i=2; i<=n; i++)
    {
        if (s[i] == s[i-1])
            k++;
        else
        {
            C += (k * (k + 1) / 2);
            k = 0;
        }
    }

    C += (k * (k + 1) / 2);
    k = 0;

    for (ll i=1; i<=n; i++)
        if (s[i] == 0)
            C++;

    cout << C << endl;

    delete[] a;
    delete[] s;

    return 0;
}
