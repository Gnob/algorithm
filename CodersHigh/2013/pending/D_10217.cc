#include <iostream>
#include <cstdio>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

class Edge
{
public:
	int to, cost, time;
	Edge(int _to, int _cost, int _time)
		: to(_to), cost(_cost), time(_time) { }

	bool operator<(const Edge &rhs) const
	{
		return this->time < rhs.time;
	}
};

int main()
{
	int T;

	cin >> T;

	while (T--)
	{
		int N, M, E;

		cin >> N >> M >> E;

		vector<vector<Edge>> v(N + 1);

		for (int i = 0; i < E; i++)
		{
			int from, to, cost, time;
			scanf("%d %d %d %d", &from, &to, &cost, &time);
			v[from].emplace_back(to, cost, -time);
		}

		vector<int> d(N + 1, INT_MAX);
		vector<bool> chk(N + 1);

		int now = 1;
		d[now] = 0;
		chk[now] = true;

		priority_queue<Edge> q;

		for (auto &e: v[now])
			if (e.cost <= M) q.push(e), d[e.to] = -e.time;

		while (!q.empty())
		{
			auto now_e = q.top(); q.pop();

			if (chk[now_e.to]) continue;

			now = now_e.to;
			chk[now] = true;

			for (auto &e: v[now])
			{
				if (!chk[e.to] && now_e.cost + e.cost <= M && d[e.to] > d[now] - e.time)
				{
					d[e.to] = d[now] - e.time;
					e.cost += now_e.cost;
					q.push(e);
				}
			}
		}

		if (d.back() == INT_MAX)
			cout << "Poor KCM" << '\n';
		else
			cout << d.back() << '\n';
	}
}
