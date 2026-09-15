#include <bits/stdc++.h>

using namespace std;

#define SIZE_UCHAR 256

int main()
{
    string str;
    int64_t n, odd;
    vector <int64_t> counter;

    cin >> str;

    n = str.length();
    for (int64_t i=0;i<SIZE_UCHAR;i++)
        counter.push_back(0);

    for (int64_t i=0;i<n;i++)
        counter[str[i]]++;

    odd = 0;
    for (int64_t i=0;i<SIZE_UCHAR;i++)
        if (counter[i] % 2 == 1)
            odd++;

    if (odd>=2 || ((n % 2 == 0) && odd==1))
    {
        cout << "NO SOLUTION";
        return 0;
    }
    else
        if (odd == 1 && n % 2 == 1)
        {

            int64_t c;
            int64_t k=0;
            for (int64_t j=0;j<SIZE_UCHAR;j++)
            {
                if (counter[j])
                    c = counter[j] / 2;
                else
                    continue;

                while (c--)
                    str[k++] = (char) j;
            }

            for (int64_t j=0;j<SIZE_UCHAR;j++)
                if (counter[j] % 2 == 1)
                {
                    str[k++] = (char) j;
                    break;
                }

            for (int64_t j=SIZE_UCHAR-1;j>=0;j--)
            {
                if (counter[j])
                    c = counter[j] / 2;
                else
                    continue;

                while (c--)
                    str[k++] = (char) j;
            }
        }
        else
            if (odd == 0)
            {

                int64_t c;
                int64_t k=0;
                for (int64_t j=0;j<SIZE_UCHAR;j++)
                {
                    if (counter[j])
                        c = counter[j] / 2;
                    else
                        continue;

                    while (c--)
                        str[k++] = (char) j;
                }

                for (int64_t j=SIZE_UCHAR-1;j>=0;j--)
                {
                    if (counter[j])
                        c = counter[j] / 2;
                    else
                        continue;

                    while (c--)
                        str[k++] = (char) j;
                }
            }

    cout << str;

    return 0;
}
