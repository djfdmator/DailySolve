#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

#include <iostream>

using namespace std;

bool isPrimeNumber(long long n)
{
    if(n < 2) return false;
    for(long long i = 2; i * i <= n; i++)
    {
        if(n % i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;

    vector<long long> candi_nums;
    long long num = 0;
    int i = 0;
    while(n > 0)
    {
        int temp = n % k;
        num += temp * pow(10, i);
        n /= k;
        
        i++;
        
        if(temp == 0)
        {
            if(num > 1)
            {
                candi_nums.push_back(num);
            }
            num = 0;
            i = 0;
        }
    }
    candi_nums.push_back(num);

    for(auto& i : candi_nums)
    {
        if(isPrimeNumber(i))
        {
            answer++;
        }
    }
    
    return answer;
}