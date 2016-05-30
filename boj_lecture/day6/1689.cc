#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> point;

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        int st, ed;
        scanf("%d %d", &st, &ed);
        point.emplace_back(st, 1);
        point.emplace_back(ed, 0);
    }

    sort(point.begin(), point.end());

    int max = 0;
    int sum = 0;
    for (int i = 0; i < point.size(); i++) {
        if (point[i].second == 0) sum--;
        else sum++;

        if (sum > max) max = sum;
    }

    cout << max;
}