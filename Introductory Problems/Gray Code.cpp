#include <bits/stdc++.h>

using namespace std;

typedef int64_t lint;

void create_gray_code(string *gray_code, lint n)
{
    lint i,j;

    if (n==1)
    {
        gray_code[0] = '0';
        gray_code[1] = '1';
        return;
    }

    create_gray_code(gray_code,n-1);

    i = 0, j = (1 << n) - 1;
    while (i < j)
        gray_code[j--] += gray_code[i++];

    i = 0, j = (1 << n) - 1;
    while (i < j)
    {
        gray_code[j--] += '1';
        gray_code[i++] += '0';
    }
}

int main()
{
    lint n;
    string *gray_code;

    cin >> n;

    gray_code = new string[(1 << n)];

    create_gray_code(gray_code,n);

    for (lint i=0;i<(1<<n);i++)
        cout << gray_code[i] <<  endl;

    delete[] gray_code;

    return 0;
}
