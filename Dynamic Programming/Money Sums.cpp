#include <bits/stdc++.h>

using namespace std;

#define M 1000

int main()
{
    int n, k, *X, *x, S, *m;
    bool *s;

    cin >> n;

    x = new int[n+1];
    X = new int[n+1];
    m = new int[n+1];

    for (int i=1; i<=n; i++)
        cin >> x[i];

    sort(x+1, x+n+1);

    m[0] = 1;
    for (int i=1; i<=n; i++)
    {
        if (x[i] == x[i-1])
            m[i] = m[i-1]+1;
        else
            m[i] = 1;
    }

    S = {};
    for (int i=1; i<=n; i++)
    {
        S += x[i];
        X[i] = S;
    }

    s = new bool[S+1];

    s[0] = true;
    for (int i=1; i<=S; i++)
        s[i] = false;

    for (int i=1; i<=n; i++)
        for (int j=X[i]; j>=x[i]*m[i]; j--)
            if (!s[j])
                s[j] = s[j - x[i]];

    k = {};
    for (int i=1; i<=S; i++)
        if (s[i])
            k++;

    cout << k << endl;

    for (int i=1; i<=S; i++)
        if (s[i])
            cout << i << ' ';
    cout << endl;

    delete[] m;
    delete[] s;
    delete[] X;
    delete[] x;

    return 0;
}
