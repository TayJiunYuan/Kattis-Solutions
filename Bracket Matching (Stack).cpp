//A0238800J
//Tay Jiun Yuan
//T07
//Athin
#include <iostream>
#include <stack>
#include <string>
using namespace std;

string bracketString;
stack<char>bracketStack;

int main(){
    int numberOfbrackets; cin>>numberOfbrackets;  //Input bracket as str
    for (int i = 0; i < numberOfbrackets; ++i){
        char temp; cin>>temp;
        bracketString.push_back(temp);
    }
    
    for (int i = 0; i < numberOfbrackets; ++i){ //pop if closing bracket match
        
        if (bracketStack.empty()){
            bracketStack.push(bracketString[i]);
        }
        
        else if ((bracketString[i]== ')' and bracketStack.top() == '(')
            or (bracketString[i]== '}' and bracketStack.top() == '{')
            or (bracketString[i]== ']' and bracketStack.top() == '[' )){
            bracketStack.pop();
            
        }
        else {
            bracketStack.push(bracketString[i]); //push if opening bracket or unmatched closing bracket
            
        }
}
    if (bracketStack.empty()){
        cout << "Valid" ;
    }
    else {
        cout << "Invalid";
    }
        
}
