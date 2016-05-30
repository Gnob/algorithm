#include<iostream>
#include<vector>
#include<algorithm>
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

    for (int j = 2; j <= N; ++j) {
        d[j] = v[j];
        if (d[j] < d[j-1] + v[j]) {
            d[j] = d[j-1] + v[j];
        }
    }

    sort(d.begin() + 1, d.end());
    cout << d.back();

    return 0;
}

