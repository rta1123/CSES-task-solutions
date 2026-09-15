#include <bits/stdc++.h>

using namespace std;

bool S(int n, vector <int> P, stack <pair<int,int>> &ans)
{
    size_t i {};
    stack <pair<int, int>> state {};
    bool s {};

    if (n == 1)
    {
        ans.push({1, 1});
        return true;
    }

    while (i < P.size())
    {
        if (n == 0)
        {
            s = true;
            break;
        }
        else
            if (n == 1)
            {
                s = true;
                ans.push({1, 1});
                break;
            }

        if ((n < P[i]) and (P[i] <= 2*n-1))
        {
            state.push({n, i});
            ans.push({P[i] - n, n});

            n = P[i] - n - 1;
        }
        else
            if (P[i] <= n)
            {
                if (state.empty())
                    break;
                else
                {
                    tie(n, i) = state.top();
                    state.pop();
                    ans.pop();
                }
            }

        i++;
    }

    return s;
}

int main()
{
    int n, *a;
    vector <int> P;
    stack <pair<int, int>> ans1, ans2;

    cin >> n;

    a = new int[3*n];

    for (int i=1; i<3*n; i++)
        a[i] = -1;

    for (int i=2; i<3*n; i++)
    {
        if (a[i] == -1)
        {
            a[i] = 1;

            for (int j=2*i; j+i<3*n; j+=i)
                a[j] = 0;
        }
    }

    for (int i=2*n-1; i>=2; i--)
        if (a[i])
            P.push_back(i);

    if (S(n, P, ans1))
    {
        ans2 = ans1;

        while (!ans1.empty())
        {
            for (int i=ans1.top().first; i<=ans1.top().second; i++)
                cout << i << " ";
            ans1.pop();
        }
        cout << endl;

        while (!ans2.empty())
        {
            for (int i=ans2.top().second; i>=ans2.top().first; i--)
                cout << i << " ";
            ans2.pop();
        }
        cout << endl;
    }
    else
        cout << "IMPOSSIBLE" << endl;

    delete[] a;

    return 0;
}
