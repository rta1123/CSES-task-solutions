#include <bits/stdc++.h>

using namespace std;

#define M 1000000007

typedef int64_t ll;

inline int abs(int u, int v)
{
    if (u >= v)
        return u - v;
    else
        return v - u;
}

ll A(int i, int r, int k, int m, int *x, ll **c)
{
    if (i > r)
        return 0;

    if (i == r)
        return 1;

    if (c[i][k] != -1)
        return c[i][k] % M;

    c[i][k] = A(i+1, r, k, m, x, c) % M;

    if (k > 1)
        c[i][k] += A(i+1, r, k-1, m, x, c) % M;

    if (k < m)
        c[i][k] += A(i+1, r, k+1, m, x, c) % M;

    return c[i][k] % M;
}

ll R(int i, int j, int k, int m, int *x, ll **c)
{
    if (i > j)
        return 0;

    if (i == j)
    {
        if (abs(k, x[j]) <= 1)
            return 1;
        else
            return 0;
    }

    if (c[i][k] != -1)
        return c[i][k] % M;

    c[i][k] = R(i+1, j, k, m, x, c) % M;

    if (k > 1)
        c[i][k] += R(i+1, j, k-1, m, x, c) % M;

    if (k < m)
        c[i][k] += R(i+1, j, k+1, m, x, c) % M;

    return c[i][k] % M;
}

ll solution(int n, int m, int *x, ll **c)
{
    ll p {}, q {}, s {};
    int l {}, r {}, mid {};

    for (int i=1; i<=n-1; i++)
        if (x[i] and x[i+1] and abs(x[i],x[i+1]) > 1)
            return 0;

    for (int i=1, j=0; i<=n; i++)
    {
       if (x[i])
           j++;

       if (j == n)
           return 1;
    }

    for (l=1; l<=n; l++)
        if (x[l] != 0)
            break;

    if (l <= n)
    {
        if (l != 1)
            for (int k=1; k<=m; k++)
                p += R(2, l, k, m, x, c) % M;

        for (r=n; r>=1; r--)
            if (x[r] != 0)
                break;

        if (r != n)
            for (int k=1; k<=m; k++)
                if (abs(x[r], k) <= 1)
                    q += A(r+2, n+1, k, m, x, c) % M;

        if (p)
        {
            if (q)
                s = p * q % M;
            else
                s = p;
        }
        else
            if (q)
                s = q;

        if (l != r)
        {
            do
            {
                while ((x[l] != 0) and (l < n))
                    l++;

                if ((l >= r) or (l >= n))
                    break;

                mid = l;
                while (x[mid] == 0)
                    mid++;

                p = {};
                for (int k=1; k<=m; k++)
                    if (abs(x[l-1],k) <= 1)
                        p += R(l + 1, mid, k, m, x, c) % M;

                if (p)
                {
                    if (s)
                        s = s * p % M;
                    else
                        s = p % M;
                }


                l = mid;

            }while (l < r);
        }
    }
    else
    {
        s = {};
        for (int k=1; k<=m; k++)
            s += A(2, n+1, k, m, x, c) % M;
    }

    return s;
}

int main()
{
    int n, m, *x;
    ll **c;

    cin >> n;
    cin >> m;

    x = new int[n+1];
    c = new ll*[n+1];
    for (int i=0; i<=n; i++)
        c[i] = new ll[m+1];

    x[0] = 0;
    for (int i=1; i<=n; i++)
        cin >> x[i];

    for (int i=0; i<=n; i++)
        for (int j=0; j<=m; j++)
            c[i][j] = -1;

    cout << solution(n, m, x, c) << endl;

    for (int i=0; i<=n; i++)
        delete[] c[i];
    delete[] c;

    delete[] x;

    return 0;
}
