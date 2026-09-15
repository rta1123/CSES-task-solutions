#include <bits/stdc++.h>

using namespace std;

struct person
{
    int64_t max_price;
    int64_t price;
};

int main()
{
    int64_t n, m, temp;
    multiset <int64_t> ticket_price;
    vector <person> p;
    person temp_p;

    cin >> n;
    cin >> m;

    for (int64_t i=0;i < n;i++)
    {
        cin >> temp;
        ticket_price.insert(-temp);
    }

    for (int64_t i=0;i < m;i++)
    {
        cin  >> temp;
        temp_p.max_price = -temp;
        temp_p.price = 1;
        p.push_back(temp_p);
    }

    for (int i=0;i<m;i++)
    {
        auto it = ticket_price.lower_bound(p[i].max_price);

        if (it!=ticket_price.end())
        {
            p[i].price = *it;
            ticket_price.erase(ticket_price.find(*it));
        }
    }

    for (int64_t i=0;i < m;i++)
        cout << -1*p[i].price << endl;

    return 0;
}
