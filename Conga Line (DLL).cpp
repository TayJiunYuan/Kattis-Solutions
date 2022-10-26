//A0238800J
//Tay Jiun Yuan
//T07
//Athin

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    Node * next;
    Node * prev;
    Node * partner;  //FOR C
};

class DLL {
private:
    Node* head;           //Maintain head pointer
    Node* tail;           //Maintain tail pointer
    Node* mic;
public:
    DLL(){
        head = NULL;
        tail = NULL;
    }

    
    void firstHead(string tempName1){
        Node * node = new Node();       //Create new Node
        node -> name = tempName1;        //Give new node value
        node -> next = head;            //Points current node to previous head
        node -> prev = NULL;            //Set prev pointer of new head
        tail = node;                //If empty list, assign tailpointer to this node
       
        head = node;                    //Assign head pointer to new head
        mic = node;                     //Assign mic pointer to first element
        
    }
    
    void insertTailleft(string tempName1){
        if (head==NULL) {                //If list empty
            firstHead(tempName1);
        }
        else
        {
             Node * node = new Node();
             node -> name = tempName1;
             node -> next = NULL;       //ADDEDLINE!!!
             node -> prev = tail;       //ADDEDLINE!!!
             tail -> next = node;
             tail = node;
            }
    }
    
    void insertTailright(string tempName1){
        if (head==NULL) {                //If list empty
            firstHead(tempName1);
        }
        else
        {
             Node * node = new Node();
             node -> name = tempName1;
             node -> next = NULL;
             node -> prev = tail;
             node -> partner = node -> prev;  //Assign right partner
             node -> prev -> partner = node;   //Assign left partner
             tail -> next = node;
             tail = node;
            }
    }
    
    
    void printListfoward(){
        Node * traverser = head;
        while (traverser != NULL){
            cout << traverser -> name << endl;
            traverser = traverser -> next;
        }
    }
    

    void function_F(){
        mic = mic -> prev;
    }
    
    void function_B(){
        mic = mic -> next;
    }
    
    void function_R(){
        if (mic->prev == NULL){              //if mic is head
            Node * temp = mic;
            Node * aft = mic -> next;
            mic = mic -> next;
            head = head ->next;
            aft -> prev = NULL;
            temp -> next = NULL;
            temp -> prev = tail;
            tail -> next = temp;
            tail = temp;
        }
        
        else if (mic->next == NULL){        //if mic is last person
            mic = head;
            
        }
        
        
        else {                              //if mic not last person
            Node * temp = mic;
            Node * pre = mic-> prev;
            Node * aft = mic -> next;
            mic = mic -> next;                  //pass mic back
            pre -> next = aft;
            aft -> prev = pre;
            temp -> next = NULL;
            temp -> prev = tail;
            tail -> next = temp;
            tail = temp;
        }
    }
    
    void function_C(){
        if (mic->prev == NULL){              //if mic is head
            Node * temp = mic;
            Node * aft = mic -> next;
            mic = mic -> next;
            head = head ->next;
            aft -> prev = NULL;
            temp->next = temp ->partner -> next;
            temp -> partner -> next = temp;
            temp -> prev = temp ->partner;
            if (temp -> next != NULL){
                temp -> next -> prev = temp;
          
            }
            else {
                tail = temp;
            }
            
        }
        
        else if (mic->next == NULL){        //if mic is last person
            Node * temp = mic;
            Node * pre = mic -> prev;
            mic = head;
            pre -> next = NULL;
            tail = pre;
            temp->next = temp ->partner -> next;
            temp -> partner -> next = temp;
            temp -> prev = temp ->partner;
            if (temp -> next != NULL){
                temp -> next -> prev = temp;
            }
            else {
                tail = temp;
            }
        }
        
        
        else {                              //if mic not last person
            Node * temp = mic;
            Node * pre = mic-> prev;
            Node * aft = mic -> next;
            mic = mic -> next;                  //pass mic back
            pre -> next = aft;
            aft -> prev = pre;
            
            temp->next = temp ->partner -> next;
            temp -> partner -> next = temp;
            temp -> prev = temp ->partner;
            if (temp -> next != NULL){
                temp -> next -> prev = temp;
          
            }
            else{
                tail = temp;
            }
        }
    }
    
    void function_P(){
        cout << mic -> partner -> name << endl;
        
    }
    

};



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    DLL congoLine;
    int numberOfcouples; cin >> numberOfcouples;
    int numberOfinstructions; cin >> numberOfinstructions;
    for (int i = 0; i < numberOfcouples; ++i ){          //Insert name into list
        string tempInsertname1; cin >> tempInsertname1;
        string tempInsertname2; cin >> tempInsertname2;
        congoLine.insertTailleft(tempInsertname1);
        congoLine.insertTailright(tempInsertname2);
    }
    
    string instructionsString; cin >> instructionsString;
    for (int i = 0; i < numberOfinstructions; ++i){
        if (instructionsString[i] =='F'){
            congoLine.function_F();
        }
        else if (instructionsString[i] == 'B'){
            congoLine.function_B();
        }
        else if (instructionsString[i] == 'R'){
            congoLine.function_R();
        }
        else if (instructionsString[i] == 'C'){
            congoLine.function_C();
        }
        
        else
            congoLine.function_P();
        }
        

    cout << "\n";
    congoLine.printListfoward();
    }
