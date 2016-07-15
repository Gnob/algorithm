#include <iostream>
#include <queue>
#include <set>
#include <string>

using namespace std;

int p[1000000];

int find_set(int x)
{
	if (p[x] == x)
		return x;

	return p[x] = x;
}

void union_set(int x, int y)
{
	p[find_set(x)] = p[y];
}

int main()
{
	cout << 1 << endl;

	set<int> daepiso;
	set<pair<int, int>> edges;

	int N = 300, M = 1000, K = rand() % 300 + 1;
	cout << N << ' ' << M << ' ' << K << endl;

	int cnt = 0;
	while (cnt < M)
	{
		auto now_edge = make_pair(rand() % N + 1, rand() % N + 1);
		auto now_edge_anthoer = make_pair(now_edge.second, now_edge.first);
		int weight = rand() % 100 + 1;

		if (edges.count(now_edge))
			continue;
		
		cnt++;
		edges.insert(now_edge);
		edges.insert(now_edge_anthoer);

		union_set(now_edge.first, now_edge.second);

		cout << now_edge.first << ' ' << now_edge.second << ' ' << weight << endl;
	}

	cnt = 0;
	priority_queue<int> pq;
	while (cnt < K)
	{
		int idx = rand() % N + 1;

		if (daepiso.count(idx))
			continue;

		cnt++;
		pq.push(-idx);
	}

	while (!pq.empty())
	{
		cout << -pq.top() << ' ';
		pq.pop();
	}
	cout << endl;

	for (int i = 1; i <= N; i++)
	{
		int pre = 1;
		int now = 1;

	}
}

