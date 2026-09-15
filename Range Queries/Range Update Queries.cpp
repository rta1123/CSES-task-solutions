#include <bits/stdc++.h>

using namespace std;

typedef int64_t lint;

enum
{
    inc_querie = 1,
    val_querie = 2,
};

void update_seg_tree(lint *diff_seg_tree, lint k, lint u)
{
    diff_seg_tree[k]+=u;

    for (lint i=k/2; i>=1; i/=2)
        diff_seg_tree[i]+=u;
}

lint sum_on_segment(lint *diff_seg_tree, lint a, lint b, lint k, lint x, lint y)
{
    lint mid = (x+y)/2;

    if (x>b || y<a)
        return 0;

    if (a<=x && y<=b)
        return diff_seg_tree[k];

    return sum_on_segment(diff_seg_tree,a,b,2*k,x,mid)+sum_on_segment(diff_seg_tree,a,b,2*k+1,mid+1,y);
}

int main()
{
    lint n, m, q, op, a, b, u, k;
    lint *diff_seg_tree;
    vector <lint> rvq;

    cin >> n;
    cin >> q;

    m = pow(2, ceil(log2(n)));

    diff_seg_tree = new lint[2*m];

    for (lint i=0; i<n; i++)
        cin >> diff_seg_tree[m+i];

    for (lint i=n+m-1; i>m; i--)
        diff_seg_tree[i]-=diff_seg_tree[i-1];

    for (lint i=m-1; i>=1; i--)
        diff_seg_tree[i] = diff_seg_tree[2*i]+diff_seg_tree[2*i+1];

    for (lint i=0; i<q; i++)
    {
        cin >> op;

        if (op == inc_querie)
        {
            cin >> a; cin >> b; cin >> u;

            update_seg_tree(diff_seg_tree, a+m-1, u);
            if (b<n)
                update_seg_tree(diff_seg_tree, b+m, -u);
        }

        if (op == val_querie)
        {
            cin >> k;

            rvq.push_back(sum_on_segment(diff_seg_tree,m,m+k-1,1,m,2*m-1));
        }
    }

    for (auto r:rvq)
        cout << r << endl;

    delete[] diff_seg_tree;

    return 0;
}
