#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    vector<pair<int, int>> v;

    while(N--) {
        int st, ed;
        scanf("%d %d", &st, &ed);

        v.emplace_back(st, 1);
        v.emplace_back(ed, 0);
    }

    sort(v.begin(), v.end());
    bool isWriting = false;
    int cnt = 0, sum = 0, stpos = 0;

    for (int i = 0; i < v.size(); i++) {
        if (v[i].second == 1) {
            cnt++;

            if (cnt == 1)
                stpos = v[i].first;
        }
        else {
            cnt--;
            if (cnt == 0)
                sum += v[i].first - stpos;
        }
    }

    cout << sum;
}