#include <bits/stdc++.h>

using namespace std;

#define null nullptr

struct sgt
{
    int l, r, m, p;
    sgt *L, *R;

    sgt()
    {
        l = {};
        r = {};
        m = {};
        p = {};
        L = null;
        R = null;
    }

    sgt(int a, int b, int *h)
    {
        l = a;
        r = b;

        if (a < b)
        {
            L = new sgt(a, (a + b)/2, h);
            R = new sgt(1 + (a + b)/2, b, h);
            if (L->m >= R->m)
            {
                m = L->m;
                p = L->p;
            }
            else
            {
                m = R->m;
                p = R->p;
            }
        }
        else
        {
            m = h[a];
            p = a;
            L = null;
            R = null;
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

    pair <int, int> search(int a, int b)
    {
        pair <int, int> ans_L {-1, 0}, ans_R {-1, 0};

        if ((l == a) and (r == b))
            return {m, p};

        if ((L != null) and (L->l <= a) and (L->r >= a))
            ans_L = L->search(a, min(L->r, b));

        if ((R != null) and (R->l <= b) and (R->r >= b))
            ans_R = R->search(max(a, R->l), b);

        if (ans_L.first >= ans_R.first)
            return ans_L;
        else
            return ans_R;
    }

};

int main()
{
    int n, q, *h, *c, a, b;
    priority_queue <int, vector<int>, greater<int>> p;
    map <int,int> k;
    queue <int> ans;
    sgt *t;

    cin >> n;
    cin >> q;

    h = new int[n+1];
    c = new int[n+1];

    for (int i=1; i<=n; i++)
        cin >> h[i];

    t = new sgt(1, n, h);

    for (int i=n; i>=1; i--)
    {
        while (!p.empty() and (h[i] >= p.top()))
        {
            k.erase(p.top());
            p.pop();
        }

        if (!p.empty())
            c[i] = k.find(p.top())->second + 1;
        else
            c[i] = 1;

        p.push(h[i]);
        k.insert({h[i],c[i]});
    }

    for (int i=1; i<=q; i++)
    {
        cin >> a;
        cin >> b;

        ans.push(c[a] - c[t->search(a, b).second] + 1);
    }

    while (!ans.empty())
    {
        cout << ans.front() << endl;
        ans.pop();
    }

    t->free();
    delete t;
    delete[] h;
    delete[] c;

    return 0;
}
