//A0238800J
//Tay Jiun Yuan
//Lab 07
//Athin




#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

bool sortRunningTime(const vector<int>& v1, const vector<int>& v2)
{
    return v1[1] < v2[1];
}

bool sortLapsCompleted(const vector<int>& v1, const vector<int>& v2)
{
    return v1[2] > v2[2];
}

bool sortStartNumber(const vector<int>& v1, const vector<int>& v2)
{
    return v1[0] < v2[0];
}

int convertToSeconds(double x)
{
    x=x*100;
    int y = round(x);
    int j = y%100;
    int k = (y-j)*60/100;
    int converted = j+k;
    return converted ;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int l, k, s;
    cin >> l >> k >> s;
    unordered_map<int, vector<int>>runningRace;
    for (int i = 0; i < l; i++){
        int startNumber; cin >> startNumber;
        float runningTime; cin >> runningTime;
        int runningTimeINT = convertToSeconds(runningTime);
    
        
        if (runningRace.find(startNumber) == runningRace.end() ){ // if runner doesnt exist in map
            vector<int>values;
            values.push_back(runningTimeINT);
            values.push_back(1);
            runningRace.insert({startNumber, values});
        }
        else {    //if runner exists in map
            runningRace.at(startNumber)[0] += runningTimeINT;
            runningRace.at(startNumber)[1] += 1;
        }
    }
    vector<vector<int>>record;                       //putting key and values into a 3d vector named record
    for (const auto &keyValue : runningRace){
        int key = keyValue.first;
        int value1 = keyValue.second[0];
        int value2 = keyValue.second[1];
        vector <int> individual(3);
        individual[0]=key;
        individual[1]=value1;
        individual[2]=value2;
        if (value2 == k){
        record.push_back(individual);
        }}
    
    sort(record.begin(),record.end(),sortStartNumber);
    stable_sort(record.begin(),record.end(),sortRunningTime);
    /*cout << endl;
    for (int i = 0; i < record.size(); i++)
        {
    
                cout << record[i][0] << "," << record[i][1] << "," << record[i][2] << '\n';
         }
        */

    for (int i = 0; i < record.size(); i++)
        {
                cout << record[i][0] << '\n' ;
            }
            

}
