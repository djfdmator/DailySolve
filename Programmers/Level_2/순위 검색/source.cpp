#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

struct stat{
    char language;
    char position;
    char career;
    char soulfood;
    int score;
};

vector<string> StringSplit(string s, char del)
{
    vector<string> result;
    stringstream ss(s);
    string temp;
    
    while(getline(ss, temp, del))
    {
        result.push_back(temp);
    }
    
    return result;
}

int Convert(string s)
{
    if(s == "python")
        return 3;
    if(s == "cpp" || s == "backend" || s == "junior" || s == "chicken")
        return 1;
    if(s == "java" || s == "frontend" || s == "senior" || s == "pizza")
        return 2;
    
    return 0;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    vector<int> v[4][3][3][3];
    for(auto& s : info)
    {
        vector<string> ss = StringSplit(s, ' ');
        int i = Convert(ss[0]);
        int j = Convert(ss[1]);
        int k = Convert(ss[2]);
        int p = Convert(ss[3]);
        v[i][j][k][p].push_back(stoi(ss[4]));
    }
    
    for(auto& q : query)
    {
        vector<string> ss = StringSplit(q, ' ');
        int start_i = Convert(ss[0]);
        int end_i = start_i + 1;
        if(start_i == 0)
        {
            start_i = 1;
            end_i = 4;
        }
        
        int start_j = Convert(ss[2]);
        int end_j = start_j + 1;
        if(start_j == 0)
        {
            start_j = 1;
            end_j = 3;
        }
        
        int start_k = Convert(ss[4]);
        int end_k = start_k + 1;
        if(start_k == 0)
        {
            start_k = 1;
            end_k = 3;
        }
        
        int start_p = Convert(ss[6]);
        int end_p = start_p + 1;
        if(start_p == 0)
        {
            start_p = 1;
            end_p = 3;
        }
        
        int score = stoi(ss[7]);
        
        int count = 0;
        for(int lan = start_i; lan < end_i; lan++)
        {
            for(int pos = start_j; pos < end_j; pos++)
            {
                for(int car = start_k; car < end_k; car++)
                {
                    for(int sou = start_p; sou < end_p; sou++)
                    {
                        for(int sco : v[lan][pos][car][sou])
                        {
                            if(score <= sco)
                                count++;
                        }
                    }
                }
            }
        }
        
        
        answer.push_back(count);
    }
    
    
    return answer;
}