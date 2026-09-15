#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int64_t VP(pair <int64_t,int64_t> p1, pair <int64_t,int64_t> p2)
{
    return p1.X * p2.Y - p2.X * p1.Y;
}

int main()
{
    int64_t n,x,y,s;
    pair <int64_t,int64_t> *p;

    cin >> n;

    p = new pair <int64_t,int64_t>[n];

    for (int64_t i =0;i<n;i++)
    {
        cin >> x;
        cin >> y;
        p[i] = {x,y};
    }

    s = 0;
    for (int64_t i =0;i<n-1;i++)
        s += VP(p[i],p[i+1]);
    s+=VP(p[n-1],p[0]);

    if (s < 0)
        s = -s;

    cout << s;

    delete[] p;

    return 0;
}
