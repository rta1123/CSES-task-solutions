#include <bits/stdc++.h>
 
using namespace std;
 
typedef int64_t ll;
 
ll next(ll x, ll a, ll b, ll c)
{
    return (a*x + b) % c;
}
 
int main()
{
    ll n, k, x, a, b, c, s, y, S;
 
    cin >> n;
    cin >> k;
    cin >> x;
    cin >> a;
    cin >> b;
    cin >> c;
 
    s = {};
    S = {};
    y = x;
    for (ll i=1; i<=k; i++)
    {
        s += x;
        x = next(x, a, b, c);
    }
    S ^= s;
 
    for (ll i=k+1; i<=n; i++)
    {
        s += x;
        s -= y;
        x = next(x, a, b, c);
        y = next(y, a, b, c);
        S ^= s;
    }
 
    cout << S << endl;
 
    return 0;
}
