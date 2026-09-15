#include <bits/stdc++.h>

using namespace std;

int main()
{
    uint64_t n, x, l, r;
    vector <pair <uint64_t, uint64_t>> a;
    pair <uint64_t, uint64_t> p, solve;

    cin >> n;
    cin >> x;


    for (uint64_t i=0;i<n;i++)
    {
        cin >> p.first;
        p.second = i;
        a.push_back(p);
    }

    sort(a.begin(),a.end());

    l = 0;
    r = n-1;
    solve = {0,0};

    while (a[r].first > x)
        r--;

    while (l<r)
    {
        while (l<r)
        {
            if (a[l].first + a[r].first <= x)
            {
                if (a[l].first + a[r].first == x)
                {
                    if (a[l].second > a[r].second)
                        solve = {a[r].second, a[l].second};
                    else
                        solve = {a[l].second, a[r].second};

                    break;
                }
                else
                    l++;
            }
            else
                break;
        }

        r--;
    }

    if (solve.first == 0 && solve.second == 0)
        cout << "IMPOSSIBLE";
    else
        cout << solve.first+1 << " " << solve.second+1;

    return 0;
}
