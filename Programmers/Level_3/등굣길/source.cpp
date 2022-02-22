#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {

    vector<vector<int>> board(n, vector<int>(m, 1));
    for(auto& i : puddles)
    {
        int x = i[0] - 1;
        int y = i[1] - 1;
        
        board[y][x] = 0;
        
        if(x == 0)
        {
            for(int j = y; j < n; j++)
            {
               board[j][0] = 0;
            }
        }
        
        if(y == 0)
        {
            for(int j = x; j < m; j++)
            {
               board[0][j] = 0;
            }
        }
    }

    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < m; j++)
        {
            if(board[i][j] == 0) continue;

            board[i][j] = (board[i - 1][j] + board[i][j - 1]) % 1000000007;
        }
    }
    
    return board[n - 1][m - 1];
}