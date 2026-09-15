#include <bits/stdc++.h>

using namespace std;

typedef unsigned int uint;

void DFS(vector <uint> *V, bool *color, uint i)
{
    for (auto it = V[i].begin(); it != V[i].end(); ++it)
    {
        if (color[*it])
            continue;
        else
        {
            color[*it] = 1;

            DFS(V, color, *it);
        }
    }
}

int main()
{
    uint n, m, count;
    vector <uint> *V;
    bool *color;
    bool **M;
    char ch;

    cin >> n;
    cin >> m;

    M = new bool*[n];
    for (uint i = 0; i < n; i++)
        M[i] = new bool[m];

    V = new vector <uint>[n*m];

    color = new bool[n*m];

     for (uint i = 0; i < n; i++)
          for (uint j = 0; j < m; j++)
            {
                cin >> ch;
                if (ch == '.')
                    M[i][j] = 1;
                else
                    M[i][j] = 0;
            }

     for (uint i = 0; i < n; i++)
          for (uint j = 0; j < m; j++)
          {
              if (i < n - 1)
                  if (M[i][j] && M[i + 1][j])
                  {
                      V[i*m + j].push_back((i+1)*m + j);
                      V[(i+1)*m + j].push_back(i*m + j);
                  }

              if (j < m - 1)
                  if (M[i][j] && M[i][j + 1])
                  {
                      V[i*m + j].push_back(i*m + j + 1);
                      V[i*m + j + 1].push_back(i*m + j);
                  }
          }

    count = 0;

    for (uint i = 0; i < n; i++)
        for (uint j = 0; j < m; j++)
        {
            if ((V[i*m + j].empty() && M[i][j]==false) || color[i*m + j])
                continue;

            color[i*m + j] = 1;

            DFS(V, color, i*m + j);

            count++;
        }

    cout << count;

    for (uint i = 0; i < n; i++)
        delete[] M[i];
    delete[] M;

    delete[] V;

    delete[] color;

    return 0;
}
