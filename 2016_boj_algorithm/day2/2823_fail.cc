/*
 * 사이클을 찾는 문제라고 생각했으나
 * 간선이 한개인 정점을 찾는 문제였음...
 */
#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int R, C;
char a[11][11];
bool c[11][11];
int dir[4][2] = { { 0, -1 }, { 1, 0 }, { 0, 1 }, { -1, 0 } };
int sx, sy;

bool dfs(int x, int y, int count)
{
	c[x][y] = true;
	count++;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		if (0 <= nx  && nx < R && 0 <= ny && ny < C)
		{
			if (count > 2 && nx == sx && ny == sy)
			{
				// cout << count << endl;
				// cout << sx << '/' << sy << endl;
				// cout << x << '/' << y << endl;
				// cout << nx << '/' << ny << endl;
				return true;
			}
			if (a[nx][ny] == '.' && c[nx][ny] == false)
			{
				if (dfs(nx, ny, count))
					return true;
			}
		}
	}

	c[x][y] = false;

	return false;
}

int main()
{
	cin >> R >> C;

	for (int i = 0; i < R; i++)
	{
		scanf("%s", a[i]);
	}

	for (sx = 0; sx < R; sx++)
	{
		for (sy = 0; sy < C; sy++)
		{
			if (a[sx][sy] == '.' && dfs(sx, sy, 0))
			{
				cout << 0;
				return 0;
			}
		}
	}

	cout << 1;
	return 0;
}
