#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
#define OUT

struct FileData
{
    string _origin;
    string _head;
    int _number;
    string _tail;
    FileData(string origin, string head, int number, string tail) : _origin(origin), _head(head), _number(number), _tail(tail)
    {
        
    }
};

void ParsingFiles(OUT vector<FileData>& out, vector<string> files)
{
    for(auto& f : files)
    {
        string head = "";
        string number = "";
        string tail = "";
        int index = 0;
        for(int i = index; i < f.length(); i++, index++)
        {
            if('0' <= f[i] && f[i] <= '9')
                break;
            
            head.push_back(f[i]);
        }
        
        int count = 5;
        for(int i = index; i < f.length(); i++, index++)
        {
            if(count == 0)
                break;
            if('0' > f[i] || f[i] > '9')
                break;
            
            number.push_back(f[i]);
            count--;
        }
        
        tail = f.substr(index);
        
        
        out.push_back(FileData(f, head, stoi(number), tail));
    }
    
}

string StringUpper(string s)
{
    int temp = 'a' - 'A';
    for(auto& c : s)
    {
        if('a' <= c && c <= 'z')
        {
            c -= temp;
        }
    }
    return s;
}

bool Comp(FileData a, FileData b)
{
    string aHead = StringUpper(a._head);
    string bHead = StringUpper(b._head);
    
    if(aHead != bHead)
    {
        return aHead < bHead;
    }
    else
    {
        if(a._number == b._number)
        {
            return false;
        }
        else
        {
            return a._number < b._number;
        }
    }
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    vector<FileData> file;
    ParsingFiles(file, files);
    stable_sort(file.begin(), file.end(), Comp);
    
    for(auto& f : file)
    {
        answer.push_back(f._origin);
    }
    
    return answer;
}