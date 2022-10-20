#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <list>
#include <deque>
#include <cstdlib>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N ; cin>> N;
    vector<int>vec;
    deque<int>deek;
    vector<int>vec2;
    for (int i = 0; i < N; i++){
        int K; cin>>K;
        vec.push_back(K);                                       //Input into vec
    }
    sort(vec.begin(),vec.end());                                //Sort Vec
    for (int i = 0; i < N; i++){
        deek.push_front(vec[i]);                                //Push elements from Vec into Deque
}
    int J = N/2;
    for (int i = 0; i < J; i++ ){                              //Push the pair of smallest,largest int into Vec2
        vec2.push_back(deek.front());                          //Currently Vec 2 stores in descending difference
        vec2.push_back(deek.back());
        deek.pop_front();
        deek.pop_back();
    }
    if (deek.size()){
        vec2.push_back(deek.front());                          //Push last element if N is Odd
    }
    reverse(vec2.begin(), vec2.end());                         //Reverse Vec2 to store in ascending difference
    for (int i = 0; i < N-2; i++){
        if (abs(vec2[i+2]-vec2[i+1])<abs(vec2[i+1]-vec2[i])){   //Compare the difference between pairs
            cout << "impossible" ;
            return 0;
        }
    }
    for (auto i : vec2){
        cout << i << " ";
    }
}
