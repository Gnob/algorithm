#include<iostream>

using namespace std;

long long int arr[1001];

int main() {
    int N;
    cin >> N;

    arr[1] = 1;

    for (int i = 2; i <= N; ++i) {
        arr[i] = arr[i-1] + arr[i-2];
    }

    cout << arr[N] << "\n";
    return 0;
}

