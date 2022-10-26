#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<int> vi;

class UnionFind {                                // OOP style
private:
  vi p, rank, setSize;                           // vi p is the key part
  //int numSets;
public:
  UnionFind(int N) {
    p.assign(N+1, 0); for (int i = 1; i < N+1; ++i) p[i] = i; //modified to start with 1, N+1 for p,rank,setSize for tildes question
    rank.assign(N+1, 0);                           // optional speedup
    setSize.assign(N+1, 1);                        // optional feature
    //numSets = N;                                 // optional feature
  }

  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

  //int numDisjointSets() { return numSets; }      // optional
  int sizeOfSet(int i) { return setSize[findSet(i)]; } // optional

  void unionSet(int i, int j) {
    if (isSameSet(i, j)) return;                 // i and j are in same set
    int x = findSet(i), y = findSet(j);          // find both rep items
    if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
    p[x] = y;                                    // set x under y
    if (rank[x] == rank[y]) ++rank[y];           // optional speedup
    setSize[y] += setSize[x];                    // combine set sizes at y
    //--numSets;                                   // a union reduces numSets
  }
};




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N; int Q; cin >> N >> Q;

    UnionFind UF(N);        //create N number of Disjoint Sets
    for (int i = 0 ; i < Q; i++){
        char K; cin>>K;
        if (K=='t'){
            int x; int y; cin >> x >> y;
            UF.unionSet(x, y);       //joins 2 disjoint sets
        }
        else{
            int K; cin >> K;
            cout << UF.sizeOfSet(K) << "\n";
        }
    }
    
}
