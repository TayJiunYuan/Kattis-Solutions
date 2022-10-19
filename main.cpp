#include <vector>
#include <iostream>
using namespace std;

//28 mins, Time Limit Exceeded

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int swapcounter = 0;
    vector<int>arr;
    int N; cin >> N;
    for (int i = 0; i <N ; i++){
        int K; cin >>K;
        arr.push_back(K);
    }
    for (int i = 0; i <N ; i++){
        if (arr[i] != i+1){
            for ( int j= i+1 ; j<N; j++){
                if (arr[j] == i+1){
                swap(arr[i],arr[j]);
                swapcounter ++;
            }
        
            }}}
    cout << swapcounter ;
}
