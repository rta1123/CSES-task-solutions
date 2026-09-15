#include <bits/stdc++.h>
 
using namespace std;
 
typedef int64_t lint;
 
lint min(lint u, lint v)
{
    if (u<=v)
        return u;
    else
        return v;
}
 
lint mvc(vector <lint> *child, lint v, lint **c, bool F, bool *leaf)
{
    lint count;
    
    if (c[v][F]!=-1)
        return c[v][F];
        
    if (leaf[v] && v > 1)
        return c[v][F] = F;

    if (F == false)
    {
        count = 0;
        for (auto w: child[v])
            count += mvc(child,w,c,true,leaf);
    }
    else
        {
            count = 1;
            for (auto w: child[v])
                count += min(mvc(child,w,c,true,leaf),mvc(child,w,c,false,leaf));
        }        

    return c[v][F] = count;
}
 
int main()
{
    lint n,v,w,min_c;
    vector <lint> *u, *child;
    queue <lint> q;
    lint **c;
    bool *leaf;
    bool *p;
 
    cin >> n;
 
    p = new bool[n+1];
    leaf = new bool[n+1];
    c = new lint*[n+1];
    for (lint i=0; i<=n; i++)
        c[i] = new lint[2];
        
    for (lint i=0; i<=n; i++)
        c[i][0]=c[i][1]=-1;    
        
    child = new vector <lint>[n+1];   
    u = new vector <lint>[n+1];
    for (lint i=1; i<=n-1; i++)
    {
        cin >> v;
        cin >> w;
        u[v].push_back(w);
        u[w].push_back(v);
    }

    p[1] = true, q.push(1);   
    while (!q.empty())
    {
        v = q.front(), q.pop();
        
        for (auto w:u[v])
            if (!p[w])
            {
                p[w] = true;
                child[v].push_back(w);
                q.push(w);
            }
    }
        
    for (lint i=1; i<=n; i++)
        if (u[i].size() == 1)
            leaf[i] = true;
            
    min_c = min(mvc(child,1,c,true,leaf), mvc(child,1,c,false,leaf));
    cout << min_c << endl;
 
    delete[] child;
    delete[] u;
    for (lint i=0; i<=n; i++)
        delete[] c[i];
    delete[] c;
    delete[] leaf;
    delete[] p;
 
    return 0;
}