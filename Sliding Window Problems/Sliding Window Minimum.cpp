#include <bits/stdc++.h>
 
using namespace std;
 
typedef int64_t ll;
 
ll X(ll x, ll a, ll b, ll c)
{
    return (a * x + b) % c;
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
    ll n, k, x, a, b, c, s;
    deque <pair<ll, ll>> q;
 
    cin >> n;
    cin >> k;
    cin >> x;
    cin >> a;
    cin >> b;
    cin >> c;
 
    s = {};
    for (ll i=1; i<=k; i++)
    {
        while (!q.empty() and (q.back().first >= x))
            q.pop_back();
        q.push_back({x, i});
        x = X(x, a, b, c);
    }
    s ^= q.front().first;
 
    for (ll i=k+1; i<=n; i++)
    {
        while (!q.empty() and ((i - q.front().second) >= k))
            q.pop_front();
            
        while (!q.empty() and (q.back().first >= x))
            q.pop_back();
        q.push_back({x, i});
        x = X(x, a, b, c);
        
        s ^= q.front().first;
    }
 
    cout << s << endl;
 
    return 0;
}
