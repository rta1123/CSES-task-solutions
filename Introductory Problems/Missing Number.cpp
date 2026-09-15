#include <bits/stdc++.h>

using namespace std;

int main()
{
    bool *a;
    int n, k;

    cin >> n;

    a = new bool[n+1];

    for (int i = 1; i <= n; i++)
        a[i] = false;

    for (int i = 1; i <= n - 1; i++)
    {
        cin >> k;
        a[k] = true;
    }

    for (int i = 1; i <= n; i++)
    {
        if (a[i]==false)
        {
            cout << i;
            break;
        }
    }


    delete[] a;

    return 0;
}
