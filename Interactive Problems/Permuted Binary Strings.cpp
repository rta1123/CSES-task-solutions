#include <bits/stdc++.h>

using namespace std;

enum {N = 1000};

int main()
{
    int n, m, *p, *a;
    bitset<N> _1, AND;
    bitset<N> *ask;
    bitset<N> *ans;

    cin >> n;

    m = ceil(log2(n));
    ask = new bitset<N>[m];
    ans = new bitset<N>[m];
    p = new int[n+1];
    a = new int[n+1];

    for (int i=1; i<=n; i++)
        p[i] = a[i] = i;

    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            ask[j][i] = ((i+1) & (1 << j));

    for (int i=0; i<m; i++)
    {
        cout << "? ";
        for (int j=0; j<n; j++)
             cout << ask[i][j];
        cout << endl;
        cin >> ans[i];
    }

    _1.set();
    for (int j=0; j<n; j++)
    {
        for (int i=0; i<m; i++)
            if (ask[i][j] == 0)
                ans[i] ^= _1;

        AND = ans[0];
        for (int i=1; i<m; i++)
            AND &= ans[i];

        for (int i=0; i<m; i++)
            if (ask[i][j] == 0)
                ans[i] ^= _1;

        p[j+1] = n - AND._Find_first();
    }

    for (int i=1; i<=n; i++)
        a[p[i]] = i;

    cout << "! ";
    for (int i=1; i<=n; i++)
        cout << a[i] << " ";
    cout << endl;

    delete[] ask;
    delete[] ans;
    delete[] p;
    delete[] a;

    return 0;
}
