#include <bits/stdc++.h>

#pragma GCC target("popcnt")

using namespace std;

enum {N = 3000, base = 10};

int main()
{
    int n;
    __uint128_t k, m;
    stack <int> ans;
    string str;
    bitset <N> bs[N] {};

    cin >> n;

    for (int i=0; i<n; i++)
    {
        cin >> str;
        for (int j=0; j<n; j++)
            bs[i][j] = (str[j] == '1' ? 1 : 0);
    }

    k = {};
    for (int i=0; i<n-1; i++)
        for (int j=i+1; j<n; j++)
        {
            m = (bs[i] & bs[j]).count();

            k += m*(m-1)/2;
        }

    while (k)
    {
        ans.push(k % base);
        k /= base;
    }

    while (!ans.empty())
    {
        cout << ans.top();
        ans.pop();
    }
    cout << endl;

    return 0;
}
