#include <bits/stdc++.h>

using namespace std;

typedef uint32_t lint;

const lint min_len = 3;

void dfs(lint v, vector <lint> *u, deque <lint> &path, lint *pos, bool &exist)
{
    for (auto w : u[v])
    {
        if (pos[w])
        {
            if ((path.size() - pos[w] + 1) >= min_len)
            {
                path.push_back(w);
                exist = true;
                return;
            }
        }
        else
        {
            pos[w] = path.size() + 1;
            path.push_back(w);
            dfs(w,u,path,pos,exist);

            if (exist)
                return;
            else
                path.pop_back();

        }
    }
}

int main()
{
    lint n,m,v,w;
    vector <lint> *u;
    deque <lint> path;
    lint *pos;
    bool exist;

    cin >> n;
    cin >> m;

    u = new vector <lint>[n+1];
    pos = new lint[n+1];

    for (lint i=1;i<=m;i++)
    {
        cin >> v;
        cin >> w;
        u[v].push_back(w);
        u[w].push_back(v);
    }

    exist = false;

    for (lint i=1;i<=n;i++)
    {
        if (pos[i])
            continue;

        pos[i] = 1;
        path.push_back(i);
        dfs(i,u,path,pos,exist);

        if (exist)
            break;
        else
            path.pop_back();
    }

    if (exist == false)
        cout << "IMPOSSIBLE";
    else
    {
        while (path.front()!=path.back())
            path.pop_front();

        cout << path.size() << endl;
        while (!path.empty())
        {
            cout << path.front() << " ";
            path.pop_front();
        }
    }

    delete[] u;
    delete[] pos;

    return 0;
}
