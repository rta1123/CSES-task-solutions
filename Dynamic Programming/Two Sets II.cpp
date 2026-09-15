#include <bits/stdc++.h>

using namespace std;

#define m 1000000007

int C(int i, int n, int N, int **c, bool **w)
{
    if (i > n)
        return 0;

    if (N == 0)
        return 1;

    if (N < 0)
        return 0;

    if (w[i][N])
        return c[i][N];
    else
        w[i][N] = true;

    c[i][N] = ((C(i+1, n, N, c, w) % m) + (C(i+1, n, N - i, c, w) % m)) % m;

    return c[i][N];
}

int main()
{
    int n, N;
    int **c = nullptr;
    bool **w = nullptr;

    cin >> n;

    N = n * (n + 1) / 2;

    if (N % 2 == 1)
        cout << 0 << endl;
    else
    {
        N = N / 2;
        c = new int*[n+1];

        for (int i=0; i<=n; i++)
            c[i] = new int[N+1];

        w = new bool*[n+1];

        for (int i=0; i<=n; i++)
            w[i] = new bool[N+1];

        for (int i=0; i<=n; i++)
            for (int j=0; j<=N; j++)
            {
                c[i][j] = 0;
                w[i][j] = false;
            }

        cout << C(1, n, N, c, w) << endl;

        for (int i=0; i<=n; i++)
            delete[] c[i];
        delete[] c;

        for (int i=0; i<=n; i++)
            delete[] w[i];
        delete[] w;
    }

    return 0;
}
