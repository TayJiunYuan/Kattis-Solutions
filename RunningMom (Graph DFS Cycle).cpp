#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <list>
#include <string>
using namespace std;

unordered_map<string, string>status;                  //initialising status map    unvisited/explored/visited
unordered_map<string, list<string>>AL;                //initialising Adjacency List
bool cycle_bool = false;


void add_edge(string x, string y){                   //add edge for undirected
    AL[x].push_back(y);
    
}

void DFS(string V){ //DFS Function                  //changes cycle_bool to true if cycle exists for V
    status[V] = "explored";
    //cout << V;                                                                    //if want to print traversal
    list<string>::iterator i;
    for (i = AL[V].begin(); i != AL[V].end(); ++i){
        if (status[*i] == "unvisited"){
            DFS(*i);}
        else if (status[*i] == "explored"){
            cycle_bool = true;
        }
    }
    status[V] = "visited";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N; cin>>N;
    for (int i = 0 ; i < N; i++){
        string x; string y; cin >> x >> y;
        add_edge(x, y);                                             //initialising AL
        status[x]= "unvisited";                                     //Initialising status
        status[y]= "unvisited";
    }
    string V;
    while (cin >> V){
        DFS(V);
        if (cycle_bool){
            cout << V << " safe" << endl;
        }
        else{
            cout << V << " trapped";
        }
        for (auto i: status){
            status[i.first]= "unvisited";}                        //resetting status
            cycle_bool = false;                                     //resetting cycle_bool
        
    }
}
