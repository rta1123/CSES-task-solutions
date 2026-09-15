#include <bits/stdc++.h>

using namespace std;

typedef unsigned int uint;
typedef unsigned long ul;
typedef unsigned long long ull;

struct D
{
   uint a;
   uint b;

};

int main()
{
    uint n, cD, *a;
    ull *s;
    D *d;


    cin >> n;
    cin >> cD;

    a = new uint[n+1];
    d = new D[cD+1];
    s = new ull[n+1];

    for (uint i = 1; i <= n; i++)
        cin >> a[i];

    for (uint i = 1; i <= cD; i++)
    {
        cin >> d[i].a;
        cin >> d[i].b;
    }

    for (uint i = 1; i <= n; i++)
        s[i] = s[i-1] + a[i];

    for (uint i = 1; i<=cD; i++)
    {
        cout << s[d[i].b] - s[d[i].a - 1] << endl;
    }



    delete[] a;
    delete[] d;
    delete[] s;

    return 0;
}
