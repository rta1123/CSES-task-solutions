#include <bits/stdc++.h>

using namespace std;

#define inf 1000000000

int min(int u, int v)
{
    if (u <= v)
        return u;
    else
        return v;
}

int C(int a, int b, int **c)
{
    int k, m = inf;

    if (c[a][b] != -1)
        return c[a][b];

    if (a == b)
    {
        c[a][b] = 0;
        return c[a][b];
    }

    if (a == 1)
    {
        c[a][b] = b - 1;
        return c[a][b];
    }

    if (b == 1)
    {
        c[a][b] = a - 1;
        return c[a][b];
    }

    for (int i=1; i<=a/2; i++)
    {
        k = C(a - i, b, c) + C(i, b, c) + 1;
        m = min(m, k);
    }

    for (int i=1; i<=b/2; i++)
    {
        k = C(a, b - i, c) + C(a, i, c) + 1;
        m = min(m, k);
    }

    c[a][b] = m;

    return c[a][b];
}

int main()
{
    int a, b, **c;

    cin >> a;
    cin >> b;

    c = new int*[a+1];
    for (int i=0; i<=a; i++)
        c[i] = new int[b+1];

    for (int i=0; i<=a; i++)
        for (int j=0; j<=b; j++)
            c[i][j] = -1;

    cout << C(a, b, c) << endl;

    for (int i=0; i<=a; i++)
        delete[] c[i];
    delete[] c;

    return 0;
}
