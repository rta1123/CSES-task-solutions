#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;

    cin >> n;

    do
    {

        cout << n << " ";

        if (n==1)
            break;

        if (n % 2 == 1)
            n = n*3 + 1;
        else
            n = n / 2;

    }while (true);

    return 0;
}
