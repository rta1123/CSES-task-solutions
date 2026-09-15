#include <bits/stdc++.h>

using namespace std;

int log2(int n)
{
    int m = 0;

    while ((1 << m) < n)
        m++;

    return m;
}

int P(int x, int k, int *p, int **d)
{
    int m = 0;

    while ((1 << m) <= k)
    {
        if ((k & (1 << m)) == (1 << m))
            x = d[x][m];
        m++;
    }

    return x;
}

int main()
{
    int n, q, *p, a, b, **d;
    queue <int> ans;

    cin >> n;
    cin >> q;

    p = new int[n+1];

    d = new int*[n+1];
    for (int i=0; i<=n; i++)
        d[i] = new int[log2(n)+1];

    p[0] = p[1] = 0;
    for (int i=2; i<=n; i++)
        cin >> p[i];

    for (int i=0; i<=n; i++)
        d[i][0] = p[i];

    for (int i=0; i<=log2(n); i++)
        d[0][i] = 0;

    for (int i=2; i<=log2(n); i++)
        d[1][i] = 0;

    for (int j=1; j<=log2(n); j++)
        for (int i=1; i<=n; i++)
            d[i][j] = d[d[i][j-1]][j-1];

    for (int i=1; i<=q; i++)
    {
        cin >> a;
        cin >> b;

        ans.push(P(a, b, p, d));
    }

    while (!ans.empty())
    {
        cout << ((ans.front() == 0) ? -1: ans.front()) << endl;
        ans.pop();
    }

    delete[] p;

    for (int i=0; i<=n; i++)
        delete[] d[i];
    delete[] d;

    return 0;
}
