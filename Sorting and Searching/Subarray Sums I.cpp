#include <bits/stdc++.h>

using namespace std;

typedef uint64_t ull;

int main()
{
    ull n, x, *a, p, q, s, c;

    cin >> n;
    cin >> x;

    a = new ull[n+1];

    for (ull i=1; i<=n; i++)
        cin >> a[i];

    c = 0;
    p = 1;
    q = 1;
    s = 0;

    do
    {
        if (s > x)
        {
            s -= a[p];
            p++;
            continue;
        }
        else
            if (s < x)
            {
                s += a[q];
                q++;
                continue;
            }
            else
                if (s == x)
                {
                    c++;

                    s += a[q];
                    q++;
                    continue;
                }

    }while (q <= n);

    while (p <= n)
    {
        if (s > x)
        {
            s -= a[p];
            p++;
            continue;
        }
        else
            if (s < x)
                break;
            else
                if (s == x)
                {
                    c++;

                    s -= a[p];
                    p++;
                    continue;
                }
    }

    cout << c << endl;

    delete[] a;

    return 0;
}
