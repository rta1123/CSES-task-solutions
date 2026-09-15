#include <bits/stdc++.h>

using namespace std;

enum {inf = 2000000000};

struct sgt
{
    sgt()
    {
        l = {};
        r = {};
        pl = {};
        pr = {};
        ml = {};
        mr = {};
        L = {};
        R = {};
    }

    sgt(int a, int b, int n, int *p)
    {
        l = a;
        r = b;

        if (a < b)
        {
            L = new sgt(a, (a + b)/2, n, p);
            R = new sgt(1 + (a + b)/2, b, n, p);

            if (L->ml < R->ml)
            {
                ml = L->ml;
                pl = L->pl;
            }
            else
            {
                ml = R->ml;
                pl = R->pl;
            }

            if (L->mr <= R->mr)
            {
                mr = L->mr;
                pr = L->pr;
            }
            else
            {
                mr = R->mr;
                pr = R->pr;
            }
        }
        else
        {
            ml = p[a] + n - a;
            mr = p[a] + a;
            pl = a;
            pr = a;
            L = {};
            R = {};
        }
    }

    void update(int k, int n, int p)
    {
        if ((l == k) and (r == k))
        {
            ml = p + n - k;
            mr = p + k;
            return;
        }

        if ((L != nullptr) and (L->l <= k) and (k <= L->r))
        {
            L->update(k, n, p);
            if (L->ml < R->ml)
            {
                ml = L->ml;
                pl = L->pl;
            }
            else
            {
                ml = R->ml;
                pl = R->pl;
            }

            if (L->mr <= R->mr)
            {
                mr = L->mr;
                pr = L->pr;
            }
            else
            {
                mr = R->mr;
                pr = R->pr;
            }
            return;
        }

        if ((R != nullptr) and (R->l <= k) and (k <= R->r))
        {
            R->update(k, n, p);
            if (L->ml < R->ml)
            {
                ml = L->ml;
                pl = L->pl;
            }
            else
            {
                ml = R->ml;
                pl = R->pl;
            }

            if (L->mr <= R->mr)
            {
                mr = L->mr;
                pr = L->pr;
            }
            else
            {
                mr = R->mr;
                pr = R->pr;
            }
            return;
        }
    }

    pair <int, int> findr(int a, int b, int n)
    {
        pair <int, int> ansL {inf, 0}, ansR {inf, 0}, ans {inf, 0};

        if (a > n or b < 1)
            return {inf, 0};

        if ((l == a) and (r == b))
            return {mr, pr};

        if ((L != nullptr) and (L->l <= a) and (a <= L->r))
            ansL = L->findr(a, min(b, L->r), n);

        if ((R != nullptr) and (R->l <= b) and (b <= R->r))
            ansR = R->findr(max(a, R->l), b, n);

        if (ansL.first <= ansR.first)
            ans = ansL;
        else
            ans = ansR;

        return ans;
    }

    pair <int, int> findl(int a, int b, int n)
    {
        pair <int, int> ansL {inf, 0}, ansR {inf, 0}, ans {inf, 0};

        if (a > n or b < 1)
            return {inf, 0};

        if ((l == a) and (r == b))
            return {ml, pl};

        if ((L != nullptr) and (L->l <= a) and (a <= L->r))
            ansL = L->findl(a, min(b, L->r), n);

        if ((R != nullptr) and (R->l <= b) and (b <= R->r))
            ansR = R->findl(max(a, R->l), b, n);

        if (ansL.first < ansR.first)
            ans = ansL;
        else
            ans = ansR;

        return ans;
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

private:
    int l, r, ml, mr, pl, pr;
    sgt *L, *R;
};

int main()
{
    int n, q, k, x, op, *p;
    queue <int> ans;
    sgt *t;

    cin >> n;
    cin >> q;

    p = new int[n+1];

    for (int i=1; i<=n; i++)
        cin >> p[i];

    t = new sgt(1, n, n, p);

    for (int i=1; i<=q; i++)
    {
        cin >> op;

        if (op == 1)
        {
            cin >> k;
            cin >> x;

            t->update(k, n, x);
            p[k] = x;
        }
        else
        {
            cin >> k;

            ans.push(min(p[k], min(t->findl(1, k - 1, n).first - n + k, t->findr(k+1, n, n).first - k)));
        }
    }

    while (!ans.empty())
    {
        cout << ans.front() << endl;
        ans.pop();
    }

    t->free();
    delete t;
    delete[] p;

    return 0;
}
