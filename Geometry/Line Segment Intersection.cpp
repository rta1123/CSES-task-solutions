#include <bits/stdc++.h>

using namespace std;

#define X real()
#define Y imag()

bool on_line(complex<int64_t> p1, complex<int64_t> p2, complex<int64_t> p3)
{
    if (((p1.X <= p3.X && p3.X <= p2.X) || (p2.X <= p3.X && p3.X <= p1.X)) &&
            ((p1.Y <= p3.Y && p3.Y <= p2.Y) || (p2.Y <= p3.Y && p3.Y <= p1.Y)))
        return true;
    else
        return false;
}

int64_t VP(complex<int64_t> p1, complex<int64_t> p2)
{
    return p1.X*p2.Y - p2.X*p1.Y;
}

bool touch(complex<int64_t> p1, complex<int64_t> p2, complex<int64_t> p3)
{
    if (VP(p2-p1,p3-p1) == 0)
        return true;
    else
        return false;
}

bool left(complex<int64_t> p1, complex<int64_t> p2, complex<int64_t> p3)
{
    if (VP(p2-p1,p3-p1) > 0)
        return true;
    else
        return false;
}

int main()
{
    uint64_t t;
    int64_t x,y;
    complex <int64_t> *p1, *p2, *p3, *p4;

    cin >> t;

    p1 = new complex<int64_t>[t];
    p2 = new complex<int64_t>[t];
    p3 = new complex<int64_t>[t];
    p4 = new complex<int64_t>[t];

    for (uint64_t i=0;i<t;i++)
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

        cin >> x;
        cin >> y;
        p4[i] = {x,y};
    }

    for (uint64_t i=0;i<t;i++)
    {
        if ((touch(p1[i],p2[i],p3[i]) && on_line(p1[i],p2[i],p3[i])) || (touch(p1[i],p2[i],p4[i]) && on_line(p1[i],p2[i],p4[i]))
                || (touch(p3[i],p4[i],p1[i]) && on_line(p3[i],p4[i],p1[i])) || (touch(p3[i],p4[i],p2[i]) && on_line(p3[i],p4[i],p2[i])) )
            cout << "YES";
        else
            if (left(p1[i],p2[i],p3[i]) != left(p1[i],p2[i],p4[i]) && left(p3[i],p4[i],p1[i]) != left(p3[i],p4[i],p2[i]))
                cout << "YES";
            else
                cout << "NO";

        cout << endl;
    }


    delete[] p1;
    delete[] p2;
    delete[] p3;
    delete[] p4;

    return 0;
}
