#include <iostream>

using namespace std;

int a[54][54];
bool chk[54];
int src, enter, set_a, set_b, quit, sink;
int N;
int x[51];

bool find_path(int now)
{
	if (now == sink)
		return true;

	chk[now] = true;

	for (int i = src; i <= sink; i++)
	{
		if (!chk[now] && a[now][i] > 0)
		{
			if (find_path(i))
			{
				a[now][i]--;
				a[i][now]++;
				
				return true;
			}
		}
	}

	return false;
}

bool is_prime(int n)
{
	for (int i = 2; i * i <= n; i++)
		if (n % 2 == 0)
			return false;
	return true;
}

int main()
{
	cin >> N;
	src = 0;
	enter = src + 1;
	set_a = enter + N;
	set_b = set_a + N;
	quit = set_b + 1;
	sink = quit + 1;

	a[src][enter] = a[quit][sink] = N / 2;
	for (int i = 0; i < N; i++)
	{
		cin >> x[i];
		a[enter][set_a + i] = 1;
		a[set_b + i][quit] = 1;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (is_prime(x[i] + x[j]))
			{
				if (x[i] > x[j])
					a[set_a + j][set_b + i] = 1;
				else
					a[set_a + i][set_b + j] = 1;
			}
		}
	}

	while (find_path(src))
		for (int i = src; i <= sink; i++)
			chk[i] = false;

	cout << ;
}
