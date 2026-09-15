#include <bits/stdc++.h>

using namespace std;

int main()
{
    uint32_t n, t1,t2, M;
    set <pair<uint32_t,uint32_t>> s;
    vector <pair<uint32_t,uint32_t>> a;
    pair<uint32_t,uint32_t> p;

    cin >> n;

    for (uint32_t i=0;i<n;i++)
    {
        cin >> t1;
        cin >> t2;
        s.insert({t1,t2});
    }

    for (auto x : s)
        a.push_back(x);

    n = a.size();
    M = 1;
    p = a[0];
    for (uint32_t i=1;i<n;i++)
    {
        while (a[i].second < p.second)
            p = a[i];

        if (a[i].first >= p.second)
        {
            M++;
            p = a[i];
        }
    }

    cout << M;

    return 0;
}
