/*
[bdoc #network-flow #modeling] 
뭐가 문젤까?
[/bdoc]
 */
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

int a[2003][2003];
int p[2003];
int N, M, K; 
int src = 0;
int worker = 1;
int work;
int sink;

typedef pair<int, int> pii;
typedef pair<int, pii> pip;

priority_queue<pip> pq;
vector<pii> v[2003];
int d[2003];
bool chk_dijk[2003];
const int INF = numeric_limits<int>::max() - 10001;

int max_wage = 0;

void init()
{
	for (int i = src; i <= sink; i++)	
	{
		d[i] = INF;
		chk_dijk[i] = false;
		p[i] = 0;
	}
}

bool dijkstra(int start)
{
	init();

	d[start] = 0;
	chk_dijk[start] = true;

	for (int i = 0; i < v[start].size(); i++)
		if (a[start][v[start][i].first] > 0)
			pq.push(make_pair(-v[start][i].second, make_pair(start, v[start][i].first)));

	while (!pq.empty())
	{
		int before_idx = pq.top().second.first;
		int now_idx = pq.top().second.second;
		int now_w = -pq.top().first;
		pq.pop();

		if (chk_dijk[now_idx]) continue;

		chk_dijk[now_idx] = true;
		d[now_idx] = now_w;
		p[now_idx] = before_idx;

		for (int i = 0; i < v[now_idx].size(); i++)
		{
			int next_idx = v[now_idx][i].first;
			int next_w = v[now_idx][i].second;

			if (a[now_idx][next_idx] > 0 && !chk_dijk[next_idx] && d[next_idx] > d[now_idx] + next_w)
				pq.push(make_pair(-(d[now_idx] + next_w), make_pair(now_idx, next_idx)));
		}
	}

	if (d[sink] == INF)
		return false;
	else
		return true;
}

void make_back(int now)
{
	if (now == src)
		return;

	if (work <= now && now < sink)
		v[now].push_back(make_pair(p[now], d[sink]));
	else
		v[now].push_back(make_pair(p[now], 0));

	a[p[now]][now]--;
	a[now][p[now]]++;

	make_back(p[now]);
}

int main()
{
	cin >> N >> M >> K;

	work = worker + N;
	sink = work + M;
	
	for (int i = worker; i < work; i++)
	{
		a[src][i] = 1;
		v[src].push_back(make_pair(i, 0));

		int W; cin >> W;
		for (int j = 0; j < 2 * W; j++)
		{
			int T; cin >> T;
			int wage; cin >> wage;
			T += work - 1;
			a[i][T] = 1;
			v[i].push_back(make_pair(T, wage));
		}
	}

	for (int i = work; i < sink; i++)
	{
		a[i][sink] = 1;
		v[i].push_back(make_pair(sink, 0));
	}

	while (dijkstra(src))
	{
		max_wage += d[sink];
		make_back(sink);
	}

	int ans = 0;
	for (int i = work; i < sink; i++)
		if (a[i][sink] == 0)
			ans++;

	cout << ans << '\n' << max_wage;
}
