#include <iostream>
#include <vector>

using namespace std;

int a[1001][1001];
int d[1001][1001];

int main(void) {
    int N, M;

    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    d[1][1] = a[1][1];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            d[i + 1][j] = max(d[i + 1][j], a[i + 1][j] + d[i][j]);
            d[i][j + 1] = max(d[i][j + 1], a[i][j + 1] + d[i][j]);
        }
    }

    cout << d[N][M];
}