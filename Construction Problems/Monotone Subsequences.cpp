#include <bits/stdc++.h>

using namespace std;

enum {inf = 100};

int ceil(int n, int p)
{
    if (n % p)
        return 1 + n/p;
    else
        return n/p;
}

int min(int u, int v)
{
    if (u <= v)
        return u;
    else
        return v;
}

int max(int u, int v)
{
    if (u >= v)
        return u;
    else
        return v;
}

int main()
{
    int n, k, m, c, d, x, t;
    deque <int> perm {};
    queue <int> *ans;

    cin >> t;

    ans = new queue<int>[t+1];

    for (int i=1; i<=t; i++)
    {
        cin >> n;
        cin >> k;

        m = inf;
        for (int j=1; j<=n; j++)
            m = min(m, max(j, ceil(n, j)));

        if (k < m)
            ans[i].push(-1);
        else
        {
            m = inf, c = 1;
            for (int j=1; j<=n; j++)
            {
                c = j;
                m = min(m, max(j, ceil(n, j)));

                if (m <= k)
                    break;
            }

            perm = {};
            d = n - (c-1) * ceil(n, c);
            for (int j=1; j<=c-1; j++)
                for (int p=0; p<ceil(n, c); p++)
                    perm.push_back(j*ceil(n,c) - p);
            for (int p=0; p<d; p++)
                perm.push_back(n-p);

            x = k - m;

            if (x)
            {
                for (int j=1; j<=x; j++)
                {
                    perm.push_front(perm.back());
                    perm.pop_back();
                }
            }

            for (auto e : perm)
                ans[i].push(e);
        }
    }

    for (int i=1; i<=t; i++)
    {
        if (ans[i].front() == -1)
        {
            cout << "IMPOSSIBLE" << endl;
        }
        else
        {
            while (!ans[i].empty())
            {
                cout << ans[i].front() << " ";
                ans[i].pop();
            }
            cout << endl;
        }
    }

    delete[] ans;

    return 0;
}
