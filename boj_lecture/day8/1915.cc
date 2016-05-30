#include <iostream>
#include <vector>

using namespace std;

int a[1000][1000], d[1000][1000];

int main()
{
    int N, M;

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%1d", &a[i][j]);
        }
    }

    for (int i = 0; i < M; i++)
    {
        d[0][i] = a[0][i];
    }
    
    for (int j = 0; j < N; ++j)
    {
        d[j][0] = a[j][0];
    }
    

    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < M; j++)
        {
            if (a[i][j] == 1)
            {
                int tmp = min(d[i - 1][j - 1], min(d[i][j - 1], d[i - 1][j]));
                if (tmp == 0)
                    d[i][j] = 1;
                else
                    d[i][j] = tmp + 1;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            ans = max(ans, d[i][j]);
        }
    }

    cout << (ans * ans);
}