#include <bits/stdc++.h>

using namespace std;

uint64_t max(uint64_t u, uint64_t v)
{
    if (u>=v)
        return u;
    else
        return v;

}

uint64_t min(uint64_t u, uint64_t v)
{
    if (u<=v)
        return u;
    else
        return v;

}

uint64_t count(uint64_t *p, uint64_t x, uint64_t n)
{
    uint64_t s = 0;
    for (uint64_t i=0;i<n;i++)
        s+= max(p[i],x) - min(p[i],x);

    return s;
}

int main()
{
    uint64_t n, *p, m;

    cin >> n;

    p = new uint64_t[n];

    for (uint64_t i=0;i<n;i++)
        cin >> p[i];

    sort(p,p+n);

    m = min(count(p,p[n/2 - 1],n),count(p,p[n/2],n));

    cout << m;

    delete[] p;
    return 0;
}
