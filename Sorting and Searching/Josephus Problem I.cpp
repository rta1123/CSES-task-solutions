#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long lint;

int main()
{
    lint n, k, m, s;
    bool *pos;
    
    cin >> n;
    
    pos = new bool[n];
    
    k = 0, m = 0, s = n;
    while (true)
    {
        if (!pos[k % n])
        {
            if (m)
            {
                m = 0;
                pos[k % n] = 1;
                s--;
                cout << k % n + 1 << " ";
            }
            else
                m++;
        }
    
        k++;
        
        if (s==0)
            break;
    }
    
    delete[] pos;
    
    return 0;
}