#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> v(N);
    unordered_map<int, int> map;

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &v[i]);

        if (map.count(v[i]) == 0)
            map[v[i]] = 1;
        else
            map[v[i]] += 1;
    }

    vector<pair<int, int>> fv;
    for (auto k : map) {
        fv.emplace_back(k.second, k.first);
    }

    sort(fv.begin(), fv.end());

    for (int j = 0; j < fv.size(); ++j) {
        if (fv.back().first == fv[j].first)
        {
            fv.erase(fv.begin(), fv.begin() + j);
            break;
        }
    }
    int freq = fv.size() == 1 ? fv.back().second : fv[1].second;


    sort(v.begin(), v.end());

    vector<int> mv(v);
    mv.erase(unique(mv.begin(), mv.end()), mv.end());
    int mid = mv[(mv.size() % 2) == 1 ? mv.size() / 2 : mv.size() / 2 - 1];
    int scope = v.back() - v.front();

    const long long C = 1000;
    long long sum = 0;

    for (auto k : v) {
        sum += k * C;
    }

    cout << (sum / v.size() + (C / 2)) / C;
    printf("\n");
    cout << mid;
    printf("\n");
    cout << freq;
    printf("\n");
    cout << scope;
}