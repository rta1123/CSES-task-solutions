#include <bits/stdc++.h>

using namespace std;

typedef uint64_t ull;

int main()
{
    ull n, *t, T;

    cin >> n;

    t = new ull[n+1];

    for (ull i=1; i<=n; i++)
        cin >> t[i];

    sort(t + 1, t + n + 1);

    T = {};
    for (ull i=1; i<=n-1; i++)
        T += t[i];

    if (T >= t[n])
        cout << T + t[n] << endl;
    else
        cout << 2 * t[n] << endl;

    delete[] t;

    return 0;
}
