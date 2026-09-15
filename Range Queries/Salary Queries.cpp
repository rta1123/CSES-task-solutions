#include <bits/stdc++.h>

using namespace std;

struct seg_tree
{
    int l, r, c;
    seg_tree *L, *R;

    seg_tree()
    {
        l = 0;
        r = 0;
        c = 0;
        L = nullptr;
        R = nullptr;
    }

    seg_tree(int a, int b, const vector <int> &u)
    {
        if (a < b)
        {
            L = new seg_tree(a, (a+b)/2, u);
            R = new seg_tree(1 + (a+b)/2, b, u);

            l = L->l;
            r = R->r;
            c = L->c + R->c;
        }
        else
        {
            l = u[a];
            r = u[a];
            c = 0;

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

    void rmv(int p)
    {
        if ((L == nullptr) and (R == nullptr) and (l == p))
        {
            c--;
            return;
        }

        if ((L != nullptr) and (L->l <= p) and (p <= L->r))
        {
            L->rmv(p);
            c--;
            return;
        }

        if ((R != nullptr) and (R->l <= p) and (p <= R->r))
        {
            R->rmv(p);
            c--;
            return;
        }
    }

    void add(int p)
    {
        if ((L == nullptr) and (R == nullptr) and (l == p))
        {
            c++;
            return;
        }

        if ((L != nullptr) and (L->l <= p) and (p <= L->r))
        {
            L->add(p);
            c++;
            return;
        }

        if ((R != nullptr) and (R->l <= p) and (p <= R->r))
        {
            R->add(p);
            c++;
            return;
        }
    }

    int count(int a, int b)
    {
        int ans = {};

        if ((l == a) and (r == b))
            return c;

        if ((L != nullptr) and (L->l <= a) and (a <= L->r))
            ans += L->count(a, min(b, L->r));

        if ((R != nullptr) and (R->l <= b) and (b <= R->r))
            ans += R->count(max(a, R->l), b);

        return ans;
    }

};

int main()
{
    int n, q, x, y, *p;
    char op;
    queue <tuple<int,int,int>> queirie;
    vector <int> u;
    queue <int> ans;
    seg_tree *tree;

    scanf("%d %d", &n, &q);

    p = new int[n+1];

    for (int i=1; i<=n; i++)
    {
        scanf("%d", &p[i]);

        u.push_back(p[i]);
    }

    for (int i=1; i<=q; i++)
    {
        scanf(" %c %d %d", &op, &x, &y);

        if (op == '!')
        {
            queirie.push({1, x, y});
            u.push_back(y);
        }
        else
        {
            queirie.push({2, x, y});
            u.push_back(x);
            u.push_back(y);
        }
    }

    sort(u.begin(), u.end());
    u.erase(unique(u.begin(), u.end()), u.end());

    tree = new seg_tree(0, u.size() - 1, u);

    for (int i=1; i<=n; i++)
        tree->add(p[i]);

    while (!queirie.empty())
    {
        tie(op, x, y) = queirie.front();
        queirie.pop();

        if (op == 1)
        {
            tree->rmv(p[x]);
            p[x] = y;
            tree->add(p[x]);
        }
        else
        {
            ans.push(tree->count(x, y));
        }
    }

    while (!ans.empty())
    {
        printf("%d\n", ans.front());
        ans.pop();
    }

    delete[] p;

    tree->free();
    delete tree;

    return 0;
}
