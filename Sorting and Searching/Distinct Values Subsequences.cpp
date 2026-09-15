#include <bits/stdc++.h>

using namespace std;

typedef uint64_t ull;

enum
{
    modulo = 1000000007,
};

int main()
{
    int n, k, *x;
    vector <int> K;
    ull C;

    cin >> n;

    x = new int[n+1];

    for (int i=1; i<=n; i++)
        cin >> x[i];

    sort(x+1, x+n+1);

    k = 1;
    for (int i=2; i<=n; i++)
    {
        if (x[i-1] == x[i])
            k++;
        else
        {
            K.push_back(k);
            k = 1;
        }
    }
    K.push_back(k);

    C = K.front();
    for (size_t i=1; i<K.size(); i++)
        C = ((K[i] + 1) * (C % modulo) + K[i]) % modulo;

    cout << C << endl;

    delete[] x;

    return 0;
}
