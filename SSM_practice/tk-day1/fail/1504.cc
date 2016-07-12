/*
[bdoc #fail]
이 문제는 DFS를 변형해서 풀면 결국 복잡도가 굉장히 크게 늘어나고,
이를 브랜치 컷하는 것 만으로는 해결이 안된다.
 */
	
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

typedef pair<int, int> pii;
vector<pii> v[801];
bool chk[801];
int d[801];
int N, E;

bool is_visited[2];
int noc[2];
const int INF = numeric_limits<int>::max() - 1001;

/*
[bdoc #rule]
1. 방문 여부 판단은 진입 전에 한다.
[/bdoc]
*/
void go_dfs(int now, int dist)
{
	if (now == N)
	{
		if (is_visited[0] && is_visited[1])
			d[N] = min(d[N], dist);
		return;
	}

	if (noc[0] == now)
		is_visited[0] = true;
	else if (noc[1] == now)
		is_visited[1] = true;

	d[now] = dist;
	chk[now] = true;
	for (int i = 0; i < v[now].size(); i++)
	{
		int next_idx = v[now][i].first;
		int next_w = v[now][i].second;
		if (!chk[next_idx] && d[next_idx] > d[now] + next_w)
			go_dfs(next_idx, d[now] + next_w);
	}
	chk[now] = false;

	if (noc[0] == now)
		is_visited[0] = false;
	else if (noc[1] == now)
		is_visited[1] = false;

	return;
}

int main()
{
	cin >> N >> E;

	for (int i = 0; i < E; i++)
	{
		int src, dst, w;
		cin >> src >> dst >> w;
		v[src].push_back(make_pair(dst, w));
		v[dst].push_back(make_pair(src, w));
	}

	cin >> noc[0] >> noc[1];

	for (int i = 1; i <= N; i++)
		d[i] = INF;

	go_dfs(1, 0);

	if (d[N] == INF)
		cout << -1;
	else
		cout << d[N];
}
