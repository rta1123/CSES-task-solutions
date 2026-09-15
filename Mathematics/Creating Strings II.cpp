#include <bits/stdc++.h>

using namespace std;

typedef uint64_t ull;

enum
{
    max_alphabet_size = 26,
    modulo = 1000000007,
};

ull fepf(ull a, ull b)
{
    ull res = 1;

    if (b == 0)
        return res;

    if (b == 1)
        return a;

    if (b % 2)
    {
        res = (a * fepf(a, b-1) % modulo);
    }
    else
    {
        res = fepf(a, b/2);
        res = (res * res % modulo);
    }

    return res;
}

ull inv(ull a)
{
    return fepf(a, modulo - 2);
}

ull factorial(ull n)
{
    if (n == 0)
        return 1;

    if (n == 1)
        return 1;

    return ((n * factorial(n-1)) % modulo);
}

int main()
{
    string s {};
    ull n {}, c[max_alphabet_size] {}, ans {};

    cin >> s;

    n = s.size();

    for (ull i=0; i<n; i++)
        c[s[i] - 'a']++;

    ans = factorial(n);
    for (ull i=0; i<max_alphabet_size; i++)
        if (c[i])
        {
            ans *= inv(factorial(c[i]));
            ans %= modulo;
        }

    cout << ans << endl;

    return 0;
}
