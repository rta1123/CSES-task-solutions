#include <bits/stdc++.h>

using namespace std;

#define max 1000000007

int main()
{
    int64_t n, **board;
    char ch;

    cin >> n;

    board = new int64_t*[n];
    for (int64_t i=0;i<n;i++)
        board[i] = new int64_t[n];


    for (int64_t i=0;i<n;i++)
        for (int64_t j=0;j<n;j++)
        {
            board[i][j] = -1;

            cin >> ch;
            if (ch == '.')
                board[i][j] = 0;
        }

    for (int64_t j=0;j<n;j++)
        if (board[0][j] == 0)
            board[0][j] = 1;
        else
            if (board[0][j] == -1)
                break;

    for (int64_t i=0;i<n;i++)
        if (board[i][0] == 0)
            board[i][0] = 1;
        else
            if (board[i][0] == -1)
                break;

    for (int64_t i=1;i<n;i++)
        for (int64_t j=1;j<n;j++)
            if (board[i][j]!=-1)
            {
                if (board[i-1][j]!=-1)
                    board[i][j]+=board[i-1][j] % max;

                if (board[i][j-1]!=-1)
                    board[i][j]+=board[i][j-1] % max;
            }

    if (board[n-1][n-1]==-1)
        cout << 0;
    else
        cout << board[n-1][n-1]  % max;

    for (int64_t i=0;i<n;i++)
        delete[] board[i];
    delete[] board;

    return 0;
}
