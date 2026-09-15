#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, l, r;
    string ans;

    cin >> n;

    vector <int> a(n+1);
    vector <int> p(n+1);
    for (int i=0; i<=n; i++)
        a[i] = i;

    for (int i=2; i<=n; i++)
    {
        l = 0, r = i;
        do
        {
            m = (l + r) / 2;

            cout << "? " << a[m] << " " << a[i] << endl;

            cin >> ans;

            if (ans == "YES")
                l = m;
            else
                r = m;

        }while ((r - l) > 1);

        a[0] = a[i];
        for (int j=i; j>r; j--)
            a[j] = a[j-1];
        a[r] = i;

    }

    for (int i=1; i<=n; i++)
        p[a[i]] = i;

    cout << "! ";
    for (int i=1; i<=n; i++)
        cout << p[i] << " ";
    cout << endl;

    return 0;
}
