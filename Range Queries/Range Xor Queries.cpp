#include <bits/stdc++.h>

using namespace std;

void create_segment_tree(int m, int *x)
{
    for (int i=m-1; i>=1; i--)
        x[i] = x[2*i] ^ x[2*i+1];
}

int querie_on_segment_tree(int i, int l, int r, int a, int b, int *x)
{
    if ((l > b) or (r < a))
        return 0;

    if ((l >= a) and (r <= b))
        return x[i];

    return (querie_on_segment_tree(2 * i, l, (l + r)/2, a, b, x) ^ querie_on_segment_tree(2 * i + 1, (l + r)/2 + 1, r, a, b, x));
}

int Log(int n)
{
    int k = 0;

    while ((1 << k) < n)
        k++;

    return k;
}

int main()
{
    int n, m, q, a, b, *x;
    queue <int> queries;

    cin >> n;
    cin >> q;

    m = (1 << Log(n));

    x = new int[2*m];

    for (int i=0; i<=2*m; i++)
        x[i] = 0;

    for (int i=m; i<=m+n-1; i++)
        cin >> x[i];

    create_segment_tree(m, x);

    for (int i=0; i<q; i++)
    {
        cin >> a;
        cin >> b;

       queries.push(querie_on_segment_tree(1, m,  m + m - 1,  m + a - 1, m + b - 1, x));
    }

    while (!queries.empty())
    {
        cout << queries.front() << endl;
        queries.pop();
    }

    delete[] x;

    return 0;
}
