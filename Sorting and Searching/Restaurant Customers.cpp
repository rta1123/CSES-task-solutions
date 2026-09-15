#include <bits/stdc++.h>

using namespace std;

int64_t max(int64_t u, int64_t v)
{
    if (u>=v)
        return u;
    else
        return v;
}

int main()
{
    int64_t n, m, M;
    vector <pair<int64_t,int64_t>> T;
    pair<int64_t,int64_t> t;
    priority_queue <int64_t> customers;

    cin >> n;

    for (int64_t i=1;i<=n;i++)
    {
        cin >> t.first;
        cin >> t.second;
        T.push_back(t);
    }

    sort(T.begin(),T.end());

    M = 1;
    m = 1;
    customers.push(-T[0].second);

    for (int64_t i=1;i<n;i++)
    {
        while (T[i].first > (-1 * customers.top()))
        {
            customers.pop();
            m--;

            if (customers.empty())
                break;
        }

        customers.push(-T[i].second);
        m++;

        M = max(M,m);
    }

    cout << M;

    return 0;
}
