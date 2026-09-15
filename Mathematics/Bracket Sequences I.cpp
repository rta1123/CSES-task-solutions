#include <iostream>

using namespace std;

enum
{
    modulo = 1000000007,
};

typedef int64_t ll;

ll pow(ll x, ll y)
{
    ll z {};

    if (y == 1)
        return x;

    if (y == 0)
        return 1;

    if (y % 2)
    {
       z = (x * pow(x, y-1) % modulo);
    }
    else
    {
        z = pow(x, y/2);
        z = (z * z % modulo);
    }

    return z;
}

ll inv(ll x)
{
    return pow(x, modulo - 2);
}

ll C(int n)
{
    ll p, q;

    p = 1;
    for (int i=n+2; i<=2*n; i++)
        p = (p * i % modulo);

    q = 1;
    for (int i=1; i<=n; i++)
        q = (q * i % modulo);

    return (p * inv(q) % modulo);
}

int main()
{
    int n;

    cin >> n;

    if (n % 2)
        cout << 0 << endl;
    else
        cout << C(n/2) << endl;

    return 0;
}
