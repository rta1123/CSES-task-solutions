#include <bits/stdc++.h>

using namespace std;

typedef int64_t lint;

int main()
{
    lint n,m;
    lint *p, *max_seg, left, right;
    multiset <lint, greater<lint>> seg;
    set <lint, greater<lint>> up;
    set <lint> down;

    cin >> n;
    cin >> m;

    p = new lint[m+1];
    max_seg = new lint[m+1];

    for (lint i = 1;i<=m;i++)
        cin >> p[i];

    up.insert(0), up.insert(n);
    down.insert(0), down.insert(n);
    seg.insert(n);

    for (lint i=1;i<=m;i++)
    {
        left = *up.lower_bound(p[i]);
        right = *down.upper_bound(p[i]);

        seg.erase(seg.find(right - left));
        seg.insert(right - p[i]);
        seg.insert(p[i] - left);

        if (seg.begin()!=seg.end())
            max_seg[i] = *seg.begin();
        else
            max_seg[i] = 0;

        up.insert(p[i]);
        down.insert(p[i]);

    }

    for (lint i = 1;i<=m;i++)
        cout << max_seg[i] << " ";

    delete[] p;
    delete[] max_seg;

    return 0;
}
