#include<iostream>
#include<vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> v(N + 1);
    vector<int> d(N + 1);

    v[0] = 0;
    d[0] = 0;

    for (int i = 1; i <= N; ++i) {
        scanf("%d", &v[i]);
    }

    d[1] = v[1];
    d[2] = d[1] + v[2];

    for (int j = 3; j <= N; ++j) {
        int one_step = d[j - 3] + v[j - 1] + v[j];
        int two_step = d[j - 2] + v[j];

        d[j] = max(one_step, two_step);
    }

    cout << d.back();

    return 0;
}

