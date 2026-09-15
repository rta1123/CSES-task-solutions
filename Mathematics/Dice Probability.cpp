#include <bits/stdc++.h>

using namespace std;

double S(int x, int k, double **p)
{
    if (x < 0)
        return 0;

    if (k == 0)
    {
        p[x][k] = 0;
        return p[x][k];
    }

    if (k == 1)
    {
        if ((x >= 1) and (x <= 6))
            p[x][k] = 1. / 6.;
        else
            p[x][k] = 0;

        return p[x][k];
    }

    if (p[x][k] != -1)
        return p[x][k];

    p[x][k] = 0;
    p[x][k] = (S(x-1, k-1, p) + S(x-2, k-1, p) + S(x-3, k-1, p) + S(x-4, k-1, p) + S(x-5, k-1, p) + S(x-6, k-1, p)) / 6.;

    return p[x][k];
}

int main()
{
    int n, a, b;
    double **p, P;

    cin >> n;
    cin >> a;
    cin >> b;

    p = new double*[b+1];
    for (int i=0; i<=b; i++)
        p[i] = new double[n+1];

    for (int i=0; i<=b; i++)
        for (int j=0; j<=n; j++)
            p[i][j] = -1;

    P = {};

    for (int i=b; i>=a; i--)
        if (p[i][n] == -1)
            S(i, n, p);

    for (int i=a; i<=b; i++)
        P += p[i][n];

    cout << fixed << setprecision(6) << P << endl;

    for (int i=0; i<=b; i++)
        delete[] p[i];
    delete[] p;

    return 0;
}
