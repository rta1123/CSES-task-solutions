#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, *x;
    uint64_t k;
    queue <int> w;
    set <int> s;

    cin >> n;

    x = new int[n+1];
    for (int i=1; i<=n; i++)
        cin >> x[i];

    k = 0;
    for (int i=1; i<=n; i++)
    {
        while (s.find(x[i]) != s.end())
        {
            s.erase(w.front());
            w.pop();
        }

        w.push(x[i]);
        s.insert(x[i]);
        k += w.size();
    }

    cout << k << endl;

    delete[] x;

    return 0;
}
