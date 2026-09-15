#include <bits/stdc++.h>

using namespace std;

typedef unsigned int uint;

int main()
{
    uint n, count, temp;
    vector <uint> a;

    cin >> n;

    for (uint i = 0; i < n; i++)
    {
        cin >> temp;
        a.push_back(temp);
    }

    sort(a.begin(), a.end());

    count = 1;
    for (uint i = 0; i < n - 1; i++)
        if (a.at(i) != a.at(i+1))
            count++;

    cout << count;

    return 0;
}
