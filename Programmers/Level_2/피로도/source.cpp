#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int Recursive(int k, vector<vector<int>> dungeons, int count)
{
    if(dungeons.size() == 0) return count;
    
    int result = count;
    
    for(int i = 0; i < dungeons.size(); i++)
    {
        if(dungeons[i][0] <= k)
        {
            int next_K = k - dungeons[i][1];
            int next_Count = count + 1;
            
            vector<vector<int>> next_Dungeons(dungeons);
            next_Dungeons.erase(next_Dungeons.begin() + i);
            
            result = max(result, Recursive(next_K, next_Dungeons, next_Count));
        }
    }
    
    
    return result;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    
    answer = Recursive(k, dungeons, 0);
    
    return answer;
}