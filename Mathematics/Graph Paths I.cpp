#include <bits/stdc++.h>

using namespace std;

enum
{
    modulo = 1000000007,
};

typedef int64_t ll;

ll** FME(ll **A, ll **T, ll **R, int n, int m)
{
    if (m == 0)
    {
        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++)
                T[i][j] = ((i == j) ? 1 : 0);

        return T;
    }

    if (m == 1)
    {
        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++)
                T[i][j] = A[i][j];

        return T;
    }

    if (m % 2)
    {
        T = FME(A, T, R, n, m - 1);

        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++)
            {
                R[i][j] = 0;
                for (int k=1; k<=n; k++)
                {
                    R[i][j] += A[i][k] * T[k][j];
                    R[i][j] %= modulo;
                }
            }
    }
    else
    {
        T = FME(A, T, R, n, m >> 1);

        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++)
            {
                R[i][j] = 0;
                for (int k=1; k<=n; k++)
                {
                    R[i][j] += T[i][k] * T[k][j];
                    R[i][j] %= modulo;
                }
            }
    }

    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            T[i][j] = R[i][j];

    return T;
}


int main()
{
    int n, m, k, u, v;
    ll **A, **R, **T;

    cin >> n;
    cin >> m;
    cin >> k;

    A = new ll*[n+1];
    for (int i=0; i<=n; i++)
        A[i] = new ll[n+1];

    T = new ll*[n+1];
    for (int i=0; i<=n; i++)
        T[i] = new ll[n+1];

    R = new ll*[n+1];
    for (int i=0; i<=n; i++)
        R[i] = new ll[n+1];

    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
        {
            A[i][j] = 0;
            T[i][j] = 0;
            R[i][j] = 0;
        }

    for (int i=1; i<=m; i++)
    {
        cin >> u;
        cin >> v;

        A[u][v]++;
    }

    T = FME(A, T, R, n, k);

    cout << T[1][n] << endl;

    for (int i=0; i<=n; i++)
        delete[] R[i];
    delete[] R;

    for (int i=0; i<=n; i++)
        delete[] T[i];
    delete[] T;

    for (int i=0; i<=n; i++)
        delete[] A[i];
    delete[] A;

    return 0;
}
