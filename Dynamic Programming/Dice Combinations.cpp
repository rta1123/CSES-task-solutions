#include <iostream>

using namespace std;

typedef unsigned int uint;
typedef unsigned long ul;
typedef unsigned long long ull;

int main()
{
    uint n;
    ull *k;
    cin >> n;

    k = new ull[n+1];
    k[0] = 1;

    for (uint i=1; i <= n; i++)
    {
        k[i] = 0;

        if (i >= 6)
            k[i] += (k[i-1] + k[i-2] + k[i-3] + k[i-4] + k[i-5] + k[i-6]) % 1000000007;
        else
            if (i >= 5)
                k[i] += k[i-1] + k[i-2] + k[i-3] + k[i-4] + k[i-5];
            else
                if (i >= 4)
                    k[i] += k[i-1] + k[i-2] + k[i-3] + k[i-4];
                else
                    if (i >= 3)
                        k[i] += k[i-1] + k[i-2] + k[i-3];
                    else
                        if (i >= 2)
                            k[i] += k[i-1] + k[i-2];
                        else
                            if ( i>=1 )
                                k[i] += k[i-1];
    }

    cout << k[n] << endl;

    delete[] k;

    return 0;
}
