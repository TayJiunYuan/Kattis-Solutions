#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int V; int M; cin >> V >> M;
    if (V==1){
        cout<<"YES";
        return 0;
    }
   
    bool output = true;
    for (int i = 0; i < M; i++){
        int x; int y; cin>> x >> y;
        add_edge( x, y);
        visited[x] = false;
        visited[y] = false;
    }
    DFS(AL.begin()->first);
    for (auto i : visited){
        if (i.second==false){
            output= false;
        }
        else{
            output=true;
        }
        
    }
    if (output){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}
