#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    sort(tickets.begin(), tickets.end(), greater<vector<string>>());
    unordered_map<string, vector<string>> m;
    for(auto& i : tickets)
    {
        m[i[0]].push_back(i[1]);
    }
    
    vector<string> stack;
    stack.push_back("ICN");
    while(stack.size() > 0)
    {
        string from = stack.back();
        if(m.find(from) != m.end() && m[from].size() > 0)
        {
            string to = m[from].back();
            m[from].pop_back();
            stack.push_back(to);
        }
        else
        {
            answer.push_back(stack.back());
            stack.pop_back();
        }
    }
    
    reverse(answer.begin(), answer.end());
    
    return answer;
}