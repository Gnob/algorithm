#include <iostream>
#include <cstdio>

using namespace std;

char a[21][21];

bool is_visited[26];
bool chk[21][21];

int dx[4] = { 0, 1, -1, 0 };
int dy[4] = { 1, 0, 0, -1 };

int N, M;
int ans;

void go_dfs(int x, int y, int cnt)
{
	ans = max(cnt, ans);
	chk[x][y] = true;
	is_visited[a[x][y] - 'A'] = true;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < N && 0 <= ny && ny < M &&
				!chk[nx][ny] && !is_visited[a[nx][ny] - 'A'])
			go_dfs(nx, ny, cnt + 1);
	}

	chk[x][y] = false;
	is_visited[a[x][y] - 'A'] = false;
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		scanf("%s", a[i]);

	go_dfs(0, 0, 1);

	cout << ans;
}
