#include <iostream>

using namespace std;

char a[100001][4];
int d[100001][4];

int main()
{
    int N; cin >> N;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    d[1][1] = a[1][1];
    d[1][2] = a[1][2];
    d[1][3] = a[1][3];

    for (int i = 2; i <= N; i++)
    {
        d[i][1] = a[i][1] + min(d[i - 1][1], d[i - 1][2]);
        d[i][2] = a[i][2] + min(d[i - 1][1], min(d[i - 1][2], d[i - 1][3]));
        d[i][3] = a[i][3] + min(d[i - 1][2], d[i - 1][3]);
    }
    int minAns = min(d[N][1], min(d[N][2], d[N][3]));

    for (int i = 2; i <= N; ++i) {
        d[i][1] = a[i][1] + max(d[i - 1][1], d[i - 1][2]);
        d[i][2] = a[i][2] + max(d[i - 1][1], max(d[i - 1][2], d[i - 1][3]));
        d[i][3] = a[i][3] + max(d[i - 1][2], d[i - 1][3]);
    }
    int maxAns = max(d[N][1], max(d[N][2], d[N][3]));


    cout << maxAns << " " << minAns;
}