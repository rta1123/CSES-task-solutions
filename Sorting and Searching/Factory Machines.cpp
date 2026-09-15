#include <bits/stdc++.h>
using namespace std;

typedef uint64_t ull;

int main()
{
    ull n, k, m, *t, tm, tl, tr;

    cin >> n;
    cin >> k;

    t = new ull[n+1];

    t[0] = 0;
    for (ull i=1; i<=n; i++)
    {
        cin >> t[i];
        t[0] += t[i];
    }

    tl = 0;
    tr = k * t[0];

    do
    {
        tm = (tr + tl) / 2;

        m = 0;
        for (ull i=1; i<=n; i++)
            m += tm / t[i];

        if (m >= k)
            tr = tm;
        else
            tl = tm;

    } while((tr - tl) > 1);

    cout << tr << endl;

    delete[] t;

    return 0;
}