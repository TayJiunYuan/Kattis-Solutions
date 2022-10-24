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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string line;
    unordered_map<string, int>proven;
    int N; cin>>N; getline(cin,line);
    for (int i = 0 ; i < N; i++){
        string line; getline(cin, line);
        istringstream ss(line);
        string a;
        while (ss >> a){
            if (a == "->"){
                break;
            }
            if (proven[a] != 1){
                cout << i+1;
                return 0;
            }
        }
        string b;
        while (ss >> b){
          proven[b] = 1;
        }}
    cout << "correct";
    }

