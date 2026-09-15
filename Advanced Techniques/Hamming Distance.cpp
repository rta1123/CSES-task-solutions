#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    vector <int> x;
    string bit_string;

    cin >> n;
    cin >> k;

    for (int i=0; i<n; i++)
    {
        cin >> bit_string;

        x.push_back(stoi(bit_string, nullptr, 2));
    }

    for (int i=0; i<n; i++)
        for (int j=i+1; j<n; j++)
            k = min(k, __builtin_popcount(x[i] ^ x[j]));

    cout << k << endl;

    return 0;
}
