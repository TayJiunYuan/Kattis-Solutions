#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

//18 minutes 47 seconds solved

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int global = 0;
    unordered_map<int,int>mp;
    int N; int Q; cin>> N >> Q;
    for (int i = 0; i < Q; i++){
        string action; cin>> action;
        if (action == "RESTART"){
            int K; cin>> K;
            global = K;
            mp.clear();
    }
        else if (action == "SET"){
            int key; int value; cin >> key >> value;
            mp.erase(key);
            mp.insert({key, value});
        }
        else{
            int key; cin >> key;
            if (mp.count(key)){
                cout << mp[key] << "\n";
            }
            else{
                cout << global << "\n" ;
            }
        }
 
}
}
