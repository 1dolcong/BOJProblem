#include <iostream>
#include <vector>
using namespace std;
int k;
int N;

void findGroup(vector<int> score, int min, int max) {
    int slice;
    int partSum;
    while (min+1 < max) {
        partSum = 0;
        slice = 0;
        int find = (min + max) / 2;
        for (int i = 0; i < N; ++i) {
            partSum += score[i];
            if(find <= partSum) {
                slice++;
                partSum = 0;
            }
        }
        if (slice >= k)  
            min = find;
        else 
            max = find;
    }
    cout << min;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> N; cin >> k;
    vector<int> scores;
    scores.reserve(N);


    int maxSum = 20 * N;
    for (int i = 0; i < N; ++i) {
        int temp;
        cin >> temp;
        scores.push_back(temp);
    }
   findGroup(scores, 0, maxSum);
}
