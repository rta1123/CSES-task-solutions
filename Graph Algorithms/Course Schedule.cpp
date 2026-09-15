#include <bits/stdc++.h>

using namespace std;

typedef int64_t lint;

lint N;

enum state
{
    not_visited = 0,
    visited = 1,
    in_processing = 2,
};

void dfs(lint u, vector <lint> *adj, lint *num, state *s)
{
    s[u] = in_processing;
    for (auto v : adj[u])
    {
        if (num[0]==0)
            return;

        if (s[v]==visited)
            continue;

        if (s[v]==in_processing)
            num[0] = 0;

        dfs(v,adj,num,s);
    }

    s[u] = visited;
    num[u] = N--;
}

int main()
{
    lint n, m, u, v;
    vector <lint> *adj;
    lint *num, *ss;
    state *s;

    cin >> n;
    cin >> m;

    adj = new vector <lint>[n+1];
    num = new lint[n+1];
    s = new state[n+1];
    ss = new lint[n+1];

    for (lint i=1;i<=m;i++)
    {
        cin >> u;
        cin >> v;
        adj[u].push_back(v);
    }

    N = n, num[0] = 1;

    for (lint i=1;i<=n;i++)
        if (s[i]==not_visited)
            dfs(i,adj,num,s);

    if (num[0]==0)
        cout << "IMPOSSIBLE";
    else
    {
        for (lint i=1;i<=n;i++)
            ss[num[i]] = i;

        for (lint i=1;i<=n;i++)
            cout << ss[i] << " ";
    }

    delete[] adj;
    delete[] num;
    delete[] s;
    delete[] ss;

    return 0;
}
