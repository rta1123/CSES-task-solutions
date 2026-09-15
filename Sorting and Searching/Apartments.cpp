#include <bits/stdc++.h>

using namespace std;

uint64_t max(uint64_t a, uint64_t b)
{
    if (a>=b)
        return a;
    else
        return b;
}

uint64_t min(uint64_t a, uint64_t b)
{
    if (a<=b)
        return a;
    else
        return b;
}


uint64_t dist(uint64_t a, uint64_t b)
{
    return (max(a,b) - min(a,b));
}

int main()
{
    uint64_t n, m, k, temp;
    vector <uint64_t> a,b;
    uint64_t count;

    cin >> n;
    cin >> m;
    cin >> k;

    for (uint64_t i=0;i<n;i++)
    {
        cin >> temp;
        a.push_back(temp);
    }

    for (uint64_t i=0;i<m;i++)
    {
        cin >> temp;
        b.push_back(temp);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    count = 0;

    for (uint64_t i=0,j=0;i<n && j<m;)
    {
        if (dist(a[i],b[j])<=k)
        {
            count++;
            i++;
            j++;
            continue;
        }

        if (b[j] > a[i])
            i++;
        else
            j++;
    }

    cout << count;

    return 0;
}
