# DailySolve 

### 풀이 프리뷰

1. 숫자 N이 1개 있을때의 경우 부터 N이 8개 있을때까지의 모든 경우를 계산하기 위해 동적계획법을 이용한다.
2. N이 하나씩 늘어남에 따라 생기는 경우들은 늘어나기 전의 N에 의해 구한 값들을 기준으로 현재 N의 경우들을 계산하여 구한다.
3. N1과 N2를 이용하면 N3를 만들 수 있고 곱하기와 더하기는 교환법칙이 성립되기 때문에 N1 +-/* 를 해도 괜찮지만 /- 는 성립되지 않기때문에 N2 /- N1에 대해 계산해줘야한다.
        
### 동적계획법 Dynamic Programming
  
현재의 연산 결과를 다음에 있을 연산에 사용하여 최종 결과를 도출하는 방식이다.   
이 문제는 N3의 값들을 구하기 위해 N1과 N2의 값들을 필요로 하고 N4는 구한 N3의 값들을 필요로하기 때문에 동적계획법을 사용하며 풀 수 있다.
