#include <bits/stdc++.h>

using namespace std;

const int m = 31;

int C(int x, int k, int **T)
{
    int n = {};

    while (k)
    {
        n = __builtin_ctz(k);

        x = T[x][n];

        k ^= (k & (~k+1));
    }

    return x;
}

int main()
{
    int n, q, *t, x, k, **T;
    queue <int> ans;

    scanf("%d",&n);
    scanf("%d",&q);

    t = new int[n+1];
    T = new int*[n+1];

    for (int i=0; i<=n; i++)
        T[i] = new int[m+1];

    for (int i=1; i<=n; i++)
        scanf("%d",&t[i]);

    for (int i=1; i<=n; i++)
        T[i][0] = t[i];

    for (int j=1; j<=m; j++)
        for (int i=1; i<=n; i++)
            T[i][j] = T[T[i][j-1]][j-1];

    for (int i=1; i<=q; i++)
    {
        scanf("%d",&x);
        scanf("%d",&k);

        ans.push(C(x, k, T));
    }

    while (!ans.empty())
    {
        printf("%d\n", ans.front());
        ans.pop();
    }

    for (int i=1; i<=n; i++)
        delete[] T[i];
    delete[] T;

    delete[] t;

    return 0;
}
