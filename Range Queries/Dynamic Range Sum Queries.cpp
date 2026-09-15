#include <bits/stdc++.h>
 
using namespace std;
 
typedef uint64_t lint;

enum
{
    update_querie = 1,
    sum_querie = 2,
};

void update_seg_tree(lint *seg_tree, lint k, lint u)
{
    seg_tree[k] = u;
    
    for (lint i = k/2; i>=1; i/=2)
        seg_tree[i] = seg_tree[2*i]+seg_tree[2*i+1];
}

lint sum_on_segment(lint *seg_tree, lint a, lint b, lint k, lint x, lint y)
{
    lint mid = (x+y)/2;

    if (x > b || y < a)
        return 0;
    
    if (a<=x && y<=b)
        return seg_tree[k];

    return sum_on_segment(seg_tree, a, b, 2*k, x, mid) + sum_on_segment(seg_tree, a, b, 2*k+1, mid+1, y);
}
 
int main()
{
    lint n, q, m, k, u, a, b, op;
    lint *seg_tree;
    vector <lint> S;
 
    cin >> n;
    cin >> q;
     
    m = pow(2, ceil(log2(n)));
     
    seg_tree = new lint[2*m];
 
    for (lint i=0; i<n; i++)
        cin >> seg_tree[m+i];
 
    for (lint i=m-1; i>=1; i--)
        seg_tree[i] = seg_tree[2*i+1]+seg_tree[2*i];
 
    for (lint i=0; i<q; i++)
    {
        cin >> op;
        
        if (op == update_querie)
        {
            cin >> k; cin >> u;
            update_seg_tree(seg_tree, k+m-1, u);
        }
    
        if (op == sum_querie)
        {
            cin >> a; cin >> b;
            S.push_back(sum_on_segment(seg_tree, a+m-1, b+m-1, 1, m, 2*m-1));
        }
    }
    
    for (auto s:S)
        cout << s << endl;

    delete[] seg_tree;
    
    return 0;
}