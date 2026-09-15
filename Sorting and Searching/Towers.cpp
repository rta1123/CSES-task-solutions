#include <bits/stdc++.h>

using namespace std;

typedef uint64_t lint;

int main()
{
    lint n, *k, count;
    multiset <lint> tree;

    cin >> n;

    k = new lint[n+1];

    for (lint i=1;i<=n;i++)
        cin >> k[i];

    count = 1;
    tree.insert(k[1]);
    for (lint i=2;i<=n;i++)
    {
        if (tree.upper_bound(k[i]) == tree.end())
        {
            count++;
            tree.insert(k[i]);
        }
        else
        {
            tree.erase(tree.upper_bound(k[i]));
            tree.insert(k[i]);
        }
    }

    cout << count;

    delete[] k;

    return 0;
}
