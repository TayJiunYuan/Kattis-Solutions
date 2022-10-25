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

//ONLY SOLVING FOR SUBTASK 1 and 2
int main()
{
    unordered_map<char, int>mumgay;
    int N; cin >> N;
    for (int i = 0 ; i < N; i++){
        string K; cin >> K;
        mumgay[K[0]] ++;
    }
    int J; cin>> J;
    for ( int i = 0; i < J; i++){
        char L; cin >> L;
        cout << mumgay[L] << endl;
    }
}
