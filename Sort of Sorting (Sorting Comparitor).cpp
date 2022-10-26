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

bool cmp(string a, string b) {
  if (a[0] != b[0])
    return a[0] < b[0];
  else
    return a[1] < b[1];
}

int main(){
    int N;
    while (cin >>N){
        if (N == 0){
            break; }
        else{
            vector<string>vec;
            for (int i = 0 ; i < N; i++){
                string K; cin >> K;
                vec.push_back(K);
            }
            stable_sort(vec.begin(),vec.end(),cmp);
            for (auto i: vec){
                cout << i << endl;
            }
        }
        cout << endl;
    }
    
}
         
         
         
        
