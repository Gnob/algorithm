#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int N;

int arr[25][25];
bool check[25][25];
int num;
vector<int> cnt;

int dx[4] { 0, 0, 1, -1 };
int dy[4] { 1, -1, 0, 0 };


void BFS(int x, int y) {
    queue<pair<int, int>> q;
    cnt.push_back(0);
    check[x][y] = true;
    cnt[num - 1]++;
    q.push({x, y});

    while(!q.empty()) {
        pair<int, int> now = q.front(); q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = now.first + dx[i], ny = now.second + dy[i];
            if (0 <= nx && nx < N && 0 <= ny && ny < N) {
                if (arr[nx][ny] && !check[nx][ny]) {
                    check[nx][ny] = true;
                    cnt[num - 1]++;
                    q.push({nx, ny});
                }
            }
        }
    }

}

int main() {
    cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%1d", &arr[i][j]);
        }
    }

    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            if (arr[k][i] && !check[k][i]){
                num++;
                BFS(k, i);
            }
        }
    }

    cout << num << "\n";
    sort(cnt.begin(), cnt.end());
    for (int n: cnt) {
        cout << n << "\n";
    }

    return 0;
}
