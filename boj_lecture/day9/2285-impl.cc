#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    long long x, y;
    vector<pair<long long, long long>> v;

    for (int i = 0; i < N; i++)
    {
        scanf("%lld %lld", &x, &y);

        if (y == 0) continue;

        v.emplace_back(x, y);
    }

    sort(v.begin(), v.end());
    
    vector<long long> s(v.size());
    
    s[0] = v[0].second;
    for (int i = 1; i < s.size(); i++)
    {
        s[i] = s[i - 1] + v[i].second;
    }
    
    long long mid = s.back() / 2;
    int pos;
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] < mid && mid <= s[i + 1])
        {
            pos = i + 1;
            break;
        }
    }

    cout << v[pos].first;
}