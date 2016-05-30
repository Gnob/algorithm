#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int d[103];

int main()
{
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> v(M);

    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &v[i].second, &v[i].first);
    }

    sort(v.begin(), v.end());
    int maxN = N + (6 - N % 6);
    for (int i = 1; i <= maxN; i++)
    {
        d[i] = v.back() * i; // assume as max in case
        for (int j = 0; j < M; j++)
        {
            d[i] = min(d[i], d[i - 1] +  v[j].first);
            if (6 <= i) d[i] = min(d[i], d[i - 6] + v[j].second);
        }
    }

    int ans = d[N];
    for (int i = N + 1; i <= maxN; i++)
    {
        ans = min(ans, d[i]);
    }

    cout << ans;
}