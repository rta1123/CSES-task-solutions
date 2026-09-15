#include <bits/stdc++.h>

using namespace std;

typedef uint64_t lint;

#define infinity 1000000000000

enum
{
    update_querie = 1,
    min_querie = 2,
};

lint max(lint u, lint v)
{
    if (u<=v)
        return u;
    else
        return v;
}

void update_seg_tree(lint *seg_tree, lint m, lint k, lint u)
{
    seg_tree[m+k-1] = u;

    for (lint i=(m+k-1)/2; i >=1; i=i/2)
        seg_tree[i]=min(seg_tree[2*i],seg_tree[2*i+1]);
}

lint min_on_segment(lint *seg_tree, lint a, lint b, lint k, lint x, lint y)
{
    lint mid = (x+y)/2;

    if (b < x || a > y)
        return infinity;

    if (a<=x &&  y<=b)
        return seg_tree[k];

    return min(min_on_segment(seg_tree,a,b,2*k,x,mid), min_on_segment(seg_tree,a,b,2*k+1,mid+1,y));
}

int main()
{
    lint n, q, m;
    lint *seg_tree, op, a, b, k, u;
    vector <lint> M;

    cin >> n; cin >> q;

    m = pow(2,ceil(log2(n)));

    seg_tree = new lint[2*m];

    for (lint i=m, j=0; j<n; i++, j++)
        cin >> seg_tree[i];

    for (lint i=n+m; i<2*m; i++)
        seg_tree[i] = infinity;

    for (lint i=m-1; i>=1; i--)
        seg_tree[i] = min(seg_tree[2*i], seg_tree[2*i+1]);

    for (lint i=0; i<q; i++)
    {
        cin >> op;

        if (op == update_querie)
        {
            cin >> k; cin >> u;
            update_seg_tree(seg_tree,m,k,u);
        }

        if (op == min_querie)
        {
            cin >> a; cin >> b;
            M.push_back(min_on_segment(seg_tree,a+m-1,b+m-1,1,m,2*m-1));
        }
    }

    for (auto x: M)
        cout << x << endl;

    delete[] seg_tree;

    return 0;
}
