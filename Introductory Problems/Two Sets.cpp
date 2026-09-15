#include <bits/stdc++.h>

using namespace std;

bool solve(bool *s, int64_t sum, int64_t n)
{
    if (sum == 0)
        return true;

    if (sum < 0)
        return false;

    if (n == 0)
        return false;

    s[n] = true;
    if (solve(s, sum - n, n-1))
        return true;
    else
    {
        s[n] = false;
        if (solve(s, sum, n-1))
            return true;
    }

    return false;
}

int main()
{
    int64_t n, count;
    int64_t sum;
    bool *s;

    cin >> n;

    sum = (n * (n + 1)) / 2;

    if (sum % 2 == 1)
    {
        cout << "NO" << endl;
        return 0;
    }
    else
        sum = sum / 2;

    s = new bool[n+1];

    if (solve(s,sum,n))
    {
        cout << "YES" << endl;
        count = 0;
        for (uint i=1; i<=n;i++)
            if (s[i])
                count++;
        cout << count << endl;
        for (uint i=1; i<=n;i++)
            if (s[i])
                cout << i << " ";
        cout << endl << n - count << endl;
        for (uint i=1; i<=n;i++)
            if (!s[i])
                cout << i << " ";
    }
    else
        cout << "NO";

    delete[] s;

    return 0;
}
