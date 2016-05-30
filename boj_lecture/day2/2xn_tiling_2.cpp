#include<iostream>

using namespace std;

int d[1001] = {1, 1, };

int main() {
    int N;
    cin >> N;

    for (int i = 2; i <= N; ++i) {
        d[i] = d[i-1] + 2 * d[i-2];
        d[i] %= 10007;
    }

    cout << d[N] % 10007 << "\n";
    return 0;
}

