#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int X = 1, Y = 1;

int arr[51][51];
bool check[51][51];
int num;

int dx[3] { -1, 0, 1 };
int dy[3] { -1, 0, 1 };


void BFS(int x, int y) {
    queue<pair<int, int>> q;
    check[x][y] = true;
    q.push({x, y});

    while(!q.empty()) {
        pair<int, int> now = q.front(); q.pop();

        printf("Visit : %d/%d\n", now.first, now.second);

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int nx = now.first + dx[i], ny = now.second + dy[j];
                printf("Checking... %d/%d\n", nx, ny);
                if (0 <= nx && nx < X && 0 <= ny && ny < Y) {
                    if (arr[nx][ny] && !check[nx][ny]) {
                        check[nx][ny] = true;
                        q.push({nx, ny});
                        printf("Target set %d/%d\n", nx, ny);
                    }
                }
            }
        }
    }

}

int main() {
    while (true) {
        cin >> Y >> X;
        if (X == 0 && Y == 0)
            break;

        num = 0;

        for (int i = 0; i < X; ++i) {
            for (int j = 0; j < Y; ++j) {
                scanf("%d", &arr[i][j]);
                check[i][j] = false;
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }

        for (int k = 0; k < X; ++k) {
            for (int i = 0; i < Y; ++i) {
                if (arr[k][i] && !check[k][i]){
                    num++;
                    BFS(k, i);
                    cout << num << "\n";
                }
            }
        }

        cout << num << "\n";
    }

    return 0;
}
