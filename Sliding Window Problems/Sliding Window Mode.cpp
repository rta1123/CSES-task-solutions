#include <bits/stdc++.h>

using namespace std;

struct cmp
{
    bool operator() (const pair<int, int> &lhs, const pair<int, int> &rhs)
    {
        if (lhs.first < rhs.first)
        {
            return false;
        }
        else
            if (lhs.first == rhs.first)
            {
                if (lhs.second >= rhs.second)
                    return false;
                else
                    return true;
            }
            else
                return true;
    }
};

int main()
{
    int n, k, *x, f, y;
    set <pair<int, int>, cmp> s;
    map <int, int> m;
    queue <int> q, ans;

    cin >> n;
    cin >> k;

    x = new int[n+1];
    for (int i=1; i<=n; i++)
        cin >> x[i];

    for (int i=1; i<=k; i++)
    {
        q.push(x[i]);

        if (m.find(x[i]) == m.end())
        {
            s.insert({1, x[i]});
            m.insert({x[i], 1});
        }
        else
        {
           f = m.find(x[i])->second;
           m.erase({x[i]});
           m.insert({x[i], f+1});

           s.erase({f, x[i]});
           s.insert({f+1, x[i]});
        }
    }
    ans.push(s.begin()->second);

    for (int i=k+1; i<=n; i++)
    {
        y = q.front();
        f = m.find(y)->second;

        m.erase({y});
        s.erase({f, y});

        if (f > 1)
        {
            m.insert({y, f-1});
            s.insert({f-1, y});
        }

        q.pop();
        q.push(x[i]);

        if (m.find(x[i]) == m.end())
        {
            s.insert({1, x[i]});
            m.insert({x[i], 1});
        }
        else
        {
           f = m.find(x[i])->second;
           m.erase({x[i]});
           m.insert({x[i], f+1});

           s.erase({f, x[i]});
           s.insert({f+1, x[i]});
        }

        ans.push(s.begin()->second);
    }

    while (!ans.empty())
    {
        cout << ans.front() << " ";
        ans.pop();
    }
    cout << endl;

    delete[] x;

    return 0;
}
