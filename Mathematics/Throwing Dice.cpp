#include <bits/stdc++.h>

using namespace std;

typedef uint64_t ull;

#define m 1000000007

struct matrix
{
    ull _[6][6];

    friend matrix operator*(const matrix &A, const matrix &B)
    {
        matrix C {};

        for (int i=0; i<6; i++)
            for (int j=0; j<6; j++)
                for (int k=0; k<6; k++)
                {
                    C._[i][j] += A._[i][k] * B._[k][j];
                    C._[i][j] %= m;
                }

        return C;
    }

    matrix()
    {
        for (ull i=0; i<6; i++)
            for (ull j=0; j<6; j++)
                _[i][j] = 0;
    }

    matrix(const matrix &A)
    {
        for (ull i=0; i<6; i++)
            for (ull j=0; j<6; j++)
                _[i][j] = A._[i][j];
    }
};

matrix pow(ull n, const matrix &I)
{
    if (n == 1)
        return I;

    if (n % 2)
        return pow(n-1, I) * I;
    else
    {
        matrix C = pow(n/2, I);
        return C*C;
    }

}

int main()
{
    ull n;
    matrix I;

    cin >> n;

    for (int i=0; i<5; i++)
        I._[i+1][i] = 1;

    for (int i=0; i<6; i++)
        I._[0][i] = 1;

    cout << pow(n, I)._[0][0] << endl;

    return 0;
}
