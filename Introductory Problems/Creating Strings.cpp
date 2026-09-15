#include <bits/stdc++.h>

using namespace std;

typedef uint32_t uint;

uint factorial(uint n)
{
    if (n == 0)
        return 1;

    return n*factorial(n-1);
}

int main()
{
    uint k, s, *a, n;
    string word;

    cin >> word;

    s = word.size();
    a = new uint[s];

    for (uint i = 0; i < s; i++)
        a[i] = word[i];

    sort(a,a+s);

    k = factorial(s);
    n = 1;
    for (uint i=0;i<s-1;i++)
    {
        if (a[i]==a[i+1])
            n++;
        else
        {
            k = k / factorial(n);
            n = 1;
        }
    }
    k = k / factorial(n);

    cout << k << endl;

    do
    {
        for (uint i = 0; i < s; i++)
            word[i] = a[i];

        cout << word << endl;

    } while (next_permutation(a,a+s));


    delete[] a;

    return 0;
}
