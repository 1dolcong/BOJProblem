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

void Moo(int k, int N) { // N: ã���� �ϴ� ����� ��ġ , k: �Լ��� �ε��� 	
	if (k == 0) { // "moo" ���� �� ��
		if (N - 1 == 0) {
			cout << "m";
		}
		else {
			cout << "o";
		}
	}

	else {
		if (N  <= offset[k - 1]){ // ���ʿ� ���� ��
			Moo(k - 1, N);
		}
		else if (N - offset[k - 1] <= k + 3) { // �߰��� ���� ��
			N -= offset[k - 1];
			if (N - 1 == 0) {
				cout << "m";
			}
			else {
				cout << "o";

			}
		}
		else { // �����ʿ� ���� �� 
			Moo(k - 1, N - (k + 3 + offset[k - 1]));
		}

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin >> N;
	findIdx(N); // N�� ����ִ� S(idx) ���� idx ã��

	Moo(idx, N);
}