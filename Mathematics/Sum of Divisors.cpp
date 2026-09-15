#include <bits/stdc++.h>

using namespace std;

enum {modulo = 1000000007};

typedef int64_t ll;
typedef __uint128_t lll;

enum {base = 10};

int main()
{
    ll n;
    stack <ll> ans;
    lll s, q, i;

    cin >> n;

    s = {};
    for (i=1; i <= n / i; i++)
    {
        q = (n / i) % modulo;

        s += ((q * i) % modulo);
        s %= modulo;
    }

    for (i=1; n / i > i; i++)
    {
        q = (((n/(i+1) + n/i + 1))*((n/i - n/(i+1))) / 2) % modulo;
        s += ((i * q) % modulo);
        s %= modulo;
    }

    while (s)
    {
        ans.push(s % base);
        s /= base;
    }

    while (!ans.empty())
    {
        cout << ans.top();
        ans.pop();
    }
    cout << endl;

    return 0;
}
