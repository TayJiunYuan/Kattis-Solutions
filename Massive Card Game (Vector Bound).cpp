//A0238800J
//Tay Jiun Yuan
//Lab 07
//Athin
#include <vector>
#include <iostream>
#include<algorithm>
using namespace std;
int n;                                                //Number of elements in array
int firstNumber{};
int lastNumber {};
int numberOfranges{};


int main(){
    cin>>n;
    vector<int>arr(n);
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    std::sort(arr.begin(),arr.end());              //Sorts Array
    cin>>numberOfranges;
    for (int i=0; i<numberOfranges; i++){
        cin>>firstNumber;
        cin>>lastNumber;
        std::vector<int>::iterator low,up;
        low = std::lower_bound(arr.begin(), arr.end(), firstNumber);
        up = std::upper_bound(arr.begin(), arr.end(), lastNumber);
        long lowerIndex= low-arr.begin();
        long upperIndex= up-arr.begin();
        cout <<endl<< upperIndex-lowerIndex<<endl ;
    }
}
