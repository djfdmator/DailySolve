#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char call[16] {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

string convert(int number, int n)
{
    if(number == 0) return "0";
    string result;
    
    while(number > 0)
    {
        result.push_back(call[number % n]);
        number /= n;
    }
    
    reverse(result.begin(), result.end());
    return result;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    int number = 0;
    string convert_number = convert(number, n);
    int convert_number_index = 0;

    while(t > 0)
    {
        
        for(int i = 1; i <= m; i++)
        {
            if(i == p)
            {
                answer.push_back(convert_number[convert_number_index]);
            }
            
            convert_number_index++;
            if(convert_number_index == convert_number.size())
            {
                convert_number = convert(++number, n);
                convert_number_index = 0;
            }
        }
        
        t--;
    }
    
    return answer;
}