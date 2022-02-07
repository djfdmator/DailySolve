#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    
    int temp = min(a, b);
    b = max(a, b);
    a = temp;

    while(a != b)
    {
        if(a % 2 == 1 && a + 1 == b)
        {
            break;
        }
        
        if(a % 2 == 1)
        {
            a++;    
        }
        if(b % 2 == 1)
        {
            b++;
        }
        a /= 2;
        b /= 2;
        answer++;
    }

    return answer;
}