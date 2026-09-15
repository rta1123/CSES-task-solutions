#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;

ll X(ll x, ll a, ll b, ll c)
{
    return (a*x + b) % c;
}

ll min(ll u, ll v)
{
    if (u <= v)
        return u;
    else
        return v;    
}

int main()
{
    ll n, k, x, a, b, c, s, j;
    
    cin >> n;
    cin >> k;
    cin >> x;
    cin >> a;
    cin >> b;
    cin >> c;
    
    s = x;
    
    for (ll i=2; i<=n; i++)
    {
        x = X(x, a, b, c);
        
        j = min(min(min(k, n - k + 1), i), n - i + 1);
        
        if (j % 2)
            s ^= x;
    }
    
    cout << s << endl;
    
    return 0;
}