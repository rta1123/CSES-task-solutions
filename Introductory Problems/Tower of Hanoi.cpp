#include <bits/stdc++.h>

using namespace std;

void SHT(int l, int m, int r, int n, queue <pair<int,int>> &mv)
{
    if (n == 1)
    {
        mv.push({l, r});
    }
    else
    {
        SHT(l, r, m, (n - 1), mv);
        mv.push({l, r});
        SHT(m, l, r, (n - 1), mv);
    }
}

int main()
{
    int n {};
    queue <pair<int, int>> mv {};

    cin >> n;

    SHT(1, 2, 3, n, mv);

    cout << mv.size() << endl;

    while (!mv.empty())
    {
        cout << mv.front().first << " " << mv.front().second << endl;
        mv.pop();
    }

    return 0;
}
