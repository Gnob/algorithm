#include <iostream>
using namespace std;
int main() {
    int N;
    cin >> N;

    long long now = 5;
    for (int i = 2; i <= N; i++) {
        now = now + (i + 1) * 2 + (i - 1);
    }

    cout << (now % 45678);
}