#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;


vector<int> solution(string msg) {
    vector<int> answer;
    
    vector<string> dic;
    for(int i = 0; i <= 'Z' - 'A'; i++)
    {
        string s(1, 'A' + i);
        dic.push_back(s);
    }
    
    queue<char> q;
    for(auto& c : msg)
    {
        q.push(c);
    }
    
    string w;
    w.push_back(q.front()); q.pop();
    int index = 0;
    while(!q.empty())
    {   
        char c;
        
        vector<string>::iterator it;
        while(true)
        {
            if((it = find(dic.begin(), dic.end(), w)) == dic.end())
            {
                break;
            }
            else
            {
                index = it + 1 - dic.begin();
                if(!q.empty())
                {
                    c = q.front(); q.pop();
                    w.push_back(c);
                }
                else
                {
                    c = ' ';
                    break;
                }
            }
        }
        
        dic.push_back(w);
        w.clear();
        w.push_back(c);
        answer.push_back(index);
    }
    
    if(w != " ")
    {
        answer.push_back(find(dic.begin(), dic.end(), w) + 1 - dic.begin());
    }

    return answer;
}