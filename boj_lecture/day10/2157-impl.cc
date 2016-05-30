#include <iostream>

using namespace std;

int a[301][301];
int d[301][301];

int main()
{
    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 0; i < K; i++)
    {
        int from, to, cost;
        scanf("%d %d %d", &from, &to, &cost);
        if (from < to && a[from][to] < cost)
            a[from][to] = cost;
    }

    d[1][1] = 0;
    for (int to = 2; to <= N; to++)
    {
        for (int seq = 2; seq <= to; seq++)
        {
            for (int from = seq - 1; from < to; from++)
            {
                d[to][seq] = max(d[to][seq], d[from][seq - 1] + a[from][to]);
            }
        }
    }

    int ans = d[N][2];
    for (int i = 3; i <= M; i++)
    {
        ans = max(ans, d[N][i]);
    }

    cout << ans;
}