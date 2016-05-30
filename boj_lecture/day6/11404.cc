#include <iostream>
#include <climits>
#include <vector>

using namespace std;

long long d[101][101];

int main(void) {
    int N, M;

    scanf("%d", &N);
    scanf("%d", &M);

    for (int j = 1; j <= N; ++j) {
        for (int i = 1; i <= N; ++i) {
            d[j][i] = INT32_MAX;
        }
    }

    for (int i = 0; i < M; i++) {
        long long x, y, z;
        scanf("%lld %lld %lld", &x, &y, &z);
        d[x][y] = min(z, d[x][y]);
    }

    for (int k = 1; k <= N; k++) {
        for (int x = 1; x <= N; x++) {
            for (int y = 1; y <= N; y++) {
                if (d[x][y] > d[x][k] + d[k][y])
                    d[x][y] = d[x][k] + d[k][y];
            }
        }
    }

    for (int x = 1; x <= N; x++) {
        for (int y = 1; y <= N; y++) {
            if (x == y)
                printf("0 ");
            else
                printf("%lld ", d[x][y]);
        }
        printf("\n");
    }
}