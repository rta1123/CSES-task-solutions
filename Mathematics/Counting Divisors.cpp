#include <bits/stdc++.h>

using namespace std;

#define max 1000000

#define max_prime 1000

uint64_t tau(uint64_t x, uint64_t *not_prime)
{
    uint64_t nu,u;
    uint64_t t, T;
    queue <uint64_t> primes;

    while (x != 1)
    {
        u = x;
        x = x / not_prime[u];
        primes.push(not_prime[u]);
    }

    t = 1;
    T = 1;

    u = primes.front();

    while (!primes.empty())
    {
        nu = primes.front();
        primes.pop();
        if (nu==u)
            t++;
        else
        {
            T = T * t;
            t = 2;
        }

        u = nu;
    }

    T = T * t;

    return T;
}

int main()
{
    uint64_t n;
    uint64_t *x;
    uint64_t *not_prime;

    cin >> n;

    not_prime = new uint64_t[max+1];
    x = new uint64_t[n+1];

    for (uint64_t i=1;i<=n;i++)
        cin >> x[i];

    not_prime[1] = 1;
    for (uint64_t i=2; i<=max;i++)
    {
        if (not_prime[i])
            continue;

        for (uint64_t j=2*i;j<=max;j+=i)
            if (not_prime[j]==0)
                not_prime[j] = i;

        not_prime[i] = i;
    }

    for (uint64_t i=1;i<=n; i++)
        cout << tau(x[i], not_prime) << endl;

    delete[] not_prime;
    delete[] x;

    return 0;
}
