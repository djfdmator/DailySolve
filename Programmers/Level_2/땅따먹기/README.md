# DailySolve 

### 풀이 프리뷰

1. 동적계획법을 이용하면 쉽게 풀 수 있다.
2. 행을 기준으로 반복문을 사용하는데 현재의 행과 다음행의 값으로 계산하여 다음행의 각 열에 들어갈 수 있는 값 중 가장 큰 값을 구해 따로 저장해둔다.
3. 따로 저장해둔 값을 다음행의 값으로 덮어쓰기한다.
4. 2,3번을 반복하여 맨 아래 행까지 계산한다.
5. 반복문이 끝나면 맨 아래 행에서 최대값을 찾아 반환한다.
        
### 피드백
  
동적계획법에는 언제나 더 좋은 방법이 있는 것 같다. 이번에 얻은 교훈은 매 행마다 구해야하는 각 열의 기준에서 생각하여 계산하면 더 쉽고 간단하게 풀릴 수 있다.

![캡처](https://user-images.githubusercontent.com/43840175/152178537-96f35738-bfaa-424c-88c4-f1bcc0d60a4e.PNG)
