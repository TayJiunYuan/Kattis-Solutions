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

int main()
{
    unordered_map<string, int>freq;
    int N; cin>> N;
    for (int i = 0 ; i < N; i ++){
        string K; cin >> K;
        long a = K.size();
        for (long j = 0; j < a; j++){
            freq[K] ++;
            K.erase(K.size()-1);
        }
    }
    
    int P; cin >> P;
    for (int i = 0; i < P ; i++){
        string L; cin >> L;
        cout << freq[L]<<endl ;
    }
}
