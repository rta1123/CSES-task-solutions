#include <bits/stdc++.h>

using namespace std;

typedef uint64_t ull;

ull m(ull p)
{
    ull q = {};

    while (p >> 1)
    {
        p = (p >> 1);
        q++;
    }

    return q;
}

ull bit_count(ull n)
{
    ull c = {};

    while (n)
    {
       n = n ^ (n & (~n + 1));
       c++;
    }

    return c;
}

int main()
{
    ull n, p, k;

    cin >> n;

    k = bit_count(n);

    while (n)
    {
        p = (n & (~n + 1));

        k += (p >> 1) * m(p);

        n = n ^ p;

        k += bit_count(n) * p;
    }

    cout << k << endl;

    return 0;
}
