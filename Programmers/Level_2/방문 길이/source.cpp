#include <string>
#include <vector>
using namespace std;

struct pos
{
    bool up;
    bool down;
    bool right;
    bool left;
    
    pos()
    {
        up = false;
        down = false;
        right = false;
        left = false;
    }
};

int solution(string dirs) {
    int answer = 0;
    
    vector<vector<pos>> map(11, vector<pos>(11));
    int curX = 5;
    int curY = 5;
    
    for(int i = 0; i < 11; i++)
    {
        map[0][i].up = true;
        map[10][i].down = true;
        map[i][0].left = true;
        map[i][10].right = true;
    }
    
    for(int i = 0; i < dirs.length(); i++)
    {
        switch(dirs[i])
        {
            case 'U':
                if(map[curY][curX].up == false)
                {
                    answer++;
                    map[curY][curX].up = true;
                    map[curY - 1][curX].down = true;
                }
                if(0 < curY) curY--;
                break;
            case 'D':
                if(map[curY][curX].down == false)
                {
                    answer++;
                    map[curY][curX].down = true;
                    map[curY + 1][curX].up = true;
                }
                if(curY < 10) curY++;
                break;
            case 'R':
                if(map[curY][curX].right == false)
                {
                    answer++;
                    map[curY][curX].right = true;
                    map[curY][curX + 1].left = true;
                }
                if(curX < 10) curX++;
                break;
            case 'L':
                if(map[curY][curX].left == false)
                {
                    answer++;
                    map[curY][curX].left = true;
                    map[curY][curX - 1].right = true;
                }
                if(0 < curX) curX--;
                break;
        }
        
        
        
    }
        
    
    
    return answer; 
}