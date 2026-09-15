#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;

int main()
{
    ll n, m, u, v, c, C;
    vector <pair<ll, ll>> *adj;
    priority_queue<pair<ll, ll>, vector<pair <ll,ll>>, greater<pair<ll, ll>>> pq;
    set <ll> t;
    bool exist_solution = true;

    cin >> n;
    cin >> m;

    adj = new vector<pair<ll, ll>>[n+1];

    for (ll i=1; i<=m; i++)
    {
        cin >> u;
        cin >> v;
        cin >> c;

        adj[u].push_back({c, v});
        adj[v].push_back({c, u});
    }

    for (auto w : adj[1])
        pq.push(w);
    t.insert(1);

    C = 0;
    while (!pq.empty())
    {
        auto w = pq.top();
        pq.pop();

        c = w.first;
        v = w.second;

        if (t.find(v) != t.end())
            continue;

        t.insert(v);
        C += c;
        for (auto w : adj[v])
            pq.push(w);
    }

    for (ll i=1; i<=n; i++)
        if (t.find(i) == t.end())
        {
            exist_solution = false;
            break;
        }

    if (exist_solution)
        cout << C << endl;
    else
        cout << "IMPOSSIBLE" << endl;

    delete[] adj;

    return 0;
}
