#include <bits/stdc++.h>

using namespace std;

int main()
{
    int64_t n, x, *c;
    uint64_t *dp;

    cin >> n;
    cin >> x;

    c = new int64_t[n+1];
    dp = new uint64_t[x+1];

    for (int64_t i=1; i<=n;i++)
        cin >> c[i];

    dp[0]=1;
    for (int64_t i=1; i<=x;i++)
        for (int64_t j=1; j<=n; j++)
            if (i - c[j]>=0)
                dp[i] = (dp[i] + dp[i - c[j]]) % 1000000007;

    cout << dp[x];

    delete[] c;
    delete[] dp;

    return 0;
}
