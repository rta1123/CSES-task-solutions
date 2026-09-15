#include <bits/stdc++.h>

using namespace std;

int max(int u, int v)
{
    if (u >= v)
        return u;
    else
        return v;
}

void S(int n, int m, int *a, int *b, int **l, queue <int> &ans)
{
    int p = 1;
    int q = 1;
    int k = l[1][1];
    int i = 1;
    int j = 1;

    while (i <= n)
    {
        while (j <= m)
        {
            if ((a[i] == b[j]) and (k == l[i][j]) and (p <= i) and (q <= j))
            {
                p = i+1;
                q = j+1;
                ans.push(a[i]);
                k--;
            }

            j++;
        }

        i++;
        j=q;
    }
}

int L(int i, int j, int n, int m, int *a, int *b, int **l)
{    
    if ((i > n) or (j > m))
        return 0;

    if (l[i][j]!= -1)
        return l[i][j];

    if (a[i] == b[j])
        l[i][j] = max(max(L(i+1, j, n, m, a, b, l), L(i, j+1, n, m, a, b, l)), 1 + L(i+1, j+1, n, m, a, b, l));
    else
        l[i][j] = max(L(i+1, j, n, m, a, b, l), L(i, j+1, n, m, a, b, l));

    return l[i][j];
}

int main()
{
    int n, m, *a, *b, **l;
    queue <int> ans;

    cin >> n;
    cin >> m;

    a = new int[n+1];
    b = new int[m+1];
    l = new int*[n+1];
    for  (int i=0; i<=n; i++)
        l[i] = new int[m+1];

    for (int i=1; i<=n; i++)
        cin >> a[i];

    for (int i=1; i<=m; i++)
        cin >> b[i];

    for (int i=0; i<=n; i++)
        for (int j=0; j<=m; j++)
            l[i][j] = -1;

    cout << L(1, 1, n, m, a, b, l) << endl;

    S(n, m, a, b, l, ans);

    while (!ans.empty())
    {
        cout << ans.front() << ' ';
        ans.pop();
    }

    delete[] a;
    delete[] b;
    for  (int i=0; i<=n; i++)
        delete[] l[i];
    delete[] l;

    return 0;
}
