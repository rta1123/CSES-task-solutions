#include <bits/stdc++.h>

using namespace std;

struct sgt
{
    int l, r, c;
    sgt *L, *R;

    sgt()
    {
        l = {};
        r = {};
        c = {};
        L = {};
        R = {};
    }

    sgt(int a, int b, const vector <int> &u)
    {
        if (a < b)
        {
            L = new sgt(a, (a+b)/2, u);
            R = new sgt(1 + (a+b)/2, b, u);
            l = L->l;
            r = R->r;
            c = L->c + R->c;
        }
        else
        {
            l = u[a];
            r = u[a];
            c = {};
            L = {};
            R = {};
        }
    }

    int cnt(int b)
    {
        int ans {};

        if (r <= b)
            return c;

        if ((L != nullptr) and (L->l <= b))
            ans += L->cnt(b);

        if ((R != nullptr) and (R->l <= b))
            ans += R->cnt(b);

        return ans;
    }

    void add(int x)
    {
        if ((l == x) and (r == x))
        {
            c++;
            return;
        }

        if ((L != nullptr) and (L->l <= x) and (x <= L->r))
        {
            L->add(x);
            c++;
            return;
        }

        if ((R != nullptr) and (R->l <= x) and (x <= R->r))
        {
            R->add(x);
            c++;
            return;
        }
    }

    void rmv(int x)
    {
        if ((l == x) and (r == x))
        {
            c--;
            return;
        }

        if ((L != nullptr) and (L->l <= x) and (x <= L->r))
        {
            L->rmv(x);
            c--;
            return;
        }

        if ((R != nullptr) and (R->l <= x) and (x <= R->r))
        {
            R->rmv(x);
            c--;
            return;
        }
    }

    void free()
    {
        if (L != nullptr)
            L->free();
        if (R != nullptr)
            R->free();
        delete L;
        delete R;
    }

};

struct s_tuple
{
    int x, y, k;

    bool operator()(const s_tuple &lhs, const s_tuple &rhs)
    {
        if (lhs.x < rhs.x)
            return true;
        else
            if ((lhs.x == rhs.x) and (lhs.y > rhs.y))
                return true;
            else
                return false;
    }

    static bool cmp(const s_tuple &lhs, const s_tuple &rhs)
    {
        if (lhs.y < rhs.y)
            return true;
        else
            if ((lhs.y == rhs.y) and (lhs.x > rhs.x))
                return true;
            else
                return false;
    }
};

int main()
{
    int n, x, y;
    sgt *tr, *tl;

    cin >> n;

    vector <s_tuple> q(n);
    vector <int> r(n), l(n), v(n+1), u(n+1);
    vector <int> ans1 (n), ans2 (n);

    for (int i=0; i<n; i++)
    {
        cin >> x;
        cin >> y;
        q[i] = {x, y, i};
        l[i] = x;
        r[i] = y;
    }

    sort(l.begin(), l.end());
    sort(r.begin(), r.end());

    for (int i=0; i<n; i++)
        u[i+1] = l[i];

    for (int i=0; i<n; i++)
        v[i+1] = r[i];

    u.erase(unique(u.begin(), u.end()), u.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    tl = new sgt(1, u.size() - 1, u);
    tr = new sgt(1, v.size() - 1, v);

    for (auto y : r)
        tr->add(y);

    for (auto x : l)
        tl->add(x);

    sort(q.begin(), q.end(), s_tuple());

    for (int i=0; i<n; i++)
    {
        ans1[q[i].k] = tr->cnt(q[i].y) - 1;
        tr->rmv(q[i].y);
    }

    sort(q.begin(), q.end(), s_tuple::cmp);

    for (int i=0; i<n; i++)
    {
        ans2[q[i].k] = tl->cnt(q[i].x) - 1;
        tl->rmv(q[i].x);
    }

    for (auto ans : ans1)
        cout << ans << " ";
    cout << endl;

    for (auto ans : ans2)
        cout << ans << " ";
    cout << endl;

    tl->free();
    tr->free();
    delete tl;
    delete tr;

    return 0;
}
