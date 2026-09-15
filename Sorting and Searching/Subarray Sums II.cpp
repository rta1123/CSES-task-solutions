#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;

int main()
{
    ll n, x, *a, C, k, j, *c;
    pair <ll, ll> *s, *S;

    cin >> n;
    cin >> x;

    a = new ll[n+1];
    s = new pair<ll,ll>[n+1];
    S = new pair<ll,ll>[n+1];
    c = new ll[n+1];

    a[0] = 0;
    for (ll i=1; i<=n; i++)
        cin >> a[i];

    s[0] = {0,0}, S[0] = {0,0};
    for (ll i=1; i<=n; i++)
    {
        s[i].second = i;
        S[i].second = i;
        s[i].first = s[i-1].first + a[i];
        S[i].first = S[i-1].first + a[i];
    }

    for (ll i=0; i<=n; i++)
    {
        c[i] = 0;
        S[i].first = S[i].first + x;
    }

    sort(s, s + n + 1);
    sort(S, S + n + 1);

    for (ll i=0, j=0; i<=n-1; i++)
        if (s[i].first == s[i+1].first)
            c[j]++;
        else
            j=i+1;

    for (ll i=0; i<=n-1; i++)
        if (c[i])
            c[i+1] = c[i] - 1;

    C = 0, k = 0, j = 0;
    while ((k <= n) and (j <= n))
    {
        if ((k <= n) and (j <= n) and (s[k].first > S[j].first))
            j++;

        if ((k <= n) and (j <= n) and (s[k].first < S[j].first))
            k++;

        if ((k <= n) and (j <= n) and ((s[k].first == S[j].first) and (s[k].second <= S[j].second)))
            k++;

        if ((k <= n) and (j <= n) and (s[k].first == S[j].first) and (s[k].second > S[j].second))
        {
            C++;

            C = C + c[k];

            j++;
        }
    }

    cout << C << endl;

    delete[] a;
    delete[] s;
    delete[] S;
    delete[] c;

    return 0;
}
