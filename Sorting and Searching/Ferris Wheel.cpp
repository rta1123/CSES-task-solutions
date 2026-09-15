#include <bits/stdc++.h>

using namespace std;

int main()
{
    int64_t n,x,temp, count;
    vector <int64_t> p;

    cin >> n;
    cin >> x;

    for (int64_t i=0;i<n;i++)
    {
        cin >> temp;
        p.push_back(temp);
    }

    sort(p.begin(),p.end());

    count = 0;
    int64_t i=0, j=n-1;
    while (i <=j)
    {
        if (p[i]+p[j] <= x)
        {
            count++;
            i++;
            j--;
            continue;
        }
        else
        {
            count++;
            j--;
        }
    }

    cout << count;

    return 0;
}
