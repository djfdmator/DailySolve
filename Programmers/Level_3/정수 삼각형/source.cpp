#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    vector<vector<int>> result_tri(triangle.size());
    result_tri[0].push_back(triangle[0][0]);
    for(int i = 0; i < triangle.size() - 1; i++)
    {
        int temp = -1;
        for(int j = 0; j < triangle[i].size(); j++)
        {
            int a = triangle[i + 1][j] + result_tri[i][j];
            int b = triangle[i + 1][j + 1] + result_tri[i][j];
            
            if(temp > a)
            {
                temp = -1;
            }
            else
            {
                if(result_tri[i + 1].size() == 0) result_tri[i + 1].push_back(a);
                else result_tri[i + 1].back() = a;
            }
            result_tri[i + 1].push_back(b);
            temp = b;
        }
    }

    return *max_element(result_tri.back().begin(), result_tri.back().end());
}