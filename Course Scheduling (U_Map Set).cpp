#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>


using namespace std;


int main()
{
    vector<string>vec;
    unordered_map<string, unordered_set<string>> module;
    int N; cin >> N;
    for (int i = 0; i < N; i++){
        string first_name; cin >> first_name;
        string last_name; cin >> last_name;
        string module_code; cin >> module_code;
        string full_name = first_name + last_name;
        module[module_code].insert(full_name);
}
    for (auto i: module){
        vec.push_back(i.first);
    }
    stable_sort(vec.begin(), vec.end());
    for (auto i : vec){
        cout << i << " " << module[i].size() << endl;
    }
}
    
