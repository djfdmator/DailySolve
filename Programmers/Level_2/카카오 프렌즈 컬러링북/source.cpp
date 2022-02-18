#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

void bfs(const vector<vector<int>>& picture, vector<vector<int>>& visits, int area_number, int x, int y)
{
    int dx[4] = {1, 0 , -1, 0};
    int dy[4] = {0, -1, 0 , 1};
    
    visits[y][x] = area_number;
    
    int n = picture[0].size();
    int m = picture.size();
    
    for(int i = 0; i < 4; i++)
    {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        
        if((0 <= nextX && nextX < n) && (0 <= nextY && nextY < m))
        {
           if(picture[y][x] == picture[nextY][nextX] && visits[nextY][nextX] == 0)
           {
               bfs(picture, visits, area_number, nextX, nextY);
           }
        }
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    vector<int> answer(2);
    
    vector<vector<int>> visits(m, vector<int>(n, 0));
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(picture[i][j] != 0 && visits[i][j] == 0)
            {
                number_of_area++;
                bfs(picture, visits, number_of_area, j, i);
            }
        }
    }
    
    unordered_map<int, int> um;
    for(auto& i : visits)
    {
        for(auto& j : i)
        {
            if(j == 0) continue;
            
            if(um.find(j) == um.end())
            {
                um[j] = 1;
            }
            else
            {
                um[j] += 1;
            }
        }
    }
    
    for(auto& i : um)
    {
        if(i.second > max_size_of_one_area)
        {
            max_size_of_one_area = i.second;
        }
    }
    
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}