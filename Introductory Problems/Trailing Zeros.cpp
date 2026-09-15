#include <bits/stdc++.h>

using namespace std;

uint64_t min (uint64_t u, uint64_t v)
{
    if (u<=v)
        return u;
    else
        return v;
}

int main()
{
    uint64_t n, temp;
    uint64_t count_2,count_5, k;

    cin >> n;

    count_2 = 0;
    count_5 = 0;
    k = 1;
    temp=pow(2,k);
    while (temp<=n)
    {
        count_2 = count_2 + (n/temp);
        k++;
        temp=pow(2,k);
    }

    k = 1;
    temp=pow(5,k);
    while (temp>=5)
    {
        count_5 = count_5 + (n/temp);
        k++;
        temp=pow(5,k);
    }

    cout << min(count_2, count_5);

    return 0;
}
