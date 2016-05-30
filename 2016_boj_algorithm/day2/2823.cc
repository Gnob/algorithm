#include<iostream>
#include<cstdio>

using namespace std;

char a[11][11];

int main()
{
	int R, C;
	cin >> R >> C;

	for (int i = 0; i < R; i++)
	{
		scanf("%s", a[i]);
	}

	int ans = 0;
	int dir[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0}};

	for (int x = 0; x < R; x++)
	{
		for (int y = 0; y < C; y++)
		{
			if (a[x][y] == '.')
			{
				int cnt = 0;

				for (int k = 0; k < 4; k++)
				{
					int nx = x + dir[k][0];
					int ny = y + dir[k][1];

					if (0 <= nx  && nx < R && 0 <= ny && ny < C 
							&& a[nx][ny] == '.')
						cnt++;
				}

				if (cnt == 1)
					ans = 1;
			}
		}
	}

	cout << ans;
}

