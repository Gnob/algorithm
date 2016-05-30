
#include<iostream>

using namespace std;

long long int arr[1001][10];

int main() {
    int N;
    cin >> N;

    for (int k = 0; k <= 9; ++k) {
        arr[1][k] = 1;
    }

    for (int i = 2; i <= N; ++i) {
        arr[i][0] = arr[i-1][0];

        for (int j = 1; j <= 9; ++j) {
            for (int k = j; k >= 0; --k) {
                arr[i][j] += arr[i-1][k];
                arr[i][j] %= 10007;
            }
        }
    }

    long long int sum = 0;

    for (int l = 0; l < 10; ++l) {
        sum += arr[N][l];
    }

    cout << sum % 10007 << "\n";
    return 0;
}
