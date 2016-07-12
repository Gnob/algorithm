#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef pair<int, int> pii;
priority_queue<pii> pq;
vector<pii> v[1001];
bool chk[1001];
int d[1001];
/* [bdoc]
   1. 다익스트라 알고리즘시 무한대 값은 (간선 수 * 최대 가중치) 보다 커야한다. 
   2. 무한대 값을 설정할때 오버플로우 방지 해줄 것
   [/bdoc]
 */
const int INF = numeric_limits<int>::max() - 100001;

int main()
{
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int src, dst, weight;
		cin >> src >> dst >> weight;
		v[src].push_back(make_pair(dst, weight));
	}

	int start, end;
	cin >> start >> end;

	for (int i = 0; i <= N; i++)
		d[i] = INF;

	chk[start] = true;
	d[start] = 0;

	for (int i = 0; i < v[start].size(); i++)
	{
		pq.push(make_pair(-v[start][i].second, v[start][i].first));
	}

	while(!pq.empty())
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

	cout << d[end];
}
