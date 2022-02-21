#include <string>
#include <vector>
#include <queue>

using namespace std;

struct compare
{
    bool operator()(pair<long long, long long> a, pair<long long, long long> b)
    {
        return a.first + a.second >= b.first + b.second;
    }
};


long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, compare> pq;
    
    double val = 0;
    for(auto& i : times)
    {
        val += 1.0 / i; 
    }
    long long bound = (long long)(n / val);
    
    for(auto& i : times)
    {
        long long count = bound / i;
        pq.push(make_pair<long long, long long>(i, count * i));
        n -= count;
    }
    
    answer = (long long)bound;
    for(int i = 0; i < n; i++)
    {
        pair<long long, long long> cur = pq.top();
        pq.pop();
        cur.second += cur.first;
        pq.push(cur);
        answer = cur.second;
    }
    
    return answer;
}