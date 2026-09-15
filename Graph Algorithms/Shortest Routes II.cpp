#include <bits/stdc++.h>
 
using namespace std;
 
typedef int64_t lint;
 
lint min(lint u,lint v)
{
    if (u<=v)
        return u;
    else
        return v;
}
 
int main()
{
    lint n,m,d;
    lint u,v,w;
    lint **dist;
    pair <lint,lint> *q;
 
    cin >> n;
    cin >> m;
    cin >> d;
 
    dist = new lint*[n+1];
    for (lint i=0;i<=n;i++)
        dist[i] = new lint[n+1];
    q = new pair<lint,lint>[d];
 
    for (lint i=1;i<=n;i++)
        for (lint j=1;j<=n;j++)
        {
            if (i!=j)
                dist[i][j] = -1;
            else
                dist[i][j] = 0;
        }
 
    for (lint i=1;i<=m;i++)
    {
        cin >> u;
        cin >> v;
        cin >> w;
        if (dist[u][v] == -1)
        {
            dist[u][v] = w;
            dist[v][u] = w;
        }
        else
            dist[u][v] = dist[v][u] = min(w, dist[u][v]);
    }
 
    for (lint i=0;i<d;i++)
    {
        cin >> u;
        cin >> v;
        q[i] = {u,v};
    }
 
    for (lint k=1;k<=n;k++)
        for (lint i=1;i<=n;i++)
            for (lint j=1;j<=n;j++)
            {
                if (dist[i][j]== -1 && dist[i][k]!=-1 && dist[k][j]!=-1)
                    dist[i][j] = dist[j][i] =dist[i][k]+dist[k][j];
                else
                    if (dist[i][j]!=-1 && dist[i][k]!=-1 && dist[k][j]!=-1)
                        dist[i][j]=dist[j][i]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
 
    for (lint i=0;i<d;i++)
        cout << dist[q[i].first][q[i].second] << endl;
 
    for (lint i=0;i<=n;i++)
        delete[] dist[i];
    delete[] dist;
    delete[] q;
 
    return 0;
}
