#include <bits/stdc++.h>

using namespace std;

uint64_t max(uint64_t u, uint64_t v)
{
    if (u>=v)
        return u;
    else
        return v;
}

uint64_t min(uint64_t u, uint64_t v)
{
    if (u<=v)
        return u;
    else
        return v;
}

int main()
{
    uint64_t t, *a, *b;
    bool *s;

    cin >> t;

    a = new uint64_t[t+1];
    b = new uint64_t[t+1];
    s = new bool[t+1];

    for (uint64_t i=1; i<=t; i++)
    {
        cin >> a[i];
        cin >> b[i];
    }

    for (uint64_t i=1;i<=t;i++)
    {
        uint64_t sum = a[i] + b[i];
        uint64_t dist = sum / 3;

        if (sum % 3 == 0)
            if ((max(a[i],b[i]) - min(a[i],b[i])) <= dist)
                s[i] = true;
    }

    for (uint32_t i=1; i<=t; i++)
    {
        if (s[i])
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }


    delete[] a;
    delete[] b;
    delete[] s;

    return 0;
}
