#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

#include <iostream>

using namespace std;

unordered_map<string, int> um;

void comb(string origin, string cur, int index, int count)
{
    if(count == cur.size())
    {
        if(um.find(cur) == um.end())
        {
            um[cur] = 1;
        }
        else
        {
            um[cur] += 1;
        }
        return;
    }
    
    for(index += 1; index < origin.size(); index++)
    {
        comb(origin, cur + origin[index], index, count);
    }
}

void substrings(string s, int count)
{
    if(s.size() < count) return;
    
    for(int i = 0; i < s.size() - count + 1; i++)
    {
        string t;
        t.push_back(s[i]);
        comb(s, t, i, count);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for(int i = 0; i < orders.size(); i++)
    {
        sort(orders[i].begin(), orders[i].end());
    }
    
    for(int i = 0; i < orders.size(); i++)
    {
        for(int j = 0; j < course.size(); j++)
        {
            substrings(orders[i], course[j]);
        }
    }
    
    for(int j = 0; j < course.size(); j++)
    {
        int maxcount = 0;
        vector<string> max_values;
        for(auto& i : um)
        {
            if(i.second < 2) continue;
            
            if(course[j] == i.first.size())
            {
                if(maxcount < i.second)
                {
                    max_values.clear();
                    maxcount = i.second;
                    max_values.push_back(i.first);
                }
                else if(maxcount == i.second)
                {
                    max_values.push_back(i.first);
                }
            }
        }
        
        for(auto& i : max_values)
        {
            answer.push_back(i);
        }
    }
    sort(answer.begin(), answer.end());
    
    return answer;
}