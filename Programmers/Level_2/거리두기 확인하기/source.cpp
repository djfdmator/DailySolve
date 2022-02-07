#include <string>
#include <vector>

#include <iostream>

using namespace std;

int judge(vector<vector<string>> &places, int i, int j, int k)
{
    int res = 1;
    if(places[i][j][k] == 'P')
    {
        res = 0;
    }
    else if(places[i][j][k] == 'O')
    {
        places[i][j][k] = '1';
    }
    else if(places[i][j][k] == '1')
    {
        res = 0;
    }
    return res;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(int i = 0; i < 5; i++)
    {
        int res = 1;
        for(int j = 0; j < 5; j++)
        {
            cout << endl;
            for(int k = 0; k < 5; k++)
            {
                if(places[i][j][k] == 'P')
                {
                    if(k + 1 < 5) {
                        res = judge(places, i, j, k + 1);
                        if(res == 0) break;
                    }
                    if(k - 1 > 0) {
                        res = judge(places, i, j, k - 1);
                        if(res == 0) break;
                    }
                    if(j + 1 < 5) {
                        res = judge(places, i, j + 1, k);
                        if(res == 0) break;
                    }
                    if(j - 1 > 0) {
                        res = judge(places, i, j - 1, k);
                        if(res == 0) break;
                    }
                }
            }
            if(res == 0) break;
        }
        
        answer.push_back(res);
    }
    return answer;
}