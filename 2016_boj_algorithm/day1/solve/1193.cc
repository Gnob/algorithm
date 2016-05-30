#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int t1,t2;
    for (int i=1;; i++) {
        if (n-i <= 0) {
            if (i%2 == 1) {
                t1 = i-n+1;
                t2 = n;
            } else {
                t1 = n;
                t2 = i-n+1;
            }
            break;
        }
        n -= i;
    }
    cout << t1 << '/' << t2 << '\n';
    return 0;
}
