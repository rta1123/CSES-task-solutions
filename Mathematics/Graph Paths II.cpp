#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;

enum {inf = __INT64_MAX__};

ll min(ll u, ll v)
{
    if (u <= v)
        return u;
    else
        return v;
}

ll **FME(ll **A, ll **T, ll **R, int n, int m)
{
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
                R[i][j] = inf;

                for (int k=1; k<=n; k++)
                    if (A[i][k] and T[k][j])
                        R[i][j] = min(R[i][j], A[i][k] + T[k][j]);
            }
    }
    else
    {
        T = FME(A, T, R, n, m >> 1);

        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++)
            {
                R[i][j] = inf;

                for (int k=1; k<=n; k++)
                    if (T[i][k] and T[k][j])
                        R[i][j] = min(R[i][j], T[i][k] + T[k][j]);
            }
    }

    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            if (R[i][j] != inf)
                T[i][j] = R[i][j];
            else
                T[i][j] = 0;

    return T;
}

int main()
{
    int n, m, k, a, b, c;
    ll **A, **T, **R;

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
            A[i][j] = inf;

    for (int i=1; i<=m; i++)
    {
        cin >> a;
        cin >> b;
        cin >> c;

        A[a][b] = min(A[a][b], c);
    }

    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
        {
            if (A[i][j] == inf)
                A[i][j] = 0;

            T[i][j] = 0;
            R[i][j] = 0;
        }

    T = FME(A, T, R, n, k);

    cout << ((T[1][n] == 0) ? -1 : T[1][n]) << endl;

    for (int i=0; i<=n; i++)
        delete[] A[i];
    delete[] A;

    for (int i=0; i<=n; i++)
        delete[] T[i];
    delete[] T;

    for (int i=0; i<=n; i++)
        delete[] R[i];
    delete[] R;

    return 0;
}
