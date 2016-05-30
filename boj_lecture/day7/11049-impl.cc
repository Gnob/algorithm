#include <iostream>
#include <vector>
#include <climits>

using namespace std;

long long d[501];
int st, ed;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> v(N);
    int x, y;
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &v[i].first, &v[i].second);
    }

    long long minimum = INT32_MAX;
    int sum;
    for (int i = 0; i < v.size() - 1; i++) {
        sum = v[i].first * v[i].second * v[i + 1].second;
        if (minimum > sum) {
            minimum = sum;
            st = i;
            ed = i + 1;
        }
    }

    d[2] = minimum;
    long long sumFront, sumRear;
    for (int i = 3; i <= N; i++) {
        sumFront = sumRear = LLONG_MAX;
        if (0 < st)
            sumFront = d[i - 1] + v[st - 1].first * v[st - 1].second * v[ed].second;
        if (ed < N - 1)
            sumRear = d[i - 1] + v[st].first * v[ed + 1].first * v[ed + 1].second;

        if (sumFront < sumRear) {
            d[i] = sumFront;
            st--;
        }
        else if (sumFront > sumRear) {
            d[i] = sumRear;
            ed++;
        }
        else {
            int sst = st - 2, eed = ed + 2;
            if (0 < sst) {
                v[sst].first * v[sst].second
            }
        }
    }

    cout << d[N];
}
