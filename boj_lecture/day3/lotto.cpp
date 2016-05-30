#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int K;

    while (true) {
        cin >> K;
        if (K == 0) break;

        vector<int> v(K);
        vector<vector<int>> vArr;
        for (int i = 0; i < K; ++i) {
            scanf("%d", &v[i]);
        }

        int maxRange = 1 << K;

        for (int j = (1 << 6) - 1; j < maxRange; ++j) {
            vector<int> tv;
            for (int u = 0; u < K; ++u) {
                int element = v[u] * ((j >> u) & 1);
                if (element != 0)
                    tv.push_back(element);
            }

            if (tv.size() == 6) vArr.push_back(tv);
        }

        sort(vArr.begin(), vArr.end());

        for (auto k : vArr) {
            for (auto k2 : k) {
                printf("%d ", k2);
            }
            printf("\n");
        }

        printf("\n");
    }

    return 0;
}