#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x;
    pair<int,int> *a;
    vector <int> ans;

    cin >> n;
    cin >> x;

    if (n <= 3)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    a = new pair<int,int>[n+1];

    for (int i=1; i<=n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a + 1, a + n + 1);

    for (int i=1; i<=n; i++)
    {
        bool exist = false;

        x -= a[i].first;

        for (int j=i+1; j<=n; j++)
        {
            x -= a[j].first;

            int p = j+1;
            int q = n;

            while (p < q)
            {
                if (a[p].first + a[q].first > x)
                    q--;
                else
                    if (a[p].first + a[q].first < x)
                        p++;
                else
                    {
                        ans.push_back(a[i].second);
                        ans.push_back(a[j].second);
                        ans.push_back(a[p].second);
                        ans.push_back(a[q].second);
                        exist = true;
                        break;
                    }
            }

            x += a[j].first;

            if (exist)
                break;
        }


        x += a[i].first;

        if (exist)
            break;
    }

    if (ans.size() != 4)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        sort(ans.begin(), ans.end());

        for (auto pos : ans)
            cout << pos << ' ';
        cout << endl;
    }

    delete[] a;

    return 0;
}
