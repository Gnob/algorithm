#include<iostream>

using namespace std;

int arr[12] = { 0, 1, 2, 4, };

int main() {
    int N = 11, T;
    cin >> T;

    for (int i = 4; i <= N; ++i) {
        for (int j = i - 1; j >= i - 3; --j) {
            arr[i] += arr[j];
        }
    }

    while (T--) {
        cin >> N;

        cout << arr[N] << "\n";
    }
    return 0;
}
