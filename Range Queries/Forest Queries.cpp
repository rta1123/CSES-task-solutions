#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, q, **m, **k, x1, y1, x2, y2, K;
    char s;
    queue <int> ans;

    cin >> n;
    cin >> q;

    m = new int*[n+1];
    for (int i=0; i<=n; i++)
        m[i] = new int[n+1];

    k = new int*[n+1];
    for (int i=0; i<=n; i++)
        k[i] = new int[n+1];

    for (int i=0; i<=n; i++)
        for (int j=0; j<=n; j++)
            m[i][j] = k[i][j] = 0;

    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
        {
            cin >> s;

            if (s  == '.')
                m[i][j] = 0;
            else
                m[i][j] = 1;
        }

    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            k[i][j] = k[i-1][j] + k[i][j-1] - k[i-1][j-1] + m[i][j];

    for (int i=1; i<=q; i++)
    {
        cin >> y1;
        cin >> x1;
        cin >> y2;
        cin >> x2;

        K = k[y2][x2] - k[y2][x1-1] - k[y1-1][x2] + k[y1-1][x1-1];

        ans.push(K);
    }

    while (!ans.empty())
    {
        cout << ans.front() << endl;
        ans.pop();
    }

    for (int i=0; i<=n; i++)
        delete[] k[i];
    delete[] k;

    for (int i=0; i<=n; i++)
        delete[] m[i];
    delete[] m;

    return 0;
}
