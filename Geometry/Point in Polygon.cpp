#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

enum
{
    left_rot = 1,
    right_rot = -1,
};

typedef int64_t ll;
typedef pair <ll, ll> point;

ll sgn(ll n)
{
    if (n > 0)
        return 1;
    else
        if (n == 0)
            return 0;
        else
            return -1;
}

ll operator * (const point &p1, const point &p2)
{
    return p1.x * p2.y - p1.y * p2.x;
}

bool operator == (const point &p1, const point &p2)
{
    if (p1.x == p2.x and p1.y == p2.y)
        return true;
    else
        return false;
}

point operator - (const point &p1, const point &p2)
{
    return {p1.x - p2.x, p1.y - p2.y};
}

istream & operator >> (istream &strm, point &p)
{
    strm >> p.x;
    strm >> p.y;

    return strm;
}

ll rot(const point &s1, const point &s2, const point &p)
{
    return sgn((p - s1) * (p - s2));
}

bool on_seg(const point &s1, const point &s2, const point &p)
{
    if ((s1 == p) or (s2 == p))
        return true;

    if (((s1.x <= p.x and p.x <= s2.x) or (s2.x <= p.x and p.x <= s1.x)) and ((s1.y <= p.y and p.y <= s2.y) or (s2.y <= p.y and p.y <= s1.y)))
        return true;

    return false;
}

int solution(vector <point> &P, const int &n, const point &p)
{
    int curr_rot {};
    stack <point> s {};

    if ((rot(P[n], P[1], p) == 0) and on_seg(P[n], P[1], p))
        return 0;

    for (int i=1; i<=n-1; i++)
        if ((rot(P[i], P[i+1], p) == 0) and on_seg(P[i], P[i+1], p))
            return 0;

    for (int i=1; i<=n; i++)
    {
        while (!s.empty() and rot(s.top(), P[i], p) != curr_rot)
            s.pop();

        if (s.empty())
            curr_rot = rot(P[n], P[i], p);

        s.push(P[i]);
    }

    if (s.size() >= 3)
        return 1;
    else
        return -1;
}

int main()
{
    int n, m;
    point  *p;
    queue <int> ans;
    vector <point> P;

    cin >> n;
    cin >> m;

    p = new point[m+1];

    P.push_back({0, 0});
    for (int i=1; i<=n; i++)
    {
        P.push_back({0, 0});
        cin >> P[i];
    }

    for (int i=1; i<=m; i++)
        cin >> p[i];

    for (int i=1; i<=m; i++)
        ans.push(solution(P, n, p[i]));

    while (!ans.empty())
    {
        if (ans.front() == -1)
            cout << "OUTSIDE";
        else
            if (ans.front() == 0)
                cout << "BOUNDARY";
            else
                cout << "INSIDE";

        ans.pop();
        cout << endl;
    }

    delete[] p;

    return 0;
}
