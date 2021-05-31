#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N;
	int	C;
	cin >> N;
	cin >> C;
	vector<int> house; // 값을 넣을 컨테이너
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		house.push_back(temp);
	}
	sort(house.begin(),house.end());

	int minDistance = 1; // 최소 거리 
	int maxDistance = house[N - 1]; // 최대 거리
	int finalDistance =0; // 결과 
	
	
	while (minDistance <= maxDistance) { // min이 max보다 커지면 최적의 값 구함
		int presentDistance = (minDistance + maxDistance) / 2; //  (이분 탐색으로 시간 줄이기) 
		int count = 1; // 처음 시작점은 넣고 시작하니 초기값 1
		int cursor = house[0]; 
		for (int i = 1; i < N; i++) {
			if (house[i] - cursor >= presentDistance) {
				// 이전 지점와 현지 지점의 거리의 차가 측정할 거리보다 크다면 count ++
				cursor = house[i];
				count++;
			}
		}
		if (count >= C) { //count가 C보다 같거나 크다면 현재 거리로 구간을 띄울 수 있다.
			finalDistance = presentDistance; // 가능한 수를 최종 거리에 넣는다.
			minDistance = presentDistance + 1; 
		}
		else { // 지금 거리로 구간을 띄울 수 없음으로 거리를 줄여야 한다.
			maxDistance = presentDistance - 1;
		}
	}
	cout << finalDistance;
}