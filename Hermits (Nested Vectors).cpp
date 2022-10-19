#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>



using namespace std;

bool sortcolumn(const vector<int>& v1, const vector<int>& v2)  //Compare function
{
    return v1[1] < v2[1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int position = 0;
    int N; cin >> N;
    vector<vector<int>>weights;
    vector<vector<pair<int,int>>>AL(N);
    
    for (int i = 0 ; i < N ; i++){          //Adding 2d vector of [Street Number, Weights]
        position ++ ;
        int K; cin >> K;
        vector<int>urmum;
        urmum.push_back(position);
        urmum.push_back(K);
        weights.push_back(urmum);
    }
    int J; cin>> J;                        //Creating AL
    for (int i  = 0; i < J; i++){
        int K; int L; cin>> K >> L;
        AL[K-1].push_back({L,weights[L-1][1]});
        AL[L-1].push_back({K,weights[K-1][1]});
    }
    for (int i = 0 ; i < N ; i++){          //Adding the weights of the crossed st. to the original st.
        for (int j = 0; j < AL[i].size(); j++){
            weights[i][1] += AL[i][j].second;
        }
    }
    stable_sort(weights.begin(), weights.end(), sortcolumn);    //Sorting to find smallest
    cout << weights[0][0];
}
