#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;

    cin >> N >> K;

    vector<int> v(N);
    vector<int> d;

    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());
    d.assign(K + 1, 0);
    d[0] = 1;
    for (int i = v[0]; i <= K; i++) {
        for (int j = 0; j < v.size(); j++) {
            if (i / v[j] == 0) break;
            for (int k = 1; k < i / v[j]; k++) {
                d[i] += d[i % v[j]];
            }
        }
    }

    cout << d.back();
}