#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <list>
#include <string>
using namespace std;

unordered_map<string, int>status;                  //initialising status map   0/1/2 =  unvisited/explored/visited
unordered_map<string, list<string>>AL;                //initialising Adjacency List
bool cycle_bool = false;


void add_edge(string x, string y){                   //add edge for undirected
    AL[x].push_back(y);
    
}

void DFS(string V){ //DFS Function                  //changes cycle_bool to true if cycle exists for V
    status[V] = 1;
    //cout << V;                                                                    //if want to print traversal
    list<string>::iterator i;
    for (i = AL[V].begin(); i != AL[V].end(); ++i){
        if (status[*i] == 0){
            DFS(*i);}
        else if (status[*i] == 1){
            cycle_bool = true;
        }
    }
    status[V] = 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N; cin>>N;
    for (int i = 0 ; i < N; i++){
        string x; string y; cin >> x >> y;
        add_edge(x, y);                                             //initialising AL
        //status[x]= "unvisited";                                     //Initialising status
        //status[y]= "unvisited";
    }
    string V;
    while (cin >> V){
        DFS(V);
        if (cycle_bool){
            cout << V << " safe" << endl;
        }
        else{
            cout << V << " trapped" << endl;
        }
        status.clear();                       //resetting status
        cycle_bool = false;                                     //resetting cycle_bool
        
    }
}
