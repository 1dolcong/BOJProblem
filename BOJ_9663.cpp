#include <iostream>
using namespace std;
const int MAX = 15;
int col[MAX]; // index�� row �ǹ� 
int N; // ü���� ũ�� 
int result = 0;

bool promising(int stage) {
	for (int i = 0; i < stage; ++i) {
		if (col[stage] == col[i] || abs(col[stage] - col[i]) == stage - i) { //stage�� i���� Ŭ ���ۿ� ����
			return false;
		}
	}
	return true;
}

void queen(int stage) { // stage ===> row // row�� �������� �ܰ躰�� �ö�� �ǹ̿��� stage��� ���
	if (promising(stage)) { // ���δ� �־�ôµ� �� ���� ������ ������ �ٽ� ���ƿ�!!
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
				col[stage + 1] = i; // �� ���� �� �־��
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