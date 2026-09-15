#include <bits/stdc++.h>

using namespace std;

bool comparator(pair <int,int> &t1, pair<int,int> &t2)
{
    if (t1.second < t2.second)
        return true;
    else
        if ((t1.second == t2.second) and (t1.first <= t2.first))
            return true;

    return false;
}

int main()
{
    int n, k, j;
    pair <int, int> *t;
    multiset <int, greater<int>> T;

    cin >> n;
    cin >> k;

    t = new pair<int,int>[n+1];

    for (int i=1; i<=n; i++)
    {
        cin >> t[i].first;
        cin >> t[i].second;
    }

    sort(t+1, t+n+1, comparator);

    j = 0;
    for (int i=1; i<=n; i++)
    {
        if (T.empty())
        {
            T.insert(t[i].second);
            j++;
        }
        else
            if (T.lower_bound(t[i].first) != T.end())
            {
                T.erase(T.lower_bound(t[i].first));
                T.insert(t[i].second);
                j++;
            }
            else
                if (int(T.size()) < k)
                {
                    T.insert(t[i].second);
                    j++;
                }
    }

    cout << j << endl;

    delete[] t;

    return 0;
}
