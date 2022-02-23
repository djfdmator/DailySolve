# DailySolve 

### 풀이 프리뷰
최소신장트리 - 크루스칼 알고리즘을 사용하면 쉽게 풀 수 있다. 추가로 크루스칼 알고리즘을 작성하기 위해 union-find 알고리즘도 알고 있어야 한다.

1. 비용이 싼 순으로 정렬한다.
2. 싼 것부터 하나씩 연결한다.
3. 연결 후 사이클이 발생하면 연결을 취소하고 다음으로 넘어간다.
4. 2~3을 마지막까지 반복한다.
        
### 피드백
사이클이 발생하는지 알기 위해 union-find 알고리즘을 사용한다.   
노드끼리 연결을 하면 한놈을 부모로하여 부모의 인덱스를 자식이 값으로 가진다.
자식에 다른 노드를 연결하려고 할 시 자식에게 있는 부모의 인덱스로 다른 노드에게 있는 부모의 인덱스와 같은지 검사한다.   
같을 경우 연결했을때 사이클이 발생하고, 다르다면 사이클이 발생하지 않는다.   
이를 이용해 노드 연결시 사이클이 발생하는지 검사할 수 있다.
<pre>
<code>
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
</code>
</pre>


