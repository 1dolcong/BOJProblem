#include <iostream>
#include <vector>
using namespace std;

int idx = 0;
vector<int> offset;

void findIdx(int N) {
	int size = 0;
	while (size < N) {
		size = idx + 3 + 2 * size;
		idx++;
		offset.push_back(size);
	}
	idx--;
}

void Moo(int k, int N) { // N: 찾고자 하는 요소의 위치 , k: 함수의 인덱스 	
	if (k == 0) { // "moo" 상태 일 때
		if (N - 1 == 0) {
			cout << "m";
		}
		else {
			cout << "o";
		}
	}

	else {
		if (N  <= offset[k - 1]){ // 왼쪽에 있을 때
			Moo(k - 1, N);
		}
		else if (N - offset[k - 1] <= k + 3) { // 중간에 있을 때
			N -= offset[k - 1];
			if (N - 1 == 0) {
				cout << "m";
			}
			else {
				cout << "o";

			}
		}
		else { // 오른쪽에 있을 때 
			Moo(k - 1, N - (k + 3 + offset[k - 1]));
		}

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin >> N;
	findIdx(N); // N이 들어있는 S(idx) 에서 idx 찾기

	Moo(idx, N);
}