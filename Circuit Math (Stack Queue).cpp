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
    queue<int>TF;
    stack<int>stk;
    int N; cin >> N;
    for (int i  = 0 ; i < N; i++){
        char K; cin >> K;
        if (K=='T'){
            TF.push(1);
        }
        else{
            TF.push(0);
        }
    }
    string K;
    while (cin>>K){
        if (K == "*"){
            int a = stk.top();
            stk.pop();
            int b = stk.top();
            stk.pop();
            int c = a*b;
            stk.push(c);
        }
        else if(K == "+"){
            int a = stk.top();
            stk.pop();
            int b = stk.top();
            stk.pop();
            int c;
            if (a==0 and b ==0){
                c = 0;
            }
            else{
                c = 1; }
            stk.push(c);
            }
        else if(K == "-"){
            int a = stk.top();
            stk.pop();
            if (a){
                a=0 ; }
            else{
                a=1;}
            stk.push(a);
            }
        else{
            stk.push(TF.front());
            TF.pop();
        }
    }
    if(stk.top()){
        cout << "T";
    }
    else{
        cout << "F";
    }
}
         
         
         
        
