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

struct sgt
{
    int l, r, m, p;
    sgt *lch, *rch;

    sgt()
    {
        l = 0;
        r = 0;
        m = 0;
        p = 0;
        lch = nullptr;
        rch = nullptr;
    }

    sgt(int L, int R, int *x)
    {
        l = L;
        r = R;

        if (L < R)
        {
            lch = new sgt(L, (L + R)/2, x);
            rch = new sgt(1 + (L + R)/2, R, x);

            if (lch->m >= rch->m)
            {
                m = lch->m;
                p = lch->p;
            }
            else
            {
                m = rch->m;
                p = rch->p;
            }
        }
        else
        {
            m = x[L];
            p = L;
            lch = nullptr;
            rch = nullptr;
        }
    }

    void free()
    {
        if (lch != nullptr)
            lch->free();

        if (rch != nullptr)
            rch->free();

        delete lch;
        delete rch;
    }

    pair<int,int> search(int a, int b)
    {
        pair <int, int> ansl {0,0}, ansr {0,0}, ans {0,0};

        if ((lch == nullptr) and (rch == nullptr))
            return {m, p};

        if (l == a and r == b)
            return {m, p};

        if ((lch != nullptr) and (lch->l <= a) and (lch->r >= a))
            ansl = lch->search(a, min(lch->r, b));

        if ((rch != nullptr) and (rch->l <= b) and (rch->r >= b))
            ansr = rch->search(max(a, rch->l), b);

        if (ansr.first > ansl.first)
            ans = ansr;
        else
            ans = ansl;

        return ans;
    }

    void update(int i, int x)
    {
        if ((lch == nullptr) and (rch == nullptr))
        {
            m = x;

            return;
        }

        if ((lch != nullptr) and (lch->l <= i) and (lch->r >= i))
            lch->update(i, x);

        if ((rch != nullptr) and (rch->l <= i) and (rch->r >= i))
            rch->update(i, x);

        m = 0;

        if ((lch != nullptr) and (lch->m >= m))
        {
            m = lch->m;
            p = lch->p;
        }

        if ((rch !=  nullptr) and (rch->m > m))
        {
            m = rch->m;
            p = rch->p;
        }
    }
};

int main()
{
    int n, k, m, *x, *p, a, b, C;
    pair <int, int> *X;
    queue <pair<int,int>> ans;
    sgt *t;
    bool solution;

    cin >> n;

    X = new pair<int,int>[n+1];

    for (int i=1; i<=n; i++)
    {
        cin >> X[i].first;
        X[i].second = i;
    }

    k = 0;
    for (int i=1; i<=n; i++)
        if (X[i].first)
            k++;

    m = 0;

    if (k)
    {
        sort(X + 1, X + n + 1);

        x = new int[k+1];
        p = new int[k+1];

        C = 0;
        for (int i=1, j=1; i<=n; i++)
            if (X[i].first)
            {
                x[j] = X[i].first;
                p[j] = X[i].second;
                C += x[j];
                j++;
            }

        n = k;

        t = new sgt(1, n, x);

        solution = true;
        for (int i=n; i>=1; i--)
        {
            if ((x[i] >= i) or (C % 2))
            {
                solution = false;
                break;
            }

            t->update(i, 0);

            b = i - 1;
            while (x[i])
            {
                a = t->search(1, b).second;

                for (int j=a; j<=b; j++)
                {
                    if (x[i])
                    {
                        x[i]--;
                        x[j]--;
                        t->update(j, x[j]);

                        m++;
                        ans.push({p[i], p[j]});
                    }
                    else
                        break;
                }

                b = a - 1;
            }
        }

        if (!solution)
            cout << "IMPOSSIBLE" << endl;
        else
        {
            cout << m << endl;
            while (!ans.empty())
            {
                cout << ans.front().first << " " << ans.front().second << endl;
                ans.pop();
            }
        }

        t->free();
        delete t;
        delete[] x;
        delete[] p;
    }
    else
    {
        cout << m << endl;
    }

    delete[] X;

    return 0;
}
