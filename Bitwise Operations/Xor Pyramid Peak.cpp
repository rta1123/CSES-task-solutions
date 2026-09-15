#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n, *a, h;
 
    cin >> n;
    a = new int[n+1];
 
    for (int i=1; i<=n; i++)
        cin >> a[i];
 
    h = 0, n = n - 1;
    for (int i=0; i<=n; i++)
    {
        if ((n | i) == n)
            h ^= a[i+1];
    }
 
    cout << h << endl;
 
    delete[] a;
 
    return 0;
}
