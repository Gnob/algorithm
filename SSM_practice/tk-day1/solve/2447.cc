#include <iostream>

using namespace std;

int N;

char picture[7000][7000];

void draw_star(int n, int x, int y, char ch)
{
	if (n == 1)
	{
		picture[x][y] = ch;
		return;
	}

	int d[3] = { 0, n / 3 , n / 3 * 2 };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == j && i == 1)	
				draw_star(n / 3, x + d[i], y + d[j], ' ');
			else
				draw_star(n / 3, x + d[i], y + d[j], ch);
		}
	}
}

int main()
{
	cin >> N;
	draw_star(N, 0, 0, '*');

	for (int i = 0; i < N - 1; i++)
		printf("%s\n", picture[i]);
	printf("%s", picture[N - 1]);
}
