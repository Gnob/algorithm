#include <iostream>

using namespace std;

struct Point
{
	int x, y;
};

const int INIT_POS[2] = { 0, 1001 };

bool visited[1002];
int other_pos[1002][2];
int d[1002][2];
Point a[1002];

inline int get_dist(int src, int dst)
{
	return abs(a[dst].x - a[src].x) + abs(a[dst].y - a[src].y);
}

int main()
{
	int N, W;

	cin >> N >> W;

	for (int i = 1; i <= W; i++)
		cin >> a[i].x >> a[i].y;

	a[INIT_POS[0]].x = 1;
	a[INIT_POS[0]].y = 1;
	
	a[INIT_POS[1]].x = N;
	a[INIT_POS[1]].y = N;

	d[1][0] = get_dist(INIT_POS[0], 1);
	d[1][1] = get_dist(INIT_POS[1], 1);

	other_pos[1][0] = INIT_POS[1];
	other_pos[1][1] = INIT_POS[0];

	for (int i = 2; i <= W; i++)
	{
		int before = d[i - 1][0] + get_dist(i - 1, i);
		int not_before = d[i - 1][1] + get_dist(other_pos[i - 1][1], i);
		if (before < not_before)
		{
			d[i][0] = before;
			other_pos[i][0] = other_pos[i - 1][0];
		}
		else
		{
			d[i][0] = not_before;
			other_pos[i][0] = i - 1;
		}

		before = d[i - 1][1] + get_dist(i - 1, i);
		not_before = d[i - 1][0] + get_dist(other_pos[i - 1][0], i);
		if (before < not_before)
		{
			d[i][1] = before;
			other_pos[i][1] = other_pos[i - 1][1];
		}
		else
		{
			d[i][1] = not_before;
			other_pos[i][1] = i - 1;
		}
	}

	int winner = 0, looser = 1;

	if (d[W][0] > d[W][1])
	{
		winner = 1;
		looser = 0;
	}

	for (int i = 1; i <= W; i++)
	{
		if (other_pos[i][0] == INIT_POS[1])
			other_pos[i][0] = 0;
		if (other_pos[i][1] == INIT_POS[1])
			other_pos[i][1] = 0;
	}
	
	cout << d[W][winner] << '\n';

	int now = W;
	int who = winner;
	bool is_winner = true;

	while (now > 0)
	{
		for (int i = now; i > other_pos[now][who]; i--)
			visited[i] = is_winner;

		now = other_pos[other_pos[now][who]][(who + 1) % 2];
		is_winner = !is_winner;
		who = (who + 1) % 2;
	}

	// do
	// {
	// 	visited[now] = true;
	// 	now = other_pos[other_pos[now][winner]][looser];
	// } while (now != INIT_POS[winner]);

	for (int i = 1; i <= W; i++)
	{
		if (visited[i])
			cout << winner + 1;
		else 
			cout << looser + 1;
		cout << '\n';
	}
}
