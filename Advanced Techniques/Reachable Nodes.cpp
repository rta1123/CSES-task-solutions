#include <bits/stdc++.h>

using namespace std;

enum { N = 50000 };

template <typename type>
class numeric_iterator
{
private:
    type i;
public:
    explicit numeric_iterator(type i) : i(i) {};

    type operator *() const
    {
        return i;
    }

    bool operator != (const numeric_iterator &rhs) const
    {
        return (i != rhs.i);
    }

    numeric_iterator& operator ++()
    {
        i++;
        return *this;
    }
};

template <typename type>
class range
{
private:
    type a, b;
public:
    explicit range(type a, type b): a(a), b(b) {};

    numeric_iterator<type> begin() const
    {
        return numeric_iterator{a};
    }

    numeric_iterator<type> end() const
    {
        return numeric_iterator{b};
    }
};

int main()
{
    using type_int = int;

    type_int n, m, u, v;

    cin >> n;
    cin >> m;

    vector <vector<type_int>> adj(n+1);
    vector <bool> p(n+1, 0);
    vector <bitset<N>> rch(n+1, 0);

    for ([[maybe_unused]] auto i : range{1, m+1})
    {
        cin >> u;
        cin >> v;

        adj[u].push_back(v);
    }

    auto find_reachable_nodes { [](auto self, type_int u, const vector <vector<type_int>> &adj, vector <bool> &p, vector <bitset<N>> &rch) -> void
        {
            p[u] = true;
            for (auto v : adj[u])
            {
                if (!p[v])
                    self(self, v, adj, p, rch);
                rch[u] |= rch[v];
            }

            rch[u][u] = 1;
        }};

    for (auto u : range{1, n+1})
        if (!p[u])
            find_reachable_nodes(find_reachable_nodes, u, adj, p, rch);

    for (auto i : range{1, n+1})
        cout << rch[i].count() << " ";
    cout << endl;

    return 0;
}
