#include <bits/stdc++.h>

using namespace std;

typedef uint64_t ull;

int main()
{
    ull n, k, K, c, *x;
    set <ull> elements;
    map <ull, ull> subarray;

    cin >> n;
    cin >> k;

    x = new ull[n+1];

    for (ull i=1; i<=n; i++)
        cin >> x[i];

    K = 0;
    for (ull i=1, j=1; i<=n; i++)
    {
        elements.insert(x[i]);

        if ((elements.size() > k))
        {
            do
            {
                c = subarray.find(x[j])->second;

                if (c > 1)
                {
                    subarray.erase(x[j]);
                    subarray.insert({x[j], c - 1});
                    j++;
                }
                else
                    if (c == 1)
                    {
                        subarray.erase(x[j]);
                        elements.erase(x[j]);
                        j++;
                    }

            } while (c != 1);
        }

        auto it = subarray.find(x[i]);

        if (it != subarray.end())
        {
            c = it->second;
            subarray.erase(x[i]);
            subarray.insert({x[i], c + 1});
        }
        else
            subarray.insert({x[i], 1});

        K += i - j + 1;
    }

    cout << K << endl;

    delete[] x;

    return 0;
}
