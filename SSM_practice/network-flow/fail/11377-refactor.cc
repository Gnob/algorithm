/*
[bdoc #network-flow #modeling] 
내가 틀린 방법을 일단 먼저 네트워크 플로우로 모델링을 다시 해봤다.
이런식으로 유동적으로 짜기 위해선 정점을 구분짓기 위한 변수가 중요
[/bdoc]
 */
#include <iostream>

using namespace std;

int a[2003][2003];
bool chk[2003];
int p[2003];
int N, M, K; 
int src = 0;
int load_balancer = 1;
int worker = 2;
int work;
int sink;
int capacity;

bool find_path(int now)
{
	if (now == sink)
		return true;

	chk[now] = true;

	for (int next = 0; next <= sink; next++)
	{
		if (!chk[next] && a[now][next] > 0)
		{
			p[next] = now;

			if (find_path(next)) 
				return true;
		}
	}

	return false;
}

void make_back(int now)
{
	if (now == src)
		return;

	a[p[now]][now]--;
	a[now][p[now]]++;

	make_back(p[now]);
}

void reset()
{
	for (int i = src; i <= sink; i++)
	{
		chk[i] = false;
		p[i] = 0;
	}
}

int main()
{
	cin >> N >> M >> K;

	work = worker + N;
	sink = work + M;
	capacity = N + K;
	
	a[src][load_balancer] = capacity;

	for (int i = worker; i < work; i++)
	{
		a[load_balancer][i] = 2;

		int W; cin >> W;
		for (int j = 0; j < W; j++)
		{
			int T; cin >> T;
			T += work - 1;
			a[i][T] = 1;
		}
	}

	for (int i = work; i < sink; i++)
		a[i][sink] = 1;

	while (find_path(src))
	{
		make_back(sink);
		reset();
	}

	int ans = 0;
	for (int i = work; i < sink; i++)
		if (a[i][sink] == 0)
			ans++;

	cout << ans;
}
