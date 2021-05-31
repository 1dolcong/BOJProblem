#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N;
	int	C;
	cin >> N;
	cin >> C;
	vector<int> house; // ���� ���� �����̳�
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		house.push_back(temp);
	}
	sort(house.begin(),house.end());

	int minDistance = 1; // �ּ� �Ÿ� 
	int maxDistance = house[N - 1]; // �ִ� �Ÿ�
	int finalDistance =0; // ��� 
	
	
	while (minDistance <= maxDistance) { // min�� max���� Ŀ���� ������ �� ����
		int presentDistance = (minDistance + maxDistance) / 2; //  (�̺� Ž������ �ð� ���̱�) 
		int count = 1; // ó�� �������� �ְ� �����ϴ� �ʱⰪ 1
		int cursor = house[0]; 
		for (int i = 1; i < N; i++) {
			if (house[i] - cursor >= presentDistance) {
				// ���� ������ ���� ������ �Ÿ��� ���� ������ �Ÿ����� ũ�ٸ� count ++
				cursor = house[i];
				count++;
			}
		}
		if (count >= C) { //count�� C���� ���ų� ũ�ٸ� ���� �Ÿ��� ������ ��� �� �ִ�.
			finalDistance = presentDistance; // ������ ���� ���� �Ÿ��� �ִ´�.
			minDistance = presentDistance + 1; 
		}
		else { // ���� �Ÿ��� ������ ��� �� �������� �Ÿ��� �ٿ��� �Ѵ�.
			maxDistance = presentDistance - 1;
		}
	}
	cout << finalDistance;
}