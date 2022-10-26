//A0238800J
//Tay Jiun Yuan
//Lab 07
//Athin
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iterator>
using namespace std;


bool sortTime(const vector<int>& v1, const vector<int>& v2)  //Compare function
{
    return v1[3] < v2[3];
}

bool sortb1(const vector<int>& v1, const vector<int>& v2)  //Compare function
{
    return v1[1] < v2[1];
}

bool sorta1(const vector<int>& v1, const vector<int>& v2)  //Compare function
{
    return v1[0] < v2[0];
}
int main (){
    int numberOfplayers; cin >> numberOfplayers;
    int numberOfpings; cin >> numberOfpings;
    vector<vector<int>>arr;                        //Initializing array
    for (int i = 0; i<numberOfpings; i++){
        vector<int>ping(4);                        //Initializing ping vector
        for(int j = 0; j<4; j++){
            cin>>ping[j];
        }
        arr.push_back(ping);
    }
    
    
    
    sort(arr.begin(), arr.end(), sortTime);          //Sort by Time
    vector<vector<int>>outputVector;
    vector<int>outputRow;
    if ( numberOfpings > 4){
    for (int i = 0; i < numberOfpings-4; i++){      //Return till 4 elements left
        for (int j = 1; j < 5; j++ ){
            if (arr[i][0] != arr [i+j][0] & sqrt(pow(arr[i][1]-arr[i+j][1],2)+ pow(arr[i][2]-arr[i+j][2],2)) <= 1000 & arr[i+j][3]-arr[i][3]<= 10 )
            {
                //cout<< arr[i][0] << " "<< arr[i+j][0] <<endl;
                outputRow.push_back(min(arr[i][0],arr[i+j][0]));
                outputRow.push_back(max(arr[i][0],arr[i+j][0]));
                outputVector.push_back(outputRow);
                outputRow.clear();
                }
        }
    }
    
    for (int i = numberOfpings - 4; i < numberOfpings-1; i ++){   //Return last 4 elements
        for (int j = i+1; j < numberOfpings; j++){
            if (arr[i][0] != arr [j][0] & sqrt(pow(arr[i][1]-arr[j][1],2)+ pow(arr[i][2]-arr[j][2],2)) <= 1000 & arr[j][3]-arr[i][3]<= 10 )
            {
                //cout<< arr[i][0] << " "<< arr[j][0] <<endl;
                outputRow.push_back(min(arr[i][0],arr[j][0]));
                outputRow.push_back(max(arr[i][0],arr[j][0]));
                outputVector.push_back(outputRow);
                outputRow.clear();
                
            }
        }
    }
    }
    
    else{
        for (int i = 0; i < numberOfpings-1; i ++){              //If size 4 or less
            for (int j = i+1; j < numberOfpings; j++){
                if (arr[i][0] != arr [j][0] & sqrt(pow(arr[i][1]-arr[j][1],2)+ pow(arr[i][2]-arr[j][2],2)) <= 1000 & arr[j][3]-arr[i][3]<= 10 )
                {
                    //cout<< arr[i][0] << " "<< arr[j][0] <<endl;
                    outputRow.push_back(min(arr[i][0],arr[j][0]));
                    outputRow.push_back(max(arr[i][0],arr[j][0]));
                    outputVector.push_back(outputRow);
                    outputRow.clear();
                }
            }
        }
    }
    
    sort(outputVector.begin(), outputVector.end(), sortb1);
    stable_sort(outputVector.begin(), outputVector.end(), sorta1);
    
    outputVector.erase(std::unique(outputVector.begin(), outputVector.end()), outputVector.end());
        
    
        cout<<outputVector.size();
        cout << endl;
    for (int i = 0; i < outputVector.size(); i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << outputVector[i][j] << " ";
        }
        cout << endl;
    }}
    



    
