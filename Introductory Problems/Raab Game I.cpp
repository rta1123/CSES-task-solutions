#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, m, k, p, q;

    cin >> t;

    for (int i=1; i<=t; i++)
    {
        cin >> n;
        cin >> m;
        cin >> k;

        if (n == 1)
        {
            if ((k == m) and (k == 0))
            {
                cout << "YES" << endl;
                cout << "1" << endl;
                cout << "1" << endl;
            }
            else
                cout << "NO" << endl;
        }
        else
            if (((m + k) > n) or (((k + m) <= n) and (((k == 0) and (m != 0)) or ((k != 0) and (m == 0)))))
                cout << "NO" << endl;
            else
            {
                cout << "YES" << endl;

                for (int j=1; j<=n; j++)
                    cout << j << ' ';
                cout << endl;

                p = 0;
                while ((n - p) > (m + k))
                {
                    cout << p+1 << ' ';
                    p++;
                }

                q = k;
                while (q >= 1)
                {
                    cout << n - q + 1 << ' ';
                    q--;
                }

                while (p < n - k)
                {
                    cout << p+1 << ' ';
                    p++;
                }

                cout << endl;

            }
    }

    return 0;
}
