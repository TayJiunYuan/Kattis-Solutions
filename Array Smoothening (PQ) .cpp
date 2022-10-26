//Tay Jiun Yuan
//A0238800J
//T07
//Athin



#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n;
int k;
int counter = 1;

template <typename T>
class binary_heap {
private:
  vector<T> A;
  int heap_size;

  int parent(int i) { return i>>1; }
  int left(int i) { return i<<1; }
  int right(int i) { return (i<<1)+1; }

  void shift_up(int i) {
    if (i == 1) return;
    if (A[i] > A[parent(i)]) {
      swap(A[i], A[parent(i)]);
      shift_up(parent(i));
    }
  }

  void shift_down(int i) {
    if (i > heap_size) return;
    int swap_id = i;
    if ((left(i) <= heap_size) && (A[i] < A[left(i)]))
      swap_id = left(i);
    if ((right(i) <= heap_size) && (A[swap_id] < A[right(i)]))
      swap_id = right(i);
    if (swap_id != i) {
      swap(A[i], A[swap_id]);
      shift_down(swap_id);
    }
  }

public:
  binary_heap() {
    A.push_back(T());
    heap_size = 0;
  }

  ~binary_heap() {
    A.clear();
  }

  void push(T x) {
    if (heap_size+1 >= (int)A.size()) // O(1)
      A.push_back(T());
    A[++heap_size] = x;
    shift_up(heap_size);
  }

  void pop() {
    if (empty()) return;
    swap(A[1], A[heap_size--]);
    shift_down(1);
  }

  T top() {
    return A[1];
  }

  bool empty() {
    return heap_size == 0;
  }


  void findVerticesbiggerthan(T v, int x){
    if (v.value > x){
      cout << v.value << endl;
      findVerticesbiggerthan(v.left, x);
      findVerticesbiggerthan(v.right, x);
    }
  }
  void printHeap(){
    while(!empty()){
      cout << top() << endl;
      pop();
    }
  }
 
    void TopNodeMinusOne(){
        A[1] = A[1]-1;
        shift_down(1);
    }
    
};



 


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    binary_heap<int> urmum;
    cin>>n >>k;
    int arr[n];
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    std::sort(arr,arr+n);
    
    for (int i=0; i<n-1; i++){
        if (arr[i] == arr [i+1]){
            counter += 1;
        }
        else {
            urmum.push(counter);
            counter = 1;
        }}
    urmum.push(counter);
    
    for (int i = 0; i < k; i++){
        urmum.TopNodeMinusOne();
   }
   printf("%d", urmum.top());

}
