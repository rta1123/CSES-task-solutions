#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, l, r, m;
    char *c;

    cin >> n;

    c = new char[n+1];

    for (int i=0; i<=n; i++)
        c[i] = 'U';

    l = 0, r = n, m = n / 2;

    cout << "? " << l+1 << endl;
    cin >> c[l];

    cout << "? " << m+1 << endl;
    cin >> c[m];

    c[r] = c[l];

    while ((r - l) > 1)
    {
        if ((m - l - 1) % 2)
        {
            if (c[l] == c[m])
            {
                l = m;
                m = (r + l) / 2;
            }
            else
            {
                r = m;
                m = (r + l) / 2;
            }
        }
        else
        {
            if (c[l] == c[m])
            {
                r = m;
                m = (r + l) / 2;
            }
            else
            {
                l = m;
                m = (r + l) / 2;
            }
        }

        cout << "? " << m+1 << endl;
        cin >> c[m];
    }

    cout << "!" << l+1 << endl;

    delete[] c;

    return 0;
}
