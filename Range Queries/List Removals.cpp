#include <bits/stdc++.h>

using namespace std;

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

    seg_tree(int L, int R, int *x)
    {
        if (L == R)
        {
            l = 0;
            r = 0;
            left = nullptr;
            right = nullptr;
            v = x[L];
        }
        else
        {
            l = 1 + (R - L)/2;
            r = R - L + 1 - l;
            left = new seg_tree(L, (L + R)/2, x);
            right = new seg_tree(1 + (L + R)/2, R, x);
            v = 0;
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

    void remove(int i)
    {
        if (i == 1 and left == nullptr and right == nullptr)
            return;

        if ((left != nullptr) and (l >= i))
        {
            left->remove(i);
            l--;
            return;
        }

        if ((right != nullptr) and ((l + r) >= i))
        {
            right->remove(i - l);
            r--;
            return;
        }
    }

    int search(int i)
    {
        if (i == 1 and left == nullptr and right == nullptr)
            return v;

        if ((left != nullptr) and (l >= i))
            return left->search(i);

        if ((right != nullptr) and ((l + r) >= i))
            return right->search(i - l);

        return 0;
    }
};

int main()
{
    int n, *p, *x;
    seg_tree *tree;
    queue <int> ans;

    cin >> n;

    x = new int[n+1];
    p = new int[n+1];

    for (int i=1; i<=n; i++)
        cin >> x[i];

    for (int i=1; i<=n; i++)
        cin >> p[i];

    tree = new seg_tree(1, n, x);

    for (int i=1; i<=n; i++)
    {
        ans.push(tree->search(p[i]));
        tree->remove(p[i]);
    }

    while (!ans.empty())
    {
        cout << ans.front() << " ";
        ans.pop();
    }
    cout << endl;

    tree->free();
    delete tree;

    delete[] x;
    delete[] p;

    return 0;
}
