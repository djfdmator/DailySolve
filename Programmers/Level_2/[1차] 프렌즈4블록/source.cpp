#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct pos
{
    int _x;
    int _y;
    pos(int x, int y) : _x(x), _y(y)
    {
        
    }
};

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    vector<pos> erased;
    
    bool isPlay = true;
    while(isPlay)
    {
        int count = 0;
        for(int i = 0; i < m - 1; i++)
        {
            for(int j = 0; j < n - 1; j++)
            {
                char c = board[i][j];
                if(c == '0')
                    continue;
                
                if(c == board[i + 1][j] && c == board[i][j + 1] && c == board[i + 1][j + 1])
                {
                    erased.push_back(pos(j,i));
                    erased.push_back(pos(j + 1,i));
                    erased.push_back(pos(j,i + 1));
                    erased.push_back(pos(j + 1,i + 1));
                }
            }
        }
        
        while(!erased.empty())
        {
            pos p = erased.back();
            erased.pop_back();
            if(board[p._y][p._x] != '0')
            {
                board[p._y][p._x] = '0';
                count++;
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            for(int j = m - 1; j >= 0; j--)
            {
                int y = j;
                while(board[j][i] == '0' && y - 1 >= 0)
                {
                    board[j][i] = board[y - 1][i];
                    board[y - 1][i] = '0';
                    y--;
                }
            }
        }
        
        answer += count;
        
        if(count == 0)
        {
            isPlay = false;
        }
    }
    
    return answer;
}