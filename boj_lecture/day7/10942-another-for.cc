#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int d[2001][2001];
int a[2001];

int main() {
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 1; i <= N; i++) {
        d[i][i] = 2;
    }

    for (int i = 1; i <= N - 1; i++) {
        if (a[i] == a[i+1])
            d[i][i+1] = 2;
        else
            d[i][i+1] = 1;
    }

    // 기준점을 잡고 일정 길이만큼 먼저 이동한다
    for (int k = 2; k <= N - 1; k++) {
        for (int i = 1; i <= N - k; i++) {
            int j = k + i;
            if (a[i] == a[j] && d[i + 1][j - 1] == 2)
                d[i][j] = 2;
            else
                d[i][j] = 1;
        }
    }

    int M;

    cin >> M;

    while(M--) {
        int st, ed;
        scanf("%d %d", &st, &ed);

        cout << d[st][ed] - 1 << "\n";
    }

}
