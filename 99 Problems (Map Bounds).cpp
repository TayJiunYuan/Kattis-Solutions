//Tay Jiun Yuan
//A0238800J
//Athin
//T07
#include <map>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    map<int,int>mp;                        //key stores variable and value stores freq
    int N; int Q; cin >> N >> Q;
    for (int i  =  0; i < N; i++){
        int D; cin >> D;
        if (mp.count(D)){                //element exists in map
            mp[D] ++;                    //add 1 to freq of map
        }
        else{
            mp.insert({D, 1});          //element does not exist in map, insert with freq 1
        }}
    
    for (int i  =  0; i < Q; i++){
        int question_type; int curr_diff; cin>> question_type >> curr_diff;
        if (question_type == 1){
            auto it = mp.upper_bound(curr_diff);    //find easist problem strictly harder current
            int discarded = (*it).first;
            if (it == mp.end()){                    //if upperbound not found
                cout << -1 << "\n";
            }
            else{
            cout << discarded << "\n";
            mp[discarded] --;                    //reduce 1 from freq
            if ( mp[discarded] == 0){
                mp.erase(discarded);
            }}
        
        }
        else{                                      //question type 2
            auto iter1 = mp.begin();
            auto iter2 = mp.rbegin();
            auto iter3 = mp.lower_bound(curr_diff);
            if (curr_diff < (*iter1).first ){       //case 1: if D < [elements]
                cout << -1 << "\n";
            }
           
            else if (curr_diff > (*iter2).first){   //case 2: if [elements] < D
                cout <<(*iter2).first<< "\n";
                mp[(*iter2).first] --;
                if ( mp[(*iter2).first] == 0){
                    mp.erase((*iter2).first);
                }}
            
                
            else {                                  //case 3: if D is in [elements]
                if (curr_diff != (*iter3).first){
                iter3 --;}
                
             cout << (*iter3).first << "\n";
                mp[(*iter3).first] --;
                if ( mp[(*iter3).first] == 0){
                    mp.erase((*iter3).first);
                        
                }     }       }
            
        }}
            
        
        
        

