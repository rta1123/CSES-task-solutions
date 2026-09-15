#include <bits/stdc++.h>

using namespace std;

#define m 1000000007

typedef uint64_t ull;

struct matrix
{
    ull _11, _12, _21, _22;

    friend matrix operator*(const matrix &A, const matrix &B)
    {
        matrix C {};

        C._11 = (A._11 * B._11 + A._12 * B._21) % m;
        C._12 = (A._11 * B._12 + A._12 * B._22) % m;
        C._21 = (A._21 * B._11 + A._22 * B._21) % m;
        C._22 = (A._21 * B._12 + A._22 * B._22) % m;

        return C;
    }

    matrix (const matrix &A) : _11(A._11), _12(A._12), _21(A._21), _22(A._22) {}
    matrix(ull _11, ull _12, ull _21, ull _22) : _11(_11), _12(_12), _21(_21), _22(_22) {}
    matrix() : _11(0), _12(0), _21(0), _22(0) {}
};

matrix pow(ull n)
{
    if (n == 1)
        return matrix(1, 1, 1, 0);

    if (n % 2)
        return pow(n-1) * matrix(1, 1, 1, 0);
    else
    {
        matrix C = pow(n/2);

        return C*C;
    }
}


int main()
{
    ull n;

    cin >> n;

    if (n == 0)
        cout << 0 << endl;
    else
        if (n == 1)
            cout << 1 << endl;
        else
            cout << pow(n-1)._11 << endl;

    return 0;
}
