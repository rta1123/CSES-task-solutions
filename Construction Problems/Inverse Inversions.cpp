#include <bits/stdc++.h>

using namespace std;

int main()
{
    int64_t n, k, i, m, M;

    cin >> n;
    cin >> k;

    i = m = 1, M = n;

    while (i <= n)
    {
        if (k >= (M - m))
        {
            cout << M << ' ';
            k -= (M - m);
            M--;
        }
        else
        {
            cout << m << ' ';
            m++;
        }

        i++;
    }

    cout << endl;

    return 0;
}
