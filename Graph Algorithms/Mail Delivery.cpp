#include <bits/stdc++.h>
 
using namespace std;
 
void ECF(int u, set <pair<int, int>, less<pair<int,int>>> &e, bool *p, queue <int> &ans)
{
    auto it = e.upper_bound({u, 0});
    
    while (it != e.end() and it->first == u)
    {
        auto v = it->second;
        
        e.erase({v,u});
        e.erase({u,v});
            
        p[v] = true;
        ECF(v, e, p, ans);
        ans.push(v);
        
        it = e.upper_bound({u, 0});
    }
}
 
int main()
{
    int n, m, u, v, *deg;
    set <pair<int,int>, less<pair<int,int>>> e;
    bool *p;
    queue <int> ans;
    bool solution;
 
    cin >> n;
    cin >> m;
 
    deg = new int[n+1];
    p = new bool[n+1];
 
    for (int i=1; i<=n; i++)
        deg[i] = 0;
 
    for (int i=1; i<=m; i++)
    {
        cin >> u;
        cin >> v;
        deg[u]++;
        deg[v]++;
 
        e.insert({u, v});
        e.insert({v, u});
    }
 
    solution = true;
    for (int i=1; i<=n; i++)
        if (deg[i] % 2)
        {
            solution = false;
            break;
        }
 
    if (!solution)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        p[1] = true;
        ECF(1, e, p, ans);
        ans.push(1);
 
        for (int i=1; i<=n; i++)
            if (!p[i] and deg[i] > 0)
            {
                solution = false;
                break;
            }
 
        if (!solution)
        {
            cout << "IMPOSSIBLE" << endl;
        }
        else
        {
            while (!ans.empty())
            {
                cout << ans.front() << " ";
                ans.pop();
            }
            cout << endl;
        }
    }
 
    delete[] p;
    delete[] deg;
 
    return 0;
}
