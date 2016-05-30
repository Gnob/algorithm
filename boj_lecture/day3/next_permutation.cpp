

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool nextPermutation(vector<int> &v) {
    int i;
    for (i = v.size() - 1; i > 0; i--) {
        if (v[i - 1] < v[i])
            break;
    }
    if (i == 0) return false;

    int j;
    for (j = v.size() - 1; j >= i; --j) {
        if (v[i - 1] < v[j]) break;
    }

    swap(v[i - 1], v[j]);

    reverse(v.begin() + i, v.end());
    return true;
}

int main() {
    int N;
    cin >> N;

    vector<int> v(N);

    for (int i = 0; i < N; ++i) {
        scanf("%d", &v[i]);
    }

    if (nextPermutation(v)) {
        for (auto k : v) {
            cout << k << " ";
        }
    }
    else {
        cout << -1;
    }

    return 0;
}