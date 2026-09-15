#include <bits/stdc++.h>

using namespace std;

const uint64_t m = 1000000007;

uint64_t POW(uint64_t x, uint64_t n)
{
    if (n == 0)
        return 1;

    if (n == 1)
        return x;

    if (n % 2 == 1)
        return (x*(POW(x, n-1) % m));
    else
        return (POW(x, n/2) % m)*(POW(x, n/2) % m);
}

int main()
{
    uint64_t n;

    cin >> n;

    cout << (POW(2,n)% m);


    return 0;
}
