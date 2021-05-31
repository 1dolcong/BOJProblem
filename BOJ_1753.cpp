#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 987654321

//��� ������ ������ ������ �����ϱ� ���� 2���� int �迭�� ���� ����� ������ �� 
//20000* 20000 * 4 byte  = 1600MB �޸� �ʰ�, O(V^2) �̹Ƿ� �ð��� �ʰ� 
int V; //  ������ ��
int E; // ������ �� 
int Dist[20001];  // �ִ� ��θ� ������Ʈ�ϴ� �迭
vector<pair<int, int>> Vertex[300001]; // ���� vertex , ����ġ 
int start; // ���� ����

void dijkstra() {
	priority_queue<pair<int,int>> pq; // �ִ����� ��� 
	pq.push(make_pair(0,start));
	Dist[start] = 0;
	while (!pq.empty()) {
		int cost = -1 * pq.top().first; // ���� �� �ٽ� �����
		int curNode = pq.top().second;
		pq.pop();

		for (int k = 0; k < Vertex[curNode].size(); k++) {
			int next = Vertex[curNode][k].first;
			int nextCost = Vertex[curNode][k].second;
			if (Dist[next] > cost + nextCost) {
				Dist[next] = cost + nextCost;
				pq.push(make_pair(-1 * Dist[next], next)); //���� �� ������
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> V >> E >> start; // ����� ��, edge�� �� , ������
	int u, v, w;

	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		Vertex[u].push_back(make_pair(v,w));
	}

	for (int i = 1; i <= V; i++) {
		Dist[i] = INF;
	}

	dijkstra();

	for (int i = 1; i <= V; i++) {
		if (Dist[i] != INF) printf("%d\n",Dist[i]);
		else printf("INF\n");
	}
	return 0;
}