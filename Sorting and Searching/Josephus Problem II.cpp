#include <bits/stdc++.h>

using namespace std;

#define null nullptr

typedef int64_t ll;

struct sgt
{
    int l, r, v;
    sgt *L, *R;

    sgt()
    {
        l = {};
        r = {};
        v = {};
        L = {};
        R = {};
    }

    sgt(int a, int b)
    {
        if (a < b)
        {
            l = (a + b)/2 - a + 1;
            r = b - (a + b) / 2;
            v = {};
            L = new sgt(a, (a + b)/2);
            R = new sgt((a + b) / 2 + 1, b);
        }
        else
        {
            l = {};
            r = {};
            v = a;
            L = {};
            R = {};
        }
    }

    int rmv(int i)
    {
        if ((L == null) and (R == null))
            return v;

        if ((L != null) and (l >= i))
        {
            l--;
            return L->rmv(i);
        }

        if ((R != null) and ((r + l) >= i))
        {
            r--;
            return R->rmv(i - l);
        }

        return {};
    }

    void free()
    {
        if (L != null)
            L->free();
        if (R != null)
            R->free();
        delete L;
        delete R;
    }

};

int main()
{
    ll n, k, m;
    queue <int> ans;
    sgt t;

    cin >> n;
    cin >> k;

    t = sgt(1, n);

    m = {};
    for (ll i=n; i>=1; i--)
    {
        m += k;
        m %= i;
        ans.push(t.rmv(m+1));
    }

    while (!ans.empty())
    {
        cout << ans.front() << " ";
        ans.pop();
    }
    cout << endl;

    t.free();

    return 0;
}
