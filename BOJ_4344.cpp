#include <iostream>
using namespace std;

int main() {
	int scoreCase;
	cin >> scoreCase;
	int* overAveragerate = new int[scoreCase];
	int* studentsNum = new int[scoreCase];
	for (int i = 0; i < scoreCase; i++) {
		int sum = 0 ;
		int studentNum;
		cin >> studentNum;
		int * studentScore = new int[studentNum];
		int average;
		int overAverageNum =0;
		for (int i = 0; i < studentNum; i++) {
			cin >> studentScore[i];
			sum += studentScore[i];
		}
		average = sum / studentNum;
		for (int i = 0; i < studentNum; i++) {
			if (average < studentScore[i]) {
				overAverageNum++;
			}
		}
		overAveragerate[i] = overAverageNum;
		studentsNum[i] = studentNum;
		delete[] studentScore;
	}
	for (int i = 0; i < scoreCase; i++) {
		printf("%.3f%%\n",(double)overAveragerate[i] * 100 /studentsNum[i]);
	}
	delete[] overAveragerate;
	delete[] studentsNum;
	return 0;
}


