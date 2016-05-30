#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long int> v(N + 1);
    vector<long long int> d(N + 1);

    v[0] = 0;
    d[0] = 0;

    for (int i = 1; i <= N; ++i) {
        scanf("%d", &v[i]);
    }

    d[1] = v[1];
    d[2] = d[1] + v[2];

    for (int j = 3; j <= N; ++j) {
        long long int one_step = d[j - 3] + v[j - 1] + v[j];
        long long int two_step = d[j - 2] + v[j];

        d[j] = max(d[j-1], max(one_step, two_step));
    }

    sort(d.begin() + 1, d.end());
    cout << d.back();

    return 0;
}

