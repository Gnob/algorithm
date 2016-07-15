#include <iostream>

using namespace std;

int p[501];
int d[501][501];
int s[501][501];

int go_dp(int i, int j)
{
	if (i == j || d[i][j] != 0)
		return d[i][j];

	s[i][j] = j;
	d[i][j] = INT_MAX;
	for (int k = i; k < j; k++)
	{
		int tmp = go_dp(i, k) + go_dp(k + 1, j) + p[i - 1] * p[k] * p[j];
		if (tmp < d[i][j])
		{
			d[i][j] = tmp;
			s[i][j] = k;
		}
	}

	return d[i][j];
}

void go_str(int i, int j)
{
	if (i == j)
		cout << "A" << i;
	else
	{
		cout << "(";
		go_str(i, s[i][j]);
		go_str(s[i][j] + 1, j);
		cout << ")";
	}
}

// wrong
void proc(int n)
{
	for (int cross = 2; cross <= n; cross++)
	{
		for (int x = 1, y = cross; y <= n; x++, y++)
		{
			d[x][y] = min(d[x][y - 1] + p[x - 1] * p[y - 1] * p[y],
					d[x - 1][y] + p[x - 1] * p[x] * p[y]);
		}
	}
}

int main()
{
	int n;
	cin >> n;

	cin >> p[0];
	
	for (int i = 2; i <= 2 * n; i++)
	{
		if (i % 2)
			cin >> p[i/2];
		else
			cin >> p[n];
	}

	// auto ans = go_dp(1, n);
	proc(n);
	auto ans = d[1][n];
	
	cout << ans;

	//go_str(1, n);
}
