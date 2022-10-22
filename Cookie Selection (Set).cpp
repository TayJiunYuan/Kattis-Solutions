#include <iostream>
#include <map>
#include <string>
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
    multiset<int>set;
    auto iter = set.begin();
    string M;
    while (cin >>M){
        if (M == "#"){
            if(set.size() % 2 == 0 ){                   //set size even
                cout<< *iter << endl;
                auto iter2 = iter;
                iter -- ;
                set.erase(iter2);
            }
            else{                                      //set size odd
                cout << *iter << endl;
                auto iter2 = iter;
                iter ++;
                set.erase(iter2);
            }}
        else{
            int K = stoi(M);
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
                if(K >= *iter){                         //if set size odd and K bigger than median
                    iter ++;
            }
        }
           // cout << "median "<< *iter <<endl;
        
    }
}
    return 0;
}
