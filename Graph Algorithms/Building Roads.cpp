#include <bits/stdc++.h>

using namespace std;

int main()
{
    uint64_t n,m,a,b,u;
    uint64_t *c, nc, k;
    bool *p;
    vector <uint64_t> *v;
    queue <uint64_t> q;
    vector <pair<uint64_t,uint64_t>> lines;

    cin >> n;
    cin >> m;

    v = new vector<uint64_t>[n+1];
    c = new uint64_t[n+1];
    p = new bool[n+1];

    for (uint64_t i=1;i<=m;i++)
    {
        cin >> a;
        cin >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    nc = 0;
    for (uint64_t i=1;i<=n;i++)
    {
        if (p[i])
            continue;

        nc++;
        q.push(i);
        p[i] = true;
        c[i] = nc;

        while (!q.empty())
        {
            u = q.front();
            q.pop();

            for (uint64_t j=0;j<v[u].size();j++)
                if (!p[v[u].at(j)])
                {
                    q.push(v[u].at(j));
                    p[v[u].at(j)] = true;
                    c[v[u].at(j)] = nc;
                }
        }
    }


    k = 2;
    for (uint64_t i=2;i<=n;i++)
    {
        if (k > nc)
            break;

        if (c[i] == k)
        {
            lines.push_back({1,i});
            k++;
        }
    }

    cout << nc - 1 << endl;

    for (auto l : lines)
        cout << l.first << " " << l.second << endl;

    delete[] v;
    delete[] c;
    delete[] p;

    return 0;
}
