#include <bits/stdc++.h>

using namespace std;

#define max(u,v) u > v ? u : v

int main()
{
    string str;
    int len, best;

    cin >> str;

    best = len = 1;
    for (size_t i = 0 ; i < str.length() - 1; i++)
    {
        if (str[i] == str[i + 1])
            len++;
        else
            len = 1;

        best = max(best, len);
    }

    cout << best;

    return 0;
}
