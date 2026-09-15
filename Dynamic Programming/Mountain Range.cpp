#include <bits/stdc++.h>

using namespace std;

int min(int u, int v)
{
    if (u <= v)
        return u;
    else
        return v;
}

int max(int u, int v)
{
    if (u >= v)
        return u;
    else
        return v;
}

struct seg_tree
{
    int l, r, m, p;
    seg_tree *left, *right;

    seg_tree()
    {
        l = 0;
        r = 0;
        m = 0;
        p = 0;
        left = nullptr;
        right = nullptr;
    }

    seg_tree(int L, int R, int *h)
    {
        l = L;
        r = R;

        if (L < R)
        {
            left = new seg_tree(L, (L + R)/2, h);
            right = new seg_tree(1 + (L + R)/2, R, h);

            if (left->m >= right->m)
            {
                m = left->m;
                p = left->p;
            }
            else
            {
                m = right->m;
                p = right->p;
            }
        }
        else
        {
            p = L;
            m = h[L];
            left = nullptr;
            right = nullptr;
        }

    }

    void free()
    {
        if (left != nullptr)
            left->free();

        if (right != nullptr)
            right->free();

        delete left;
        delete right;
    }

    pair<int,int> search(int a, int b)
    {
        pair <int,int> ansl {-1, 0}, ansr {-1, 0};

        if ((l == a) and (r == b))
        {
            return {m,p};
        }

        if ((left != nullptr) and (left->l <= a) and (left->r >= a))
        {
            ansl = left->search(a, min(left->r, b));
        }

        if ((right != nullptr) and (right->l <= b) and (right->r >= b))
        {
            ansr = right->search(max(a, right->l), b);
        }

        if (ansl.first >= ansr.first)
            return ansl;
        else
            return ansr;
    }
};

int compression(int m, int *p, int *h)
{
    if (p[m] == 0)
        return m;

    if (h[m] == h[p[m]])
        p[m] = compression(p[m], p, h);

    return p[m];
}

void C(int m, int *p, int *c, int *h)
{
    if (m != p[m])
    {
        compression(m, p, h);

        if (h[p[m]] > h[m])
            c[p[m]] = max(c[p[m]], c[m] + 1);
    }
}

int main()
{
    int n, *h, *c, k;
    seg_tree *tree;
    int l, r, m, lm, rm;
    queue <tuple<int,int,int>> q;
    stack <tuple<int,int,int>> s;
    stack <int> sC, sc;
    int *p;

    cin >> n;

    h = new int[n+1];
    c = new int[n+1];
    p = new int[n+1];

    for (int i=1; i<=n; i++)
        cin >> h[i];

    tree = new seg_tree(1, n, h);

    q.push({1, tree->search(1, n).second, n});
    while (!q.empty())
    {
        tie(l, m, r) = q.front();
        q.pop();

        if ((l == m) and (m == r))
            continue;

        if ((l < m) and (m < r))
        {
            lm = tree->search(l, m-1).second;
            q.push({l, lm, m-1});

            rm = tree->search(m+1, r).second;
            q.push({m+1, rm, r});

            s.push({lm, m, rm});

            continue;
        }

        if ((l == m) and (m < r))
        {
            rm = tree->search(l+1, r).second;
            q.push({l+1, rm, r});
            s.push({m, m, rm});
            continue;
        }

        if ((l < m) and (m == r))
        {
            lm = tree->search(l, r-1).second;
            q.push({l, lm, r-1});
            s.push({lm, m, m});
            continue;
        }
    }

    for (int i=1; i<=n; i++)
        c[i] = 1;

    for (int i=0; i<=n; i++)
        p[i] = 0;

    while (!s.empty())
    {
        tie(l, m, r) = s.top();
        s.pop();

        if (l != m)
        {
            if (p[l] == 0)
                p[l] = m;
            else
                if (h[p[l]] < h[m])
                    p[l] = m;

            sc.push(l);
        }

        if (r != m)
        {
            if (p[r] == 0)
                p[r] = m;
            else
                if (h[p[r]] < h[m])
                    p[r] = m;
            sc.push(r);
        }
    }

    while (!sc.empty())
    {
        sC.push(sc.top());
        sc.pop();
    }

    while (!sC.empty())
    {
        C(sC.top(), p, c, h);
        sC.pop();
    }

    k = 1;
    for (int i=1; i<=n; i++)
        k = max(k, c[i]);

    cout << k << endl;

    tree->free();
    delete tree;
    delete[] h;
    delete[] c;
    delete[] p;

    return 0;
}
