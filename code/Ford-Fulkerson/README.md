# Ford-Fulkerson Algorithm


Ford-Fulkerson Algorithm이란 가중치가 있는 방향그래프 G와 시작 노드 s, 도착 노드 t가 주어졌을 때 갓 엣지의 용량을 고려햐여 s에서 t로 흘려보낼 수 있는 최대 유량을 구하는 알고리즘을 말한다.
이는 전력, 수도, 통신 등 다양한 분야에서 응용된다.

*****

## 구조

G의 갓 엣지 가중치를 용량이라고 하고 (u,v)의 용량을 c(u,v)라고 하고, 용량은 항상 0 이상이다.
노드 u와 v 사이를 흐르는 유량은 f(u,v)라고 쓰며 유량은 실수치 함수이다.

### 최대 유량의 조건
1. f(u,v) <= c(u,v)
2. f(u,v) = -f(v,u)
3. 각 노드에서 유량은 새로 더해지거나 감소되지 않는다.

### residual network
u에서 v로의 residual capacity c_f(u,v)는 c(u,v) - f(u,v) 로 정의된다.
이 residual network를 응용해 최대 유량을 구하는 기법이 Ford-Fulkerson Algorithm 이다.

*****

## 동작방식

포드-풀커슨 알고리즘의 의사코드는 다음과 같다.

![의사코드](/assets/images/%EC%9D%98%EC%82%AC%EC%BD%94%EB%93%9C.png)

>1. 먼저 주어진 그래프의 모든 간선 (u,v)에 대해 현재 u에서 v로 흐르는 유량을 0으로 초기화한다.
>2. 모든 간선 (u,v)에 대해 c_f(u,v) > 0인 G_f에서 s에서 t로 가는 경로 p가 있을 경우, 아래를 반복합니다.
>>1. c_f(p) = min{c_f(u,v) : (u,v) ∈ p}를 찾는다.

>>2. 각 간선 (u,v) ∈ p 에 대해 아래를 반복
>>>1. f(u,v) <- f(u,v) + c_f(p)  경로를 따라 유량을 흘려보낸다.
>>>2. f(u,v) <- f(u,v) - c_f(p)  역방향으로 유량을 흘려보낸다.

### 작동 예

다음과 같은 residual network G_f 가 주어졌을 때,

![1](/assets/images/ford1.png)

너비우선탐색(BFS)를 사용하여 s에서 t로 가는 경로를 찾는다.
{s,a,b,t} 경로에서 흐를 수 있는 최대 유량은 1 이다. (c_f(a,b) = 1)

![2](/assets/images/ford2.png)

직전 단계에서 구한 경로의 반대 방향으로 최대 유량을 흘려보내는 엣지를 만든다.
이후, 다시 전단계로 돌아가 반복한다.

![3](https://i.imgur.com/jrrzK79.png)
![4](https://i.imgur.com/rGIvRjB.png)
![5](https://i.imgur.com/jrrzK79.png)

단계를 반복하다가 s에서 t로 가는 경로가 존재하지 않을 경우,

![6](https://i.imgur.com/8oGwcq3.png)

포드-풀커슨 알고리즘 수행을 종료한다.
s에서 t로 향하는 최대 유량은 {a,t}에서 2, {b,t}에서 3으로 5가 된다.

*****

## 구현

![초기설정](/assets/images/%EC%B4%88%EA%B8%B0%EC%84%A4%EC%A0%95.png)

### 변수의 의미
MAX : 노드의 최대 갯수
INF : 무한대를 표현
adj[] : 노드 간의 연결을 표현
c[a][b] : a노드와 b노드 사이의 용량
f[a][b] : a노드에서 b노드로 흐르는 유량

![makeGraph](/assets/images/makeGraph.png)

노드 간의 관계, 즉 그래프를 만드는 함수이다.
예를 들어 makeGraph(1,2,8) 은 노드1과 노드2가 연결되어 있으며, 둘 사이의 용량(capacity)은 8로 설정하겠다는 의미이다.