#include <bits/stdc++.h>

using namespace std;

int main()
{
    int *a;
    int n;
    long long total;

    cin >>n;
    a = new int [n+1];

    for (int i = 1 ;i <= n; i++)
        cin >> a[i];

    total = 0;
    for (int i = 1; i <= n - 1; i++)
        if (a[i+1] < a[i])
        {
            total += a[i] - a[i+1];
            a[i+1] = a[i];
        }

    cout << total;

    delete[] a;

    return 0;
}
