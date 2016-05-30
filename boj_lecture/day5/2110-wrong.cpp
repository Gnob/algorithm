#include <iostream>
#include <vector>

using namespace std;

vector<long long> v, d;

bool check(const long long dist, const int rcnt) {
    bool isPossible = false;
    int sum = 0, cnt = rcnt;

    for (int i = 0; i < v.size() - (rcnt - 1); ++i) {
        isPossible = false;
        cnt = rcnt - 1;
        sum = 0;
        for (int j = i + 1; cnt > 0 && j < v.size(); ++j) {
            sum += d[j - 1];
            if (dist <= sum) {
                if (dist == sum)
                    isPossible = true;
                cnt--;
                sum = 0;
            }
        }

        if (isPossible && cnt == 0)
            break;
    }

    return isPossible && cnt == 0;
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