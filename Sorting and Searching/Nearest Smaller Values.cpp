#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    pair <int,int> *x;
    vector <pair<int,int>> v;

    cin >> n;

    x = new pair<int,int>[n+1];

    x[0] = {0, 0};
    for (int i=1; i<=n; i++)
    {
        cin >> x[i].first;
        x[i].second = i;
    }

    cout << 0 << ' ';
    v.push_back(x[1]);

    for (int i=2; i<=n; i++)
    {
        if (v.back().first < x[i].first)
        {
            cout << v.back().second << ' ';
            v.push_back(x[i]);
        }
        else
        {
            while (!v.empty() and (x[i].first <= v.back().first))
                v.pop_back();

            if (v.empty())
                cout << 0 << ' ';
            else
                cout << v.back().second << ' ';

            v.push_back(x[i]);
        }
    }

    cout << endl;

    delete[] x;

    return 0;
}
