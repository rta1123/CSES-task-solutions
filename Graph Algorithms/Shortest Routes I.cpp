#include <bits/stdc++.h>

using namespace std;

typedef int64_t lint;

lint min(lint u, lint w)
{
    if (u<=w)
        return u;
    else
        return w;
}

int main()
{
    lint n,m,u,w,d,x;
    vector <pair<lint,lint>> *v;
    priority_queue <pair<lint,lint>, vector<pair<lint,lint>>, greater<pair<lint,lint>>> q;
    lint *dist;
    bool *p;

    cin >> n;
    cin >> m;

    v = new vector <pair<lint,lint>> [n+1];
    dist = new lint[n+1];
    p = new bool [n+1];

    for (lint i=1;i<=m;i++)
    {
        cin >> u;
        cin >> w;
        cin >> d;
        v[u].push_back({d,w});
    }

    for (lint i=1;i<=n;i++)
        dist[i] = INFINITY;
    dist[1] = 0;
    q.push({0,1});

    while (!q.empty())
    {
        u = q.top().second;
        q.pop();

        if (p[u])
            continue;

        p[u] = true;

        for (auto y:v[u])
        {
            if (dist[u]+y.first < dist[y.second])
            {
                dist[y.second] = dist[u]+y.first;
                q.push({dist[y.second],y.second});
            }
        }
    }

    for (lint i=1;i<=n;i++)
        cout << dist[i] << " ";


    delete[] v;
    delete[] dist;
    delete[] p;

    return 0;
}
