#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n, x, s, p, q;
    pair <int, int> *a;
    vector <int> ans;
 
    cin >> n;
    cin >> x;
 
    if (n <= 2)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
 
    a = new pair<int,int>[n+1];
 
    for (int i=1; i<=n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
 
    sort(a + 1, a + n + 1);
 
    
    for (int i=1; i<=n; i++)
    {
        bool exist = false;
        
        x -= a[i].first;
      
        p = i + 1;
        q = n;
 
        while (p < q)
        {
            if (a[p].first + a[q].first > x)
                q--;
            else
                if (a[p].first + a[q].first < x)
                    p++;
                else
                {
                    exist = true;
                    ans.push_back(a[p].second);
                    ans.push_back(a[q].second);
                    break;
                }
        }
        
        if (exist)
        {
            ans.push_back(a[i].second);
            break;
        }
        
        x += a[i].first;
    }
 
    if (ans.size() <= 2)
        cout << "IMPOSSIBLE" << endl;
    else
    {
        sort(ans.begin(), ans.end());
        for (auto i : ans)
            cout << i << ' ';
        cout << endl;
    }
 
    delete[] a;
 
    return 0;
}
