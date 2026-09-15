#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;

ll max(ll u, ll v)
{
    if (u >= v)
        return u;
    else
        return v;
}

struct point_xy
{
    ll x, y;

    bool operator()(const point_xy &p1, const point_xy &p2) const { return (p1.x + p1.y) > (p2.x + p2.y); }

    point_xy() : x(0), y(0) {};
    point_xy(ll x, ll y) : x(x), y(y) {};
};

struct point_xY
{
    ll x, y;

    bool operator()(const point_xY &p1, const point_xY &p2) const { return (-p1.x + p1.y) < (-p2.x + p2.y); }

    point_xY() : x(0), y(0) {};
    point_xY(ll x, ll y) : x(x), y(y) {};
};

struct point_Xy
{
    ll x, y;

    bool operator()(const point_Xy &p1, const point_Xy &p2) const { return (-p1.x + p1.y) > (-p2.x + p2.y); }

    point_Xy() : x(0), y(0) {};
    point_Xy(ll x, ll y) : x(x), y(y) {};
};

struct point_XY
{
    ll x, y;

    bool operator()(const point_XY &p1, const point_XY &p2) const { return (p1.x + p1.y) < (p2.x + p2.y); }

    point_XY() : x(0), y(0) {};
    point_XY(ll x, ll y) : x(x), y(y) {};
};

int main()
{
    ll n, x, y, dist;
    priority_queue <point_xy, vector<point_xy>, point_xy> q1;
    priority_queue <point_xY, vector<point_xY>, point_xY> q2;
    priority_queue <point_Xy, vector<point_Xy>, point_Xy> q3;
    priority_queue <point_XY, vector<point_XY>, point_XY> q4;
    queue <ll> ans;

    cin >> n;

    dist = {};

    for (int i=1; i<=n; i++)
    {
        cin >> x;
        cin >> y;

        q1.push({x,y});
        q2.push({x,y});
        q3.push({x,y});
        q4.push({x,y});

        dist = max(dist, fabs(x - q1.top().x) + fabs(y - q1.top().y));
        dist = max(dist, fabs(x - q2.top().x) + fabs(y - q2.top().y));
        dist = max(dist, fabs(x - q3.top().x) + fabs(y - q3.top().y));
        dist = max(dist, fabs(x - q4.top().x) + fabs(y - q4.top().y));

        ans.push(dist);
    }

    while (!ans.empty())
    {
        cout << ans.front() << endl;
        ans.pop();
    }

    return 0;
}
