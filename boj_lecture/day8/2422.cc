#include <iostream>
#include <vector>

using namespace std;

bool a[201][201];

int main()
{
    int N, M; cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);

        a[x][y] = true;
        a[y][x] = true;
    }

    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = i + 1; j <= N; j++)
        {
            for (int k = j + 1; k <= N; k++)
            {
                if (a[i][j]) continue;
                if (a[k][j]) continue;
                if (a[i][k]) continue;
                ans++;
            }
        }
    }

    cout << ans;
}