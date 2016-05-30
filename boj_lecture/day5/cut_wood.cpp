#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<long long int> v;

int main(void) {
    int N, K;
    cin >> K >> N;

    long long int left = 1;
    long long int result = 0;
    long long int right = 0;

    for (int i = 0; i < K; ++i) {
        long long int tmp;
        scanf("%lld", &tmp);
        v.push_back(tmp);
        right = max(right, tmp);
    }

    while (left + 1 != right) {
        long long int mid = (left + right) / 2;
        long long int sum = 0;

        for (auto ve : v) {
            if (ve - mid > 0) {
                sum += ve - mid;
            }
        }

        if (sum < N) {
            right = mid;
        }
        else if (sum >= N) {
            left = mid;
            result = max(mid, result);
        }
    }

    long long int sumLeft = 0, sumRight = 0;

    for (auto ve : v) {
        if (ve - sumLeft > 0) {
            sumLeft += ve - left;
        }

        if (ve - sumRight > 0) {
            sumRight += ve - right;
        }
    }

    if (sumRight >= N)
        result = max(right, result);
    if (sumLeft >= N)
        result = max(left, result);

    cout << result;
}