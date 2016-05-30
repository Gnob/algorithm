#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

typedef pair<int,int> pii;

struct Status {
	int cnt;
	pii dir;
};

int N;
pii s, e;
char v[101][101];
int d[101][101];

int result = 100000000;

void dfs(const int &x, const int &y, const Status &stat)
{
	if (v[x][y] == '!')
	{
		if (d[x][y] > stat.cnt) d[x][y] = stat.cnt;
		else return;
	}

	if (v[x][y] == '*' || result <= stat.cnt) return;

	if (e.first == x && e.second == y) 
	{
		result = min(result, stat.cnt);
		return;
	}

	int dx = stat.dir.first;
	int dy = stat.dir.second;

	int rx = x, ry = y, nx, ny;

	for (int i = 0; i < N; i++)
	{
		rx += stat.dir.first;
		ry += stat.dir.second;

		if (v[rx][ry] == '*') return;

		if (v[rx][ry] == '!')
		{
			Status lStat = { stat.cnt + 1, make_pair(dy, -dx) };
			nx = rx + lStat.dir.first;
			ny = ry + lStat.dir.second;
			if (0 <= nx && nx < N && 0 <= ny && ny < N)
				dfs(nx, ny, lStat);

			Status rStat = { stat.cnt + 1, make_pair(-dy, dx) };
			nx = rx + rStat.dir.first;
			ny = ry + rStat.dir.second;
			if (0 <= nx && nx < N && 0 <= ny && ny < N)
				dfs(nx, ny, rStat);
		}
	}
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> v[i];

	int cnt = 0;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
	{
		d[i][j] = 5000;
		if (v[i][j] == '#')
		{
			if (cnt == 0) s = make_pair(i, j);
			else e = make_pair(i, j);
			cnt++;
		}
	}

	pii dir;
	if (s.first == 0) dir = make_pair(1, 0);
	else if (s.first == N - 1) dir = make_pair(-1, 0);
	else if (s.second == 0) dir = make_pair(0, 1);
	else if (s.second == N - 1) dir = make_pair(0, -1);
	Status stat = { 0, dir };

	dfs(s.first, s.second, stat);

	cout << result;
}

