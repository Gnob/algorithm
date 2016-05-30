#include <cstdio>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct _node
{
	int x, y, r;
};

using Node = struct _node;

vector<int> p(3000);
vector<Node> v(3000); 

int find_set(int x)
{
	if (x == p[x])
		return x;

	return p[x] = find_set(p[x]);
}

void union_set(int x, int y)
{
	p[find_set(x)] = y;
}

int pow(const int &x)
{
	return x * x;
}

int main()
{
	int T, N;

	cin >> T;

	while (T--)
	{
		scanf("%d", &N);

		for (int i = 0; i < N; i++)
			p[i] = i;

		scanf("%d %d %d", &v[0].x, &v[0].y, &v[0].r);
		for (int i = 1; i < N; i++)
		{
			scanf("%d %d %d", &v[i].x, &v[i].y, &v[i].r);

			for (int j = 0; j < i; j++)
			{
				if (find_set(i) != find_set(j)
						&& pow(v[j].x - v[i].x) + pow(v[j].y - v[i].y) <= pow(v[i].r + v[j].r))
					union_set(i, j);
			}
		}

		int cnt = 0;
		for (int i = 0; i < N; i++)
			if (find_set(i) == i) cnt++;

		cout << cnt << "\n";
	}
}
