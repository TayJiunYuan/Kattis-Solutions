#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <list>
#include <string>
#include <sstream>
using namespace std;

int main(){
    int counter = 1;
    int arr[5];
    for (int i = 0; i < 5; i++){
        int K; cin >> K;
        arr[i] = K;
    }
    while (counter !=0){
        counter= 0;
    for (int i = 0; i < 4; i++){
        if (arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
            counter ++;
            for (auto i : arr){
                cout << i << " ";
            }
            cout << endl;
        }
    }
    }
    
}
         
         
         
        
