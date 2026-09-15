#include <bits/stdc++.h>

using namespace std;

int min(int u, int v)
{
    if (u <= v)
        return u;
    else
        return v;
}

int main()
{
    int n, m, x, *w, *c, *W;

    cin >> n;
    cin >> x;

    w = new int[n];
    c = new int[(1 << n)];
    W = new int[(1 << n)];

    for (int i=0; i<n; i++)
        cin >> w[i];

    for (int i=0; i<(1 << n); i++)
    {
        W[i] = x;
        c[i] = n;
    }
    W[0] = 0, c[0] = 1;

    sort(w, w+n);

    for (int m=1; m<(1 << n); m++)
        for (int i=0; i<n; i++)
            if (m & (1 << i))
            {
                if ((W[m ^ (1 << i)] + w[i]) <= x)
                {
                    if (c[m ^ (1 << i)] < c[m])
                    {
                        c[m] = c[m ^ (1 << i)];
                        W[m] = W[m ^ (1 << i)] + w[i];
                    }
                    else
                        if (c[m ^ (1 << i)] == c[m])
                        {
                            if ((W[m ^ (1 << i)] + w[i]) < W[m])
                            {
                                c[m] = c[m ^ (1 << i)];
                                W[m] = W[m ^ (1 << i)] + w[i];
                            }
                        }
                }
                else
                {
                    if ((c[m ^ (1 << i)] + 1) < c[m])
                    {
                        c[m] = c[m ^ (1 << i)] + 1;
                        W[m] = w[i];
                    }
                }
            }

    m = {};
    for (int i=0; i<n; i++)
        m |= (1 << i);

    cout << c[m] << endl;

    delete[] w;
    delete[] c;
    delete[] W;

    return 0;
}
