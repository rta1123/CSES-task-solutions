#include <bits/stdc++.h>

using namespace std;

#define X real()
#define Y imag()

int64_t VP(complex <int64_t> p1, complex <int64_t> p2)
{
    return p1.X*p2.Y - p1.Y*p2.X;
}

int main()
{
    uint64_t n;
    int64_t x,y, v;
    complex <int64_t> *p1,*p2,*p3;

    cin >> n;

    p1 = new complex<int64_t>[n];
    p2 = new complex<int64_t>[n];
    p3 = new complex<int64_t>[n];

    for (uint64_t i=0;i<n;i++)
    {
        cin >> x;
        cin >> y;
        p1[i] = {x,y};

        cin >> x;
        cin >> y;
        p2[i] = {x,y};

        cin >> x;
        cin >> y;
        p3[i] = {x,y};
    }

    for (uint64_t i=0;i<n;i++)
    {
        v = VP(p2[i]-p1[i],p3[i]-p1[i]);

        if (v>0)
            cout << "LEFT";
        else
            if (v<0)
                cout << "RIGHT";
            else
                cout << "TOUCH";

        cout << endl;
    }


    delete[] p1;
    delete[] p2;
    delete[] p3;

    return 0;
}
