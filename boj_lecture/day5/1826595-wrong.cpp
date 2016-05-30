#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

bool check(const long long t, const long long n) {
    long long total = v.size();

    for (int i = 0; i < v.size(); ++i) {
        total += t / v[i];
    }

    return n >= total;
}

int main(void) {
    long long  N, M;

    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int tmp;
        scanf("%d", &tmp);
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    long long left, right, mid, ans;
    left = 1;
    right = 2000000000LL * 1000000LL;

    while (left <= right) {
        mid = (left + right) / 2;

        if (check(mid, N)) {
            ans = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    long long total = v.size();

    for (int i = 0; i < v.size(); ++i) {
        total += (ans - 1) / v[i];
    }

    while (total < N) {
        for (int j = 0; j < v.size(); ++j) {
            if (ans % v[j] == 0) {
                total++;

                if (N == total) cout << v[j];
            }
        }
    }
}