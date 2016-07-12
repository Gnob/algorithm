#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef pair<int, int> pii;

priority_queue<pii> pq;
bool chk[300001];
int d[300001];
vector<pii> v[300001];
const int INF = numeric_limits<int>::max() - 100;

int main()
{
	int V, E, start;

	cin >> V >> E >> start;

	for (int i = 0; i < E; i++)
	{
		int src, dst, weight;
		cin >> src >> dst >> weight;
		v[src].push_back(make_pair(dst, weight));
	}

	for (int i = 0; i <= V; i++)
		d[i] = INF;

	chk[start] = true;
	d[start] = 0;
	for (int i = 0; i < v[start].size(); i++)
		pq.push(make_pair(-v[start][i].second, v[start][i].first));

	while (!pq.empty())
	{
		pii now = pq.top(); pq.pop();

		if (chk[now.second])
			continue;

		chk[now.second] = true;
		d[now.second] = -now.first;

		for (int i = 0; i < v[now.second].size(); i++)
		{
			int n_src = now.second;
			int n_dst = v[now.second][i].first;
			int n_w = v[now.second][i].second;

			if (!chk[n_dst] && d[n_dst] > d[n_src] + n_w)
				pq.push(make_pair(-(d[n_src] + n_w), n_dst));
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (d[i] == INF)
			cout << "INF\n";
		else
			cout << d[i] << '\n';
	}
}
