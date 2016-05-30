#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N, sum = 0;
    cin >> N;
    vector<int> v(N), d(N);

    for (int i = 0; i < N; ++i) {
        scanf("%d", &v[i]);
    }

    sort(v.begin(), v.end());

    d[0] = v[0];
    sum = v[0];
    for (int j = 1; j < N; ++j) {
        d[j] = d[j - 1] + v[j];
        sum += d[j];
    }

    cout << sum;
    return 0;
}