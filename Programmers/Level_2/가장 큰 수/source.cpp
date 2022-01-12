#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(int a, int b)
{
    string sa = to_string(a);
    string sb = to_string(b);
    if(sa + sb > sb + sa)
    {
        return true;
    }
    return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(), numbers.end(), comp);
    for(auto& i : numbers) answer += to_string(i);
    
    return answer[0] == '0' ? "0" : answer;
}