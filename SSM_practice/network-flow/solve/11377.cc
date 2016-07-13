/*
[bdoc #network-flow #modeling] 
모델링을 변경했다. 정점을 추가해서 src -> load_balancer로 K 만큼만 흘려보낼수 있게 제한하고
laod_balancer -> worker 로 1씩 추가한다. 이는 추가적으로 일할 수 있는 여유를 나타내는 것.
이렇게 하면 경로를 찾으면서 누가 일을 더할지를 결정하면서 동시에 K의 제한을 두게된다.
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
	
	a[src][load_balancer] = K;

	for (int i = worker; i < work; i++)
	{
		a[src][i] = a[load_balancer][i] = 1;

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
