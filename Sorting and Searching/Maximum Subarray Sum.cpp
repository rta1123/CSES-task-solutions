#include <bits/stdc++.h>

using namespace std;

int64_t max(int64_t u, int64_t v)
{
    if (u>=v)
        return u;
    else
        return v;

}

int main()
{
    int64_t n, *x, s, S;

    cin >> n;

    x = new int64_t[n];
    for (int64_t i=0;i<n;i++)
        cin >> x[i];

    S = x[0];
    s = x[0];

    for (int64_t i =1;i<n;i++)
    {
        s = max(s+x[i],x[i]);
        S = max(S,s);
    }

    cout << S;

    delete[] x;

    return 0;
}
