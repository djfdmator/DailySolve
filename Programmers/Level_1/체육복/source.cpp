#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
//Version :: set
    //unordered_set<int> l(lost.begin(), lost.end());
    //set<int> r;
    //for(auto& x : reserve)
    //{
    //    if(l.find(x) == l.end()) r.insert(x);
    //    else l.erase(x);
    //}
    //for(auto& x : r)
    //{
    //    if(l.find(x-1) != l.end()) l.erase(x - 1);
    //    else if (l.find(x+1) != l.end()) l.erase(x + 1);
    //}
    //return n - l.size();
    
//Version :: vector
    //vector<int> v(n + 2, 1);
    //
    //for(int i = 0; i < reserve.size(); i++)
    //{
    //    v[reserve[i]]++;
    //}
    //for(int i = 0; i < lost.size(); i++)
    //{
    //    v[lost[i]]--;
    //}
    //for(int i = 1; i <= n; i++)
    //{
    //    if(v[i - 1] == 0 && v[i] == 2){
    //        v[i - 1] = v[i] = 1;
    //    }
    //    else if(v[i + 1] == 0 && v[i] == 2)
    //    {
    //        v[i + 1] = v[i] = 1;
    //    }
    //}
    //for(int i = 1; i <= n; i++)
    //{
    //    if(v[i] > 0) answer++;
    //}
    //    
    //return answer;
}