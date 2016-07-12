#include <iostream>
#include <limits>
#include <vector>

using namespace std;

pair<int, int> a[1001];
unsigned int d[1001][1001];

pair<int, int> p[1001][1001];

unsigned int get_dist(int x, int y)
{
	return abs(a[y].first - a[x].first) + abs(a[y].second - a[x].second);
}

int main()
{
	int N, W;
	cin >> N >> W;

	a[0].first = a[0].second = 1;
	a[W + 1].first = a[W + 1].second = N;
	for (int i = 1; i <= W; i++)
		cin >> a[i].first >> a[i].second;

	for (int i = 0; i <= W; i++) for (int j = 0; j <= W; j++)
		d[i][j] = numeric_limits<int>::max();

	d[0][0] = 0;
	d[1][0] = get_dist(0, 1);
	d[0][1] = get_dist(W + 1, 1);

	p[1][0].first = p[1][0].second = p[0][1].first = p[0][1].second = 0;

	int tmp_origin[2];
	for (int i = 0; i < W; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (i != j)
			{
				int next = max(i, j) + 1;

				tmp_origin[0] = d[next][j];
				tmp_origin[1] = d[i][next];

				d[next][j] = min(d[next][j], d[i][j] + get_dist(i, next));
				if (j == 0)
					d[i][next] = min(d[i][next], d[i][j] + get_dist(W + 1, next));
				else
					d[i][next] = min(d[i][next], d[i][j] + get_dist(j, next));

				if (tmp_origin[0] != d[next][j])
				{
					p[next][j].first = i;
					p[next][j].second = j;
				}

				if (tmp_origin[1] != d[i][next])
				{
					p[i][next].first = i;
					p[i][next].second = j;
				}
			}
		}
	}

	unsigned int ans = numeric_limits<int>::max();
	pair<int, int> now;

	for (int i = 0; i < W; i++)
	{
		pair<int, int> tmp;
		if (d[W][i] < d[i][W])
		{
			tmp.first = W;
			tmp.second = i;
		}
		else
		{
			tmp.first = i;
			tmp.second = W;
		}

		if (d[tmp.first][tmp.second] < ans)
		{
			ans = d[tmp.first][tmp.second];
			now = tmp;
		}
	}

	vector<int> history;

	while (!(now.first == 0 && now.second == 0))
	{
		pair<int, int> before = p[now.first][now.second];

		if (now.first != before.first)
			history.push_back(1);
		else
			history.push_back(2);

		now = before;
	}

	cout << ans << '\n';

	while (history.size())
	{
		cout << history.back() << '\n';
		history.pop_back();
	}
}
