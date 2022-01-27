#include<unordered_set>

using namespace std;

int solution(int N, int number) {
    int answer = -1;
    
    unordered_set<int> data[8];
    int num = 0;
    for(int i = 0; i < 8; i++)
    {
        num = num * 10 + 1;
        data[i].insert(N * num);
    }
    
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < i; j++)
        {
            for(auto& a : data[j])
            {
                for(auto& b : data[i - j - 1])
                {
                    data[i].insert(a * b);
                    if(b != 0) data[i].insert(a / b);
                    data[i].insert(a + b);
                    data[i].insert(a - b);
                }
            }
        }
        
        if(data[i].find(number) != data[i].end())
        {
            answer = i + 1;
            break;
        }
    }
    
    return answer;
}