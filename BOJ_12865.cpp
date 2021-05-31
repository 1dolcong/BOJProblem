#include <iostream>
using namespace std;

int N,K; // 물품의 수, 버틸 수 있는 무게
int DP[101][100001] = { 0, };
int W[100];
int V[100];

void knapSack() {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= K; ++j) {
			if (W[i] <= j) {
				if (DP[i-1][j] <= DP[i-1][j-W[i]] + V[i]) {
					DP[i][j] = DP[i-1][j-W[i]] +V[i];
				}
				else {
					DP[i][j] = DP[i-1][j];
				}
			}
			else {
				DP[i][j] = DP[i-1][j];
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;

	for (int i = 0; i < N; ++i) {
		cin >> W[i + 1] >> V[i + 1];
	}
	
	knapSack();

	cout << DP[N][K];
}