#include <bits/stdc++.h>

using namespace std;

bool comparator(tuple <int, int, int> &s1, tuple <int, int, int> &s2)
{
    int a, b, p, c, d, q;

    tie(a, b, p) = s1;
    tie(c, d, q) = s2;

    if (a < c)
        return true;
    else
        if ((a == c) and (b > d))
            return true;

    return false;
}

int max(int u, int v)
{
    if (u >= v)
        return u;
    else
        return v;
}

int min(int u, int v)
{
    if (u <= v)
        return u;
    else
        return v;
}

int main()
{
    int n, a, b, p, c, d, q;
    vector <tuple <int, int, int>> seg;

    int *contains;
    int *contained;

    cin >> n;

    contains = new int[n+1];
    contained = new int[n+1];

    for (int i=0; i<n; i++)
    {
        cin >> a;
        cin >> b;
        seg.push_back({a, b, i+1});

        contains[i+1] = false;
        contained[i+1] = false;
    }

    sort(seg.begin(), seg.end(), comparator);

    tie(a, b, p) = seg[n-1];
    for (int i=n-2; i>=0; i--)
    {
        tie(c, d, q) = seg[i];

        if (d >= b)
            contains[q] = true;

        b = min(b, d);
    }

    tie(a, b, p) = seg[0];
    for (int i=1; i<n; i++)
    {
        tie(c, d, q) = seg[i];

        if (d <= b)
            contained[q] = true;

        b = max(b, d);
    }

    for (int i=0; i<n-1; i++)
    {
        tie(a, b, p) = seg[i];
        tie(c, d, q) = seg[i+1];

        if ((a == c) and (b == d))
        {
            contains[p] = contains[q] = true;
            contained[p] = contained[q] = true;
        }
    }

    for (int i=1; i<=n; i++)
        cout << contains[i] << ' ';
    cout << endl;

    for (int i=1; i<=n; i++)
        cout << contained[i] << ' ';
    cout << endl;

    delete[] contains;
    delete[] contained;

    return 0;
}
