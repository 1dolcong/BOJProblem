#include <iostream>
using namespace std;
const int MAX = 15;
int col[MAX]; // index는 row 의미 
int N; // 체스판 크기 
int result = 0;

bool promising(int stage) {
	for (int i = 0; i < stage; ++i) {
		if (col[stage] == col[i] || abs(col[stage] - col[i]) == stage - i) { //stage는 i보다 클 수밖에 없다
			return false;
		}
	}
	return true;
}

void queen(int stage) { // stage ===> row // row를 기준으로 단계별로 올라는 의미에서 stage라고 사용
	if (promising(stage)) { // 전부다 넣어봤는데 그 줄이 가망이 없으면 다시 돌아옴!!
		if (stage + 1 == N) {
			result++;

			//cout << "path ::";
			//for (int i = 0; i < N; ++i) {
			//	cout << col[i] << ' ';
			//}
			//cout << endl;
		}
		else {
			for (int i = 0; i < N; ++i) {
				col[stage + 1] = i; // 한 번씩 다 넣어보기
				queen(stage + 1);
			}
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		col[0] = i;
		queen(0);
	}

	cout << result;
}