#include <bits/stdc++.h>

using namespace std;

#define null nullptr

struct sgt
{
    int l, r, m;
    sgt *L, *R;

    sgt()
    {
        l = {};
        r = {};
        m = {};
        L = {};
        R = {};
    }

    sgt(int a, int b)
    {
         l = a;
         r = b;

         if (a < b)
         {
             L = new sgt(a, (a + b)/2);
             R = new sgt(1 + (a + b)/2, b);
             m = {};
         }
         else
         {
             m = {};
             L = {};
             R = {};
         }
    }

    int search(int a, int b)
    {
        int ans {}, ansL {}, ansR {};

        if ((l == a) and (r == b))
            return m;

        if ((L != null) and (L->l <= a) and (L->r >= a))
            ansL = L->search(a, min(L->r, b));

        if ((R != null) and (R->l <= b) and (R->r >= b))
            ansR = R->search(max(R->l, a), b);

        ans = max(ansL, ansR);

        return ans;
    }

    void update(int k, int u)
    {
        if ((l == k) and (r == k))
        {
            m = u;
            return;
        }

        if ((L != null) and (L->l <= k) and (L->r >= k))
        {
            L->update(k, u);
            m = max(L->m, m);
            return;
        }

        if ((R != null) and (R->l <= k) and (R->r >= k))
        {
            R->update(k, u);
            m = max(R->m, m);
            return;
        }
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
    int n, k, p, *x, *s;
    map <int, int> m;
    sgt *t;

    cin >> n;

    x = new int[n+1];
    s = new int[n+1];
    t = new sgt(1, n);

    for (int i=1; i<=n; i++)
        cin >> x[i];

    for (int i=1; i<=n; i++)
        s[i] = x[i];

    sort(s+1, s+n+1);

    k = 0, p = 0;
    for (int i=1; i<n; i++)
    {
        if (s[i] != s[i+1])
        {
            m.insert({s[i], p+k+1});
            p += k+1;
            k = 0;
        }
        else
            k++;
    }

    if (m.find(s[n]) == m.end())
        m.insert({s[n], n});

    for (int i=n; i>=1; i--)
    {
        p = m.find(x[i])->second;
        if ((p + 1) > n)
            t->update(p, 1);
        else
            t->update(p, t->search(p + 1, n) + 1);
    }

    cout << t->search(1, n) << endl;

    t->free();
    delete t;
    delete[] s;
    delete[] x;

    return 0;
}
