#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int N, M;
int kind = 1;
char command[1000][1000];
int isVisit[1000][1000];
int macro[4][2] = { {0,-1},{1,0},{0,1},{-1,0} }; // U , R , D , L


int findMacroNum(int y, int x) {
	int macroNum;
	if (command[y][x] == 'U') macroNum = 0;
	else if (command[y][x] == 'R') macroNum = 1;
	else if (command[y][x] == 'D') macroNum = 2;
	else  macroNum = 3;
	return macroNum;
}


int Visit(int y, int x) {
	if (isVisit[y][x] != -1) return isVisit[y][x];
	int result;
	isVisit[y][x] = kind;
	int macroNum = findMacroNum(y, x);
	int aftery = y + macro[macroNum][1];
	int afterx = x + macro[macroNum][0];
	result = Visit(aftery, afterx);
	isVisit[y][x] = result;
	return result;
}

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			char c;
			cin >> c;
			command[i][j] = c;
			isVisit[i][j] = -1;
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (isVisit[i][j] == -1) {
				Visit(i, j);
				kind++;
			}
		}
	}
	set<int> s;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			s.insert(isVisit[i][j]);
		}
	}
	cout << s.size();
	return 0;
}