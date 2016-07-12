/*
[bdoc @network-flow]
영훈이에게 네트워크 플로우 설명을 들었다. 유량에 집중하는 이 개념은 매우 인상깊다.
이 문제는 그중에서 기본이 되는 문제이다. 

구현에서 주의해야할 부분이 몇가지 있다.

1. 내가 나눠둔 레이어의 정점 번호를 정확하게 기억해 두고 범위를 설정할것 (M 범위에 문제가 있었음)
2. back edge를 생성할때도 헷갈리지 말 것
3. dfs 구현시 방문을 한번 했다면 재방문 하지 않아도 된다 (왜?)

(problem)[https://www.acmicpc.net/problem/11376]
[/bdoc]
*/

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
		a[0][i] = 2;

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
