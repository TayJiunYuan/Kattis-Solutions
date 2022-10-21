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
    set<int>set;
    auto iter = set.begin();
    for (int i = 0; i < 90; i++){
        int K; cin >> K;
        if (set.size() == 0){
            set.insert(K);
            iter = set.begin();
        }
        else if (set.size() % 2 ==0 ){                   //if set size even
            set.insert(K);
            if (K < *iter){                          //set size even and K smaller than median
                iter -- ; }
    }
        else{                                       //if set size odd
            set.insert(K);
            if(K > *iter){                         //if set size odd and K bigger than median
                iter ++;
            }
        }
        cout << "median "<< *iter <<endl;
        
    }
}
