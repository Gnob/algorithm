#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int main() {
    int N, M, K, cnt = 0;
    cin >> N >> M >> K;

    if (N >= 2 * M) {
        cnt = M;
        N = N - 2 * M;
        M = 0;
    }
    else {
        cnt = N/2;
        M = M - cnt;
        N = N - 2 * cnt;
    }

    while (K-- > 0) {
        if (M > 0) {
            M--;
            continue;
        }
        if (N > 0) {
            N--;
            continue;
        }
        cnt--;
        N += 2;
    }

    cout << cnt;


    return 0;
}