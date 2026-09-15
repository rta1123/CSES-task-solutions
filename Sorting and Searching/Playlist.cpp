#include <bits/stdc++.h>

using namespace std;

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
    lint n, *k, x, count, best;
    queue <lint> q;
    set <lint> h;

    cin >> n;

    k = new lint[n+1];

    for (lint i=1;i<=n;i++)
        cin >> k[i];

    best = 1;
    count = 0;
    for (lint i=1;i<=n;i++)
    {
        if (h.find(k[i])!=h.end())
        {
            x = q.front();
            while (x!=k[i])
            {
                h.erase(x);
                q.pop();
                count--;
                x = q.front();
            }

            h.erase(k[i]);
            q.pop();
            count--;
        }

        h.insert(k[i]);
        q.push(k[i]);
        count++;

        best = max(best, count);
    }

    cout << best;

    delete[] k;

    return 0;
}
