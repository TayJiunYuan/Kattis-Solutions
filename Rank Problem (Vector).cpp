#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <list>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    vector<string>vec;
        int N; int Q; cin >> N >> Q;
        for (int i = 0 ; i < N ; i++){
            vec.push_back("T"+to_string(i+1));
        }
        for (int i = 0; i < Q ; i ++){
            int winner_index=0; int loser_index=0;
            string winner; string loser; cin >> winner >> loser;
            for(int j = 0; j<N;j++){
                if (vec[j]==winner){
                    winner_index = j;
                }
                if (vec[j]==loser){
                    loser_index = j;
                }}
            if (loser_index < winner_index){
                vec.insert(vec.begin()+winner_index+1, loser);
                vec.erase(vec.begin()+loser_index);
                }
            
        }
        for (auto i: vec){
            cout << i << " ";
        }
}
