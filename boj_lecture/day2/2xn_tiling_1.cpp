#include<iostream>

using namespace std;

int d[1001] = {1, 1, };

int main() {
    int N;
    cin >> N;

    for (int i = 2; i <= N; ++i) {
        d[i] = d[i-1] + d[i-2];
    }

    cout << d[N] << "\n";
    return 0;
}

