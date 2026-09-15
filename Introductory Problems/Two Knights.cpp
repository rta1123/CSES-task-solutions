#include <bits/stdc++.h>

using namespace std;

unsigned long long P(unsigned long long n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 12;
    if (n == 3)
        return 56;
    if (n == 4)
        return 192;
    if (n == 5)
        return 504;

    return ((unsigned long long)(n-4)*(n-4)*(n*n - 9) + 4*(n-4)*(2*n*n-12) + 4*(n*n - 5) + 8*(n*n-4) + 4*(n*n-3));
}

int main()
{
    unsigned long long n;

    cin >> n;

    for (unsigned long long i = 1; i <= n; i++)
        cout << P(i)/2 << endl;


    return 0;
}
