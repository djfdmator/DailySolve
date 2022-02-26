#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;

    int change_binary_count = 0;
    int zero_count = 0;
    while(s != "1")
    {
        int cnt = count(s.begin(), s.end(), '1');
        zero_count += s.size() - cnt;
        
        s.clear();
        while(cnt > 0)
        {
            s.push_back((cnt % 2) + '0');
            cnt /= 2;
        }
        reverse(s.begin(), s.end());
        change_binary_count++;
    }
    
    answer.push_back(change_binary_count);
    answer.push_back(zero_count);
    return answer;
}