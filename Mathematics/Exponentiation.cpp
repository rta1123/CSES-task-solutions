#include <bits/stdc++.h>

using namespace std;

#define max 1000000007

uint64_t POW(uint64_t a, uint64_t b)
{
//    if (a==0 && b==0)
//        return 1;

    if (b==0)
        return 1;

    if (b==1)
        return a;

    if (b % 2 == 1)
        return (a * POW(a,b-1)) % max;
    else
        return (POW(a,b/2) * POW(a,b/2)) % max;
}

int main()
{
    uint32_t n;
    uint64_t *a, *b;

    cin >> n;

    a = new uint64_t[n+1];
    b = new uint64_t[n+1];

    for (uint64_t i=1;i<=n;i++)
    {
        cin >> a[i];
        cin >> b[i];
    }

    for (uint64_t i=1;i<=n;i++)
        cout << (POW(a[i],b[i]) % max) << endl;

    delete[] a;
    delete[] b;

    return 0;
}
