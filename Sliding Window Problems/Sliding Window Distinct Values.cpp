#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k, *x, c, f, y;
    map <int, int> m;
    queue <int> q, ans;
    
    cin >> n;
    cin >> k;
    
    x = new int[n+1];
    for (int i=1; i<=n; i++)
        cin >> x[i];
    
    for (int i=1; i<=k; i++)
    {
        q.push(x[i]);
        if (m.find(x[i]) == m.end())
        {
            m.insert({x[i], 1});
        }
        else
        {
            f = m.find(x[i])->second;
            
            m.erase(x[i]);
            m.insert({x[i], f+1});
        }
    }
    ans.push(m.size());
    
    for (int i=k+1; i<=n; i++)
    {
        y = q.front();
        q.pop();
        
        f = m.find(y)->second;
        m.erase(y);
        if (f > 1)
            m.insert({y, f-1});
    
        q.push(x[i]);
        if (m.find(x[i]) == m.end())
        {
            m.insert({x[i], 1});
        }
        else
        {
            f = m.find(x[i])->second;
            m.erase(x[i]);
            m.insert({x[i], f+1});
        }
        
        ans.push(m.size());
    }
    
    while(!ans.empty())
    {
        cout << ans.front() << " ";
        ans.pop();
    }
    cout << endl;
    
    delete[] x;
    
    return 0;
}