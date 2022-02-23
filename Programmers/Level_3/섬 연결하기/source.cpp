#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool comp(vector<int> a, vector<int> b)
{
    return a[2] < b[2];
}

int getParent(int visits[], int x)
{
    if(visits[x] == x) return x;
    return getParent(visits, visits[x]);
}

void unionParent(int visits[], int a, int b)
{
    a = getParent(visits, a);
    b = getParent(visits, b);
    
    int value = min(a, b);
    visits[a] = value;
    visits[b] = value;
}

bool find(int visits[], int a, int b)
{
    a = getParent(visits, a);
    b = getParent(visits, b);
    return a == b;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    sort(costs.begin(), costs.end(), comp);
    
    int visits[n];
    for(int i = 0; i < n; i++)
    {
        visits[i] = i;
    }
    
    for(auto& cost : costs)
    {
        if(!find(visits, cost[0], cost[1]))
        {
            answer += cost[2];
            unionParent(visits, cost[0], cost[1]);
        }
    }
    
    return answer;
}