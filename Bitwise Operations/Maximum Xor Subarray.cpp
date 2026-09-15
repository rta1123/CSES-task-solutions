#include <bits/stdc++.h>

using namespace std;

#define null nullptr
#define MNB 30

struct bin_tree
{
    bin_tree *l, *r;
    bool L, R;

    bin_tree()
    {
        l = {};
        r = {};
        L = {};
        R = {};
    }

    void insert(uint x, uint p)
    {
        if (p)
        {
            if (x & (1 << p))
            {
                if (r == null)
                    r = new bin_tree();

                r->insert(x, p-1);
            }
            else
            {
                if (l == null)
                    l = new bin_tree();

                l->insert(x, p-1);
            }
        }

        if (x & (1 << p))
            R = true;
        else
            L = true;
    }

    uint find_addititon(uint x, uint p)
    {
        if (p)
        {
            if (x & (1 << p))
            {
                if (l != null)
                    return ((1 << p) + l->find_addititon(x, p-1));
                else
                    return r->find_addititon(x, p-1);
            }
            else
            {
                if (r != null)
                    return ((1 << p) + r->find_addititon(x, p-1));
                else
                    return (l->find_addititon(x, p-1));
            }
        }
        else
        {
            if (x & (1 << p))
            {
                if (L)
                    return 1;
                else
                    return 0;
            }
            else
            {
                if (R)
                    return 1;
                else
                    return 0;
            }
        }
    }

    void free()
    {
        if (l != null)
            l->free();
        if (r != null)
            r->free();

        delete l;
        delete r;
    }
};


int main()
{
    uint n, *x, *s, m;
    bin_tree *tree {};

    tree = new bin_tree;

    cin >> n;

    x = new uint[n+1];
    s = new uint[n+1];

    m = {};
    for (uint i=1; i<=n; i++)
    {
        cin >> x[i];
        m = max(m, x[i]);
    }

    s[0] = {};
    for (uint i=1; i<=n; i++)
    {
        s[i] ^= s[i-1] ^ x[i];
        m = max(m, s[i]);
    }

    for (uint i=1; i<=n; i++)
        tree->insert(s[i], MNB);

    for (uint i=1; i<=n; i++)
        m = max(m, tree->find_addititon(s[i], MNB));

    cout << m << endl;

    tree->free();
    delete tree;
    delete[] x;
    delete[] s;

    return 0;
}
