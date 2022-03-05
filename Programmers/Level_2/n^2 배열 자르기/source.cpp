#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    long long start_Line = left / n;
    long long start_index = left % n;
    
    long long end_Line = right / n;
    long long end_index = right % n;
    
    long long pivot_value = start_Line < start_index ? start_index + 1 : start_Line + 1;
    long long value = pivot_value;
    
    long long start = start_Line * n + start_index;
    long long end = end_Line * n + end_index;
    for(long long i = start; i <= end; i++)
    {
        if(i == 0)
        {
            answer.push_back(1);
            value = 2;
            continue;
        }
        
        if(i % n == 0)
        {
            start_Line++;
            
            pivot_value = start_Line + 1;
            value = pivot_value;
        }
        
        answer.push_back(value);
        
        if(i % n + 1 == value)
            value++;
    }

    return answer;
}