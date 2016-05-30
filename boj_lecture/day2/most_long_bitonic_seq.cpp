#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> v(N + 1);
    vector<int> d(N + 1);
    vector<int> d2(N + 1);

    v[0] = 0;
    d[0] = 0;
    d2[0] = 0;

    for (int i = 1; i <= N; ++i) {
        scanf("%d", &v[i]);
    }

    d[1] = 1;
    d2[N] = 1;

    for (int j = 2; j <= N; ++j) {
        int max = 1;
        for (int i = j - 1; i >= 1; i--) {
            if (v[j] <= v[i]) continue;
            int tmp = d[i] + 1;
            if (max < tmp) max = tmp;

        }
        d[j] = max;
    }

    for (int j = N - 1; j >= 1; --j) {
        int max = 1;
        for (int i = j + 1; i <= N; i++) {
            if (v[j] <= v[i]) continue;
            int tmp = d2[i] + 1;
            if (max < tmp) max = tmp;
        }
        d2[j] = max;
        d[j] += d2[j] - 1;
    }

    sort(d.begin(), d.end());
    cout << d.back();

    return 0;
}

