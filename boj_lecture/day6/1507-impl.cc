#include <iostream>
#include <vector>
#include <climits>

using namespace std;


long long d[21][21];

int main() {
    int V;

    scanf("%d", &V);

    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            scanf("%lld", &d[i][j]);
        }
    }

    for (int k = V; k > 0; k--) {
        for (int i = V; i > 0; i--) {
            for (int j = V; j > 0; j--) {
                if (d[i][k] != 0 && d[k][j] != 0 && d[i][j] == d[i][k] + d[k][j]) {
                    d[i][j] = 0;
                }
            }
        }
    }

    long long sum = 0;
    int cnt = 0;
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            if (d[i][j] > 0) {
                sum += d[i][j];
                cnt++;
            }
        }
    }

    if (sum == 0 || cnt / 2 < V) cout << -1;
    else cout << sum / 2;

}