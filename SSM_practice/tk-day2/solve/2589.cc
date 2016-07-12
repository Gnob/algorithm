#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> ppi;

char a[51][51];
bool chk[51][51];
int d[51][51];

int dx[4] = { 0, 1, -1, 0 };
int dy[4] = { 1, 0, 0, -1 };

int N, M;
int res = 0;

int bfs(int x, int y)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			chk[i][j] = false;

	queue<ppi> q;

	q.push(make_pair(make_pair(x, y), 0));
	chk[x][y] = true;

	while (!q.empty())
	{
		pii now = q.front().first;
		int w = q.front().second; q.pop();
		res = max(res, w);

		for (int i = 0; i < 4; i++)
		{
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			
			if (0 <= nx && nx < N && 0 <= ny && ny < M && a[nx][ny] == 'L' && !chk[nx][ny])
			{
				chk[nx][ny] = true;
				q.push(make_pair(make_pair(nx, ny), w + 1));
			}
		}
	}

	return res;
}

int main()
{
	cin >> N >> M;
	
	for (int i = 0; i < N; i++)
		scanf("%s", a[i]);
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (a[i][j] == 'L')
				bfs(i, j);

	cout << res;
}
