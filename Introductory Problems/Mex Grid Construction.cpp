#include <bits/stdc++.h>

using namespace std;

enum {inf = 1000000};

struct sgt
{
    sgt *L, *R;
    int l, r, m;

    sgt()
    {
        L = {};
        R = {};
        l = {};
        r = {};
        m = inf;
    }

    sgt(int a, int b)
    {
        l = a;
        r = b;

        if (a < b)
        {
            L = new sgt(a, (a + b)/2);
            R = new sgt((a + b)/2 + 1, b);
            m = min(L->m, R->m);
        }
        else
        {
            L = {};
            R = {};
            m = l;
        }
    }

    void add_min(int M)
    {
        if ((l == M) and (r == M))
        {
            m = M;
            return;
        }

        if ((L != nullptr) and (L->l <= M) and (L->r >= M))
        {
            L->add_min(M);
            m = min(L->m, R->m);
            return;
        }

        if ((R != nullptr) and (R->l <= M) and (R->r >= M))
        {
            R->add_min(M);
            m = min(L->m, R->m);
            return;
        }
    }

    void remove_min(int M)
    {
        if ((l == M) and (r == M))
        {
            m = inf;
            return;
        }

        if ((L != nullptr) and (L->l <= M) and (L->r >= M))
        {
            L->remove_min(M);
            m = min(L->m, R->m);
            return;
        }

        if ((R != nullptr) and (R->l <= M) and (R->r >= M))
        {
            R->remove_min(M);
            m = min(L->m, R->m);
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

int main()
{
    int n, **mex;
    sgt *t;

    cin >> n;

    mex = new int*[n+1];
    for (int i=0; i<=n; i++)
        mex[i] = new int[n+1];

    mex[1][1] = 0;
    for (int i=2; i<=n; i++)
    {
        mex[1][i] = i-1;
        mex[i][1] = i-1;
    }

    t = new sgt(0, 2*n);
    for (int i=2; i<=n; i++)
    {
        for (int j=2; j<=n; j++)
        {
            for (int k=1; k<j; k++)
                t->remove_min(mex[i][k]);

            for (int k=1; k<i; k++)
                t->remove_min(mex[k][j]);

            mex[i][j] = t->m;

            for (int k=1; k<j; k++)
                t->add_min(mex[i][k]);

            for (int k=1; k<i; k++)
                t->add_min(mex[k][j]);
        }
    }

    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
            cout << mex[i][j] << " ";
        cout << endl;
    }

    t->free();
    delete t;
    for (int i=0; i<=n; i++)
        delete[] mex[i];
    delete[] mex;

    return 0;
}
