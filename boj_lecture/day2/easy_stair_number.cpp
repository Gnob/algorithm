#include<iostream>

using namespace std;

long long int arr[1001][10];

int main() {
    int N;
    cin >> N;

    for (int k = 1; k <= 9; ++k) {
        arr[1][k] = 1;
    }

    for (int i = 2; i <= N; ++i) {
        arr[i][0] = arr[i-1][1];
        arr[i][9] = arr[i-1][8];

        for (int j = 1; j <= 8; ++j) {
            arr[i][j] += arr[i-1][j-1];
            arr[i][j] %= 1000000000;
            arr[i][j] += arr[i-1][j+1];
            arr[i][j] %= 1000000000;
        }
    }

    long long int sum = 0;

    for (int l = 0; l < 10; ++l) {
        sum += arr[N][l];
    }

    cout << sum%1000000000 << "\n";
    return 0;
}

