# DailySolve

비교할 두 수 a(123), b(321)로 ab(123321), ba(321123) 처럼 만들어 a, b 중 어느 것이 앞에 있을때 큰 수가 나오는지 확인해야한다.   
위 처럼하는 이유는 a, b가 길이가 달라도
string 형 변수로 + 연산을 하면 string형 변수끼리 이어지게 되기 때문에 이를 이용하여 

### 풀이 프리뷰

1. algorithm 헤더의 sort함수를 이용하는데 쓰일 comparison 함수를 정의한다.
2. comparison 함수에 int형 변수 두개를 매개변수로 받고 이 변수들을 string으로 변환 후 a + b > b + a 일 경우 true를 반환한다.
3. 아닐 경우 false를 반환한다.
4. main 함수에서 sort함수에 인자로 문제에서 주어진 vector<int> 와 comparison 지정해서 호출, sort함수에서 comparison 함수를 이용하여 vector<int>의 원소들을 정렬한다.
5. 정렬된 vector<int>의 값들을 순서대로 string형으로 바꿔 answer에 + 연산으로 이어붙인다.
6. answer를 반환한다.
        
### 피드백
  
주어진 vector<int>를 vector<string>으로 변환한 후 진행했으면 스택 메모리를 조금 더 할당되겠지만 처리 속도는 조금 더 늘릴 수 있지 않을까? 

        
#### sort()

sort함수는 nlogn의 복잡도를 가지고, 보편적으로 정렬 알고리즘은 이보다 빠르기 힘들다. 정렬이 필요하다면 sort함수를 사용하자.
