#include <bits/stdc++.h>

using namespace std;

int max(int u, int v)
{
    if (u >= v)
        return u;
    else
        return v;
}

int main()
{
    int n, k, K, a, b, *R;
    pair<int, int> c;
    vector <pair <int, int>> T;
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> qn, qk;
    priority_queue <int, vector<int>, greater<int>> r;

    cin >> n;

    T.push_back({0,0});
    for (int i=1; i<=n; i++)
    {
        cin >> a;
        cin >> b;

        T.push_back({a, b});
    }

    for (int i=1; i<=n; i++)
    {
        qn.push({T[i].first, i});
        qk.push({T[i].second, i});
    }

    k = {}, K = {};
    do
    {
        c = qn.top();
        qn.pop();
        k++;

        while ((!qk.empty()) and (c.first > qk.top().first))
        {
            qk.pop();
            k--;
        }

        K = max(K, k);

    }while (!qn.empty());

    while (!qk.empty())
        qk.pop();

    R = new int[n+1];

    for (int i=0; i<=n; i++)
        R[i] = 0;

    for (int i=1; i<=n; i++)
    {
        qn.push({T[i].first, i});
        qk.push({T[i].second, i});
    }

    for (int i=1; i<=K; i++)
        r.push(i);

    do
    {
        c = qn.top();
        qn.pop();

        while ((!qk.empty()) and (c.first > qk.top().first))
        {
            r.push(R[qk.top().second]);
            qk.pop();
        }

        R[c.second] = r.top();
        r.pop();

    }while (!qn.empty());

    cout << K << endl;
    for (int i=1; i<=n; i++)
        cout << R[i] << ' ';
    cout << endl;

    delete[] R;

    return 0;
}

