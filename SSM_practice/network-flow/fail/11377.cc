/*
[bdoc #network-flow #modeling] 
열혈강호3
열혈강호는 네트워크 플로우 모델링 시리즈인듯 하다.
처음 모델링을 한 방법은 src -> worker 까지 모두 2의 가중치를 줬다.
그리고 capacity를 N + K로 두고 경로를 찾을 때마다 1씩 감소시켰다.
반례를 못 찾겠으나 채점 결과는 틀림...

영훈이에게 물어본 결과는 이 방법은 최대 K명만 2개씩 일을 할 수 있다는 전제를 무시한 것과 같다.
그리고 전역 변수로 두기 보단 모델링으로 풀어내는 방법을 익혀야 할거같음.
[/bdoc]
 */
#include <iostream>

using namespace std;

int a[2002][2002];
bool chk[2002];
int p[2002];
int N, M, K; 
int src = 0;
int worker = 1;
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

	work = N + 1;
	sink = N + M + 1;
	capacity = 2 * K + N - K;
	
	for (int i = worker; i < work; i++)
	{
		a[0][i] = 2;

		int W; cin >> W;
		for (int j = 0; j < W; j++)
		{
			int T; cin >> T;
			T += N;
			a[i][T] = 1;
		}
	}

	for (int i = work; i < sink; i++)
		a[i][sink] = 1;

	while (capacity && find_path(0))
	{
		make_back(sink);
		capacity--;
		reset();
	}

	int ans = 0;
	for (int i = work; i < sink; i++)
		if (a[i][sink] == 0)
			ans++;

	cout << ans;
}
