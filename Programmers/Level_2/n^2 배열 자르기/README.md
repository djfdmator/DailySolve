# DailySolve 

### 풀이 프리뷰

1. 배열의 인덱스를 잘 다루면 풀기 쉽다.
2. 제한사항에 맞게 반복문을 쓰되, right - left 만큼만 반복되도록 짜는 것이 좋다.
        
### 피드백

내 풀이는 뭔가 짜맞춘 느낌의 코드이다.   
문제에 데이터가 들어가는 규칙이 존재한다.   
아래 그림처럼 현재의 Line으로 기준 값을 알 수 있고 그 다음 수들은 index로 값을 알 수 있다.   
Line값보다 index 값이 커질때부터 index값을 이용해서 결과에 넣으면 된다.    
고로 아래 코드처럼 아름다운 반복문으로 끝내버릴 수 있다.   

![image](https://user-images.githubusercontent.com/43840175/156866285-495f08a6-01e5-400f-b455-9594b4a50fd1.png)

<pre>
<code>
        for(long long i = left; i <= right; i++)
        {
                answer.push_back(max(i / n, i % n) + 1);
        }
</code>
</pre>
