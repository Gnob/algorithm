#include <iostream>
#include <algorithm>

using namespace std;

int a[2002][2002];
bool chk[2002];
int p[2002];
int N, M; 

bool dfs(int now)
{
	if (now == N + M + 1)
		return true;

	chk[now] = true;
	for (int i = 0; i <= N + M + 1; i++)
	{
		if (!chk[i] && a[now][i] > 0)
		{
			p[i] = now;

			if (dfs(i))
				return true;
		}
	}

	return false;
}

void make_back(int now)
{
	if (now == 0)
		return;

	a[p[now]][now]--; 
	a[now][p[now]]++; 

	make_back(p[now]);
}

int main()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		a[0][i] = 1;

		int w; scanf("%d", &w);
		for (int j = 0; j < w; j++)
		{
			int y; scanf("%d", &y);
			a[i][N + y] = 1;
		}
	}

	for (int i = N + 1; i <= N + M; i++)
		a[i][N + M + 1] = 1;

	while (dfs(0))
	{
		make_back(N + M + 1);
		fill(p, p + N + M + 2, 0);
		fill(chk, chk + N + M + 2, false);
	}

	int ans = 0;
	for (int i = N + 1; i <= N + M; i++)
		if (a[i][N + M + 1] == 0)
			ans += 1;

	cout << ans;
}

