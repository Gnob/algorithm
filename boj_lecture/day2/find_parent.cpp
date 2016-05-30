#include<iostream>
#include<queue>

using namespace std;

int N = 1;

int v[100000][100000];
vector<int> p(100000);
bool check[100000];

int main() {
    cin >> N;
    int TN = N - 1, a, b;

    while (TN--) {
        scanf("%d %d", &a, &b);
        v[a][b] = 1;
        v[b][a] = 1;
    }

    queue<int> q;
    q.push(1);
    check[1] = true;

    while(!q.empty()) {
        int now = q.front(); q.pop();

        for (int i = 1; i <= N; ++i) {
            if (v[i][now] && !check[i]) {
                p[i] = now;
                q.push(i);
                check[i] = true;
            }
        }
    }

    for (int j = 2; j <= N; ++j) {
        printf("%d\n", p[j]);
    }


    return 0;
}
