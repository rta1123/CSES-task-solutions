#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;

enum {inf = -1000000000000000};

struct seg_tree
{
    int l, r;
    ll sum, prefix_sum;
    seg_tree *left, *right;
    seg_tree ()
    {
        prefix_sum = 0;
        sum = 0;
        l = 0;
        r = 0;
        left = nullptr;
        right = nullptr;
    }

    seg_tree(int L, int R, ll *x)
    {
        l = L;
        r = R;

        if (L < R)
        {
            left = new seg_tree(L, (L + R)/2, x);
            right = new seg_tree(1 + (L + R)/2, R, x);

            sum = left->sum + right->sum;
            prefix_sum = sum;
            prefix_sum = max(prefix_sum, left->prefix_sum);
            prefix_sum = max(prefix_sum, left->sum + right->prefix_sum);
        }
        else
        {
            sum = x[L];
            prefix_sum = sum;
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

    void update(int k, int u)
    {
        if ((left == nullptr) and (right == nullptr) and (l == k))
        {
            sum = u;
            prefix_sum = u;
            return;
        }

        if ((left != nullptr) and (left->l <= k) and (left->r >= k))
        {
            left->update(k, u);
            sum = left->sum + right->sum;
            prefix_sum = sum;
            prefix_sum = max(prefix_sum, left->prefix_sum);
            prefix_sum = max(prefix_sum, left->sum + right->prefix_sum);
            return;
        }

        if ((right != nullptr) and (right->l <= k) and (right->r >= k))
        {
            right->update(k, u);
            sum = left->sum + right->sum;
            prefix_sum = sum;
            prefix_sum = max(prefix_sum, left->prefix_sum);
            prefix_sum = max(prefix_sum, left->sum + right->prefix_sum);
            return;
        }
    }

    pair<ll,ll> max_prefix_sum(int a, int b)
    {
        ll s  = 0;
        ll sl = 0;
        ll sr = 0;
        ll p  = inf;
        ll pl = inf;
        ll pr = inf;

        if (l == a and r == b)
            return {prefix_sum, sum};

        if ((left != nullptr) and (left->l <= a) and (left->r >= a))
        {
            tie(pl, sl) = left->max_prefix_sum(a, min(b, left->r));
            s += sl;
            p = max(s, p);
            p = max(p, pl);
        }

        if ((right != nullptr) and ((right->l <= b) and (right->r >= b)))
        {
            tie(pr, sr) = right->max_prefix_sum(max(a, right->l), b);
            s += sr;
            p = max(s, p);
            p = max(p, sl + pr);
        }

        return {p, s};
    }

};

int main()
{
    int n, q, op, k, a, b;
    ll *x, u;
    queue <ll> ans;
    seg_tree *tree;

    cin >> n;
    cin >> q;

    x = new ll[n+1];

    for (int i=1; i<=n; i++)
        cin >> x[i];

    tree = new seg_tree(1, n, x);

    for (int i=1; i<=q; i++)
    {
        cin >> op;

        if (op == 1)
        {
            cin >> k;
            cin >> u;

            tree->update(k, u);
        }
        else
        {
            cin >> a;
            cin >> b;

            auto r = tree->max_prefix_sum(a, b);
            ans.push(max(ll(0), max(r.first, r.second)));
        }
    }

    while (!ans.empty())
    {
        cout << ans.front() << endl;
        ans.pop();
    }

    tree->free();
    delete tree;
    delete[] x;

    return 0;
}
