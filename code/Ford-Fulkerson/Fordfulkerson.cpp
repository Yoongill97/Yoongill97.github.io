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
		std::vector<int> dist(MAX, -1);     //�湮�� ������� Ȯ��
		std::queue<int> q;
		q.push(start);

		while (!q.empty()) {
			int current = q.front();
			q.pop();

			for (int i = 0; i < adj[current].size(); ++i) {
				int next = adj[current][i];

				if (c[current][next] - f[current][next] > 0 && dist[next] == -1) {
                    //�湮�������� ��尡 �뷮�� ������ ��
					dist[next] = current;   //��θ� ����Ѵ�.
					q.push(next);
					if (next == end) break; //����
				}
			}
		}
        if (dist[end] == -1) break;     //��� ��θ� ã�Ҵٸ� break

		int flow = INF; 
		for (int i = end; i != start; i = dist[i])
            //�Ųٷ� �Ž����ö󰡸� �ּ� ������ Ž���Ѵ�.
			flow = std::min(flow, c[dist[i]][i] - f[dist[i]][i]);
            //flow�� ����

		for (int i = end; i != start; i = dist[i]) {
            //�ּ� ������ŭ �߰�
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

    std::cout << "�ִ� ���� : " << FordFulkerson(1,4);

    return 0;
}