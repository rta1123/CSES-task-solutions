#include <bits/stdc++.h>

using namespace std;

int main()
{
    int64_t n, *x, *p, k, count;

    cin >> n;

    x = new int64_t[n+1];
    p = new int64_t[n+1];
    for (int64_t i=1;i<=n;i++)
        cin >> x[i];

    for (int64_t i=1;i<=n;i++)
        p[x[i]] = i;


    count = 1, k = n;

    while (k>=2)
    {
        if (p[k-1]>p[k])
            count++;
        k--;
    }

    cout << count;

    delete[] x;
    delete[] p;

    return 0;
}
