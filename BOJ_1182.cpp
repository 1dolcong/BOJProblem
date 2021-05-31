#include <iostream>
#include <vector>
using namespace std;

int main(){
    int S, N, ans = 0;
    cin >> N >> S;
    vector<int> v;
    v.reserve(N);
    for(int i=0; i<N; i++){
        int temp;
        cin >> temp; 
        v.push_back(temp);
    } 

    for(int i =1 ; i< (1<<N); i++){
        int sum = 0;
        for(int k=0; k<N; k++){
            if(i & (1 << k)){
                sum += v[k];
            }
        }
        if(sum==S) ans++;
    }
    cout << ans << endl;
    return 0;
}