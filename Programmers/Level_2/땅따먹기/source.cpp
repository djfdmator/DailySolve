#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int row = land.size(), column = 4; 

    for(int i = 0; i < row - 1; i++)
    {
        vector<int> temp_max(4);
        for(int j = 0; j < 4; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                int index = (j + k + 1) % 4;
                int value = land[i][j] + land[i + 1][index];
                if(temp_max[index] < value)
                {
                    temp_max[index] = value;
                }
            }
        }
        
        for(int j = 0; j < 4; j++)
        {
            land[i + 1][j] = temp_max[j];
        }
    }
    
    for(int j = 0; j < 4; j++)
    {
        if(answer < land.back()[j])
        {
            answer = land.back()[j];
        }
    }

    return answer;
}