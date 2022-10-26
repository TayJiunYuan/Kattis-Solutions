#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n; cin>>n;
    int x = 0;
    int y = 0;
    vector<int>arr(n);
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    for (int k = 1; k<= n/2; k++){
        for (int i = k-1; i<n-k ; i=i+k){
            if (arr[i] < arr[i+k]){
                x=x+1;
            }
            y=y+1;
        }
        if (x==y){
            cout<< k;
            return 0;
        }else{
            y=0;
            x=0;
        }
 
    }
    cout<<"ABORT!";
    return 0;
}
