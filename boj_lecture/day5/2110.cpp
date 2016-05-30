#include <iostream>
#include <vector>

using namespace std;

vector<long long> v, d;

bool check(const long long dist, const int rcnt) {
    int sum = 0, cnt = 1;

    for (int j = 1; j < v.size(); ++j) {
        sum += d[j - 1];
        if (dist <= sum) {
            cnt++;
            sum = 0;
        }
    }

    return cnt >= rcnt;
}

int main(void) {
    int N, C;
    cin >> N >> C;


    for (int i = 0; i < N; ++i) {
        long long tmp;
        scanf("%lld", &tmp);
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    long long left = 1, right = (v.back() - v.front()) / 2, ans = 0;

    for (int j = 0; j < v.size() - 1; ++j) {
        d.push_back(v[j + 1] - v[j]);
    }

    while (left <= right) {
        long long mid = (left + right) / 2;

        if (check(mid, C)) {
            if (ans < mid)
                ans = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    cout << ans;
}