#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, u, v;
    queue <pair <int, int>> ans;

    cin >> n;
    cin >> m;

    for (int i=1; i<=m; i++)
    {
        cin >> u;
        cin >> v;

        if (u < v)
            ans.push({u, v});
        else
            ans.push({v, u});
    }

    while (!ans.empty())
    {
        cout << ans.front().first << " " << ans.front().second << endl;
        ans.pop();
    }

    return 0;
}
