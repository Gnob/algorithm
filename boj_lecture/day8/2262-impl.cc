#include <iostream>
#include <vector>

using namespace std;

int d[256][256];

int main()
{
    int N; cin >> N;

    vector<int> a(N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int l = 0; l < N - 1; ++l)
    {
        d[l][l + 1] = abs(a[l] - a[l + 1]);
    }

    for (int k = 3; k <= N; k++)
    {
        for (int i = 0; i <= N - k; i++)
        {
            int j = i + k - 1;
            d[i][j] = 100000000;
            for (int p = i; p < j; p++)
            {
                d[i][j] = min(d[i][j], abs(d[i][p] - d[p][j]));
            }
        }
    }

    cout << d[0][N - 1];
}