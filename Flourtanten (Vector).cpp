#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
ll currentCount = 0;
ll maxCount=0;
ll bjorn = 0;
int main(){
    ll n; cin>>n;
    vector<ll>arr(n);
    for (ll i=0; i<n; i++){
            cin>>arr[i];    //input array
        }
    arr.erase(std::remove(arr.begin(), arr.end(), bjorn), arr.end()); //remove Bjorn
    auto startPos = arr.begin();
    arr.insert(startPos,0); // Add Bjorn to front
    for (ll j =0; j<n;j++){
        currentCount += arr[j]* (j+1) ;} //maxCount = Count when Bjorn in front
    maxCount=currentCount;
        
    for (ll i=0; i<n-1; i++){  //Swapping Bjorn with right in each iteration
        ll temp1=arr[i];
        ll temp2=arr[i+1];
        arr[i]=temp2;
        arr[i+1]=temp1;
        currentCount = currentCount + (arr[i]*(i+1) + (arr[i+1]*(i+2))) - ((arr[i]*(i+2))+(arr[i+1]*(i+1)));

        if (currentCount> maxCount){
            maxCount = currentCount;}
        
        
}
    cout<<maxCount;
    return 0;
    }
