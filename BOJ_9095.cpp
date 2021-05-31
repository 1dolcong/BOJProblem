#include <iostream>
using namespace std;
int DP[11];

void inputDP(int n){
    //n의 관점에서 1을 더 추가 할 수 있는 경우는  DP[n-1]
    //n의 관점에서 2를 더 추가 할 수 있는 경우는  DP[n-2]
    //n의 관점에서 3를 더 추가 할 수 있는 경우는  DP[n-3]
    DP[n] = DP[n-1] + DP[n-2] + DP[n-3]; 
}
int main(){


    ios_base::sync_with_stdio(false); cin.tie(0);
    DP[1] = 1; // 처음 경우는 1  (1)
    DP[2] = 2; // 두번째 경우는 11 2 (2)
    DP[3] = 4; // 세번째 경우는 111 12 21 3 (4)
    int input;
    cin >> input;
    for(int i=4; i<11; i++){
        inputDP(i);
    }
    for(int i=0; i<input; i++){
        int temp;
        cin >> temp;
        cout << DP[temp] << endl;
    }

}
