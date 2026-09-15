#include <bits/stdc++.h>

using namespace std;

typedef int64_t lint;

#define X real()
#define Y imag()

lint vector_product(complex <lint> p, complex <lint> q)
{
    return p.X * q.Y - q.X * p.Y;
}

lint labs(lint u)
{
    if (u < 0)
        return -u;
    else
        return u;
}

lint gcd(lint u, lint v)
{
    if (u==0)
        return v;
    if (v==0)
        return u;

    if (u > v)
        return gcd(u % v, v);
    else
        return gcd(u, v % u);
}

int main()
{
    lint n, S, B, G, x, y;
    vector <complex<lint>> P;

    cin >> n;

    for (lint i=0;i<n;i++)
    {
        cin >> x;
        cin >> y;
        P.push_back({x,y});
    }
    P.push_back(P[0]);

    S = 0, G = 0;
    for (lint i = 0; i < n; i++)
    {
        S += vector_product(P[i],P[i+1]);
        x = labs(P[i].X - P[i+1].X);
        y = labs(P[i].Y - P[i+1].Y);
        G += 1  + gcd(x, y);
    }
    G -= n;
    S = S/2;
    S = labs(S);
    B = 1 + S - G / 2;

    cout << B << " " << G;

    return 0;
}
