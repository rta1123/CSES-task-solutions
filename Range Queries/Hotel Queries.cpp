#include <bits/stdc++.h>

using namespace std;

int max(int u, int v)
{
    if (u >= v)
        return u;
    else
        return v;
}

struct seg_tree
{
    int l, r, v;
    seg_tree *left, *right;

    seg_tree()
    {
        l = 0;
        r = 0;
        v = 0;
        left = nullptr;
        right = nullptr;
    }

    seg_tree(int L, int R, int *h)
    {
        l = L;
        r = R;

        if (R > L)
        {
            left = new seg_tree(L, (L + R)/2, h);
            right = new seg_tree(1 + (L + R)/2, R, h);

            v = max(left->v, right->v);
        }
        else
        {
            left = nullptr;
            right = nullptr;
            v = h[l];
        }
    }

    void free()
    {
        if (left != nullptr)
        {
            left->free();
            delete left;
        }

        if (right != nullptr)
        {
            right->free();
            delete right;
        }
    }

    int pstn(int u)
    {
        if ((l == r) and (v >= u))
            return l;

        if (left != nullptr)
        {
            if (left->v >= u)
                return left->pstn(u);
        }

        if (right != nullptr)
        {
            if (right->v >= u)
                return right->pstn(u);
        }

        return 0;
    }

    void dcr(int l, int r, int i, int u)
    {
        if ((i < l) or (i > r))
            return;

        if ((i == l) and (i == r))
        {
            v -= u;
            return;
        }

        if ((i >= l) and (i <= (r+l)/2))
        {
            left->dcr(l, (r+l)/2, i, u);
            v = max(left->v, right->v);
            return;
        }

        if ((i >= (1 + (r+l)/2)) and (i <= r))
        {
            right->dcr(1 + (r+l)/2, r, i, u);
            v = max(left->v, right->v);
            return;
        }
    }
};

int main()
{
    int n, m, r, p;
    int *h;
    queue <int> ans;
    seg_tree *tree;

    cin >> n;
    cin >> m;

    h = new int[n+1];

    for (int i=1; i<=n; i++)
        cin >> h[i];

    tree = new seg_tree(1, n, h);

    for (int i=1; i<=m; i++)
    {
        cin >> r;

        p = tree->pstn(r);

        ans.push(p);

        tree->dcr(1, n, p, r);
    }

    while (!ans.empty())
    {
        cout << ans.front() << " ";
        ans.pop();
    }
    cout << endl;

    tree->free();
    delete tree;

    delete[] h;

    return 0;
}
