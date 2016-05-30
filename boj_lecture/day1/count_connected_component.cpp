#include<iostream>
#include<queue>

using namespace std;

int adjArr[1001][1001];

bool check[1001];

void BFS(int v, int maxV) {
    queue<int> waiting_q;
    int nowV;

    waiting_q.push(v);
    check[v] = true;

    while (!waiting_q.empty()) {
        nowV = waiting_q.front();
        waiting_q.pop();
//        printf("%d ", nowV);

        for (int i = 1; i <= maxV; ++i) {
            if (adjArr[i][nowV] && !check[i]) {
                waiting_q.push(i);
                check[i] = true;
            }
        }
    }
}

void DFS(int v, int maxV) {
//    printf("%d ", v);
    check[v] = true;

    for (int i = 1; i <= maxV; ++i) {
        if (adjArr[i][v] && !check[i]) {
            DFS(i, maxV);
        }
    }
}

int main() {
    int x, y;
    int N, M, count = 0;

    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        scanf("%d %d", &x, &y);
        adjArr[x][y] = adjArr[y][x] = 1;
    }

    for (int j = 1; j <= N; ++j) {
        if (!check[j]) {
            count++;
            BFS(j, N);
//            DFS(j, N);
        }
    }

    cout << count;

    return 0;
}
