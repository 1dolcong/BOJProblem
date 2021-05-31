#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 987654321

//모든 정점과 간선의 정보를 저장하기 위해 2차원 int 배열로 인접 행렬을 생성할 시 
//20000* 20000 * 4 byte  = 1600MB 메모리 초과, O(V^2) 이므로 시간도 초과 
int V; //  정점의 수
int E; // 간선의 수 
int Dist[20001];  // 최단 경로를 업데이트하는 배열
vector<pair<int, int>> Vertex[300001]; // 목적 vertex , 가중치 
int start; // 시작 정점

void dijkstra() {
	priority_queue<pair<int,int>> pq; // 최대힙을 기반 
	pq.push(make_pair(0,start));
	Dist[start] = 0;
	while (!pq.empty()) {
		int cost = -1 * pq.top().first; // 꺼낼 때 다시 양수로
		int curNode = pq.top().second;
		pq.pop();

		for (int k = 0; k < Vertex[curNode].size(); k++) {
			int next = Vertex[curNode][k].first;
			int nextCost = Vertex[curNode][k].second;
			if (Dist[next] > cost + nextCost) {
				Dist[next] = cost + nextCost;
				pq.push(make_pair(-1 * Dist[next], next)); //넣을 때 음수로
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> V >> E >> start; // 노드의 수, edge의 수 , 시작점
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