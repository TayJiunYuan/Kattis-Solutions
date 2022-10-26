#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <list>
#include <string>
#include <sstream>
#include <list>
#include <queue>
#include <stack>
using namespace std;


int main(){
    int N; cin >> N;
    for (int i = 0 ; i < N ; i++){
        int K; int L; cin >> K >> L;
        stack<char>stk;
        int p = 1 ; int q = 1;
        while (L>1){
            if (L % 2 == 0){
                stk.push('L');
            }
            else{
                stk.push('R');
            }
            L = L/2;
        }
        while (stk.size()>0){
            char a = stk.top();
            stk.pop();
            if (a == 'L'){
                q = p+q;
            }
            else{
                p = p+q;
            }
        }
        cout << K << " "<< p << "/" << q << endl;
    }
}
         
         
         
        
