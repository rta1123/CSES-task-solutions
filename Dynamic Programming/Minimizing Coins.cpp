#include <bits/stdc++.h>

using namespace std;

#define MAX 1000007

int64_t min(int64_t u, int64_t v)
{
    if (u <= v)
        return u;
    else
        return v;
}

int main()
{
    int64_t n, x, *c, *dp;

    cin >> n;
    cin >> x;

    c = new int64_t[n+1];
    dp = new int64_t[x+1];

    for (int64_t i=1; i<=n ;i++)
        cin >> c[i];

    dp[0] = 0;
    for(int64_t i=1; i<=x; i++)
        dp[i] = MAX;

    for(int64_t i=1; i<=x; i++)
        for (int64_t j=1; j<=n;j++)
            if (i - c[j]>=0)
                dp[i] = min(dp[i],dp[i-c[j]] + 1);

    if (dp[x] == MAX)
        cout << -1;
    else
        cout << dp[x];

    delete[] c;
    delete[] dp;

    return 0;
}
