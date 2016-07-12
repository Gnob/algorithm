#include <iostream>

using namespace std;

char picture[3100][6300];

void draw_tri(int n, int x, int y)
{
	if (n == 3)
	{
		for (int i = 0; i < 3; i++)
			for (int j = -i; j <= i; j++)
				if (!(i == 1 && j == 0))
					picture[x + i][y + j] = '*';
		return;
	}

	int dx[] = { 0, n / 2, n / 2 };
	int dy[] = { 0, - n / 2, n / 2 };

	for (int i = 0; i < 3; i++)
		draw_tri(n / 2, x + dx[i], y + dy[i]);
}

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < 2 * N - 1; j++)
			picture[i][j] = ' ';

	draw_tri(N, 0, N - 1);

	for (int i = 0; i < N; i++)
		printf("%s\n", picture[i]);
}
