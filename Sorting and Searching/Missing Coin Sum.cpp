#include <bits/stdc++.h>

using namespace std;

int main()
{
    int64_t n, *x, s;

    cin >> n;

    x = new int64_t[n];

    for (int64_t i=0;i<n;i++)
        cin >> x[i];

    sort(x,x+n);

    s = 0;
    for (int64_t i=0;i<n;i++)
    {
        if (s+1<x[i])
            break;

        s+=x[i];
    }

    cout << s+1;

    delete[] x;

    return 0;
}
