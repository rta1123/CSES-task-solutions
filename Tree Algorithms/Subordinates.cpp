#include <bits/stdc++.h>

using namespace std;

typedef unsigned int uint;

void dfs(vector <uint> *v, uint* count, uint k)
{
    for (auto u:v[k])
    {
        dfs(v,count,u);
        count[k]+= count[u]+1;

    }
}

int main()
{
    uint n;
    uint *chief, *count;
    vector <uint> *v;

    cin >> n;

    chief = new uint[n+1];
    count = new uint[n+1];
    v = new vector <uint> [n+1];

    chief[1] = 1;

    for (uint i=2; i<=n; i++)
        cin >> chief[i];

    for (uint i=2;i<=n;i++)
        v[chief[i]].push_back(i);

    dfs(v,count,1);

    for (uint i=1; i<=n; i++)
        cout << count[i] << " ";

    delete[] v;
    delete[] count;
    delete[] chief;

    return 0;
}
