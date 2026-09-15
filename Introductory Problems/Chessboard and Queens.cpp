#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long lint;

const int size = 8;

lint solve(int row, bool chessboard[size][size], bool restricted_area[size][size], int nQ)
{
    bool old_chessboard[size][size];
    lint count = {};
    
    if (row == size)
    {
        if (nQ == size)
            return 1;
        else
            return 0;
    }
    
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            old_chessboard[i][j] = chessboard[i][j];
    
    for (int column = 0; column < size; column++)
    {
        if (chessboard[row][column] || restricted_area[row][column])
            continue;
        else
            {
                for (int i = row; i < size; i++)
                    chessboard[i][column] = 1;
            
                for (int i = row, j = column; i < size && j < size; i++, j++)
                    chessboard[i][j] = 1;
                
                for (int i = row, j = column; i < size && j >=0; i++, j--)
                    chessboard[i][j] = 1;    
                    
                count += solve(row + 1, chessboard, restricted_area, nQ + 1);
            
                for (int i = row; i < size; i++)
                    chessboard[i][column] = old_chessboard[i][column];
            
                for (int i = row, j = column; i < size && j < size; i++, j++)
                    chessboard[i][j] = old_chessboard[i][j];
                      
                for (int i = row, j = column; i < size && j >=0; i++, j--)
                    chessboard[i][j] = old_chessboard[i][j];
                    
            }
    }
    
    return count;
}

int main()
{
    bool chessboard[size][size], restricted_area[size][size];
    char s;
    
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            {
                cin >> s;
                
                if (s == '*')
                    restricted_area[i][j] = 1;
                else
                    restricted_area[i][j] = 0;
            
                chessboard[i][j] = 0;
            }
    
    cout << solve(0, chessboard, restricted_area, 0);
    
    return 0;
}