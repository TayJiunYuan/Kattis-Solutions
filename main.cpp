#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <stack>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int counter = 0;
    unordered_map<int, unordered_map<string, string>>outer;
    unordered_map<string, stack<string>>datastack;
    long N; cin >> N;
        for ( int i = 0; i < N; i++){
            string K; cin>> K;
            if (K=="{"){
                counter ++ ; }
            else if (K == "DECLARE"){
                string variable_name; cin>> variable_name;
                string data_type; cin>> data_type;
                if (outer[counter].count(variable_name)){   //check if key(variable name) exist in inner
                    cout<<"MULTIPLE DECLARATION";
                    return 0;
                }
                else{
                    outer.insert(make_pair(counter, unordered_map<string, string>()));  //inserts element
                    outer[counter].insert(make_pair(variable_name, data_type));
                    datastack[variable_name].push(data_type);
                }}
            else if (K == "TYPEOF"){
                string variable_name;
                cin >> variable_name;
                if(datastack[variable_name].empty()){
                    cout << "UNDECLARED" << "\n" ;
                }
                else{
                    cout<<datastack[variable_name].top() << "\n";
                }
            }
            else{                                                       //K=="}"
                for (auto i : outer[counter]){
                    datastack[i.first].pop();
                }
                outer.erase(counter);
                counter --;
            }
        }
}
   
