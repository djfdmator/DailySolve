# DailySolve 

### 풀이 프리뷰

1. minheap을 이용하면 쉽게 풀 수 있다. heap으로 구현된 priority_queue를 사용하자.
2. priority_queue를 minheap이 되도록 선언하고 scoville로 초기화한다.
3. priority_queue.top()을 하면 최소값이 나오기 때문에 While문을 이용하여 K보다 작거나 같을때만 동작하도록 한다.
4. priority_queue에 원소가 하나만 남을때가 아니라면 주어진 식을 통해 계산하며 최소값을 높인다.
        
### priority_queue
  
내부적으로 heap을 이용하여 구현되어 있다.   
선언시 min, max중 선택하여 구성되도록 할 수 있는데 greater<int> 가 min , less<int> 가 max이니 주의하자.   
        priority_queue<int, vector<int> greater<int>> pq    
        
