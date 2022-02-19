#include <string>
#include <vector>
#include <iostream>

using namespace std;

int factorial(int n)
{
    int result = 0;
    for(int i = 1; i <= n; i++)
    {
        result += i;
    }
    return result;
}

enum DIR{
    DOWN=0,
    RIGHT=1,
    UPLEFT=2,
};

vector<int> solution(int n) {
    vector<int> answer;
    
    int maxCount = factorial(n);
    
    int dir = DOWN;
    int dx[3] = {0, 1, -1};
    int dy[3] = {1, 0, -1};
    int x = 0, y = 0;
    
    vector<vector<int>> board(n, vector<int>(n, 0));
    
    int value = 1;
    while(true)
    {
        board[y][x] = value;
        if(value == maxCount) 
            break;
        
        int nextX = x + dx[dir];
        int nextY = y + dy[dir];
        
        if( (0 <= nextX && nextX < n) && (0 <= nextY && nextY < n) && board[nextY][nextX] == 0)
        {
            x = nextX;
            y = nextY;
            value++;
        }
        else
        {
            dir = (dir + 1) % 3;
        }
        
    }
    
    for(auto& i : board)
    {
        for(auto& j : i)
        {
            if(j == 0) break;
            answer.push_back(j);
        }
    }
    
    return answer;
}