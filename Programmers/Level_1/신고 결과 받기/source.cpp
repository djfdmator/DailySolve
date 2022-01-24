#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

vector<string> split(string s, char del)
{
    vector<string> result;
    istringstream ss(s);
    string buf;
    while(getline(ss, buf, del))
    {
        result.push_back(buf);
    }
    
    return result;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    unordered_set<string> organized_report(report.begin(), report.end());
    
    unordered_map<string, int> rep;
    unordered_map<string, vector<string>> dec_id;
    
    for(auto& i : organized_report)
    {
        vector<string> split_report = split(i, ' ');
        rep[split_report[1]]++;
        dec_id[split_report[0]].push_back(split_report[1]);
    }
    
    unordered_set<string> stopped;
    for(auto& i : rep)
    {
        if(i.second >= k)
        {
            stopped.insert(i.first);
        }
    }
    
    for(int i = 0; i < id_list.size(); i++)
    {
        int j = 0;
        for(auto& i : dec_id[id_list[i]])
        {
            if(stopped.find(i) != stopped.end())
            {
                j++;
            }
        }
        answer.push_back(j);
    }
    
    return answer;
}