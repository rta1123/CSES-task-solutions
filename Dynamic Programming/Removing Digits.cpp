#include <bits/stdc++.h>

using namespace std;

int64_t digit(int64_t a, int64_t position)
{
    while (position)
    {
        a = a / 10;
        position--;
    }

    return a % 10;
}


int64_t min(int64_t u, int64_t v)
{
    if (u<=v)
        return u;
    else
        return v;
}

#define MAX 1000000

int main()
{
    int64_t n, *N, num_positions, m, M;

    cin >> n;

    N = new int64_t[n+1];
    N[0] = 0;
    for (int64_t i=1;i<=n;i++)
        N[i] = MAX;

    num_positions = 0;
    while (true)
    {
        m = pow(10,num_positions);
        M = pow(10,num_positions+1);
        for (int64_t i = m; i < M; i++)
        {
            for (int64_t j=0; j<=num_positions;j++)
                if (i - digit(i,j)>=0)
                N[i] = min(N[i],N[i - digit(i,j)]+1);

            if (i==n)
            {
                 cout << N[n];
                 delete[] N;
                 return 0;
            }
        }

        num_positions++;
    }

    return 0;
}
