#include <string>
#include <vector>
#include <iostream>

using namespace std;


int solution(int n) {
    int answer = 1;
    
    vector<int> dp(n);
    dp[0] = 1;
    dp[1] = 2;
    // 1, 2, 3, 5, 8, 13
    for(int i = 2; i < n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
    }

    return dp[n - 1];
}