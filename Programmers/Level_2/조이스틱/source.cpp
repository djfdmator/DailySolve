#include <string>
#include <cmath>
#include <vector>

#include <iostream>
using namespace std;

int recursive(vector<int> index, int len, int cursorpos, int count)
{
    if(index.empty()) return count;
    vector<int> a(index);
    vector<int> b(index);

    int tempA = 0, tempB = 0;
    if(!a.empty())
    {
        int next_cursorpos = a.front();
        int i = next_cursorpos - cursorpos;
        if(i < 0) i += len;
        a.erase(a.begin());
        tempA = recursive(a, len, next_cursorpos, count + i);
    }
    
    if(!b.empty())
    {
        int next_cursorpos = b.back();
        int j = cursorpos - next_cursorpos;
        if(j < 0) j += len;
        b.erase(b.end() - 1);
        tempB = recursive(b, len, next_cursorpos, count + j);
    }

    return min(tempA, tempB);
}

int solution(string name) {
    int answer = 0;
    
    vector<int> index;
    for(int i = 0; i < name.size(); i++)
    {
        char cur = name[i];
        answer += min(cur - 'A', 'Z' - cur + 1);
        if(cur != 'A') index.push_back(i);
    }

    answer += recursive(index, name.size(), 0, 0);

    return answer;
}