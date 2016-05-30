#include <iostream>
#include <vector>

using namespace std;

const int getSum(const vector<int> &cv, const int cset, const int cn) {
    int sum = 0;

    for (int j = 0; j < cn; ++j) {
        int element = cv[j] * ((cset >> j) & 1);
        sum += element;
    }

    return sum;
}

int main() {
    int N, S;

    cin >> N >> S;

    vector<int> v(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &v[i]);
    }

    int cnt = 0;
    int maxRange = 1 << N;
    for (int j = 1; j < maxRange; ++j) {
        int subsum = getSum(v, j, N);
        if(S == subsum) cnt++;
    }

    cout << cnt;

    return 0;
}