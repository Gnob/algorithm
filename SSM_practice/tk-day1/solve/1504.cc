#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef pair<int, int> pii;

priority_queue<pii> pq;
vector<pii> v[801];
int d[801];
bool chk[801];
const int INF = numeric_limits<int>::max() - 1001;

int N, E;

void init()
{
	for (int i = 1; i <= N; i++)	
	{
		d[i] = INF;
		chk[i] = false;
	}
}

void dijkstra(int start)
{
	init();

	d[start] = 0;
	chk[start] = true;

	for (int i = 0; i < v[start].size(); i++)
		pq.push(make_pair(-v[start][i].second, v[start][i].first));

	while (!pq.empty())
	{
		int now_idx = pq.top().second;
		int now_w = -pq.top().first;
		pq.pop();

		if (chk[now_idx]) continue;

		chk[now_idx] = true;
		d[now_idx] = now_w;

		for (int i = 0; i < v[now_idx].size(); i++)
		{
			int next_idx = v[now_idx][i].first;
			int next_w = v[now_idx][i].second;

			if (!chk[next_idx] && d[next_idx] > d[now_idx] + next_w)
				pq.push(make_pair(-(d[now_idx] + next_w), next_idx));
		}
	}
}

int main()
{
	cin >> N >> E;

	for (int i = 0; i < E; i++)
	{
		int s, d, w;
		cin >> s >> d >> w;
		v[s].push_back(make_pair(d, w));
		v[d].push_back(make_pair(s, w));
	}

	int A, B;
	cin >> A >> B;

	dijkstra(1);
	int dist_s2a = d[A];
	int dist_s2b = d[B];

	dijkstra(N);
	int dist_a2e = d[A];
	int dist_b2e = d[B];

	dijkstra(A);
	int dist_a2b = d[B];

	int ans = 0;
	if (dist_s2a == INF && dist_s2b == INF)
		ans = -1;
	if (dist_a2e == INF && dist_b2e == INF)
		ans = -1;
	if (dist_a2b == INF)
		ans = -1;

	if (ans != -1)
	{
		int s_a_e = dist_s2a + dist_a2b + dist_b2e;
		int s_b_e = dist_s2b + dist_a2b + dist_a2e;

		if (s_a_e < s_b_e)
			ans = s_a_e;
		else
			ans = s_b_e;
	}

	cout << ans;
}
