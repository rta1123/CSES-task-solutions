#include <bits/stdc++.h>

using namespace std;



long double P(int n, int m, int k, long double **p)
{
    long double j {};

    if (n == 1)
    {
        p[n][m] = 1. / k;
        return p[n][m];
    }

    if (p[n][m] != -1)
        return p[n][m];
    
    j = m; j /= k;
    p[n][m] = (pow(j, n - 1) + (m - 1) * P(n - 1, m, k, p)) / k;
     
    return p[n][m];
}

int main()
{
    int n, k;
    long double **p, M;
    
    cin >> n;
    cin >> k;
    
    p = new long double*[n+1];
    for (int i=0; i<=n; i++)
        p[i] = new long double[k+1];
    
    for (int i=0; i<=n; i++)
        for (int j=0; j<=k; j++)
            p[i][j] = -1;
    
    M = 0;
    for (int m=1; m<=k; m++)        
        M += P(n, m, k, p) * m;
        
    cout << fixed << setprecision(6) << M << endl;  
        
    for (int i=0; i<=n; i++)
        delete[] p[i];
    delete[] p;
    
    return 0;
}