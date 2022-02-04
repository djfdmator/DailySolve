#include <vector>
#include <algorithm>

using namespace std;

bool CheckZero(vector<vector<int>> board)
{
    bool result = true;
    
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board[0].size(); j++)
        {
            if(board[i][j] == 1) return false;
        }
    }
    
    return result;
}

int solution(vector<vector<int>> board)
{
    int answer = 1;
    int column = board.size(), row = board[0].size();
    
    if(CheckZero(board)) return 0;
    
    for(int i = 1; i < column; i++)
    {
        for(int j = 1; j < row; j++)
        {
            if(board[i][j] == 0) continue;
            board[i][j] = min(min(board[i - 1][j], board[i][j - 1]), board[i - 1][j - 1]) + 1;
            answer = max(board[i][j], answer);
        }
    }

    return answer * answer;
}