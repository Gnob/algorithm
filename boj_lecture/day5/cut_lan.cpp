#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<unsigned int> v;

int main(void) {
    int N, K;
    cin >> K >> N;

    for (int i = 0; i < K; ++i) {
        int tmp;
        scanf("%d", &tmp);
        v.push_back(tmp);
    }

    unsigned int left = 1;
    unsigned int right = INT32_MAX;
    unsigned int result = 0;

    while (left + 1 != right) {
        unsigned int mid = (left + right) / 2;
        int sum = 0;

        for (auto ve : v) {
            sum += ve / mid;
        }

        if (sum < N) {
            right = mid;
        }
        else if (sum >= N) {
            left = mid;
            result = max(mid, result);
        }
    }

    int sumLeft = 0, sumRight = 0;

    for (auto ve : v) {
        sumLeft += ve / left;
        sumRight += ve/ right;
    }

    if (sumRight >= N)
        result = max(right, result);
    else if (sumLeft >= N)
        result = max(left, result);

    cout << result;
}