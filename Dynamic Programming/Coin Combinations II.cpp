#include <bits/stdc++.h>

using namespace std;

#define p 1000000007

typedef uint64_t lint;

lint max(lint u, lint v)
{
    if (u>=v)
        return u;
    else
        return v;
}

int main()
{
    lint n, x, *dp;
    lint *c;

    cin >> n;
    cin >> x;

    dp = new lint[x+1];
    c = new lint[n+1];

    for (lint i=1;i<=n;i++)
        cin >> c[i];

    sort(c,c+n+1);

    dp[0] = 1;
    for (lint i=1;i<=n;i++)
        for (lint j=1;j<=x;j++)
        {
            if (j>=c[i])
                dp[j]+=dp[j-c[i]] % p;
            dp[j] = dp[j] % p;
        }

    cout << dp[x] % p;

    delete[] dp;
    delete[] c;

    return 0;
}
