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
    int N, tmp;
    cin >> N;

    vector<vector<int>> price;
    vector<int> cities(N);

    for (int i = 0; i < N; ++i) {
        price.emplace(price.begin() + i);
        cities[i] = i;
        for (int j = 0; j < N; ++j) {
            scanf("%d", &tmp);
            price[i].push_back(tmp);
        }
    }

    int minValue = 10000000;
    do {
        int sum = price[cities[N - 1]][cities[0]];
        for (int i = 0; i < N - 1; ++i) {
            if (price[cities[i]][cities[i+1]] == 0) {
                sum = -1;
                break;
            }
            sum += price[cities[i]][cities[i+1]];
        }
        if (sum == -1) continue;

        minValue = min(sum, minValue);
    } while (nextPermutation(cities));

    cout << minValue;


    return 0;
}