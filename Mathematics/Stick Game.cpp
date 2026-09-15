#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k, *p, *w;

    cin >> n;
    cin >> k;

    p = new int[k+1];
    for (int i=1; i<=k; i++)
        cin >> p[i];

    w = new int[n+1];
    for (int i=0; i<=n; i++)
        w[i] = -1;

    w[0] = 0;
    for (int i=0; i<=n; i++)
    {
        if (w[i] == -1)
            w[i] = 0;

        if (w[i] == 0)
            for (int j=1; j<=k; j++)
                if (i + p[j] <= n)
                    w[i + p[j]] = 1;
    }

    for (int i=1; i<=n; i++)
    {
        if (w[i] == 1)
            cout << "W";
        else
            cout << "L";
    }
    cout << endl;

    delete[] p;
    delete[] w;

    return 0;
}
