#include<iostream>

using namespace std;

int arr[1000001];

int main() {
    int N;

    cin >> N;

    for (int i = 2; i <= N; ++i) {
        int target = i;
        int x=1000001, y=1000001, z=1000001;
        int minCount;

        if (target % 3 == 0 && target / 3 > 0)
            x = arr[target / 3];
        if (target % 2 == 0 && target / 2 > 0)
            y = arr[target / 2];
        z = arr[target - 1];

        minCount = min(x, min(y, z));

        arr[i] = 1 + minCount;
    }

    cout << arr[N];

    return 0;
}
