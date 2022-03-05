#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(auto& n : numbers)
    {
        long long one = 1;
        if((n & one) == 0)
        {
            answer.push_back(n+1);
            continue;
        }
        
        while(true)
        {
            if((n & one) == 0)
            {
                n += (one / 2);
                break;
            }
            one = one << 1;
        }
        answer.push_back(n);
        
    }
    
    return answer;
}