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
	int N;  // 집의 개수 
	int C;  // 공유기 개수		   
	cin >> N;  // 집의 개수와 공유기 개수 입력 받기
	cin >> C;
	vector<int> house(N);
	for (int i = 0; i < N; i++) {
		cin >> house[i]; // 집의 좌표 입력받기;
	}
	sort(house.begin(), house.end());
	cout << recursiveSearch(house, C - 2, 0, N-1);
}