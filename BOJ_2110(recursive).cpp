#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int recursiveSearch(vector<int> house, int count, int minidx, int maxidx){ 
	int difference = 0;
	int temp = 0;
	int idx ;
	for (int i = minidx + 1; i < maxidx; i++) {
		temp = min(house[i] - house[minidx], house[maxidx] - house[i]);
		if (temp > difference) {
			difference = temp;
			idx = i;
		}	
	}
	if (count == 1) {
		return difference;
	}
	return max(recursiveSearch(house, count - 1, minidx, idx), recursiveSearch(house, count - 1, idx, maxidx));
}

int main() {
	int N;  // ���� ���� 
	int C;  // ������ ����		   
	cin >> N;  // ���� ������ ������ ���� �Է� �ޱ�
	cin >> C;
	vector<int> house(N);
	for (int i = 0; i < N; i++) {
		cin >> house[i]; // ���� ��ǥ �Է¹ޱ�;
	}
	sort(house.begin(), house.end());
	cout << recursiveSearch(house, C - 2, 0, N-1);
}