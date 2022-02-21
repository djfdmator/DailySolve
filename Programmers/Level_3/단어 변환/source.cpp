#include <string>
#include <vector>

using namespace std;

bool diffOneAlphabet(string s, string t)
{
    int count = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] != t[i])
        {
            count++;
        }
    }
        
    return count >= 2 ? false : true;
}

int dfs(string s, string t, vector<string> words, int count)
{
    if(s == t) return count;
    if(words.empty()) return 0;
    
    int result = 0;
    
    for(int i = 0; i < words.size(); i++)
    {
        if(diffOneAlphabet(s, words[i]) == true)
        {
            vector<string> next_words(words);
            next_words.erase(next_words.begin() + i);
            result = dfs(words[i], t, next_words, count + 1);
        }
    }
    return result;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    //변환할 수 없는 경우 :: target이 없음, 다 방문했거나 더이상 방문할 수 있는 곳이 없는데-target이랑 다를경우 0
    bool isExist = false;
    for(auto& i : words)
    {
        if(target == i)
        {
            isExist = true;
            break;
        }
    }
    if(isExist == false)
        return 0;
    
    answer = dfs(begin, target, words, 0);
    
    return answer;
}