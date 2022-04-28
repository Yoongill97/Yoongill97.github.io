#include <bits/stdc++.h>

constexpr int MAX = 100;
constexpr int INF = 1000000;

std::vector<int> adj[MAX];
int c[MAX][MAX], f[MAX][MAX];

void makeGraph(int start, int end, int capacity) {
	adj[start].push_back(end);
	adj[end].push_back(start);
	c[start][end] = capacity;
	c[end][start] = 0;
}

int FordFulkerson(int start, int end) {
	int result = 0;

	while (true) {
		std::vector<int> dist(MAX, -1);     //방문한 노드인지 확인
		std::queue<int> q;
		q.push(start);

		while (!q.empty()) {
			int current = q.front();
			q.pop();

			for (int i = 0; i < adj[current].size(); ++i) {
				int next = adj[current][i];

				if (c[current][next] - f[current][next] > 0 && dist[next] == -1) {
                    //방문하지않은 노드가 용량이 남았을 때
					dist[next] = current;   //경로를 기억한다.
					q.push(next);
					if (next == end) break; //도착
				}
			}
		}
        if (dist[end] == -1) break;     //모든 경로를 찾았다면 break

		int flow = INF; 
		for (int i = end; i != start; i = dist[i])
            //거꾸로 거슬러올라가며 최소 유량을 탐색한다.
			flow = std::min(flow, c[dist[i]][i] - f[dist[i]][i]);
            //flow값 갱신

		for (int i = end; i != start; i = dist[i]) {
            //최소 유량만큼 추가
			f[dist[i]][i] += flow;
			f[i][dist[i]] -= flow;
		}
		result += flow;
	}
	return result;
}

int main(){
    makeGraph(1,2,2);
    makeGraph(1,3,5);
    makeGraph(2,3,1);
    makeGraph(2,4,4);
    makeGraph(3,4,3);

    std::cout << "최대 유량 : " << FordFulkerson(1,4);

    return 0;
}