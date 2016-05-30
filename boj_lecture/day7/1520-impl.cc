#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct Walker {
    int x, y, id;
};

int a[500][500];
int M, N;
int ans;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int d[500][500];

int main() {

    cin >> M >> N;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    vector<pair<int,int>> v;

    d[0][0] = 1;

    for (int x = 0; x < M; ++x) {
        for (int y = 0; y < N; ++y) {
            if (x == 0 && y == 0) continue;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (0 <= nx && nx < M && 0 <= ny && ny <= M) {
                    if (a[x][y] < a[nx][ny]) {
                        d[x][y] += d[nx][ny];
                        if (d[x][y] == 0)
                            v.emplace_back(x, y);
                    }
                }
            }
        }
    }

    for (int i = 0; i < v.size(); i++) {
        int x = v[i].first;
        int y = v[i].second;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (0 <= nx && nx < M && 0 <= ny && ny <= M) {
                if (a[x][y] < a[nx][ny]) {
                    d[x][y] += d[nx][ny];
                }
            }
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }

    cout << d[M - 1][N - 1];
}