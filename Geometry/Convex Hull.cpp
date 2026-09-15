#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef pair <ll, ll> point;

#define x first
#define y second

ll operator * (const point &p1, const point &p2)
{
    return p1.x * p2.y - p1.y * p2.x;
}

point operator - (const point &p1, const point &p2)
{
    return {p1.x - p2.x, p1.y - p2.y};
}

ll sgn(ll w)
{
    if (w > 0)
        return 1;
    else
        if (w == 0)
            return 0;
        else
            return -1;
}

enum
{
    LR = 1,
    RR = -1,
};

ll rotation(const point &s1, const point &s2, const point &p)
{
    return sgn((p - s1)  * (p - s2));
}

int main()
{
    int n, a, b;
    point p;
    vector <point> P;
    vector <point> up, down, out;
    set <point> ECH;

    cin >> n;

    for (int i=1; i<=n; i++)
    {
        cin >> a;
        cin >> b;
        P.push_back({a, b});
    }

    sort(P.begin(), P.end());

    up.push_back(P[0]);
    up.push_back(P[1]);
    for  (int i=2; i<n; i++)
    {
        p = P[i];

        while (up.size() > 2 and rotation(up[up.size() - 2], up[up.size() - 1], p) == LR)
            up.pop_back();

        if (rotation(up[up.size() - 2], up[up.size() - 1], p) != LR)
            up.push_back(p);
        else
            if ((up.size() == 2))
                up[up.size() - 1] = p;
    }

    down.push_back(P[n-1]);
    down.push_back(P[n-2]);
    for  (int i=n-3; i>=0; i--)
    {
        p = P[i];

        while (down.size() > 2 and rotation(down[down.size() - 2], down[down.size() - 1], p) == LR)
            down.pop_back();

        if (rotation(down[down.size() - 2], down[down.size() - 1], p) != LR)
            down.push_back(p);
        else
            if (down.size() == 2)
                down[down.size() - 1] = p;
    }

    for (size_t i=0; i<up.size(); i++)
    {
        if (ECH.find(up[i]) == ECH.end())
        {
            out.push_back(up[i]);
            ECH.insert(up[i]);
        }
    }

    for (size_t i=0; i<down.size(); i++)
    {
        if (ECH.find(down[i]) == ECH.end())
        {
            out.push_back(down[i]);
            ECH.insert(down[i]);
        }
    }

    cout << out.size() << endl;
    for (auto p : out)
        cout << p.x << " " << p.y << endl;

    return 0;
}
