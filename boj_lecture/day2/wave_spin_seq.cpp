#include<iostream>
#include<vector>
using namespace std;

int main() {
    int T, N;
    cin >> T;

    vector<long long int> d(101);

    d[0] = 0;
    d[1] = 1;
    d[2] = 1;
    d[3] = 1;
    d[4] = 2;

    for (int j = 5; j <= 100; ++j) {
        d[j] = d[j - 1] + d[j - 5];
    }

    while (T--) {
        scanf("%d", &N);

        cout << d[N] << "\n";
    }

    return 0;
}

