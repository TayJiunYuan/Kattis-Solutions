#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;
int main()
{
    int N;
    while (cin >> N , N != -1){
    int AM[N][N];                           //Initialise AM
    list<int>checker;
    for (int i = 0; i<N; i++ ){             //Inputting graph
        for (int j = 0; j<N; j++){
            int K; cin >> K;
            AM[i][j] = K;
        }
    }
    for (int i = 0; i<N; i++){
        bool is_i_weak = true;
        for (int j = 0; j < N; j++){
            for (int k = j+1; k<N; k++ ){
                if (AM[i][j] and AM[i][k] and AM[j][k]){  //check for triangle
                    is_i_weak = false;
                }
            }
        }
        if (is_i_weak){
            cout << i << " ";
        }
    }
    cout << endl;
    }
}
