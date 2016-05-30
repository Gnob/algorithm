#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int a[1001][1001];
int d[1001];
bool c[1001];

int main() {
    int V, E;

    scanf("%d", &V);

    for (int i = 1; i <= V; i++) {
        d[i] = INT32_MAX - 1;
        for (int j = 1; j <= V; j++) {
            a[i][j] = INT32_MAX - 1;
        }
    }

    scanf("%d", &E);

    for (int i = 0; i < E; i++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        a[x][y] = min(a[x][y], z);
    }

    int st, ed;
    scanf("%d %d", &st, &ed);
    c[st] = true;
    d[st] = 0;

    while (true) {
        int min = INT32_MAX;
        int now = 0;
        for (int i = 1; i <= V; i++) {
            if (! c[i] && min > d[i]) {
                min = d[i];
                now = i;
            }
        }

        if (now == 0) break;
        c[now] = true;

        for (int i = 1; i <= V; i++) {
            if (d[i] > d[now] + a[now][i]) {
                d[i] = d[now] + a[now][i];
            }
        }
    }

    cout << d[ed];
}