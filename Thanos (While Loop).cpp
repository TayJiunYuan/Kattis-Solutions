#include <iostream>
using namespace std;
int main() {
    int T; cin >> T;
    while (T--) {
        long long P, R, F; cin >> P >> R >> F;
        int year = 0;
        while (P <= F) { //still survive
        ++year; //go to another year
        P *= R;
        }
        cout << year << '\n';
    }
    return 0;
}
