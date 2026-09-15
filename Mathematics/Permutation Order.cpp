#include <bits/stdc++.h>

using namespace std;

typedef uint64_t ull;

enum {N = 20};

#define null nullptr

struct sgt
{
    ull l, r, v;
    sgt *L, *R;

    sgt()
    {
        l = {};
        r = {};
        v = {};
        L = {};
        R = {};
    }

    sgt(ull a, ull b)
    {
        if (a < b)
        {
            l = (a + b)/2 - a + 1;
            r = b - (a + b)/2;
            L = new sgt(a, (a + b)/2);
            R = new sgt(1 + (a + b)/2, b);
            v = {};
        }
        else
        {
            l = {};
            r = {};
            L = {};
            R = {};
            v = a;
        }
    }

    bool empty()
    {
        return ((l + r) == 0);
    }

    ull last()
    {
        return (l + r);
    }

    ull rmv(ull m)
    {
        if ((L == null) and (R == null))
            return v;

        if ((L != null) and (l >= m))
        {
            l--;
            return L->rmv(m);
        }

        if ((R != null) and ((l + r) >= m))
        {
            r--;
            return R->rmv(m - l);
        }

        return {};
    }

    void free()
    {
        if (L != null)
            L->free();

        if (R != null)
            R->free();

        delete L;
        delete R;
    }
};

int main()
{
    ull t, n, k, j, q, y, *v;
    double m;
    vector <ull> F;
    vector <ull> P;
    vector <vector<ull>> ans;
    sgt *p;

    cin >> t;

    F.push_back(1);
    for (ull i=1; i<=N; i++)
        F.push_back(F.back() * i);

    for (ull i=1; i<=t; i++)
    {
        cin >> q;

        if (q == 1)
        {
            cin >> n;
            cin >> k;

            P = {};

            p = new sgt(1, n);
            j = 1;

            while (k)
            {
                m = ceil(k / double(F[n-j]));
                k = k % F[n-j];

                P.push_back(p->rmv(m));

                if (k == 0)
                    while (!p->empty())
                        P.push_back(p->rmv(p->last()));

                j++;
            }

            ans.push_back(P);

            p->free();
            delete p;
        }
        else
        {
            cin >> n;

            v = new ull[n+1];
            for (j=1; j<=n; j++)
                cin >> v[j];

            k = {};

            for (j=1; j<=n; j++)
            {
                y = {};
                for (ull r=j+1; r<=n; r++)
                    if (v[j] > v[r])
                        y++;

                k += y*F[n-j];
            }

            P = {}; P.push_back(k+1);

            ans.push_back(P);

            delete v;

        }
    }

    for (const auto &x : ans)
    {
        for (const auto &a : x)
            cout << a << " ";
        cout << endl;
    }

    return 0;
}
