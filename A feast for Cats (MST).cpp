#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<int, vector<pair<int,int>>>AL;
vector<int>taken;
priority_queue<pair<int,int>>pq;


void process(int u) { // set u as taken and enqueue neighbors of u
  taken[u] = 1;
  for (auto &[v, w] : AL[u])
    if (!taken[v])
      pq.push({-w, -v});                         // sort by non-dec weight
}                                                // then by inc id


int main(){
    int TC; cin >> TC;
    for (int i = 0; i < TC; i++){
        int milk; int cats; cin >> milk >> cats;
        taken.assign(cats, 0);
        //AL.clear();
        for (int j = 0; j < (cats*(cats-1)/2); j++){
            int node; cin>> node;
            int incoming; int weight; cin >> incoming >> weight;
            pair<int,int>x;
            x.first= incoming;
            x.second= weight;
            AL[node].push_back(x);
        }
        process(0);                                    // take+process vertex 0
          int mst_cost = 0, num_taken = 0;               // no edge has been taken
          while (!pq.empty()) {                          // up to O(E)
            auto [w, u] = pq.top(); pq.pop();            // C++17 style
            w = -w; u = -u;                              // negate to reverse order
            if (taken[u]) continue;                      // already taken, skipped
            mst_cost += w;                               // add w of this edge
            process(u);                                  // take+process vertex u
            ++num_taken;                                 // 1 more edge is taken
           // if (num_taken == cats-1) break;                 // optimization
          }
        if (mst_cost+cats <= milk){
            cout << "yes" <<endl;
        }
        else{
            cout << "no" <<endl;
        }
        
    }
}
