#include <bits/stdc++.h>

using namespace std;

unsigned long max(unsigned long u, unsigned long v)
{
    if (u>v)
        return u;
    else
        return v;
}

int main()
{
    int t;
    unsigned long *x,*y;

    cin >> t;

    x = new unsigned long[t+1];
    y = new unsigned long[t+1];

    for (int i=1; i<=t; i++)
    {
        cin >> x[i] >> y[i];
    }

    for (int i=1; i<=t; i++)
    {
        unsigned long long m = 0;
        unsigned long long M = 0;

        M = max(x[i],y[i])*max(x[i],y[i]);
        m = M - 2*(max(x[i],y[i]) - 1);

        if (x[i] % 2 == 0 && x[i] == max(x[i],y[i]))
        {
            cout << M - y[i] + 1 << "\n";
            continue;
        }

        if (x[i] % 2 == 1 && x[i] == max(x[i],y[i]))
        {
            cout << m + y[i] - 1 << "\n";
            continue;
        }

        if (y[i] % 2 == 1 && y[i] == max(x[i],y[i]))
        {
            cout << M - x[i] + 1 << "\n";
            continue;
        }

        if (y[i] % 2 == 0 && y[i] == max(x[i],y[i]))
        {
            cout << m + x[i] - 1 << "\n";
            continue;
        }
    }

    delete[] x;
    delete[] y;

    return 0;
}
