#include<iostream>
#include<cstdio>

using namespace std;

int a[50][50];
bool chk[50][50];
int b[50][50];

int N;

int dir[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

void godp(const int &x, const int &y, const int &cnt)
{
	if (cnt < b[x][y])
		b[x][y] = cnt;

	if (x == N - 1 && y == N - 1)
		return;
	
	chk[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dir[i][0], ny = y + dir[i][1];
		if (0 <= nx && nx < N && 0 <= ny && ny < N && !chk[nx][ny])
		{
			int ncnt = cnt;
			if (a[nx][ny] == 0) ncnt = cnt + 1;

			if (ncnt < b[nx][ny])
			{
				godp(nx, ny, ncnt);
			}
		}
	}
	chk[x][y] = false;
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			b[i][j] = 10000;
			scanf("%1d", &a[i][j]);
		}
	}

	godp(0, 0, 0);

	if (b[N-1][N-1] == 10000)
		b[N-1][N-1] = 0;

	cout << b[N-1][N-1];
}
