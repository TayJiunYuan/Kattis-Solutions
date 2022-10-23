#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>
#include <list>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

unordered_map<string, bool>visited;                  //initialising visited array
map<string, list<string>>AL;                  //initialising Adjacency List
stack<string>stk;


void add_edge(string x, string y){                   //add edge for undirected
    AL[x].push_back(y);
}

void DFS_Topo(string V){ //DFS Function                                                                   //Topo Sort
    visited[V] = true;
    //cout << "visited: "<< V << endl;                                                                    //if want to print traversal
    list<string>::iterator i;
    for (i = AL[V].begin(); i != AL[V].end(); ++i){
        if (!visited[*i]){
            DFS_Topo(*i);}}
    //cout << "urmum: " << V << endl;
        stk.push(V);
    
    }


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string line;
    int N; cin >> N; getline(cin,line);
    for (int i = 0; i < N; i++){
        string line; getline(cin, line);            //reading line of input
        stringstream ss(line);                      //initializing sstream on linr
        string file; ss >>file; file.pop_back();    //reading first word and popping the ":"
        string dep;
        while (ss >> dep){
            add_edge(dep, file);                    //initialising AL
            visited[file] = false;                  //initialising visited[]
            visited[dep] = false;
        }
    }
    string K; cin >> K;
   // cout << "modified file: " << K << endl;
    DFS_Topo(K);
    while (!stk.empty()){                           //stack cannot use i<stack.size
        cout << stk.top() << endl;
        stk.pop();
    }
    
}
