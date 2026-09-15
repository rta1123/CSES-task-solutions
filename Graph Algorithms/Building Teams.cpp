#include <bits/stdc++.h>

using namespace std;

typedef uint32_t lint;

enum color
{
    no_color = 0,
    white = 1,
    black = 2,
};

void dfs(lint v, color *c, vector <lint> *u, bool &result)
{
    for (auto w : u[v])
    {
        if ((c[v]==white && c[w]==white) || (c[v]==black && c[w]==black))
        {
            result = false;
            return;
        }
        else
            if ((c[v]==white && c[w]==black) || (c[v]==black && c[w]==white))
                continue;
            else
                if (c[v]==white && c[w]==no_color)
                {
                    c[w] = black;
                    dfs(w,c,u,result);
                }
                else
                    if (c[v]==black && c[w]==no_color)
                    {
                        c[w] = white;
                        dfs(w,c,u,result);
                    }
    }
}

int main()
{
    lint n, m, v, w;
    vector <lint> *u;
    color *c;
    bool result;

    cin >> n;
    cin >> m;

    u = new vector <lint>[n+1];
    c = new color[n+1];

    for (lint i=1;i<=m;i++)
    {
        cin >> v;
        cin >> w;
        u[v].push_back(w);
        u[w].push_back(v);
    }

    result = true;
    for (lint i=1;i<=n;i++)
    {
        if (c[i]==no_color && result)
        {
            c[i] = white;
            dfs(i, c, u, result);
        }
        else
            continue;
    }

    if (result == false)
        cout << "IMPOSSIBLE";
    else
        for (lint i=1;i<=n;i++)
            cout << c[i] << " ";

    delete[] u;
    delete[] c;

    return 0;
}
