#include <bits/stdc++.h>

using namespace std;

int main()
{
    uint32_t n,m,s,f;
    char ch;
    uint32_t **M;
    vector <uint32_t> *vertex_list, path;
    queue <uint32_t> q;
    uint32_t *dist;
    vector <char> commands;

    cin >> n;
    cin >> m;

    M = new uint32_t*[n];
    for (uint32_t i = 0;i<n;i++)
        M[i] = new uint32_t[m];

    vertex_list = new vector<uint32_t>[n*m];

    dist = new uint32_t[n*m];

    for (uint32_t i=0; i<n;i++)
    {
        for (uint32_t j=0;j<m;j++)
        {

            cin >> ch;

            if (ch == '.' || ch == 'A' || ch == 'B')
            {
                M[i][j] = 1;

                if (ch == 'A')
                    s = i*m + j;
                else
                    if (ch == 'B')
                        f = i*m+j;
            }
            else
                if (ch == '#')
                    M[i][j] = 0;
        }

    }

    for (uint32_t i=0; i<n;i++)
        for (uint32_t j=0;j<m;j++)
        {
            if (i < n && j+1 < m)
                if (M[i][j] && M[i][j+1])
                {
                    vertex_list[i*m + j].push_back(i*m+j+1);
                    vertex_list[i*m + j+1].push_back(i*m+j);
                }

            if (i+1 < n && j < m)
                if (M[i][j] && M[i+1][j])
                {
                    vertex_list[i*m + j].push_back((i+1)*m+j);
                    vertex_list[(i+1)*m + j].push_back(i*m+j);
                }
        }

    q.push(s);
    dist[s] = 1;
    while (!q.empty())
    {
        auto u = q.front();
        q.pop();

        for (auto v:vertex_list[u])
        {
            if (!dist[v])
            {
                q.push(v);
                dist[v] = dist[u]+1;
            }
        }
    }

    q.push(f);
    while (!q.empty())
    {
        auto u = q.front();
        q.pop();

        path.push_back(u);

        for (auto v:vertex_list[u])
        {
            if (dist[v] == dist[u] - 1)
            {
                q.push(v);
                break;
            }
        }
    }

    reverse(path.begin(),path.end());

    for (auto it = path.begin(); it<path.end() - 1; ++it)
    {
        uint32_t curr,next;
        uint32_t i1,i2,j1,j2;

        curr = *it;
        next = *(it+1);

        j1 = curr % m;
        i1 = (curr - j1) / m;

        j2 = next % m;
        i2 = (next - j2) / m;

        if (i1==i2 && j2==j1+1)
            commands.push_back('R');

        if (i1==i2 && j2+1==j1)
            commands.push_back('L');

        if (i1+1==i2 && j2==j1)
            commands.push_back('D');

        if (i1==i2+1 && j2==j1)
            commands.push_back('U');
    }

    if (dist[f])
    {
        cout << "YES" << endl;
        cout << dist[f] - 1<< endl;
        for (uint32_t i=0;i<commands.size();i++)
            cout << (char)commands[i];
    }
    else
        cout << "NO";

    for (uint32_t i = 0;i<n;i++)
        delete[] M[i];
    delete[] M;

    delete[] vertex_list;

    delete[] dist;

    return 0;
}
