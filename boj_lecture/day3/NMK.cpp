#include <iostream>
#include <functional>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    int lb = M + K - 1, rb = M * K;

    if (lb <= N <= rb) {
        cout << -1;
    }
    else {

    }


    return 0;
}