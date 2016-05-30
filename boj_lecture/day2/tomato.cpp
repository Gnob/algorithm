#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int M = 1, N = 1;

int arr[1001][1001];
bool check[1001][1001];
int num;
int day;

int dx[4] { 0, -1, 0, 1 };
int dy[4] { -1, 0, 1, 0 };


void BFS(int x, int y) {
    queue<pair<pair<int, int>, int>> q;
    check[y][x] = true;
    q.push({{x, y}, 0});

    while(!q.empty()) {
        pair<int, int> now = q.front().first;
        int curDay = q.front().second; q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = now.first + dx[i], ny = now.second + dy[i];
            if (0 <= nx && nx < M && 0 <= ny && ny < N) {
                if (arr[ny][nx] == 0 && !check[ny][nx]) {
                    check[ny][nx] = true;
                    q.push({{nx, ny}, curDay + 1});
                }
            }
        }
        day = curDay;
    }

}

int main() {
    cin >> M >> N;

    num = 0;

    for (int n = 0; n < N; ++n) {
        for (int m = 0; m < M; ++m) {
            scanf("%d", &arr[n][m]);
        }
    }

    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < M; ++i) {
            if (arr[k][i] && !check[k][i]){
                num++;
                BFS(i, k);
            }
        }
    }

    cout << (num > 1 ? 0 : day) << "\n";

    return 0;
}
