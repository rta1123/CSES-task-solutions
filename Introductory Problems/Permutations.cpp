#include <bits/stdc++.h>

using namespace std;

bool permutation(int *a, int n)
{
    bool result;

    result = false;


    return result;
}

int main()
{
    int n;

    cin >> n;

    if (n==4)
    {
        cout << 2 << " " << 4 << " " << 1 << " " << 3 << " ";
        return 0;
    }

    if (n <= 3 && n!=1)
        cout << "NO SOLUTION";
    else
    {
        for (int i = 1; i<=n; i+=2)
            cout << i << " ";

        for (int i = 2; i<=n; i+=2)
            cout << i << " ";
    }

    return 0;
}
