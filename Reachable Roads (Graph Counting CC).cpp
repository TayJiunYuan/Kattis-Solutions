#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

unordered_map<int, bool>visited;                  //initialising visited array
unordered_map<int, list<int>>AL;                  //initialising Adjacency List


void add_edge(int x, int y){                   //add edge for undirected
    AL[x].push_back(y);
    AL[y].push_back(x);
}

void DFS(int V){ //DFS Function
    visited[V] = true;
    //cout << V;                                                                    //if want to print traversal
    list<int>::iterator i;
        for (i = AL[V].begin(); i != AL[V].end(); ++i)
            if (!visited[*i])
                DFS(*i);
}

int counting_CC(int V){
    int CC = 0;
    for (int i = 0; i < V; i ++){
        if (visited[i] == false){
            CC++;
            DFS(i);
        }
    }
    return CC;
}


using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N; cin >> N;
    for (int i = 0 ; i < N; i++){
        int V; int E; cin >> V >> E;
        for (int i = 0; i < V; i++){                //Initiating Visited
            visited.insert({i,false});
        }
        for (int i = 0 ; i < E; i++){               //Initialising AL
            int x; int y; cin >> x >> y;
            add_edge(x, y);
        }
        cout << counting_CC(V)-1 << endl;           //Printout number of CC - 1
        visited.clear();
        AL.clear();
    }
}

