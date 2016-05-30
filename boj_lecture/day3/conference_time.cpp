#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool comparePairs(const std::pair<int,int>& lhs, const std::pair<int,int>& rhs)
{
    if (lhs.second == rhs.second) return lhs.first < rhs.first;
    return lhs.second < rhs.second;
}

int main() {
    int N, cnt = 1;
    cin >> N;
    vector<pair<int, int>> v;

    for (int i = 0; i < N; ++i) {
        int f, s;
        scanf("%d %d", &f, &s);
        v.emplace_back(make_pair(f, s));
    }

    sort(v.begin(), v.end(), comparePairs);

    int ref = 0;
    for (int k = 1; k < N; ++k) {
        if(v[ref].second <= v[k].first) {
            cnt++;
            ref = k;
        }
    }

    cout << cnt;
    return 0;
}