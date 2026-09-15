#include <bits/stdc++.h>

using namespace std;

enum {N = 1000000};

int main()
{
    int n, k, *d, *p, ans;

    cin >> n;

    d = new int[N+1];
    p = new int[N+1];

    for (int i=1; i<=N; i++)
    {
        d[i] = {};
        p[i] = {};
    }

    for (int i=1; i<=n; i++)
    {
        cin >> k;
        d[k]++;
    }

    for (int i=2; i<=N; i++)
    {
        if (p[i])
            continue;

        for (int j=i; j<=N; j+=i)
            if (d[j])
                p[i] += d[j];
    }

    ans = 1;
    for (int i=N; i>=1; i--)
        if (d[i] > 1 or p[i] > 1)
        {
            ans = i;
            break;
        }

    cout << ans << endl;

    delete[] d;
    delete[] p;

    return 0;
}
