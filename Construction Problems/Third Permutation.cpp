#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, k, *a, *b, *c, *inv_a;
    vector <vector <int>> idxs, idxs_2;
    bool *p;

    cin >> n;

    a = new int[n+1];
    b = new int[n+1];
    c = new int[n+1];
    inv_a = new int[n+1];
    p = new bool[n+1];

    for (int i=1; i<=n; i++)
        cin >> a[i];

    for (int i=1; i<=n; i++)
        cin >> b[i];

    if (n == 2)
    {
        delete[] a;
        delete[] b;
        delete[] c;
        delete[] inv_a;
        delete[] p;

        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    for (int i=1; i<=n; i++)
    {
        inv_a[a[i]] = i;
        p[i] = false;
    }

    for (int i=1; i<=n; i++)
    {
        vector <int> idx {};
        int j = i;

        if (p[j])
            continue;
        do
        {
            p[j] = true;
            idx.push_back(j);
            j = inv_a[b[j]];

        }while (a[i] != b[j]);

        p[j] = true;
        idx.push_back(j);

        if (idx.size() == 2)
            idxs_2.push_back(idx);
        else
            idxs.push_back(idx);
    }

    m = idxs.size();
    for (int i=0; i<m; i++)
        for (auto j : idxs[i])
            c[j] = b[inv_a[b[j]]];

    k = idxs_2.size();
    for (int i=0; i<k; i++)
        for (auto j : idxs_2[i])
            c[j] = b[inv_a[b[j]]];

    if (k == 1)
    {
        auto u = c[idxs_2[0][0]];
        auto v = c[idxs_2[0][1]];

        c[idxs_2[0][0]] = c[idxs[0][0]];
        c[idxs_2[0][1]] = c[idxs[0][1]];

        c[idxs[0][0]] = u;
        c[idxs[0][1]] = v;
    }
    else
        if (k >= 2)
        {
            auto u = c[idxs_2[0][0]];
            auto v = c[idxs_2[0][1]];

            for (int i=1; i<k; i++)
            {
                c[idxs_2[i-1][0]] = c[idxs_2[i][0]];
                c[idxs_2[i-1][1]] = c[idxs_2[i][1]];
            }

            c[idxs_2[k-1][0]] = u;
            c[idxs_2[k-1][1]] = v;
        }

    for (int i=1; i<=n; i++)
        cout << c[i] << ' ';
    cout << endl;

    delete[] a;
    delete[] b;
    delete[] c;
    delete[] inv_a;
    delete[] p;

    return 0;
}
