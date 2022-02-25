#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool comp(vector<int> a, vector<int> b)
{
    return a[0] < b[0];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;

    sort(routes.begin(), routes.end(), comp);
    while(!routes.empty())
    {
        int a = min(routes.back()[0], routes.back()[1]);
        while(!routes.empty() && (a <= routes.back()[0] || a <= routes.back()[1]))
        {
            routes.pop_back();
        }
        answer++;
    }

    return answer;
}