#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, *c, *k;
    priority_queue <int, vector<int>, greater<int>> q;
    vector <pair<int,int>> t;

    cin >> n;

    k = new int[n + 1];
    c = new int[n - 1];

    for (int i=1; i<=n; i++)
        k[i] = 0;

    for (int i=1; i<=n-2; i++)
        cin >> c[i];

    for (int i=1; i<=n-2; i++)
        k[c[i]]++;

    for (int i=1; i<=n; i++)
        if (!k[i])
            q.push(i);

    for (int i=1; i<=n-2; i++)
    {
        t.push_back({q.top(), c[i]});

        q.pop();
        k[c[i]]--;
        if (k[c[i]] == 0)
            q.push(c[i]);
    }

    t.push_back({q.top(), 0});
    q.pop();
    t.back().second = q.top();
    q.pop();

    for (auto e : t)
        cout << e.first << " " << e.second << endl;

    delete[] k;
    delete[] c;

    return 0;
}
