#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int d[101][101];

int main() {
    int N, M;

    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        d[x][y] = 1;
        d[y][x] = 1;
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (i == j) continue;
                if (d[i][k] != 0 && d[k][j] != 0) {
                    if (d[i][j] == 0)
                        d[i][j] = d[i][k] + d[k][j];
                    else
                        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }

    int min = INT32_MAX;
    int minp = 0;
    for (int i = 1; i <= N; i++) {
        int sum = 0;
        for (int j = 1; j <= N; j++) {
            sum += d[i][j];
        }
        if (sum < min) {
            min = sum;
            minp = i;
        }
    }

    cout << minp;
}