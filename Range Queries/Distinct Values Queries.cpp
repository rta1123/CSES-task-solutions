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
        L = nullptr;
        R = nullptr;
    }

    sgt(int a, int b)
    {
        l = a;
        r = b;
        c = {};

        if (a < b)
        {
            L = new sgt(a, (a + b)/2);
            R = new sgt(1 + (a + b)/2, b);
        }
        else
        {
            L = nullptr;
            R = nullptr;
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

    void add(int p)
    {
        if ((l == p) and (r == p))
        {
            c++;
            return;
        }

        if ((L != nullptr) and (L->l <= p) and (p <= L->r))
        {
            c++;
            L->add(p);
            return;
        }

        if ((R != nullptr) and (R->l <= p) and (p <= R->r))
        {
            c++;
            R->add(p);
            return;
        }
    }

    void rmv(int p)
    {
        if ((l == p) and (r == p))
        {
            c--;
            return;
        }

        if ((L != nullptr) and (L->l <= p) and (p <= L->r))
        {
            c--;
            L->rmv(p);
            return;
        }

        if ((R != nullptr) and (R->l <= p) and (p <= R->r))
        {
            c--;
            R->rmv(p);
            return;
        }
    }

    int cnt(int a, int b)
    {
        int ans {};

        if ((a == l) and (r == b))
            return c;

        if ((L != nullptr) and (L->l <= a) and (L->r >= a))
            ans = L->cnt(a, min(L->r, b));

        if ((R != nullptr) and (R->l <= b) and (R->r >= b))
            ans += R->cnt(max(R->l, a), b);

        return ans;
    }
};

struct s_tuple
{
    int a, b, j;

    s_tuple() {};
    s_tuple(int a, int b, int j) : a(a), b(b), j(j) {};
};

bool cmp(const s_tuple &lhs, const s_tuple &rhs)
{
    if (lhs.b < rhs.b)
        return true;
    else
        if ((lhs.b == rhs.b) and (lhs.a < rhs.a))
            return true;
        else
            return false;
}

int main()
{
    int n, k, a, b, *x;
    vector <s_tuple> Q;
    int *f, *last_pos, *ans;
    pair<int,int> *u;
    sgt *t;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> k;

    x = new int[n+1];
    f = new int[n+1];
    last_pos = new int[n+1];
    ans = new int[k+1];
    u = new pair<int,int>[n+1];
    t = new sgt(1, n);

    for (int i=1; i<=n; i++)
    {
        cin >> x[i];
        u[i] = {x[i],i};
        last_pos[i] = {};
    }

    for (int i=1; i<=k; i++)
    {
        cin >> a;
        cin >> b;

        Q.push_back({a, b, i});
    }

    sort(u+1, u+n+1);

    f[u[0].second] = 1;
    for (int i=1, j=1; i<=n; i++)
    {
        if (u[i].first != u[i-1].first)
            j++;

        f[u[i].second] = j;
    }

    sort(Q.begin(), Q.end(), cmp);
    reverse(Q.begin(), Q.end());

    for (int i=1; i<=n; i++)
    {
        if (last_pos[f[i]])
            t->rmv(last_pos[f[i]]);
        t->add(i);
        last_pos[f[i]] = i;

        while (!Q.empty() and (Q.back().b == i))
        {
            ans[Q.back().j] = t->cnt(Q.back().a, Q.back().b);
            Q.pop_back();
        }
    }

    for (int i=1; i<=k; i++)
        cout << ans[i] << endl;

    t->free();
    delete t;
    delete[] u;
    delete[] ans;
    delete[] last_pos;
    delete[] f;
    delete[] x;

    return 0;
}
