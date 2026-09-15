#include <bits/stdc++.h>

using namespace std;

typedef uint64_t ull;

int main()
{
    ull n, k, *x;
    set <pair<ull, ull>> subarray_up;
    set <pair<ull, ull>, greater<pair<ull,ull>>> subarray_down;
    pair <ull, ull> X, Y;
    queue <ull> ans;

    cin >> n;
    cin >> k;

    x = new ull[n+1];

    for (ull i=1; i<=n; i++)
        cin >> x[i];

    for (ull i=1; i<=k; i++)
    {
        subarray_up.insert({x[i],i});
        subarray_down.insert({x[i],i});
    }

    X = *subarray_up.begin();
    for (ull i=1; i<(k+1)/2; i++)
        X = *subarray_up.upper_bound({X.first, X.second});

    ans.push(X.first);

    for (ull i=k+1; i<=n; i++)
    {
        Y = *subarray_up.find({x[i-k], i-k});

        if (!((Y.first == X.first) and (Y.second == X.second)))
        {
            if (Y.first > X.first)
            {
                if (subarray_up.size() % 2 == 1)
                    X = *subarray_down.upper_bound({X.first, X.second});
            }
            else
                if (subarray_up.size() % 2 == 0)
                    X = *subarray_up.upper_bound({X.first, X.second});
        }
        else
        {
            if (subarray_up.size() % 2 == 1)
                X = *subarray_down.upper_bound({X.first, X.second});
            else
                X = *subarray_up.upper_bound({X.first, X.second});
        }

        subarray_down.erase({Y.first, Y.second});
        subarray_up.erase({Y.first, Y.second});

        subarray_up.insert({x[i], i});
        subarray_down.insert({x[i], i});

        if (x[i] >= X.first)
        {
            if (subarray_up.size() % 2 == 1)
                X = *subarray_up.upper_bound({X.first, X.second});
        }
        else
            if (subarray_up.size() % 2 == 0)
                X = *subarray_down.upper_bound({X.first, X.second});

        ans.push(X.first);
    }

    while (!ans.empty())
    {
        cout << ans.front() << ' ';
        ans.pop();
    }

    cout << endl;

    delete[] x;

    return 0;
}
