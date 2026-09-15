#include <bits/stdc++.h>

using namespace std;

#define max 1000000007
#define phi_max 1000000006

uint64_t POW(uint64_t a, uint64_t b, uint64_t m)
{
    if (b==0)
        return 1;

    if (b==1)
        return a;

    if (b % 2 == 1)
        return (a * POW(a,b-1,m)) % m;
    else
        return (POW(a,b/2,m) * POW(a,b/2,m)) % m;
}

int main()
{
    uint64_t n;
    uint64_t *a,*b,*c;

    cin >>n;

    a = new uint64_t[n+1];
    b = new uint64_t[n+1];
    c = new uint64_t[n+1];

    for (uint64_t i=1;i<=n;i++)
    {
        cin >> a[i];
        cin >> b[i];
        cin >> c[i];
    }

    for (uint64_t i=1;i<=n;i++)
        cout << POW(a[i], POW(b[i], c[i], phi_max), max) % max << endl;

    delete[] a;
    delete[] b;
    delete[] c;

    return 0;
}
