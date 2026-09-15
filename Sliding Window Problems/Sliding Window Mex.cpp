#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k, *x, y, f;
    set <pair<int, int>, less<pair<int, int>>> s;
    map <int, int> m;
    set <int, less<int>> mex;
    queue <int> q, ans;
    
    cin >> n;
    cin >> k;
    
    x = new int[n+1];
    for (int i=1; i<=n; i++)
        cin >> x[i];
    
    mex.insert(0);
    for (int i=1; i<=k; i++)    
    {
        q.push(x[i]);
        if (m.find(x[i]) == m.end())
        {
            m.insert({x[i], 1});
            s.insert({x[i], 1});
            
            mex.erase(x[i]);
            if (m.find(x[i]+1) == m.end())
                mex.insert(x[i]+1);
            if ((x[i] >= 1) and (m.find(x[i]-1) == m.end()))
                mex.insert(x[i]-1);
        }
        else
        {
            f = m.find(x[i])->second;
            
            m.erase(x[i]);
            m.insert({x[i], f+1});
            
            s.erase({x[i], f});
            s.insert({x[i], f+1});
        }
    }
    ans.push(*mex.begin());
    
    for (int i=k+1; i<=n; i++)    
    {
        y = q.front();
        q.pop();
        
        f = m.find(y)->second;
            
        m.erase(y);
        s.erase({y, f});
        
        if (f > 1)
        {
            m.insert({y, f-1});
            s.insert({y, f-1});
        }
        else
        {
            mex.insert(y);
        }
        
        q.push(x[i]);
        if (m.find(x[i]) == m.end())
        {
            m.insert({x[i], 1});
            s.insert({x[i], 1});
            
            mex.erase(x[i]);
            if (m.find(x[i]+1) == m.end())
                mex.insert(x[i]+1);
            if ((x[i] >= 1) and (m.find(x[i]-1) == m.end()))
                mex.insert(x[i]-1);
        }
        else
        {
            f = m.find(x[i])->second;
            
            m.erase(x[i]);
            m.insert({x[i], f+1});
            
            s.erase({x[i], f});
            s.insert({x[i], f+1});
        }
        
        ans.push(*mex.begin());
    }
    
    while (!ans.empty())
    {
        cout << ans.front() << " ";
        ans.pop();
    }
    cout << endl;
    
    delete[] x;
    
    return 0;
}