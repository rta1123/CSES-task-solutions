#include <bits/stdc++.h>

using namespace std;

int main()
{
    int l, r, m;
    string ans;

    l = 0;
    r = 1000000001;

    while ((r - l) > 1)
    {
        m = (r + l) / 2;

        cout << "? "<< m << endl;
        cin >> ans;

        if (ans == "YES")
            l = m;
        else
            r = m;
    }

    cout << "! " << r << endl;

    return 0;
}
