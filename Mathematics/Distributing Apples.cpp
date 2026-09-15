#include <bits/stdc++.h>

using namespace std;

enum
{
    modulo = 1000000007,
};

typedef uint64_t ull;

ull FEIPF(ull a, ull b)
{
    ull c = 1;

    if (b == 1)
        return a;

    if (b == 0)
        return c;

    if (b % 2)
    {
        c = a * FEIPF(a, b-1) % modulo;
    }
    else
    {
        c = FEIPF(a, b/2);
        c = (c * c % modulo);
    }

    return c;
}

ull inv(ull a)
{
    return (FEIPF(a, modulo - 2));
}

ull factorial(ull n)
{
    ull m = 1;

    if (n == 0)
        return m;

    for (ull i=1; i<=n; i++)
        m = m * i % modulo;

    return m;
}


int main()
{
    ull n, m;

    cin >> n;
    cin >> m;

    cout << (factorial(n + m - 1) * (inv(factorial(n-1)) * inv(factorial(m)) % modulo) % modulo) << endl;

    return 0;
}
